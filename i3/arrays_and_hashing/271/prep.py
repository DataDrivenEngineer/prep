wordIndices = []

def encode(strs):
    encoded = ""
    for str in strs:
        for c in str:
            encoded += c
        wordIndices.append(len(encoded))
    return encoded

def decode(str):
    decoded = []
    start = 0
    for end in wordIndices:
        decoded.append(str[start : end])
        start = end
    return decoded

strs = ["we", "say", ":", "yes"]
encoded = encode(strs)
print(encoded)
# print(wordIndices)
print(decode(encoded))