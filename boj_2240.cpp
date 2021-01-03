#include <iostream>

using namespace std;
int arr[1000] = {0,};
int dp[2][31][1000] = {0,};
int w, t;
int main(){
    
    ios::sync_with_stdio(false);
    int answer = 1;
    cin >> t >> w;
    for(int i=0;i<t;i++) {
        cin >> arr[i];
        --arr[i];
    }

    
    if(arr[0] == 0){
        for(int i=0;i<=w;i+=2){
            dp[0][i][0] = 1;
        }
    }
    else{
        for(int i=1;i<=w;i+=2){
            dp[1][i][0] = 1;
        }
    }
    for(int i=1;i<t;i++){
        dp[0][0][i] = dp[0][0][i-1] + (arr[i] ? 0 : 1);
        answer = dp[0][0][i];
    }
    
    //dp[1][i][0] 을 하지 않는 이유는 w=0인 상태에서 나무를 옮길 수 없기 때문에
    

    for(int c=1;c<t;c++){
        for(int r=1;r<=w;r++){
            for(int index=0;index<2;index++){
            bool i = index;
                int& a = dp[i][r][c];
                a = max(dp[i][r][c-1], dp[!i][r-1][c-1])+ (arr[c] == index ? 1 : 0);
                answer = answer > a ? answer : a;
            }
        }
    }


    cout<<answer<<"\n";
    

    return 0;
}