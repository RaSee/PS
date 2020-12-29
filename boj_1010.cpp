#include <iostream>

using namespace std;

int DP[30][30];
int t;
int main(){

    for(int i=0;i<30;i++){
        DP[0][i] = i+1;
        DP[i][i] = 1;
    }
    for(int i=1;i<30;i++){
        for(int j=i+1;j<30;j++){
            DP[i][j] = DP[i-1][j-1] + DP[i][j-1];
        }
    }

    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        cout<<DP[n-1][m-1]<<"\n";
    }

    return 0;
}