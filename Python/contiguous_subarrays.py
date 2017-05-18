#!/usr/bin/python	

a = [1, 2, 3]

# Contiguous sub-arrays given [1, 2, 3]
# [1], [1, 2], [1, 2, 3]
# [2], [2, 3]
# [3]
def subarray_contiguous(a, subs):
	if a:
		subs.append(a)
		subarray_contiguous(a[:-1], subs)

# Find the powerset for a given array/list using bits
def powerset(a):
	_powerset = []
	for i in range((1 << len(a))):
		ss = []
		for j in range(len(a)):
			if ((1 << j) & i) > 0:
				ss.append(a[j])
				
		if ss: _powerset.append(ss)
		
	return _powerset

# Recursively, P(abc) = {abc} + P(ab) + P(ac), and so on
#
# Pseudo-algorithm:
# -------------------
# Is the set passed empty? Done
# If not, take an element out 
#   - Recursively call method on the remainder of the set
#   - Return the set composed of the Union of 
#       (1) the powerset of the set without the element (from the recursive call) 
#       (2) this same set (i.e., (1)) but with each element therein unioned with the element initially taken out

def powerset_recursive(a, ps):
	if not a: return
	
	powerset_recursive(a[1:], ps)

s1 = []
for i in range(len(a)):
	subarray_contiguous(a[i:], s1)

print s1

s2 = powerset(a)
#s2 = []
#powerset_recursive(a, s2)
print s2