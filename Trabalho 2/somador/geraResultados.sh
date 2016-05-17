#!/bin/bash


for compiler in GPP CLANGPP; do

	for optimizationFlag in -O -O2 -O3; do

		./compile$compiler.sh $optimizationFlag

		mkdir Logs_$compiler$optimizationFlag

		for i in 1 2 3 4 5 6 7 8 9 10 15 20 30; do 

			for j in 100000000 1000000000 10000000000; do

				for k in 1 2 3 4 5 6 7 8 9 10; do

					./somador $i $j > Logs_$compiler$optimizationFlag/$i.$j.$k.txt

					cat Logs_$compiler$optimizationFlag/$i.$j.$k.txt | grep "execução" | awk '{print $4}' >> Logs_$compiler$optimizationFlag/times.$i.$j.txt

					#tempo para liberar a memória

					sleep 2

					if [[ $k -eq 10 ]]; then

						#calcular médias

						if [[ $(ls | grep calculateAverages) -eq "" ]]; then

							#se o calculador de médias não foi compilado...
						
							g++ calculateAverages.cpp -o calculateAverages.exe

						fi

						echo $i,$j,$(./calculateAverages Logs_$compiler$optimizationFlag/times.$i.$j.txt) >> Logs_$compiler$optimizationFlag/averages$compiler$optimizationFlag.csv

					fi

				done

			done

		done

	done

done