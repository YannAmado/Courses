//
// Created by Yann on 23/09/2022.
//

import string


int encShift(plainText, shift) {
    cipherTextFinal = []
    for(auto i; i < vector.size(); i++){
        cipherText = []
        for()
    }
    for
    letter
    in
    line:
    if letter.isalpha():
    // shifting in ascII
    l = ord(letter) + (shift % 26)
    // if it is a special char or an upper case turned into lower case
    if not chr(l).isalpha() or letter.isupper() != chr(l).isupper():
                        l -= 26
                    cipherText.append(chr(l))
                else:
                    cipherText.append(letter)
            cipherTextStr = ''.join(cipherText)
            cipherTextFinal.append(cipherTextStr)
        return cipherTextFinal
}


    def decShift(text, shift):
        return encShift(text, -shift)


    def encMap(text, mapStr, dec=False):
# creating dictionary with both lower and upper case
        alphabetLow = string.ascii_lowercase
        alphabetUp = string.ascii_uppercase
        if not dec:
            dicLow = dict(zip(alphabetLow, mapStr))
            dicUp = dict(zip(alphabetUp, mapStr.upper()))
        else:
            dicLow = dict(zip(mapStr, alphabetLow))
            dicUp = dict(zip(mapStr.upper(), alphabetUp))
        dic = dicLow.copy()
        dic.update(dicUp)

        cipherTextFinal = []

        for line in text:
            finalText = []
            for letter in line:
                if letter in dic:
                    finalText.append(dic[letter])
                else:
                    finalText.append(letter)
            finalTextStr = ''.join(finalText)
            cipherTextFinal.append(finalTextStr)

        return cipherTextFinal


    def decMap(text, mapStr):
        return encMap(text, mapStr, dec=True)


# Reading the encryption information line.
    requests = input().split(' ')

# Reading the input until an empty line is encountered
    text = []
    while True:
        try:
            line = input()
            text.append(line)
        except EOFError:
            break


    for i in range(0, len(requests), 2):
        encOrDec = requests[i]
        mapOrShift = requests[i + 1]
        if encOrDec == 'e' and mapOrShift.isalpha():
            text = encMap(text, mapOrShift)
        elif encOrDec == 'd' and mapOrShift.isalpha():
            text = decMap(text, mapOrShift)
        elif encOrDec == 'e':
# resultingShift += int(mapOrShift)
            text = encShift(text, int(mapOrShift))
        else:
# resultingShift -= int(mapOrShift)
            text = decShift(text, int(mapOrShift))

# text = encShift(text, int(resultingShift))

    for line in text:
        print(line)