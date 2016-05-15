#!/bin/bash

clang++ -std=c++11 -pthread $1 somador.cpp -o somador
