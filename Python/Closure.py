#!/usr/bin/python

# Closure Example

def startAt(x):
	def incrementBy(y):
		return x + y
	
	return incrementBy

c1 = startAt(1)
c2 = startAt(5)

print c1(4)
print c2(10)