#!/bin/bash

clang++ -std=c++11 -pthread $1 parallelVectorGeneration.cpp -o parallelVectorGeneration
clang++ -std=c++11 $1 serialVectorGeneration.cpp -o serialVectorGeneration
