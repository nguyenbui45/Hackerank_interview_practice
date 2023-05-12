import math
import os
import random
import re
import sys
from collections import defaultdict


'''
insert: put into hashtable, if exists, plus it to it frequency
        if not exists, dict['x'] = 1
dictdelete: check key in hashtable, if exist minus frequency by 1  
            if not exist, continue, dict['y'] -=1
output: declare count;  check if dict[i] = z, if yes, count+=1
count
'''
def freqQuery(queries):
    dict_data = defaultdict(set) # dict with key is frequency, value is number
    look_up = dict() # dict with key is insert number, value is frequency of insert number
                     # we use dict_data to check if exist a similar frequency of a value. Thus no need to use 
                     # iteration to check the frequency for all dict ; O(n) -> O(1)
    output = []
    for i in queries:
        option,value = i
        initial = look_up.get(value,0)

        if option == 1:
            look_up[value] = initial + 1 # if initial is 1, lookup dict has already got value, so plus its appearence
            dict_data[initial].discard(value) # the frequency of value need to plus 1 and interchangable by another key-value set
            dict_data[initial + 1].add(value)
        elif option == 2:
            look_up[value] = max(0,initial-1) # if initial is 0, then there nothing to discard
            dict_data[initial].discard(value) # the value of frequency is decrease by 1, thus need to reupdate the dict_data
            dict_data[initial-1].add(value)
        else:
            output.append(1 if dict_data[value] else 0) # check if frequency z is exist, if yes, return 1 and vice versa.
    return output

if __name__ == '__main__':

    q = int(input().strip())

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    ans = freqQuery(queries)
    print(ans)

