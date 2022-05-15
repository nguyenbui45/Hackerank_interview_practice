#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter


def sherlockAndAnagrams(s):
    arr = []
    for i in range(1,len(s)):
        for j in range(0,len(s)-i+1):
            arr.append("".join(sorted(s[j:j+i])))
      
    x = Counter(arr)
    
    count = {k:v for k,v in x.items() if v > 1}
    print(count)
    result = 0
    for i in count.values():
        result +=sum(range(i))
# 
    return result



if __name__ == '__main__':

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = sherlockAndAnagrams(s)
        print(result)
