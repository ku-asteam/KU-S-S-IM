# KU-S-S-IM
Improved Network Protocol State Inference (2nd Year)

In this project, we propose a new approach to protocol inference through the improved KU-S-S-IM project.

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
In the initial study, as shown in the first figure, the two protocols overlapped considerably with green / red.
This meant that the two protocols were indistinguishable.
We used the deep neural network-based Auto-Encoder by setting a linear function as its activation function and the mean squared error (MSE) as a loss function. As a result of clustering through R, the protocol is divided into more than a certain level as shown in the second figure.This is in our paper.

![image](https://user-images.githubusercontent.com/41291493/68915431-66910600-07a5-11ea-88f7-b9bc18b00b7a.png)
![image](https://user-images.githubusercontent.com/41291493/68915437-698bf680-07a5-11ea-9c78-ebae9f41e7eb.png)

+ (20191115)
> `ssl/main.cpp`is the initial research step to solve the inference factor due to the SSL layer, and the implementation of obtaining the correct value from the structure of SSL is the first step.
  1. Build `main.py`
  2. Run `main.exe`(bulid file)

