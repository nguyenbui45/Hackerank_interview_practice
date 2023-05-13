
def twoSum(nums, target):
    index_0 = 0
    index_1 = len(nums) - 1
    while(1):
        if nums[index_0] + nums[index_1] == target:
            if index_0 > index_1:
                return [index_1,index_0]
            else:
                return [index_0,index_1]
        elif nums[index_0] + nums[index_1] > target:
            index_1 -=1
        elif nums[index_0] + nums[index_1] < target:
            index_0 +=1

        



num = int(input())
lis = list(map(int,input().strip().split()))[:num]

target = int(input())
print(twoSum(lis,target))
