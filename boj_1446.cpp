#include <cstdio>
#include <vector>
#include <algorithm>

const int INF = 100000000;
struct{
    int s;
    int e;
    int d;
}typedef road;

bool cmp(const road a, const road b){
    if(a.s != b.s) return a.s < b.s;
    else if(a.e != b.e) return a.e < b.e;
    else return a.d < b.d;
}

int DFS(int now, int ptr, std::vector<road>& v, int cost, int end){

    if(now == end) return cost;
    else if(now > end) return INF;

    int answer = INF, t, t2;
    for(int i=ptr;i<v.size();i++){
        if(v[i].s < now) continue;
        t = DFS(v[i].e, ptr+1, v, cost + (v[i].s - now) + v[i].d, end);
        if(t < answer) answer = t;
    }
    t2 = DFS(end, ptr+1, v, cost + (end-now), end);
    if(t2 < answer) return t2;
    else return answer;
    
}

int main(){

    int n, d; scanf("%d%d",&n,&d);
    std::vector<road> v(n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&v[i].s, &v[i].e, &v[i].d);
    }

    std::sort(v.begin(), v.end(), cmp);

    printf("%d\n", DFS(0,0, v,0,d));
}