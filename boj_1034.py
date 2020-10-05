from collections import Counter

t = input().split(' ')
n = int(t[0])
m = int(t[1])
light = []
for i in range(n):
	light.append(input())
rows = dict(Counter(light))
k = int(input())
answer = 0
for key in rows:
	num_zero = key.count('0')
	if (num_zero > k):
		continue
	if ((k-num_zero) % 2  == 0):
		answer = rows[key] if rows[key] > answer else answer
	
print(answer)