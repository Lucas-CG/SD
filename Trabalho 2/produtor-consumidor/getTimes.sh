for i in 1 2 3 4 5
do
	./main 2 1 1 10000 | grep "Tempo" >> 211.txt
	./main 2 2 2 10000 | grep "Tempo" >> 222.txt
	./main 2 5 5 10000 | grep "Tempo" >> 255.txt
	./main 2 10 10 10000 | grep "Tempo" >> 21010.txt
	./main 2 2 10 10000 | grep "Tempo" >> 2210.txt
	./main 2 10 2 10000 | grep "Tempo" >> 2102.txt
	./main 4 1 1 10000 | grep "Tempo" >> 411.txt
	./main 4 2 2 10000 | grep "Tempo" >> 422.txt
	./main 4 5 5 10000 | grep "Tempo" >> 455.txt
	./main 4 10 10 10000 | grep "Tempo" >> 41010.txt
	./main 4 2 10 10000 | grep "Tempo" >> 4210.txt
	./main 4 10 2 10000 | grep "Tempo" >> 4102.txt
	./main 8 1 1 10000 | grep "Tempo" >> 811.txt
	./main 8 2 2 10000 | grep "Tempo" >> 822.txt
	./main 8 5 5 10000 | grep "Tempo" >> 855.txt
	./main 8 10 10 10000 | grep "Tempo" >> 81010.txt
	./main 8 2 10 10000 | grep "Tempo" >> 8210.txt
	./main 8 10 2 10000 | grep "Tempo" >> 8102.txt
	./main 16 1 1 10000 | grep "Tempo" >> 1611.txt
	./main 16 2 2 10000 | grep "Tempo" >> 1622.txt
	./main 16 5 5 10000 | grep "Tempo" >> 1655.txt
	./main 16 10 10 10000 | grep "Tempo" >> 161010.txt
	./main 16 2 10 10000 | grep "Tempo" >> 16210.txt
	./main 16 10 2 10000 | grep "Tempo" >> 16102.txt
	./main 32 1 1 10000 | grep "Tempo" >> 3211.txt
	./main 32 2 2 10000 | grep "Tempo" >> 3222.txt
	./main 32 5 5 10000 | grep "Tempo" >> 3255.txt
	./main 32 10 10 10000 | grep "Tempo" >> 321010.txt
	./main 32 2 10 10000 | grep "Tempo" >> 32210.txt
	./main 32 10 2 10000 | grep "Tempo" >> 32102.txt
done