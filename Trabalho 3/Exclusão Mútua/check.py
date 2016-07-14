import sys

def check(f):
	d = {};
	f = open(f,'r')
	for line in f:
		if len(line)!=0:
			valor = line.split("\n")[0]
			if d.has_key(valor):
				aux = d.get(valor)
				d[valor] = aux + 1
			else:
				d[valor]= 1

	if len(d.keys()) != 100:
		return false

	for j in d.values():
		if j!=100:
			return false

if (len(sys.argv) != 2): print "Uso: python check.py [nome do arquivo]"

check(sys.argv[1])