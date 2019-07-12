#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import string

exc = ""
pal = ""

exc = raw_input('')
pal = raw_input('')

while pal[0] != '0' and exc[0] != '0':
    zero = True
    pal = string.replace(pal, exc, '')
    posicao = 0
    if pal == '' or int(pal) == 0:
        print 0
    else:
        print pal
    exc = raw_input('')
    pal = raw_input('')