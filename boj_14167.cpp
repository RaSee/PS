#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> points;
vector<int> parent;
priority_queue<pair<int, pair<int, int>>> pq; //{dist {src , dst}}

inline int mypow(int a){return a*a;}

int find(int n){
    if(parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void merge(int p1, int p2){parent[find(p1)] = find(p2);}


int main(){

    int answer = 0;
    scanf("%d",&n);
    points.resize(n); parent.resize(n);
    for(auto &p : points) scanf("%d%d", &(p.first), &(p.second)); 
    for(int i=0;i<n;i++) parent[i] = i;
    

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++) {
            pq.push({-mypow(points[i].first - points[j].first) - mypow(points[i].second - points[j].second), 
                        {i, j}});
        }
    }

    int edge_count = 0;
    while(pq.size()){
        auto now = pq.top(); pq.pop();
        if(find(now.second.first) != find(now.second.second)){
            merge(now.second.first, now.second.second);
            edge_count += 1;
            answer = now.first;
        }

        if(edge_count == n-1) break;
    }
    printf("%d\n", -answer);


    return 0;

}