n = int(input())
c = list(map(int, input().split()))
c.sort()
e = 0
for a in c:
    if e + 1 < a: break
    e += a
print(e+1)
    
    