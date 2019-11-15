# KU-S-S-IM
Network Protocol State Inference

## Introduction
Network Protocol Inference of aSTEAM Project (Next-Generation Information Computing Development Program through the National Research Foundation of Korea (NRF) funded by the Ministry of Science and ICT). 
The function of this software is to infer the state from the information of the previously acquired protocol. This can be used in a variety of ways and will play an important role in future integration with SDN.

## Requirements and Dependencies
* OS : `Ubuntu 18.04.1 LTS`
* Language : `c++`
* Library : `KU-S-S-EM`

## Instructions
* The Architecture of Protocol State Inference
본 아키텍처는 KU-S-S-EM에서 역공학을 통해 프로토콜의 Specification을 획득한 이후에,
해당 정보를 통해서 간단한 상태추론(전송중/전송완료)부터 심화연구까지를 연구하는데 활용됨

![architecture](https://user-images.githubusercontent.com/41291493/68915312-d226a380-07a4-11ea-975e-b82fc08c0540.png)

획득한 프로토콜 Specification을 바탕으로, 커널 바이패스 환경에서 `pseudo_code.cpp`의 방식으로 아래의 상태추론 메커니즘을 수행함

![image](https://user-images.githubusercontent.com/41291493/68915379-2598f180-07a5-11ea-8ad3-d6a3291681b3.png)


* Instructions for Use of `KU-S-S-IM`
  1. Open a terminal
  2. Install dependent libraries through `make install`
  3. Install `$ sudo apt-get install g++`
  4. Build `main.cpp`
  5. Run through the result of the `KU-S-S-EM`
  
 

+ (20191115)
서로 다른 프로토콜 간의 Classification을 수행하기 위한 연구. 초기 연구에서는 첫번째 그림처럼 2개의 프로토콜이 초록색/빨간색으로 상당히 많이 중복되는 부분이 발생하였다. 이는 두 가지 프로토콜을 구분할 수 없다는 점을 의미하였는데, 심층 신경망 기반의 Auto-Encoder에서 활성화 함수를 선형 함수로 사용하고 손실함수로 MSE(Mean Squared Error)를 사용하는 것으로 주성분 분석의 효과를 얻고 나서 Classification.r을 통해 군집화를 수행한 결과 두번째 그림처럼 프로토콜이 일정 수준 이상으로 구분되는 결과를 획득함. 해당 내용은 논문에 있음.

![image](https://user-images.githubusercontent.com/41291493/68915431-66910600-07a5-11ea-88f7-b9bc18b00b7a.png)
![image](https://user-images.githubusercontent.com/41291493/68915437-698bf680-07a5-11ea-9c78-ebae9f41e7eb.png)

+ (20191115)
> `ssl/main.cpp`은 SSL 레이어 떄문에 추론에 방해가 요소를 해결하기 위한 초기 연구단계로 가장 선행적으로 SSL의 구조에서 부터 정확한 값을 가져오는 것을 구현하고자 함.
  1. Build `main.py`
  2. Run `main.exe`(bulid file)

