#!/bin/bash


compiler=GPP
optimizationFlag=-O2


./compile$compiler.sh $optimizationFlag

mkdir Logs_$compiler$optimizationFlag

for i in 1 2 3 4 5 6 7 8 9 10 15 20 30; do #número de threads

	for j in 100000000 1000000000 10000000000; do #tamanho do vetor

		for k in 1 2 3 4 5 6 7 8 9 10; do #número da execução

			./somador $i $j > Logs_$compiler$optimizationFlag/log.$i.$j.$k.txt


			#tempo de execução
			cat Logs_$compiler$optimizationFlag/log.$i.$j.$k.txt | grep "execução" | awk '{print $4}' >> Logs_$compiler$optimizationFlag/runtimes.$i.$j.txt

			#tempo total
			cat Logs_$compiler$optimizationFlag/log.$i.$j.$k.txt | grep "total" | awk '{print $3}' >> Logs_$compiler$optimizationFlag/totaltimes.$i.$j.txt

			#tempo para liberar a memória
			sleep 2

			if [[ $k -eq 10 ]]; then

				#calcular médias
				
				g++ calculateAverages.cpp -o calculateAverages

				echo $j,$(./calculateAverages Logs_$compiler$optimizationFlag/runtimes.$i.$j.txt) >> Logs_$compiler$optimizationFlag/averagesruntime.$i.csv

				echo $j,$(./calculateAverages Logs_$compiler$optimizationFlag/totaltimes.$i.$j.txt) >> Logs_$compiler$optimizationFlag/averagestotaltime.$i.csv
			fi

		done

	done

done



