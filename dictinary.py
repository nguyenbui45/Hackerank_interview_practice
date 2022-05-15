arr = [4,3,1,2]
nguyen = dict(enumerate(arr,1))
bui = {v:k for k,v in nguyen.items()}

# print(nguyen)
count = 0
for i in nguyen:
    x = nguyen[i] # 1 2 3 4 5 real value of dict ~ arr[i]
    if x != i:
        y = bui[i] # y = 1  2 3  4  5 index
        nguyen[y] = x # arr = real value 
        bui[x] = y # dict[real] = index
        count +=1

print(nguyen,bui)
print(count)

