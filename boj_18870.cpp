#include <cstdio>
#include <map>
#include <algorithm>

using std::map;
/*
Solution : 최적화

*/
int main(){

    map<int, int> m;

    int origin[1000000];
    int sorted[1000000];
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){ 
        scanf("%d",origin+i);
        sorted[i] = origin[i];
    }

    std::sort(sorted, sorted+n);
    m[sorted[0]] = 0;
    int count = 1;
    for(int i=1;i<n;i++){
        if(sorted[i] ^ sorted[i-1]){
            m[sorted[i]] = count++;
        }
    }

    for(int i=0;i<n;i++){
        printf("%d ",m[origin[i]]);
    }

}