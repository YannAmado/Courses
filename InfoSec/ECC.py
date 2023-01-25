def groupAddVertical():
    return (float('inf'), float('inf'))


def findS(sTop, sBot, p):
    sBot = pow(sBot, -1, p)
    s = (sTop * sBot) % p
    return s

def findGroupCoordinates(s, x1, x2, y1, p):
    x3 = (s**2 - x1 - x2) % p
    y3 = (s * (x1 - x3) - y1) % p
    return x3, y3

def groupAddition(point1, point2, a, p):
    x1, y1 = point1[0], point1[1]
    x2, y2 = point2[0], point2[1]
    if point1[0] == float('inf'):
        return point2
    elif point2[0] == float('inf'):
        return point1
    if point1 == point2:
        return groupPointDoubling(point1, a, p)
    if (x1 - x2) == 0:
        return groupAddVertical()
    sTop = (y2 - y1) % p
    sBot = x2 - x1
    s = findS(sTop, sBot, p)
    x3, y3 = findGroupCoordinates(s, x1, x2, y1, p)
    return (x3, y3)

def groupPointDoubling(point, a, p):
    x_g = point[0]
    y_g = point[1]
    if y_g == 0:
        return groupAddVertical()
    if point[0] == float('inf'):
        return point
    sTop = (3 * (x_g**2) + a) % p
    sBot = 2 * y_g
    s = findS(sTop, sBot, p)
    x_2g, y_2g = findGroupCoordinates(s, x_g, x_g, y_g, p)
    return (x_2g, y_2g)


def findCyclicGroup(initialPoint, finalPointIndex, a, p):
    groups = [initialPoint] * (finalPointIndex + 1)
    if finalPointIndex > 2:
        groups[2] = groupPointDoubling(groups[1], a, p)
    for i in range(3, finalPointIndex+1):
        groups[i] = groupAddition(groups[i-1], groups[1], a, p)
    return groups

def ECC(initialPoint, a, b, p, m, n):
    groups = findCyclicGroup(initialPoint, n, a, p)
    P = groups[n]
    groups = findCyclicGroup(P, m, a ,p)
    P = groups[m]
    return P

def readInput():
    x, y = input().split(',')
    x = ''.join(filter(str.isdigit, x))
    y = ''.join(filter(str.isdigit, y))
    a, b, p = input().split()
    m, n = input().split()
    initialPoint  = (int(x), int(y))
    return initialPoint, int(a), int(b), int(p), int(m), int(n)


if __name__ == '__main__':
    initialPoint, a, b, p, m, n = readInput()
    print(ECC(initialPoint, a, b, p, m, n))
