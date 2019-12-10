// client 참고용 샘플코드
// 추출된 프로토콜 순서 fsm와 결합하여 활용하면 됨
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mut;
int packetCounter = 0;


void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int _main(char *argv[]);
int main(int argc, char *argv[])
{
    int N = 10;
    thread t[N];
    for (int i = 0; i < N; i++)
        t[i] = thread(&_main, argv);
    for (int i = 0; i < N; i++)
        t[i].join();
    return 0;
}
// 비신뢰성 프로토콜인 udp에서 client와 통신 간 패킷 하나당 ack를 받도록 함.
// 이를 protocol inference를 통해 추출한 상태추론 fsm과 유기결합하는 진행중임.

// udp 환경에서 message를 받으면 ack를 보냄
int _main(char *argv[])
{
    int sock, n,
            errorRate = atoi(argv[3]) * 10;
    unsigned int length = sizeof(struct sockaddr_in);;
    struct sockaddr_in server, from;
    struct hostent *hp;
    char buffer[256];

    sock= socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) error("socket");

    server.sin_family = AF_INET;
    hp = gethostbyname(argv[1]);
    if (hp == 0) error("Unknown host");

    bcopy((char *)hp->h_addr,
          (char *)&server.sin_addr,
          hp->h_length);
    server.sin_port = htons(atoi(argv[2]));
    bzero(buffer, 1000);

    clock_t startTime = clock();
    double secondsPassed;
    double secondsToDelay = atof("600");
    bool flag = true;
    while (flag)
    {
        {
            lock_guard<mutex> guard(mut);
            if (packetCounter % 10 == errorRate)
            {
                packetCounter++;
                continue;
            }
        }
        n = sendto(sock,buffer,
                   strlen(buffer),0,(const struct sockaddr *)&server,length);

        n = recvfrom(sock,buffer,256,0,(struct sockaddr *)&from, &length);
        {
            lock_guard<mutex> guard(mut); 
            const char* tmp = to_string(packetCounter + 1).c_str();
            packetCounter++;
            write(1, tmp, sizeof(tmp));
        }
        write(1,buffer,n);

        secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;
        if(secondsPassed >= secondsToDelay)
            flag = false;
    }
    close(sock);
    return 0;
}
