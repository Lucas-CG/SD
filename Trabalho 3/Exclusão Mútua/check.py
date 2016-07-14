import sys

def check(f, np):
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

	if len(d.keys()) != np:
		print len(d.keys())
		return False

	for j in d.values():
		if j!=100:
			print "agora"
			return False

if (len(sys.argv) != 3): print "Uso: python check.py [nome do arquivo] [numero de processos]"

print check(sys.argv[1], sys.argv[2])