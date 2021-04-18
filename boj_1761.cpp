#include <cstdio>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> v;

int n,m;
//1-based
int cost[40001];
int depth[40001];
int table[21][40001];
bool visited[40001];

void dfs(int now, int tcost, int d, int p){

    if(visited[now]) return;

    visited[now] = true;
    cost[now] = tcost;
    depth[now] = d;
    table[0][now] = p;

    for(auto edge : v[now]){
        dfs(edge.first, tcost+edge.second, d+1, now);
    }
}

void make_table(){
    for(int i=1;i<=20;i++){
        for(int j=1; j<= n;j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
}

int get_lca(int a, int b){

    //must be depth a < depth b
    if(depth[a] > depth[b]){
        int t = a;
        a = b;
        b = t;
    }

    for(int i=20;i>=0;i--){
        if(depth[b] - depth[a] >= (1<<i)){
            b = table[i][b];
        }
    }
    if(a==b) return b;
    for(int i=20;i>=0;i--){
        if(table[i][b] != table[i][a]){
            a = table[i][a];
            b = table[i][b];
        }
    }

    return table[0][a];
}

int main(){

    int a,b,c;
    
    scanf("%d",&n);
    v.resize(n+1);

    for(int i=0;i<n-1;i++){
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    dfs(1,0,0, 0);
    make_table();

    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&a,&b);
        int lca = get_lca(a,b);
        printf("lca : %d\n", lca);
        printf("%d\n", cost[a]+cost[b]-2*cost[lca]);
    }

    return 0;
}