#
# Created by Yann on 30/07/2021.
#

class no_t:
    def __init__(self, pai: int, mae: int, id: int):
        self.pai = pai
        self.mae = mae
        self.id = id
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


def remover_no(lista_nos: list, no_remover: int):
    for no in lista_nos:
        if no.id == no_remover:
            lista_nos.remove(no)
            return lista_nos
    return lista_nos


def encontrar_no(lista_nos: list, no_encontrar: int):
    for no in lista_nos:
        if no.id == no_encontrar:
            return no
    return None

def busca_profundidade_algoritmo(matriz_adj: list, no_comeco: int, branco: list,
                                 preto: list, cinza: list, sorv: list, descendentes_de_1: list):
    no_comeco_pos = no_comeco - 1    # -1 pra ser pos em array
    cinza.append(no_comeco)    # seta o no inicial como cinza
    branco.remove(no_comeco)
    # O for abaixo ira montar a pilha dos elementos cinzas completa recursivamente
    # Primeiro verifica se o no ta na fila preto ou cinza

    #se o vertice atual tem filhos
    if matriz_adj[no_comeco_pos]:
        # remove ele da lista de sorvedouros
        sorv = remover_no(sorv, no_comeco)

    for no_atual in matriz_adj[no_comeco_pos]:


        # Procura se o no esta na lista de sorvedouros
        no =  encontrar_no(sorv, no_atual)
        # Se tiver
        if no:
            # Seta o pai se ainda nao existir
            if no.pai == 0:
                no.pai = no_comeco
            # Seta a mae se ainda nao existir
            elif no.mae == 0:
                no.mae = no_comeco

        # Se o pai do no for 1 ou descendente de 1
        if no_comeco == 1 or no_comeco in descendentes_de_1:
            descendentes_de_1.append(no_atual)

        if no_atual != 0:   # verifica se existe aresta entre os nos

            if no_atual in branco:
                sorv, descendentes_de_1, preto = busca_profundidade_algoritmo(matriz_adj, no_atual, branco, preto, cinza, sorv, descendentes_de_1)

    # Quando acabar a recursao, vai a partir do ultimo elemento da pilha colocando no prto e tirando do cinza
    preto.append(no_comeco)
    cinza.pop()
    return sorv, descendentes_de_1, preto


def busca_profundidade(matriz_adj: list, id_nos):
    branco = []
    cinza = []
    preto = []
    sorv = []
    descendentes_de_1 = [1]
    for i in id_nos:
        branco.append(i) # +1 pra representar realmente o numero do no
        sorv.append(no_t(0, 0, i))
    while branco: # enquanto ainda existirem elementos para serem iterados
        sorv, descendentes_de_1, preto = busca_profundidade_algoritmo(matriz_adj, branco[0], branco, preto, cinza, sorv, descendentes_de_1) # +1 pra ser no e nao pos
        for no in preto:
            if no in branco:
                branco.remove(no)

    descendentes_sorv = []

    # Analisando todos os sorvedouros
    for no in sorv:

        # Se ambos os pais do sorvedouro forem descendentes de 1
        if no.pai in descendentes_de_1 and no.mae in descendentes_de_1:
            descendentes_sorv.append(no.id)
    descendentes_sorv.sort()
    return descendentes_sorv


def achar_descendentes(matriz_adj: list, id_nos):
    descendentes_sorvedouros = busca_profundidade(matriz_adj, id_nos)
    for i in descendentes_sorvedouros:
        print(i)


nome_arquivo = input()
matriz_dist, n_nos, id_nos = ler_arquivo_pajek(nome_arquivo)
matriz_adj = criar_matriz_adjacencias(matriz_dist, n_nos)
achar_descendentes(matriz_adj, id_nos)
