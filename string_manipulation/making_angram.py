

import enum


a = str()
a_list = []
b = str()
b_list = []

a = input(a)
a_list.extend(a)
print(a_list)

b = input(b)
b_list.extend(b)
print(b_list)

a_dict = {a_list[0]:1}
for i in range(1,len(a_list)):
    if a_list[i] in a_dict:
        a_dict[a_list[i]]+=1
    else:
        a_dict[a_list[i]] = 1

print(a_dict)


b_dict = {b_list[0]:1}
for i in range(1,len(b_list)):
    if b_list[i] in b_dict:
        b_dict[b_list[i]]+=1

    else:
        b_dict[b_list[i]] = 1

print(b_dict)

eliminate = 0
for i in range(0,len(a_list)):
    if a_list[i] in b_dict:
        b_dict[a_list[i]]-=1
        if b_dict[a_list[i]] < 0:
            eliminate +=1
    else:
        eliminate +=1

for i in range(0,len(b_list)):
    if b_list[i] in a_dict:
        a_dict[b_list[i]]-=1
        if a_dict[b_list[i]] < 0:
            eliminate +=1
    else:
        eliminate +=1

print(eliminate)

