import sys

def interval(f):
	l = [];
	f = open(f,'r')
	for line in f:
		if len(line)!=0:
			l.append(int(line.split(" ")[1]))							
	maximo = max(l)
	minimo = min(l)
	print maximo-minimo
	

interval(sys.argv[1])
