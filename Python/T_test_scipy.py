#!/usr/bin/python

import scipy.stats as stats
import numpy as np


if __name__ == "__main__":
	a = np.float32([15.2, 15.3, 16.0, 15.8, 15.6, 14.9, 15.0, 15.4, 15.6, 15.7, 15.5, 15.2, 15.5, 15.1, 15.3, 15.0])

	b = np.float32([15.9, 15.9, 15.2, 16.6, 15.2, 15.8, 15.8, 16.2, 15.6, 15.6, 15.8, 15.5, 15.5, 15.5, 14.9, 15.9])

	assert len(a) == len(b)

	# Mean, variance, and std dev (variance^2) of both sets
	print 'a: mean = {} | stdev = {} | var = {}'.format(np.mean(a), np.var(a), np.std(a))
	print 'b: mean = {} | stdev = {} | var = {}'.format(np.mean(b), np.var(b), np.std(b))

	t_test = stats.ttest_ind(a, b)
	p = t_test.pvalue

	if p < 0.05:
		print "Don't reject: Set difference is statistically significant"
	else:
		print "Reject: Set difference is not statistically significant"
	
