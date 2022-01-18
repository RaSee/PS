import sys
sys.setrecursionlimit(1000100)

class trie:
    def __init__(self):
        self.next = dict()
        self.cnt = 0
    
    def insert(self, s, i):
        self.cnt += 1
        c = s[i]
        if c not in self.next:
            self.next[c] = trie()
        if c != ' ':
            self.next[c].insert(s, i+1)
        
    def search(self, s, i):
        c = s[i]
        if c == ' ': return i
        if self.cnt < 2: return i
        return self.next[c].search(s, i+1)
        

def solution(words):
    answer = 0
    t = trie()
    for w in words:
        t.insert(w+' ', 0)
    
    for w in words:
        answer += t.search(w+' ', 0)
        pass
    
    return answer