#include <algorithm>
#include <cstdio>

using std::max;
/*
Solution : 조건을 활용한 DP
*/
int main(){

    int n; scanf("%d",&n);
    int DP[100000];
    int person[100000];

    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d%d%d",&a,&b, person+i);
    }
    DP[0] = person[0];
    DP[1] = person[1];
    DP[2] = person[0]+person[2];
    for(int i=3;i<n;i++){
        DP[i] = person[i] + max(DP[i-2], DP[i-3]);
    }
    if(n == 1) printf("%d\n",DP[0]);
    else printf("%d\n", max(DP[n-1], DP[n-2]));


    return 0;
}