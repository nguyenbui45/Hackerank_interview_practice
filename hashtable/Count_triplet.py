#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

# Complete the countTriplets function below.
def countTriplets(arr, r):
    dict_arr = Counter(arr)
    count_triplet = 0
    dict_value = Counter()
    
    for i in arr:
        num_1 = i // r # resemble as 1st of i
        num_3 = i * r # resemble as 3nd of i
        dict_arr[i] -=1 # confirm to slide over i value in array

        if dict_arr[num_3] and dict_value[num_1] and not i%r:  # check if exist left and right of number i are exist to form a triplet.
            count_triplet += dict_arr[num_3] * dict_value[num_1]

        dict_value[i] += 1
    return count_triplet
if __name__ == '__main__':

    nr = input().rstrip().split()

    n = int(nr[0])

    r = int(nr[1])

    arr = list(map(int, input().rstrip().split()))

    ans = countTriplets(arr, r)
    print(ans)