
def textIntersect(text1, text2):
	words = {}
	for w in text1:
		if w not in words:
			words[w] = 1
		else:
			words[w] = words[w] + 1;
			
#	intersection = set()
	intersection = []
	for w in text2:
		if w in words and words[w] > 0:
			intersection.append(w)
#			intersection.add(w)
			
	print intersection

t1 = "hello the dog is blue and the sun is red"
t2 = "the whisker blue laid bare on the ground"
textIntersect(t1.split(" "), t2.split(" "))