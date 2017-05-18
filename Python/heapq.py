#!/usr/bin/python

from heapq import heappush, heappop

data = [10, 14, 2, 5, 20, 3]
heap = []
for d in data: heappush(heap, d)

print data
print heap

heappop(heap)
print heap
