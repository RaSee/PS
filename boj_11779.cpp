#include <cstdio>
#include <vector>
#include <queue>

using std::vector;
using std::pair;
using std::priority_queue;
int n,m;
vector<vector<pair<int, int>>> edge;
vector<int> before;
vector<int> total_cost;
vector<int> path;
void find_path(int start, int end){
    
    priority_queue<pair<int, int>> next;
    next.push({0, start});

    while(!next.empty()){
        
        int cost = -next.top().first;
        int now = next.top().second;
        next.pop();

        //printf("now : %d\n", now);

        if(now == end){
            return;
        }

        for(pair<int, int> info : edge[now]){
            //printf("A : %d , B : %d\n", cost + info.first , total_cost[info.second]);
            if(cost + info.first < total_cost[info.second]){
                before[info.second] = now;
                total_cost[info.second] = cost + info.first;
                next.push({-total_cost[info.second], info.second});
            }
        }
    }
    return;
}

void get_path(int start, int end){

    int now = end;
    while(true){
        path.push_back(now);
        
        if(now==start)
            break;
        now = before[now];
    }
}


int main(){
    int start, end;
    scanf("%d%d",&n,&m);
    edge.resize(n+1);
    before.resize(n+1, 0);
    total_cost.resize(n+1, 0x0fffffff);
    for(int i=0;i<m;i++){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        edge[a].push_back({c, b});
    }
    scanf("%d%d",&start, &end);
    find_path(start, end);
    get_path(start, end);
    printf("%d\n%d\n", total_cost[end], path.size());

    
    for(auto it = path.rbegin(); it != path.rend(); ++it){
        printf("%d\n", *it);
    }
    

    return 0;
}