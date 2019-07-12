#!/usr/bin/env python2
# -*- coding: utf-8 -*-

'''
    Kleyton Leite
    Problema do primo jposephus, deve ser considerado a primeira troca
    Arquivo uri_1032.py
'''
import math


def isprime(n):
    flag = True
    if n == 2:
        return flag
    for i in range(2, int(math.sqrt(n))+1, 1):
        if(n % i == 0):
            flag = False
            break
    return flag


def primo(pos):
    for i in range(2, 32000, 1):
        if(isprime(i)):
            pos = pos - 1
        if (not pos):
            return i


n = 0
n = input("")
pulo = 0
posicao = 0

if n > 0:
    lista = list(range(1, n+1, 1))
    p_primo = 1
    while(len(lista) > 1):
        pulo = primo(p_primo)-1
        while (pulo):
            posicao = (posicao+1) % len(lista)
            pulo = pulo - 1
        del(lista[posicao])
        p_primo = p_primo + 1

    print (lista)
