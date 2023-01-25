#
# Created by Yann on 19/07/2021.
#

class No_t:
    def __init__(self, peso_aresta: int, id: int):
        self.peso_aresta = peso_aresta
        self.id = id


class FilaPrioridade:
    def pop(lista_no: list):
        no_sai = lista_no.pop(0)
        return lista_no, no_sai

    def push(lista_no: list, novo_no: No_t):
        nova_lista = []

        # se a lista for vazia
        if not lista_no:
            nova_lista.append(novo_no)
            return nova_lista

        i = 0
        # procura a posicao na fila de prioridade
        while i < len(lista_no) and lista_no[i].peso_aresta < novo_no.peso_aresta:
            nova_lista.append(lista_no[i])
            i += 1
        nova_lista.append(novo_no)

        # coloca os elementos restantes na lista

        for j in range(i, len(lista_no)):
            nova_lista.append(lista_no[j])
        return nova_lista


def ler_arquivo_pajek(nome_arquivo: str):
    arquivo = open(nome_arquivo, "r")
    str, n_nos_str = arquivo.readline().split(" ")
    n_nos = int(n_nos_str)
    type = arquivo.readline()
    matriz = [[0 for i in range(n_nos)] for j in range(n_nos)]
    str = arquivo.readline()
    while len(str) > 3: #monta a matriz contendo se a aresta entre 2 nos existe ou nao
        v1_str, v2_str, weight_str = str.split(" ")
        v1 = int(v1_str)
        v2 = int(v2_str)
        weight = int(weight_str)
        matriz[v1-1][v2-1] = weight; #-1 porque passa de numero para pos em vetor

        #Se for um grafo nao direcionado
        if type == "*Edges\n":
            matriz[v2-1][v1-1] = weight; #coloca o valor na inversa
        str = arquivo.readline()


    arquivo.close()
    return matriz, n_nos


def criar_matriz_adjacencias(matriz: list, n_nos: int):
    matriz_adj = [[] for _ in range(n_nos)]
    for i in range(n_nos):
        for j in range(n_nos):
            if i != j and matriz[i][j] > 0:
                matriz_adj[i].append(j+1)  # +1 pra transformar de pos em array pra numero
    return matriz_adj


def prim(matriz_dist: list, matriz_adj: list, n_nos: int):

    arvore = []
    total = 0
    no_pai = No_t(0, 1)

    pq = FilaPrioridade
    # n_nos-1 porque cada iteracao entra um novo no, mas o no raiz ja entra fora do loop
    for i in range(n_nos-1):

        arvore.append(no_pai.id)

        arestas = []

        # para todos os vertices que estao na arvore
        for vertice in arvore:
            # ira verificar todos os nos adjacentes desse vertice
            for adj in matriz_adj[vertice-1]:
                # se o no adjacente ainda nao estiver na arvore, ele eh colocado para ser analisado
                if adj not in arvore:
                    no = No_t(matriz_dist[vertice-1][adj-1], adj)
                    arestas = pq.push(arestas, no)


        # retira o no que ainda nao esta na arvore e tem menor peso
        arestas, filho = pq.pop(arestas)

        total += filho.peso_aresta
        no_pai = filho

    print(total)


nome_arquivo = input()
matriz_dist, n_nos = ler_arquivo_pajek(nome_arquivo)
matriz_adj = criar_matriz_adjacencias(matriz_dist, n_nos)
prim(matriz_dist, matriz_adj, n_nos)
