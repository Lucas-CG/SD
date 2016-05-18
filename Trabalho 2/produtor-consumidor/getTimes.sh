echo "Rodando programa"
mkdir tempos
mkdir tempos/medias

for i in 1 2 3 4 5 6 7 8 9 10
do
	./main 2 1 1 10000 | grep "Tempo de execução:" >> tempos/211.txt
	./main 2 2 2 10000 | grep "Tempo de execução:" >> tempos/222.txt
	./main 2 5 5 10000 | grep "Tempo de execução:" >> tempos/255.txt
	./main 2 10 10 10000 | grep "Tempo de execução:" >> tempos/21010.txt
	./main 2 2 10 10000 | grep "Tempo de execução:" >> tempos/2210.txt
	./main 2 10 2 10000 | grep "Tempo de execução:" >> tempos/2102.txt
	./main 4 1 1 10000 | grep "Tempo de execução:" >> tempos/411.txt
	./main 4 2 2 10000 | grep "Tempo de execução:" >> tempos/422.txt
	./main 4 5 5 10000 | grep "Tempo de execução:" >> tempos/455.txt
	./main 4 10 10 10000 | grep "Tempo de execução:" >> tempos/41010.txt
	./main 4 2 10 10000 | grep "Tempo de execução:" >> tempos/4210.txt
	./main 4 10 2 10000 | grep "Tempo de execução:" >> tempos/4102.txt
	./main 8 1 1 10000 | grep "Tempo de execução:" >> tempos/811.txt
	./main 8 2 2 10000 | grep "Tempo de execução:" >> tempos/822.txt
	./main 8 5 5 10000 | grep "Tempo de execução:" >> tempos/855.txt
	./main 8 10 10 10000 | grep "Tempo de execução:" >> tempos/81010.txt
	./main 8 2 10 10000 | grep "Tempo de execução:" >> tempos/8210.txt
	./main 8 10 2 10000 | grep "Tempo de execução:" >> tempos/8102.txt
	./main 16 1 1 10000 | grep "Tempo de execução:" >> tempos/1611.txt
	./main 16 2 2 10000 | grep "Tempo de execução:" >> tempos/1622.txt
	./main 16 5 5 10000 | grep "Tempo de execução:" >> tempos/1655.txt
	./main 16 10 10 10000 | grep "Tempo de execução:" >> tempos/161010.txt
	./main 16 2 10 10000 | grep "Tempo de execução:" >> tempos/16210.txt
	./main 16 10 2 10000 | grep "Tempo de execução:" >> tempos/16102.txt
	./main 32 1 1 10000 | grep "Tempo de execução:" >> tempos/3211.txt
	./main 32 2 2 10000 | grep "Tempo de execução:" >> tempos/3222.txt
	./main 32 5 5 10000 | grep "Tempo de execução:" >> tempos/3255.txt
	./main 32 10 10 10000 | grep "Tempo de execução:" >> tempos/321010.txt
	./main 32 2 10 10000 | grep "Tempo de execução:" >> tempos/32210.txt
	./main 32 10 2 10000 | grep "Tempo de execução:" >> tempos/32102.txt
done

echo "Calculando as médias"
cd tempos
for f in *.txt
do
	cat $f | awk '{print $4}' >> medias/A$f
	./../calculateAverages medias/A$f >> medias/AV$f
	rm medias/A$f
done
