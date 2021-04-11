#include <queue>
#include <vector>

#include <cstdio>

using namespace std;

int n,m,x;

int a, b, c;

int forward_cost[1001];
int reverse_cost[1001];

vector<vector<pair<int, int>>> forward_edge;
vector<vector<pair<int, int>>> reverse_edge;

void djikstra(int start, vector<vector<pair<int, int>>>& v, int* cost_arr){

    priority_queue<pair<int, int>> pq;

    for(auto info : v[start]){
        cost_arr[info.second] = info.first;
        pq.push(info);
    }

    while(!pq.empty()){

        auto top = pq.top();
        pq.pop();

        int cost = top.first;
        int next = top.second;
        if(cost_arr[next] > cost) continue;

        for(auto next_info : v[next]){
            int next_next = next_info.second;
            int next_cost = next_info.first;

            if(cost + next_cost > cost_arr[next_next]){
                cost_arr[next_next] = cost + next_cost;
                pq.push({cost+next_cost, next_next});
            }
        }        
    }

    cost_arr[start] = 0;
}

int main(){

    scanf("%d%d%d",&n,&m,&x);

    forward_edge.resize(n+1);
    reverse_edge.resize(n+1);

    for(int i=1;i<=n;i++){
        forward_cost[i] = reverse_cost[i] = 0xf0000000;
    }

    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        forward_edge[a].push_back({-c, b});
        reverse_edge[b].push_back({-c, a});
    }
    
    djikstra(x, forward_edge, forward_cost);
    djikstra(x, reverse_edge, reverse_cost);

    int max = 0;
    int student = 0;
    for(int i=1;i<n;i++){
        if(forward_cost[i]+reverse_cost[i] < max){
            max = forward_cost[i]+reverse_cost[i];
        }

    }

    printf("%d\n",-max);


    return 0;
}