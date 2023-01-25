import string

def encVigenere(text: str, keyword: str, decryption=False) -> str:
    currentKeyLetter = 0
    finalText = ''
    alphabet = string.ascii_lowercase
    map = dict(zip(alphabet, range(1, len(alphabet)+1)))
    for letter in text:
        if letter.isalpha():
            #print(f'{map[letter.lower()]} + {map[keyword[currentKeyLetter]]} - {map[alphabet[currentKeyLetter]]}')
            # finding the new letter using the vigenere formula
            if decryption:
                newL = (map[letter.lower()] - (map[keyword[currentKeyLetter]] - 1)) % 26
            else:
                newL = (map[letter.lower()] + (map[keyword[currentKeyLetter]] - 1)) % 26
            currentKeyLetter = (currentKeyLetter + 1) % len(keyword)
            if letter.isupper():
                finalText += alphabet[newL-1].upper()
            else:
                finalText +=  alphabet[newL-1]
        else:
            finalText += letter
    return finalText

def decVigenere(text: str, keyword: str) -> str:
    return encVigenere(text, keyword, decryption=True)


request = input().split(' ')
encOrDec = request[0]
keyword = request[1]

text = input()
if encOrDec == 'e':
    text = encVigenere(text, keyword)
else:
    text = decVigenere(text, keyword)

print(text)

