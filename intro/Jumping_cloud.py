import math
import os
import random
import re
import sys


def jumpingOnClouds(c):
    step = 0
    if len(c) < 4:
        return 1
    i = 0
    while i < len(c):
        if (len(c) - i) <= 3:
            step += 1
            break
        if c[i+2] == 0:
            step += 1
            i += 2
        elif c[i+2] == 1:
            step+= 1
            i +=1
    return step


if __name__ == '__main__':
    n = int(input().strip())

    c = list(map(int, input().rstrip().split()))

    print(jumpingOnClouds(c))

