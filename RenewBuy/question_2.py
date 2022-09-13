"""
Question 2:

Define a class with a generator which can iterate the numbers, which are divisible by 7, between a given range 0 and n.
"""
	
class generator():
	def __init__(self, n):
		self.n = n
		
	def divBySeven(self):
		for i in range(0, self.n+1):
			if i % 7 == 0:
				yield i

n = int(input())
for num in generator(n).divBySeven():
	print(num)