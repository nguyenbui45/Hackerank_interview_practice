

# def hourglassSum(arr): python way
#     arr = np.array(arr)
#     conv_filter = [[1,1,1],
#               [0,1,0],
#               [1,1,1]]
#     hour_glass_sum = []
#     for i in range(4):
#         for j in range(4):
#             unit_arr = arr[i:i+3,j:j+3]
#             conv_result = 0
#             for k in range(3):
#                 for h in range(3):
#                     conv_result += conv_filter[k][h]*unit_arr[k][h]
#             hour_glass_sum.append(conv_result)
    
#     print(hour_glass_sum)
#     return np.max(hour_glass_sum)


def hourglassSum(arr):
    conv_filter = [[1,1,1],
              [0,1,0],
              [1,1,1]]
    hour_glass_sum = []
    conv_result = 0
    i = 0
    j = 0
    k = 0
    h = 0
    while i <= 3:
        while j <= 3:
            while k < 3:
                while h < 3:
                    conv_result += arr[i+k][j+h]* conv_filter[k][h]
                    h+=1
                k+=1
                h = 0
            k=0
            hour_glass_sum.append(conv_result)
            conv_result = 0
            j +=1
        j = 0
        i+=1
    return max(hour_glass_sum)