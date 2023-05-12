#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isValid(s):
    
    counter = Counter(s)
    prob = Counter(counter.values())
    max_pr = prob.most_common()[0]
    #max(prob.values())   min(prob.values())
    min_pr = prob.most_common()[-1]
    if len(prob) == 1:
        return "YES"
    if len(prob)>2:
        return "NO"
    if 1 in prob.values() and (prob[min(prob.keys())]==1 or (max(prob.keys()) - min(prob.keys())==1)):
        return "YES"
    else:
        return "NO"
        

if __name__ == '__main__':

    s = input()

    result = isValid(s)
    print(result)
