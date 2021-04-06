#include <cstdio>
#include <cmath>



int arr[30];
bool dp[16001][30];
int r,T;



int main(){
    scanf("%d",&r);

    int total = 0;

    for(int i=0;i<r;i++) {
        scanf("%d",arr+i);
        dp[arr[i]][i] = true;
        total += arr[i];
    }

    for(int j=1;j<r;j++){
        for(int i=15000;i>=1;i--){  

            dp[i][j] |= dp[i][j-1];
            dp[i][j] |= dp[i+arr[j]][j-1];
            dp[i][j] |= dp[std::abs(i-arr[j])][j-1];
            
        }
    }
    
    
    for(int j=0;j<r;j++){
        for(int i=1;i<=total;i++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    
    
    scanf("%d",&T);
    while(T--){
        int t; scanf("%d",&t);
        if(t <= total)
            printf("%c ", dp[t][r-1] ? 'Y': 'N');
        else
            printf("N ");

    }


    return 0;
}