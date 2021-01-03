#include <iostream>

using namespace std;

int main(){
    int n,k; cin >> n >> k;
    int dp[2][100001] = {0,};
    int answer = 0;
    bool now;
    for(int i=0;i<n;i++){
        int w,v; cin >> w>>v;
        now = i%2;
        bool pre = !now;

        for(int j=0;j<=k;j++){
            if(j<w)
                dp[now][j] = dp[pre][j];
            else
                dp[now][j] = max(dp[pre][j], dp[pre][j-w]+v);
            // dp[pre][j] : 현재 물건을 넣지 않는 경우
            // dp[pre][j-w] +v : 현재 물건을 넣는 경우
        }
    }
    for(int i=0;i<=k;i++){
        if(answer < dp[now][i]) 
            answer = dp[now][i];
    }
    cout<<answer<<"\n";
    return 0;
}