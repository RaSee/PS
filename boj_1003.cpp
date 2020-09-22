#include <cstdio>

int DP0[41] = {1,0,0,};
int DP1[41] = {0,1,0,};



int main(){

    int n; scanf("%d",&n);
    
    for(int i=2;i<41;i++){
        DP0[i] = DP0[i-1]+DP0[i-2];
        DP1[i] = DP1[i-1]+DP1[i-2];
    }

    while(n--){
        int target; scanf("%d",&target);
        printf("%d %d\n",DP0[target], DP1[target]);
    }

    return 0;
}