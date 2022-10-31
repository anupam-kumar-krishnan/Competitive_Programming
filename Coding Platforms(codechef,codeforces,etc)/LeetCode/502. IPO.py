from heapq import heappop,heappush
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        proj = list(zip(Capital,Profits))
        proj.sort(key = lambda a:a[0], reverse = True)
        profitHeap = []  # Max Heap
        for i in range(k):
            while proj and W>=proj[-1][0]:
                heappush(profitHeap,-proj.pop()[1]) # - to make it a max heap
            if not profitHeap:
                break
            W+=-heappop(profitHeap)
            
        return W
