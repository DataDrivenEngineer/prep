import heapq as hq

def topKFrequent(nums, k):
    numToFreq = {}
    for num in nums:
        numToFreq[num] = 1 + numToFreq.get(num, 0)
    heap = []
    for n,f in numToFreq.items():
        hq.heappush(heap, [-f,n])
    topKPairs = [hq.heappop(heap) for _ in range (k)]
    return [pair[1] for pair in topKPairs]

nums = [1]
k = 1
print(topKFrequent(nums, k))