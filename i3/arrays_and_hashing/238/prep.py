# def productOfArrayExceptSelf(nums):
#     after = [0] * len(nums)
#     for index in range(len(nums) - 2, -1, -1):
#         if index == len(nums) - 2:
#             after[index] = nums[index + 1]
#         else:
#             after[index] = nums[index + 1] * after[index + 1]

#     print(after)
    
#     before = [0] * len(nums)
#     for index in range(1, len(nums), 1):
#         if index == 1:
#             before[index] = nums[index - 1]
#         else:
#             before[index] = nums[index - 1] * before[index - 1]

#     print(before)

#     after[-1] = before[-1]
#     for index in range(1, len(nums) - 1, 1):
#         after[index] *= before[index]
    
#     return after

def productOfArrayExceptSelf(nums):
    after = [0] * len(nums)
    for index in range(len(nums) - 2, -1, -1):
        if index == len(nums) - 2:
            after[index] = nums[index + 1]
        else:
            after[index] = nums[index + 1] * after[index + 1]

    print(after)
    
    for index in range(2, len(nums), 1):
        nums[index - 1] *= nums[index - 2]
    nums[-1] = nums[-2]

    print(nums)

    after[-1] = nums[-1]
    for index in range(1, len(nums) - 1, 1):
        after[index] *= nums[index - 1]
    
    return after

nums = [1,2,3,4]
# nums = [-1,1,0,-3,3]
print(productOfArrayExceptSelf(nums))