import os

# def partion(array,low,high):
#     pivot = array[high]
    
#     i = low - 1

#     for j in range(low,high):
#         if array[j] <= pivot:
#             i +=1
#             (array[i],array[j]) = (array[j],array[i])
#             if array[j] != pivot:
#                 global count_swap
#                 count_swap +=1

#         (array[i+1],array[high]) = (array[high],array[i+1])
#         if array[i+1] != array[high]:
#             count_swap +=1

#     return i+1


# def quicksort(array,low,high):
#     if low < high:
#         pi = partion(array,low,high)

#         quicksort(array,low,pi-1)
#         quicksort(array,pi+1,high)

# def return_index(a,array):
#     for index,i in enumerate(array):
#         if a == i:
#             return index


# def return_index(a,array):
#     temp_index = 0
#     while(array[temp_index] != a):
#                 temp_index +=1
            
#     print(temp_index)
#     return temp_index

def minimumSwaps(arr):
    count_swap = 0
    a = dict(enumerate(arr,1)) # store value of each index
    b = {v:k for k,v in a.items()} #store index of each value
    
    for i in(a):
        x = a[i]
        if i!= x:
            y = b[i] # index of correct value in array
            a[y] = x # change value of correct index with the value that took its position
            b[x] = y # update new index of the wrong value
            count_swap +=1
    print(a,b)
    return count_swap

array = [4, 3, 1, 2]
# quicksort(array,0,len(array) - 1)

print(minimumSwaps(array))
