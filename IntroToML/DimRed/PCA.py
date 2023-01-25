import numpy as np

def PCA(X, d: int):
    Z = X - np.mean(X)
    line = drawRandomLine
    # finding PC
    for i in range(d):
        while not maximized:
            projectedPoints = projectPoints(points)
            SS = sum(projectedPoints. ^ 2)
            line = updateLine()
        # finding unit vector
        line = line / line.slope()


data = load('COIL20.mat')

X = input()
d = input()
plot(PCA(X, d))


