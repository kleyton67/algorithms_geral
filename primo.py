#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import math

n = input("")
flag = True

for i in range(2, int(math.sqrt(n))+1, 1):
    if(n % i == 0):
        flag = False
        break

print(flag)