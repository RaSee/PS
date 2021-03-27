#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int n;
vector<pair<int, pair<int, int>>> edge;

// parent[now] = 0 : root node
int parent[100001];
int cost  [100001];

int find(int now){
    if(parent[now]){
        return parent[now] = find(parent[now]);
    }
    else{
        return now;
    }
}


int merge(int a, int b, int c){

    a = find(a);
    b = find(b);

    if(a == b) return cost[a];
    else{
        parent[b] = a;
        cost[a] += (cost[b] + c);
        return cost[a];
    }
}



int main(){

    vector<pair<int, int>> point[3];

    int v;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&v);
            point[j].push_back({v,i+1});
        }
    }

    for(int i=0;i<3;i++){
        sort(point[i].begin(), point[i].end());
        int vsize = point[i].size();
        for(int j=0;j<vsize-1;j++){
            edge.push_back({ abs(point[i][j].first - point[i][j+1].first), 
                            {point[i][j].second, point[i][j+1].second}});
        }
    }

    sort(edge.begin(), edge.end());
    int answer = 0;
    for(auto a : edge){
        answer = merge(a.second.first, a.second.second, a.first);
    }

    printf("%d\n",answer);

    return 0;
}