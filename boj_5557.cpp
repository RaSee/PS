#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int arr[100];
    unsigned long long dp[100][21] = {0,};
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    dp[0][arr[0]] = 1;

    for(int i=1;i<n-1;i++){
        for(int j=0;j<=20;j++){
            dp[i][j] += ((j-arr[i] >= 0 && j-arr[i] <=20 ) ? 
                         dp[i-1][j-arr[i]] : 0);
            dp[i][j] += ((j+arr[i] >= 0 && j+arr[i] <=20 ) ? 
                         dp[i-1][j+arr[i]] : 0);
            
        }
    }

    std::cout<<dp[n-2][arr[n-1]]<<"\n";

    return 0;
}