# Trabalho 2
Implementação do Somador Paralelo com *Spinlocks* e do Produtor-Consumidor com Semáforos

<strong>Instruções para Somador</strong>

O código fonte do programa é o arquivo somador.cpp. Para compilá-lo, basta usar um dos *scripts* de compilação, a depender do compilador instalado no sistema (o nome inicia com *compile*). O *script* suporta inserir *flags* de otimização como parâmetros.
Para executar os estudos de caso com as configurações do relatório, executar o *script* geraResultados.sh.
Os arquivos gerados com os tempos de execução estão na pasta Logs_GPP-O2.
O algoritmo usado para gerar o vetor de forma paralela para testes está na pasta "Geração de Vetor Aleatório". Para compilar os programas, executar um dos dois *scripts* de compilação da mesma forma que no código principal.

O algoritmo para gerar o vetor de forma paralela funciona da seguinte forma:
<ol>

	<li>Obtenção do número de _threads_ máximo suportado pelo processador.</li>
	<li>Geração de uma quantidade de _threads_ (nthreads) igual ao número obtido no passo anterior. As _threads_ apontam para as nthreads primeiras posições (contíguas) do vetor.</li>
	<li>Cada _thread_ gera um número aleatório, insere na posição alocada a ela e se move para nthreads posições à frente, até chegar ao fim do vetor.</li>

</ol>

<strong>Instruções para Produtor-Consumidor com Semáforos</strong>

O código fonte do programa é o arquivo main.cpp. Para compilá-lo, usar o *script* compileGPP.sh.
Resultados estão na pasta tempos. Pode-se executar os estudos de caso usando o *script* getTimes.sh.








