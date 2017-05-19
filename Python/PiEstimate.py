#!/usr/bin/python

import numpy as np

def getRandomPoint():
	return np.random.uniform(0, 1), np.random.uniform(0, 1)

def isInside(x, y):
	return x**2 + y**2 < 1.0

def estimatePi(n=100):
	numInside = 0
	
	for i in range(n + 1):
		x, y = getRandomPoint()
		if isInside(x, y):
			numInside += 1

	# The estimate of pi is the number of samples that land inside the
	# circle divided by the total number of samples times 4. The logic
	# is as follows:
	#
	# Area for square (of length x) is: x^2
	# Area for circle (diameter x) is: (pi / 4) * x^2
	#
	# Therefore, the ratio between the areas is:
	# ratio = ((pi / 4) * x^2) / (x^2) which becomes (x^2 cancels out)
	# ratio = pi / 4
	#
	# Therefore the estimate of pi becomes (solving for pi):
	# pi = ratio * r
	#
	# where the ratio is the number of hits inside the circle divided
	# by the total number of hits

	return (float(numInside) / float(n)) * 4.0


if __name__ == "__main__":
	piEst = estimatePi(100000)
	print "pi (estimated) =", piEst
