#!/bin/bash

g++ -std=c++11 -pthread $1 parallelVectorGeneration.cpp -o parallelVectorGeneration
g++ -std=c++11 $1 serialVectorGeneration.cpp -o serialVectorGeneration
