import math
import os
import random
import re
import sys



def checkMagazine(magazine, note):
    magazine_dict = {magazine[0]:1}
    for i in range(1,len(magazine)):
        if magazine[i] in magazine_dict:
            magazine_dict[magazine[i]] += 1
        else:
            magazine_dict[magazine[i]] = 1

    #print(magazine_dict)
    flag = True
    for i in range(len(note)):
        if note[i] not in magazine_dict:
            flag = False
            break
        else:
            if magazine_dict[note[i]] <= 0:
                flag = False
                break
            else:
                magazine_dict[note[i]] -=1
        
    #print(magazine_dict)
    return print("Yes") if  flag == True  else print("No")


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    m = int(first_multiple_input[0])

    n = int(first_multiple_input[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()

    checkMagazine(magazine, note)
