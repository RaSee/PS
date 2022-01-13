from collections import deque

def solution(n, path, order):
    answer = True
    visited = [False] * (n+1)
    visited[0] = True
    graph = [{'p':0, 'n':[],'a':0} for _ in range(n+1)]
    indegree = [1] * (n+1)
    
    for o in order:
        graph[o[0]+1]['n'].append(o[1]+1)
        graph[o[0]+1]['a'] = (o[1]+1)
        indegree[o[1]+1] += 1
    
    for p in path:
        graph[p[0]+1]['n'].append(p[1]+1)
        graph[p[1]+1]['n'].append(p[0]+1)

    def dfs(now, p):
        if visited[now]: return
        visited[now] = True;
        graph[now]['p'] = p
        for g in graph[now]['n']:
            if g != graph[now]['a']: 
                dfs(g, now)
    
    dfs(1,0)
    indegree[1] -= 1
    if indegree[1]: return False
    q = deque([1])
    cnt = 0
    
    while len(q):
        qsize = len(q)
        for _ in range(qsize):
            now = q[-1]
            q.pop()
            cnt += 1
            for nn in graph[now]['n']:
                if graph[now]['p'] == nn: continue
                indegree[nn] -= 1
                if not indegree[nn]:
                    q.appendleft(nn)
    
    return cnt == n