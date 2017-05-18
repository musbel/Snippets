#!/usr/bin/python

def getBit(n, i):
	return int((n & (1 << i)) > 0)
	
def setBit(n, i):
	return (n | (1 << i))

def clearBit(n, i):
	# 1) Bit shift i times: e.g. i = 2 -> 00100
	# 2) Inverse 00100 -> 11011
	# 3) Now, & with 0 will always be 0 thus it'll clear any value
	return (n & (~(1 << i)))

def toBinary(n, digits=8):
	s = ''.join(str(getBit(n, i)) for i in range(digits))[::-1]
	return s

def lonelyInteger(numbers):
	# Description:
	# If a number is xor with itself, it becomes 0. Therefore each pair
	# of numbers will cancel each other out. The "lonely" number will
	# remain in its original bit form.
	# E.g. 0010 xor 0010 -> 0000
	
	# 2 -> 0010
	# 4 -> 0100
	# 2 -> 0010
	
	# 0010   0110
	# 0100   0010 (xor)
	# ----   ----
	# 0110   0100 -> 4 is the lonely number

	result = 0
	for number in numbers:
		result ^= number
	
	return result

def updateBits(n, m, i, j):
	max = ~0	
	left = max - ((1 << j) - 1)
	right = ((1 << i) - 1)
	
	mask = left | right
	
	merged = (n & mask) | (m << i)
	return merged

def getMax(a, b): # Without using if-else or any comparison operator
	print("> getMax(%d, %d)" % (a, b))
	c = a - b
	print " : c =", c
	k = (c >> 31) & 0b1
	print " : k =", toBinary((c >> 31), 32)
	maxVal = a - k * c
	print " : m =", maxVal
	return maxVal


if __name__ == "__main__":
	print("41 -> {}".format(toBinary(41)))
	b1, b2 = 0b0101001, 0b0001000
	print("{} & {} -> {}".format(toBinary(b1), toBinary(b2), toBinary(b1 & b2)))
	
	assert(setBit(2, 0) == 3)   # 0010 -> Set the first bit to 1 -> 0011 -> 3
	assert(clearBit(3, 0) == 2) # 0011 -> Clear the first bit    -> 0010 -> 2

	b_original = 0b10000000000
	b_insert = 0b10101
	print("updateBits: {} -> {} -> {}".format(toBinary(b_insert), toBinary(b_original, 12), toBinary(updateBits(b_original, b_insert, 2, 6), 12)))
	
	integerList = [2, 4, 2, 3, 5, 3, 7, 5, 7]
	print("Lonely Integer: {} -> {}".format(integerList, lonelyInteger(integerList)))
	
	getMax(3, 10)
	
	print toBinary(5, 8)
	print toBinary(-5, 8)
