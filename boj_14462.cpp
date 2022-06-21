#include <cstdio>
#include <algorithm>

int n, ans;
int arr[2000], dp[1000][1000];

bool cmp(int a, int b){ return std::abs(a-b) <= 4; }

int main(){

    scanf("%d",&n);
    for(int i=0;i<2*n;i++) scanf("%d",arr+i);
    
    if(cmp(arr[0], arr[n])) dp[0][0] = 1;
    for(int i=1;i<n;i++){
        if(cmp(arr[0], arr[i+n]) || dp[0][i-1]) dp[0][i] = 1;
        if(cmp(arr[i],arr[n])    || dp[i-1][0]) dp[i][0] = 1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(cmp(arr[i], arr[n+j])){ 
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = std::max(dp[i][j], std::max(dp[i-1][j-1], std::max(dp[i-1][j], dp[i][j-1])));
            if(dp[i][j] > ans) ans = dp[i][j];
        }
    } 

    printf("%d\n",ans);

    return 0;
}