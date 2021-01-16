#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    int T; cin >> T;

    while(T--){

        int arr[501] = {0,};
        int DP[501][501];
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
            //arr[i] += arr[i-1];
        }
        for(int i=1; i+1<=n;i++){
          DP[i][i+1] = arr[i] + arr[i+1]; 
        }

        for(int k=2;k<=n;k++){
          for(int i=1;i+k<=n;i++){
            int j=i+k;
            DP[i][j] = 0x0fffffff;
            for(int a=0;a<k;a++){
              int start = DP[i][j-a-1]*2;
              int end = DP[j-a][j]*2;
              if(i == j-a-1) start = arr[i];
              if(j == j-a) end = arr[j];
              DP[i][j] = min(DP[i][j],DP[i][j-a-1] + DP[j-a][j] );

            }
          }
        }

        for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
            cout<<DP[i][j]<<" ";
          }
          cout<<"\n";
        }
        cout << DP[1][n]<<"\n";
    }

    return 0;
}