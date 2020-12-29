# KU-S&S-IMv3
Improved Network Protocol State Inference (3rd Year)

In this project, we propose a new approach to protocol inference through the improved KU-S-S-IM project.

## Introduction
Network Protocol Inference of aSTEAM Project (Next-Generation Information Computing Development Program through the National Research Foundation of Korea (NRF) funded by the Ministry of Science and ICT). 
The software features the ability to collect data based on the Floodlight SDN controller and Mininet virtual networks, and statistical analysis of target packet data extracts five characteristics of different types of traffic types and classifies each type through the application of the DAGMM deep learning model.


## Requirements and Dependencies
* OS : `Ubuntu 18.04.1 LTS`
* Language : `python 2.7`
* Library : `KU-S-S-EM`

## Instructions
* Instructions for Use of `KU-S-S-IM`
  1. Open a terminal
  2. Convert Jupyter to Python code `jupyter nbconvert --to script dagmm_proto_inference.ipynb`
  3. Excute `dagmm_proto_inference.py`

```shell script
$ python dagmm_proto_inference.py
```


`AVG_IVL`: Average interval of packet

`AVG_PAY`: Average size of payload

`AVG_CNT`: Average count of packet

`PCL`: Protocol Number
