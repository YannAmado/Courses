import random

def acharGrau(matriz, N, vertice):
    grau = 0
    for i in range(N):
        if(matriz[i][vertice-1] == 1):   #-1 porque os numeros dos vertices sao n + 1 numero das posicoes do vetor
            grau += 1
    return grau

def acharVertAdj(matriz, N, vertice):
    vertAdj = []
    for i in range(N):
        if(matriz[i][vertice-1] == 1):
            vertAdj.append(i+1) #+1 pois ocorreu o inverso, passou de posicao de vetor para numero do vertice
    return vertAdj

def acharArestaComum(matriz, vi, vj):
    if(matriz[vi-1][vj-1] > 0): #-1 Pra passar de numero para pos em vetor
        print(f"existe {matriz[vi-1][vj-1]} aresta entre os vertices {vi} e {vj}")
    else:
        print(f"Nao existem arestas entre os vertices {vi} e {vj}")


N = int(input("Digite N: "))
p = float(input("Digite p: "))
M = [[0 for j in range(N)] for i in range(N)]
for i in range(N):
    for j in range(N-i):    #Como a matriz eh simetrica, so precisa rodar um lado acima ou abaixo da diagonal principal e depois copia o valor pra deabixo
        j += i
        if(i == j):
            M[i][j] = 0
        else:
            if(random.random() > p):
                M[i][j] = 1
            else:
                M[i][j] = 0
            M[j][i] = M[i][j]
for i in M:
    print(i)
vertice = int(input("Digite o vertice para buscar os adjacentes: "))
vertAdj = acharVertAdj(M, N, vertice)
grau = acharGrau(M, N, vertice)
print(f"grau: {grau}")
print(f"vertices adjacentes: {vertAdj}")
i, j = input("Digite os vertices i e j para suas arestas em comum: ").split()
i = int(i)
j = int(j)
acharArestaComum(M, i, j)