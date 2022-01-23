from collections import deque

def get_bit(bit, n): return (bit >> n) & 1
def solution(info, edges):
    answer = 0
    n = len(info)
    graph = dict()
    visited = [False] * (1<<(n+1))
    for i in range(n):  graph[i] = []
    for e in edges: graph[e[0]].append(e[1])
    
    c = deque()
    c.append(1)
    visited[1] = True
    
    while len(c):
        a = c.popleft()
        s = w = 0
        for i in range(n):
            if get_bit(a, i):
                if info[i]: w += 1
                else: s += 1
        if w >= s: continue
        answer = answer if answer >= s else s
        
        for i in range(n):
            if get_bit(a, i): 
                for child in graph[i]:
                    n = a | (1<<child)
                    if not visited[n]:
                        visited[n] = True
                        c.append(n)
    return answer