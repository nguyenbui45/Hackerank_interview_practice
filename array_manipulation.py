import math
import os
import random
import re
import sys


def arrayManipulation(n,queries):
    max = 0
    x = 0
    array = list(range(n+1))
    for i in range(len(array)):
        array[i] = 0

    for i in range(len(queries)):
        a = queries[i][0]
        b = queries[i][1]
        k = queries[i][2]

        array[a] +=k
        if b+1 <= n:
            array[b+1] -=k

    for i in range(1,len(array)):
        x = array[i] + x
        if max < x:
            max = x

    return max

# ELIMINATE , by using dictionary
# def arrayManipulation(n,queries):
#     max = 0
#     # array = list(range(n))
#     # for i in range(len(array)):
#     #     array[i] = 0
#     array = {v: 0  for v,x in enumerate(range(n))} # x trash value

#     for i in range(len(queries)):
#         a = queries[i][0]
#         b = queries[i][1]
#         k = queries[i][2]

#         for j in range(a,b+1,1):
#             array[j-1] += k

#             if max < array[j-1]:
#                 max = array[j-1]
#     return max









if __name__ == "__main__":

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)
    print(result)