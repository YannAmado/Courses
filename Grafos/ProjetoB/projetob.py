#
# Created by Yann on 25/07/2021.
#

def ler_arquivo_pajek(nome_arquivo: str):
    arquivo = open(nome_arquivo, "r")
    str, n_nos_str = arquivo.readline().split(" ", 1)
    n_nos = int(n_nos_str)
    type = arquivo.readline()
    matriz = [[0 for i in range(n_nos)] for j in range(n_nos)]
    str = arquivo.readline()
    id_nos = []
    while len(str) > 2: #monta a matriz contendo se a aresta entre 2 nos existe ou nao
        v1_str, v2_str = str.split(" ", 1)
        v1 = int(v1_str)
        v2 = int(v2_str)
        matriz[v1-1][v2-1] = 1; #-1 porque passa de numero para pos em vetor
        #Se for um grafo nao direcionado
        if type == "*Edges":
            matriz[v2-1][v1-1] = 1; #coloca o valor na inversa
        str = arquivo.readline()

        if v1 not in id_nos:
            id_nos.append(v1)
        if v2 not in id_nos:
            id_nos.append(v2)

    arquivo.close()
    return matriz, n_nos, id_nos


def criar_matriz_adjacencias(matriz: list, n_nos: int):
    matriz_adj = [[] for _ in range(n_nos)]
    for i in range(n_nos):
        for j in range(n_nos):
            if i != j and matriz[i][j] > 0:
                matriz_adj[i].append(j+1) #+1 pra transformar de pos em array pra numero
    return matriz_adj


def busca_profundidade_algoritmo(matriz_adj: list, n_nos: int, no_comeco: int, branco: list,
                                 preto: list, cinza: list, sorv: list):
    no_comeco_pos = no_comeco - 1    # -1 pra ser pos em array
    cinza.append(no_comeco)    # seta o no inicial como cinza
    branco.remove(no_comeco)
    # O for abaixo ira montar a pilha dos elementos cinzas completa recursivamente
    # Primeiro verifica se o no ta na fila preto ou cinza

    #se o vertice atual tem filhos
    if matriz_adj[no_comeco_pos]:
        # remove ele da lista de sorvedouros
        sorv.remove(no_comeco)

    for no_atual in matriz_adj[no_comeco_pos]:
        if no_atual != 0:   # verifica se existe aresta entre os nos

            if no_atual in branco:
                sorv, preto = busca_profundidade_algoritmo(matriz_adj, n_nos, no_atual, branco, preto, cinza, sorv)

    # Quando acabar a recursao, vai a partir do ultimo elemento da pilha colocando no prto e tirando do cinza
    preto.append(no_comeco)
    cinza.pop()
    return sorv, preto


def busca_profundidade(matriz_adj: list, n_nos: int, id_nos):
    branco = []
    cinza = []
    preto = []
    sorv = []
    for i in id_nos:
        branco.append(i) # +1 pra representar realmente o numero do no
        sorv.append(i)
    while branco: # enquanto ainda existirem elementos para serem iterados
        sorv, preto = busca_profundidade_algoritmo(matriz_adj, n_nos, branco[0], branco, preto, cinza, sorv) # +1 pra ser no e nao pos
        for no in preto:
            if no in branco:
                branco.remove(no)
    return sorv

def achar_fontes(matriz_adj: list, n_nos: list, id_nos):
    sorv = busca_profundidade(matriz_adj, n_nos, id_nos)
    print(len(sorv))


nome_arquivo = input()
matriz_dist, n_nos, id_nos = ler_arquivo_pajek(nome_arquivo)
matriz_adj = criar_matriz_adjacencias(matriz_dist, n_nos)
achar_fontes(matriz_adj, n_nos, id_nos)
