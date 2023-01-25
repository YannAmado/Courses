import random
import numpy as np


def readCSV(filename: str):
    data = []
    with open(filename, 'r') as f:
        for line in f:
            l = line.split(',')
            data.append(list(map(float, l)))
    return data

def findWinner(prototypes, dataPoint):
    minDist = float('inf')
    winner = -1
    for p in prototypes:
        dist = np.linalg.norm(dataPoint-p)
        if dist < minDist:
            winner = p
    return winner

def updateWinner(prototypes, dataPoint, eta):
    p = findWinner(prototypes, dataPoint)
    return p + eta*(dataPoint - p)


def plotData(data, prototypes):
    return error

def winnerVQ(K, eta, t_max, data):
    prototypes = random.sample(data, K)
    for epoch in range(t_max):
        order = np.random.permutation(len(data))
        for i in order:
            prototypes = updateWinner(prototypes, data[i], eta)
        plotData(data, prototypes)
        print(f'quantization error HVQ: {findError()}')
    plotLearningCurve()
    return

if __name__ == '__main__':
    data = readCSV('simplevqdata.csv')
