import sys

def swapLetters(letter1, letter2):
    return letter2, letter1

def rc4(key: list, inputText: list, n: int):
    keyS = []
    s = []
    K = []
    for i in range(0, 256):
        s.append(i)
        K.append(key[i%len(key)])
    j = 0
    for i in range(0, 256):
        j = (j + s[i] + K[i]) % 256
        s[i], s[j] = swapLetters(s[i], s[j])
    j = 0
    i = 0
    for _ in range(n + 256):
        i = (i + 1) % 256
        j = (j + s[i]) % 256
        s[i], s[j] = swapLetters(s[i], s[j])
        t = (s[i] + s[j]) % 256
        keyS.append(s[t])
    keyS = keyS[256:]
    out = []
    # performing de XOR bitwise
    for byte, k in zip(inputText, keyS):
        aux = byte ^ k
        out.append(aux.to_bytes(1, 'big'))
    return b''.join(out)

def readInput():
    input = sys.stdin.buffer.read()
    aux = input.split(b'\xff',1)
    key = aux[0]
    text = aux[1]
    return key, text

key, text = readInput()
out = rc4(list(key), list(text), len(text))
sys.stdout.buffer.write(out)