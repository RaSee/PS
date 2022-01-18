import sys
sys.setrecursionlimit(500000)

def solution(k, room_number):
    answer = []
    now = dict()
    
    for num in room_number:
        if num not in now:
            now[num] = num + 1
        else:
            stack = []
            while num in now:
                num = now[num]
                stack.append(num)
            now[num] = num+1
            for n in stack:
                now[n] = num+1
        answer.append(num)
        
    return answer

#Union - Find Version
'''
def solution(k, room_number):
    answer = []
    now = dict()
    
    def find(a):
        if a not in now : return a
        else:
            now[a] = find(now[a])
            return now[a]
    
    def union(a, b):
        a = find(a)
        b = find(b)
        now[a] = b


    for number in room_number:
        n = find(number)
        answer.append(n)
        union(number, n+1)
        
    
    return answer
'''