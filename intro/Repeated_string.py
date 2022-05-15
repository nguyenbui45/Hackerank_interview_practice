import math
import os
import random
import re
import sys


def repeatedString(s, n):
    length_s = len(s)
    count = 0
    pos = []
    for index,j in enumerate(s):
        if j == 'a':
            pos.append(index+1)
    m = len(pos)

    A = int(n / length_s)
    count = A * m

    for k in range(n% len(s)):
        if s[k] == 'a':
            count +=1
    
    return count

if __name__ == '__main__':
    s = input()

    n = int(input().strip())

    print(repeatedString(s, n))
