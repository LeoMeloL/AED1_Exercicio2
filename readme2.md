Exercicio 2:

• O codigo utiliza da variavel char *nomes para armazenar todos os nomes em uma unica string, a funcao adicionarNome 
aloca e realoca memoria equivalente ao tamanho do nome digitado e salva na string.
• A funcao removeNome utiliza o comando memmove para retirar o nome da string e apos isso libera a memoria previamente alocada.

O codigo nao esta gerando warnings e esta funcionando completamente. Os testes do dr. Memory indicam que nao tem leak de memoria.