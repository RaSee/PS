#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int indgree[32001];
vector<vector<int>> graph;


int main(){
    scanf("%d%d",&n,&m);
    graph.resize(n+1);
    for(int i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        indgree[b]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indgree[i]){
            q.push(i);
        }
    }
    /*
    while(q.size()){
        int qsize = q.size();
        while(qsize--){
            int now = q.front();
            printf("%d ",now);
            q.pop();
            for(int next : graph[now]){
                if(indgree[next] == 0) continue;
                indgree[next]--;
                if(indgree[next] == 0) q.push(next);
            }
        }
    }
    */
    
    while(q.size()){
        int now = q.front();
        printf("%d ",now);
        q.pop();
        for(int next : graph[now]){
            if(indgree[next] == 0) continue;  // 혹시 모를 underflow defense
            indgree[next]--;
            if(indgree[next] == 0) q.push(next);
        }
    }
    
    return 0;
}