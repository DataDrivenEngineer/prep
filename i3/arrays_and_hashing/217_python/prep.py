def containsDuplicates(arr):
    seen = set()
    for number in arr:
        if number in seen:
            return True
        else:
            seen.add(number)
    return False

arr = [1,2,3,1]
print(containsDuplicates(arr))