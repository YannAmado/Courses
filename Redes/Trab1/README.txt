Integrantes do grupo:

Yann Amado Nunes Costa nUSP: 10746943
Beatriz Aparecida Diniz nUSP: 11925430
Bruna Azevedo Garcia nUSP: 11381789

Código rodado no Ubuntu versão 22.04 LS.
O compilador utilizado foi o terminal do linux com o gcc.

Para instalar a biblioteca pthread: sudo apt-get install libpthread-stubs0-dev

Para rodar o servidor:
	make server
	make runServer

Para rodar o cliente:
	make client
	make runClient

Para rodar a aplicação, duas janelas de inicial devem ser inicializadas, uma pro servidor e outra pro cliente
Depois, basta dar os comandos make e depois run de seus respectivos.

O código não possui critério de parada já que nenhum foi especificado, e por isso ele vai ficar rodando para sempre, podendo ficar enviando e recebendo mensagens.





