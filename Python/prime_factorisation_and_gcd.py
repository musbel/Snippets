#!/usr/bin/python

def isPrime(n):
	# 0 and 1 are not primes
	if n < 2: return False

	# 2 is the only even prime number
	if n == 2: return True    

	# All other even numbers are not primes
	if not n & 1: return False

	# Range starts with 3 and only needs to go up 
	# the square root of n for all odd numbers
	for x in range(3, int(n**0.5) + 1, 2):
		if n % x == 0:
			return False

	return True

def primeFactors(n):
	'''
	Bottom-up Prime Factorisation
	'''
	factors = []
	if n < 2: return factors
	divisors = [d for d in range(2, int(n**0.5) + 1) if isPrime(d)]
	for d in divisors:
		while n % d == 0:
			factors.append(d)
			n /= d
	
	return factors

def gcd(a, b):
	'''
	Greatest Common Divisor using Euclid's algorithm
	(uses division algorithm/modulus)
	'''
	if b == 0: return a
	return gcd(b, a % b)

def gcd_factorisation(a, b):
	'''
	Greatest Common Divisor by using prime factorisation 
	and then find multiple of shared factors
	'''
	factors_a = primeFactors(a)
	factors_b = primeFactors(b)

	import numpy as np
	return np.prod(np.intersect1d(factors_a, factors_b))


if __name__ == "__main__":
	assert(isPrime(5))
	assert(not isPrime(9))
	assert(isPrime(41))
	assert(isPrime(5987))

	assert(primeFactors(48) == [2, 2, 2, 2, 3])

	assert(gcd(48, 18) == 6)
	assert(gcd_factorisation(48, 18) == 6)
	
	
	