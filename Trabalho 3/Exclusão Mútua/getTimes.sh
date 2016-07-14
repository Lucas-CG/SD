#!/bin/bash

mkdir -p resultados-EM/times
mkdir -p resultados-EM/logs
mkdir -p resultados-EM/outputs

g++ -O3 calculateAverages.cpp -o calculateAverages

./coordinator &

for arrival in "bulk" "sequential"; do

    for numprocs in 1 2 4 8 16 32 64 128; do
        for i in 1 2 3 4 5 6 7 8 9 10; do        
            
            ./client $arrival $numprocs
            
            python interval.py log.txt >> resultados-EM/times.$arrival.$numprocs.txt
            
            mv log.txt resultados-EM/log.$arrival.$numprocs.$i.txt
            mv output.txt resultados-EM/output.$arrival.$numprocs.$i.txt
            
            
        done
        
        echo numprocs,timeaverage >> resultados-EM/finalresults.$arrival.csv
        echo $numprocs,$(./calculateAverages resultados-EM/times.$arrival.$numprocs.txt) >> resultados-EM/finalresults.$arrival.csv
        
    done

done

killall -9 coordinator


