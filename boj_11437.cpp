#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int ancestor[50001][30];
int depth[50001];
vector<vector<int>> graph;

int lca(int a, int b){
    if(depth[a] < depth[b])
        swap(a,b);
    int sub = depth[a] - depth[b];
    int power = 0;

    while(sub){
        int t = sub%2;
        sub /= 2;
        if(t != 0)
            a = ancestor[a][power];
        power += 1;
        //안올라가는줄 알았는데 왜 올라가야하지
    }
    while(a != b){
        power = 0;
        while(ancestor[a][power] != ancestor[b][power]){
            power += 1;
        }
        if(power > 0)
            power -= 1;
        a = ancestor[a][power];
        b = ancestor[b][power];
    }
    return a;
}

void make_ancestor(){

    //BFS로 짰는데, DFS로 짜면 더 짧아질 것 같음
    bool visited[50001] = {false,};
    int d = 0;
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    
    while(q.size()){
        int qsize = q.size();
        for(int i=0;i<qsize;i++){
            int now = q.front();
            visited[now] = true;
            q.pop();
            for(int next : graph[now]){
                if(!visited[next]){
                    ancestor[next][0] = now;
                    depth[next] = depth[now]+1;
                    q.push(next);
                }
            }
        }
    }

    for(int index = 1;index<30; index++){
        int t = 0;
        for(int i=2;i<=n;i++){
            ancestor[i][index] = ancestor[ancestor[i][index-1]][index-1];
            t += ancestor[i][index];
        }
        if(!t) 
            break;
    }
}


int main(){
    
    scanf("%d",&n);
    graph.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a, b; scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    make_ancestor();

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int a, b; scanf("%d%d",&a,&b);
        printf("%d\n", lca(a,b));
    }

    return 0;
}