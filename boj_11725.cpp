#include <cstdio>
#include <vector>

using std::vector;
bool visited[100001];
int parent[100001];
vector<vector<int>> graph;

void dfs(int now){

    if(visited[now])
        return;
    visited[now] = true;
    for(int next : graph[now]){
        if(!parent[next]){
            parent[next] = now;
            dfs(next);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    graph.resize(n+1);
    parent[1] = -1;
    for(int i=0;i<n-1;i++){
        int a,b; scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for(int i=2;i<=n;i++){
        printf("%d\n",parent[i]);
    }

    return 0;
}