#include <cstdio>

int n,m,k;
int arr[10001], dp[10001]; //DP[i] = 1 ~ i 까지 구한 최대값

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d", arr+i);

    for(int i=1;i<=n;i++){
        m = arr[i];
        for(int j=1;j<=k && i-j >= 0;j++){
            if(dp[i] < dp[i-j] + m*j)  dp[i] = dp[i-j] + m*j;
            if(m < arr[i-j]) m = arr[i-j];
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}