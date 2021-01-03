#include <iostream>
#include <vector>

using namespace std;

int n;
unsigned int arr[500][2] = {0,}, dp[500][500] = {0,};

unsigned int make_dp(int start, int end){
    if(start == end){
        return 0;
    }
    if(dp[start][end]){
        return dp[start][end];
    }
    else{
        unsigned int min = 0xffffffff, t = 0;
        for(int k=start; k<end; k++){
            t = make_dp(start, k) + make_dp(k+1, end) + arr[start][0] * arr[k][1] * arr[end][1];
            if(t < min) min = t;
        }
        return dp[start][end] = min;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i][0] >> arr[i][1];

    cout << make_dp(0,n-1) <<"\n";

    return 0;
}