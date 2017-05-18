#!/usr/bin/python

def factorial_recursive(n):
	if n == 0: return 1
	return n * factorial_recursive(n - 1)

def combination(n, k):
	return factorial_recursive(n) / (factorial_recursive(k) * factorial_recursive(n - k))

def pascals_triangle(numRows):
	rows = []
	for r in range(numRows):
		row = []
		for elm in range(r + 1):
			row.append(combination(r, elm))
		
		rows.append(row)

	return rows

for row in pascals_triangle(8):
	print row