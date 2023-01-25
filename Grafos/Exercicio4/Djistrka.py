#
# Created by Yann on 09/07/2021.
#

class no_t():
    def __init__(self, caminho_nos: list, dist_ate_no: int, id: int):
        self.caminho_nos = caminho_nos
        self.dist_ate_no = dist_ate_no
        self.id = id


def printar_matriz(matriz: list, n: int):
    new_matriz = []
    for i in matriz:
        new_matriz += i
    numb_str = str(max(new_matriz))
    max_len = len(numb_str)
    for row in matriz:
        for col in row:
            numb_str = str(col)
            n_letras = len(numb_str)
            while n_letras < max_len:
                print(" ", end="")
                n_letras += 1
            print(numb_str, end=" ")
        print()


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
        if type == "*Edges":
            matriz[v2-1][v1-1] = weight; #coloca o valor na inversa
        str = arquivo.readline()


    arquivo.close()
    return matriz, n_nos


def criar_matriz_adjacencias(matriz: list, n_nos: int):
    matriz_adj = [[] for _ in range(n_nos)]
    for i in range(n_nos):
        for j in range(n_nos):
            if i != j and matriz[i][j] > 0:
                matriz_adj[i].append(j+1) #+1 pra transformar de pos em array pra numero
    return matriz_adj


def remover_folha_dup(comeco: int, folhas: list):
    for i in range(comeco, len(folhas)):
        for j in range(i+1, len(folhas)):
            if folhas[i].id == folhas[j].id:
                if folhas[i].dist_ate_no > folhas[j].dist_ate_no:
                    folhas.pop(i)
                else:
                    folhas.pop(j)
                return remover_folha_dup(i, folhas)

def no_esta_no_vetor(lista: list, no: int):
    for i in lista:
        if i.id == no:
            return True
    return False


def remover_folha(folhas: list, no_para_remover: no_t):
    for i in folhas:
        if i.id == no_para_remover.id:
            folhas.remove(i)
            return




def search_by_djistrka(n_nos: int, root_pos: int, target_pos: int, matriz_adj: list, matriz_dist: list):
    folhas = []
    caminho = []
    root = root_pos + 1
    target = target_pos + 1
    distancia = 0
    no_raiz = no_t([], 0, root)
    caminho.append(no_raiz)
    while caminho[-1].id != target:
        no_pai = caminho[-1]
        #Se o no ainda nao estiver na fila
        for i in matriz_adj[no_pai.id-1]:
            if not no_esta_no_vetor(caminho, i):
                #distancia ja percorrida + distancia do pai ate o novo no
                folha = no_t(caminho, distancia + matriz_dist[no_pai.id-1][i-1], i)
                folhas.append(folha)

        remover_folha_dup(0, folhas)

        folha_expandir = folhas[0]
        menor_dist = folha_expandir.dist_ate_no
        for i in folhas:
            if i.dist_ate_no < menor_dist:
                menor_dist = i.dist_ate_no
                folha_expandir = i

        caminho = folha_expandir.caminho_nos
        caminho.append(folha_expandir)
        distancia = folha_expandir.dist_ate_no
        remover_folha(folhas, folha_expandir)

    return distancia


def djistrka_alg(n_nos: int, matriz_dist: list, matriz_adj: list):
    for i in range(n_nos):
        for j in range(n_nos):
            if i != j:
                matriz_dist[i][j] = search_by_djistrka(n_nos, i, j, matriz_adj, matriz_dist );


nome_arquivo = input()
matriz_dist, n_nos = ler_arquivo_pajek(nome_arquivo)
matriz_adj = criar_matriz_adjacencias(matriz_dist, n_nos)
djistrka_alg(n_nos, matriz_dist, matriz_adj)
printar_matriz(matriz_dist, n_nos)
