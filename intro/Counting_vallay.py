import math 
import os
import random
import re
import sys

def coutingValley(step,path):
    cost = 0
    D_start_count = 0
    valley = 0
    for i in range(step):
        if cost == 0 and path[i] == 'D':
            D_start_count +=1

        if cost == -1 and path[i] == 'U':
            if D_start_count == 1:
                valley += 1
                D_start_count = 0

        if path[i] == 'U':
            cost += 1

        elif path[i] == 'D':
            cost += -1
    
    return valley
        
        
            

if __name__ == '__main__' : 
    steps = int(input().strip())
    path = input()
    print(coutingValley(steps, path))
