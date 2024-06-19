def groupAnagrams(strs):
    outFreq = {}
    for str in strs:
        currFreq = {}
        for c in str:
            currFreq[c] = 1 + currFreq.get(c, 0)
        fCurrFreq = frozenset(currFreq.items())
        if fCurrFreq in outFreq:
            outFreq[fCurrFreq].append(str)
        else:
            outFreq[fCurrFreq] = [str]
    return outFreq.values()

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(groupAnagrams(strs))