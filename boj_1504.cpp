#include <cstdio>
#include <queue>
#include <vector>
using namespace std;


const int INF = 0xffffff;

int n,m;
vector<vector<pair<int, int>>> graph;

vector<int> dik(int start){

    vector<int> dist(n, INF);
    priority_queue<pair<int, int>> q;

    dist[start] = 0;
    q.push({0,start});

    while(q.size()){

        int now = q.top().second;
        int cost = -q.top().first;
        q.pop();

        for(auto next_info : graph[now]){
            int next_cost = next_info.second;
            int next_node = next_info.first;
            if(dist[next_node] > next_cost + cost){
                dist[next_node] = next_cost + cost;
                q.push({-(next_cost+cost), next_node});
            }
        }
    }

    return dist;
}

int main(){

    int mid1, mid2;
    scanf("%d%d",&n,&m);
    graph.resize(n);
    for(int i=0;i<m;i++){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        --a,--b;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    scanf("%d%d",&mid1, &mid2);
    --mid1, --mid2;

    vector<int> d1 = dik(0);
    vector<int> d2 = dik(mid1);
    vector<int> d3 = dik(mid2);


    if(d1[n-1] == INF){
        printf("-1\n");
    }
    else{
        int path1 = d1[mid1] + d2[mid2] + d3[n-1];
        int path2 = d1[mid2] + d3[mid1] + d2[n-1];

        printf("%d", path1 < path2 ? path1 : path2);
    }


    return 0;
}