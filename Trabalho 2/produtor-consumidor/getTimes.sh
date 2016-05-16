echo "Rodando programa"
for i in 1 2 3 4 5 6 7 8 9 10
do
	./main 2 1 1 10000 | grep "Tempo de execução:" >> 211.txt
	./main 2 2 2 10000 | grep "Tempo de execução:" >> 222.txt
	./main 2 5 5 10000 | grep "Tempo de execução:" >> 255.txt
	./main 2 10 10 10000 | grep "Tempo de execução:" >> 21010.txt
	./main 2 2 10 10000 | grep "Tempo de execução:" >> 2210.txt
	./main 2 10 2 10000 | grep "Tempo de execução:" >> 2102.txt
	./main 4 1 1 10000 | grep "Tempo de execução:" >> 411.txt
	./main 4 2 2 10000 | grep "Tempo de execução:" >> 422.txt
	./main 4 5 5 10000 | grep "Tempo de execução:" >> 455.txt
	./main 4 10 10 10000 | grep "Tempo de execução:" >> 41010.txt
	./main 4 2 10 10000 | grep "Tempo de execução:" >> 4210.txt
	./main 4 10 2 10000 | grep "Tempo de execução:" >> 4102.txt
	./main 8 1 1 10000 | grep "Tempo de execução:" >> 811.txt
	./main 8 2 2 10000 | grep "Tempo de execução:" >> 822.txt
	./main 8 5 5 10000 | grep "Tempo de execução:" >> 855.txt
	./main 8 10 10 10000 | grep "Tempo de execução:" >> 81010.txt
	./main 8 2 10 10000 | grep "Tempo de execução:" >> 8210.txt
	./main 8 10 2 10000 | grep "Tempo de execução:" >> 8102.txt
	./main 16 1 1 10000 | grep "Tempo de execução:" >> 1611.txt
	./main 16 2 2 10000 | grep "Tempo de execução:" >> 1622.txt
	./main 16 5 5 10000 | grep "Tempo de execução:" >> 1655.txt
	./main 16 10 10 10000 | grep "Tempo de execução:" >> 161010.txt
	./main 16 2 10 10000 | grep "Tempo de execução:" >> 16210.txt
	./main 16 10 2 10000 | grep "Tempo de execução:" >> 16102.txt
	./main 32 1 1 10000 | grep "Tempo de execução:" >> 3211.txt
	./main 32 2 2 10000 | grep "Tempo de execução:" >> 3222.txt
	./main 32 5 5 10000 | grep "Tempo de execução:" >> 3255.txt
	./main 32 10 10 10000 | grep "Tempo de execução:" >> 321010.txt
	./main 32 2 10 10000 | grep "Tempo de execução:" >> 32210.txt
	./main 32 10 2 10000 | grep "Tempo de execução:" >> 32102.txt
done

echo "Calculando as médias"

for f in *.txt
do
	cat $f | awk '{print $4}' >> A$f
	./calculateAverages A$f >> AV$f
	rm A$f
done
