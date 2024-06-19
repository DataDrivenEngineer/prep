def isValidAnagram(s, t):
    freq = {}
    for c in s:
        freq[c] = 1 + freq.get(c, 0)
    for c in t:
        freq[c] = freq.get(c, 0) - 1
    for v in freq.values():
        if v != 0:
            return False
    return True

s = 'rat'
t = 'car'
print(isValidAnagram(s, t))