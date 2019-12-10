// server 참고용 샘플코드
// 추출된 프로토콜 순서 fsm와 결합하여 활용하면 됨
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <thread>
#include <chrono>
using namespace std;
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

// 비신뢰성 프로토콜인 udp에서 client와 통신 간 패킷 하나당 ack를 받도록 함.
// 이를 protocol inference를 통해 추출한 상태추론 fsm과 유기결합하는 진행중임.
int main(int argc, char *argv[])
{
    struct sockaddr_in server,
            from;
    int sock,
            length = sizeof(server),
            n;
    socklen_t fromlen = sizeof(struct sockaddr_in);
    char buf[1024];

    int errorRate = atoi(argv[2]) * 10, // between 0.1 - 0.9
            packetCounter = 0;

    sock=socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) error("Opening socket");

    bzero(&server, length);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));

    if (bind(sock, (struct sockaddr *)&server, length) < 0)
        error("binding");

    while (1)
    {
        if ((packetCounter + 3) % 10 == errorRate)
        {
            packetCounter++;
            continue;

        }
        n = recvfrom(sock, buf, 1024, 0, (struct sockaddr *)&from, &fromlen);
        this_thread::sleep_for(chrono::milliseconds(10));

        const char* tmp = to_string(packetCounter + 1).c_str();
        write(1, tmp, sizeof(tmp));
        write(1," Received a datagram: ",21);
        write(1,buf,n);

        n = sendto(sock,"message\n",17, // ack
                   0,(struct sockaddr *)&from,fromlen);


        packetCounter++;
    }
    return 0;
}
