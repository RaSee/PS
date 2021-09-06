a = int(input())
answer = 1

x = 10**100
y = 0
while x > y:
    b = (x+y) // 2
    if b*b + b >= 2*a:
        x = b - 1
    elif b*b + 3*b + 2 < 2*a:
        y = b + 1
    else:
        x = b
        break

x += 1
answer = 2*a - x
print(answer)