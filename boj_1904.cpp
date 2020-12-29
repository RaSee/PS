#include <iostream>

using namespace std;
int dp[1000000]={1,2,};
int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1]+dp[i-2];
        dp[i] %= 15746;
    }
    cout<<dp[n-1]<<"\n";

    return 0;
}