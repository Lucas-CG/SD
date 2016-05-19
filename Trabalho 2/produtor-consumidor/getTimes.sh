echo "Rodando programa"
mkdir tempos
mkdir tempos/medias

for i in 1 2 3 4 5 6 7 8 9 10
do
	./main 2 1 1 10000
	./main 2 2 2 10000
	./main 2 5 5 10000
	./main 2 10 10 10000
	./main 2 2 10 10000
	./main 2 10 2 10000
	./main 4 1 1 10000
	./main 4 2 2 10000
	./main 4 5 5 10000
	./main 4 10 10 10000
	./main 4 2 10 10000
	./main 4 10 2 10000
	./main 8 1 1 10000
	./main 8 2 2 10000
	./main 8 5 5 10000
	./main 8 10 10 10000
	./main 8 2 10 10000
	./main 8 10 2 10000
	./main 16 1 1 10000
	./main 16 2 2 10000
	./main 16 5 5 10000
	./main 16 10 10 10000
	./main 16 2 10 10000
	./main 16 10 2 10000
	./main 32 1 1 10000
	./main 32 2 2 10000
	./main 32 5 5 10000
	./main 32 10 10 10000
	./main 32 2 10 10000
	./main 32 10 2 10000
done

echo "Calculando as médias"
cd tempos
for f in *.txt
do
	cat $f >> medias/A$f
	./../calculateAverages medias/A$f >> medias/AV$f
	rm medias/A$f
done
