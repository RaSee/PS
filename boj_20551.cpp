#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,m,t; scanf("%d%d",&n,&m);
    vector<int> v;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    while(m--){
        scanf("%d",&t);
        int answer = -1;
        auto it = lower_bound(v.begin(), v.end(), t);
        if(*it == t){
            answer = (int)(it - v.begin());
            if(answer >= n) answer = -1;
        }
        printf("%d\n",answer);
    }
    return 0;
    
}