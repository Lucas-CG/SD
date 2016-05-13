#!/bin/bash

clang++ -std=c++14 -pthread $1 somador.cpp -o somador
