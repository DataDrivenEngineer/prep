def twoSum(nums, target):
    numToIdx = {num:idx for idx,num in enumerate(nums)}
    for idx, num in enumerate(nums):
        if (target - num) in numToIdx and idx != numToIdx[target - num]:
            return [idx, numToIdx[target-num]]
    return []

nums = [3,3]
target = 6
print(twoSum(nums, target))