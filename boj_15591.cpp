#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int n, q, a,b,c;
vector<vector<pair<int, int>>> graph;
int USADO[5000][5000];

void DFS(int s, int n, int cost, bool visited[5000]){
    if(visited[n]) return;
    visited[n] = true;
    USADO[s][n] = cost;
    for(auto t : graph[n]){
        DFS(s, t.first, t.second < cost ? t.second : cost, visited);
    }
}

int getUSADO(int k, int s){

    int ret = 0;
    for(int i=0;i<n;i++){
        if(i != s && USADO[s][i] >= k) ++ret;
    }
    return ret;
}

int main(){

    scanf("%d%d",&n,&q);
    graph.resize(n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d%d",&a,&b,&c);
        graph[a-1].push_back({b-1, c});
        graph[b-1].push_back({a-1, c});
    }
    for(int i=0;i<n;i++) {
        bool visited[5000] = {false,};
        DFS(i, i, 0xfffffff, visited);
    }

    while(q--){
        scanf("%d%d",&a,&b);
        printf("%d\n",getUSADO(a, b-1));
    }

    return 0;
}
