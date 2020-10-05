#include <cstdio>
#include <vector>
#include <algorithm>

/*

*/

std::vector<long long int> v;

void DFS(int now, long long sum){
    v.push_back(sum);
    if(now == 0) return;
    for(int i=0; i< now;i++){
        DFS(i, sum*10+i);
    }
}

int main(){

    int n; scanf("%d",&n);
    DFS(10,0);
    std::sort(v.begin(), v.end());
    if(n >= v.size()) printf("-1\n");
    else printf("%lld\n",v[n+1]);
    
}