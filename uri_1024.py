#!/usr/bin/env python2
# -*- coding: utf-8 -*-

loop = input()
#print("Palavra: " + palavra + ", tamanho da palavra : " + str(len(palavra)))

while loop:
    resultado = ''
    palavra = ''
    palavra = raw_input()
    #primeira etapa
    letra = ''
    for n in range(len(palavra)):
        if ((ord(palavra[n]) > 64 and 
        ord(palavra[n]) < 91) ) or (
            (ord(palavra[n]) > 96 and 
        ord(palavra[n]) < 123)):
            letra = ord(palavra[n])+3
        else:
            letra = ord(palavra[n])
        resultado = resultado+chr(letra)
        #print chr(letra)
    
    #segunda etapa
    invertido = ''
    invertido = resultado[::-1]

    #terceira etapa somente metade
    final = ''
    letra = ''
    final = invertido[0:int(len(invertido)/2):1]
    #print "range = " + str(range(int(len(invertido)/2), len(invertido)))
    for n in range(int(len(invertido)/2), len(invertido)):
        letra = ord(invertido[n])
        if letra != 32:#caractere  espaco
            letra = letra-1
        final = final+chr(letra)
    print(final)
    loop -=1