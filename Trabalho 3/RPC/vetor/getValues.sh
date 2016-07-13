echo "Rodando programa"
mkdir tempos
mkdir tempos/media
cd tempos

for k in 1,1 1,2 1,4 1,8 1,16 1,32 1,64 1,128 2,1 2,2 2,4 2,8 2,16 2,32 2,64 2,128 3,1 3,2 3,4 3,8 3,16 3,32 3,64 3,128
do
	IFS=",";
	set $k;
	for i in 1 2 3 4 5 6 7 8 9 10
	do		
		./../calculate_client $1 $2 | grep "Tempo de execução:" | awk '{print $4}' >> tempos-$1-$2.txt
	done
done


echo "Calculando as médias"
for k in 1,1 1,2 1,4 1,8 1,16 1,32 1,64 1,128 2,1 2,2 2,4 2,8 2,16 2,32 2,64 2,128 3,1 3,2 3,4 3,8 3,16 3,32 3,64 3,128
do
	IFS=",";
	set $k;
	./../calculateAverages tempos-$1-$2.txt >> media/medias.txt
done