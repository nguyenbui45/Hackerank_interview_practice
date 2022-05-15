#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'twoStrings' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s1
#  2. STRING s2
#

def twoStrings(s1, s2):
    s1_dict = {s1[v]:1 for v in range(len(s1)) }
    s2_dict = {s2[v]:0 for v in range(len(s2)) }
    
    for i in range(len(s2_dict)):
        print(list(s2_dict)[i])
        if list(s2_dict)[i] in s1_dict:
            return "YES"
    return "NO"

    

if __name__ == '__main__':

    q = int(input().strip())

    for q_itr in range(q):
        s1 = input()

        s2 = input()

        result = twoStrings(s1, s2)

        print(result)

