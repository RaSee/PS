#include <iostream>

using std::cin;
using std::cout;

int main(){

    std::ios::sync_with_stdio(false);

    int arr[1000], n;
    int DP[1000][1000] = {0,};
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        int t_max = arr[i];
        DP[i][i] = 1;
        for(int j=i+1;j<n;j++){
            DP[i][j] = DP[i][j-1];
            if(arr[j] > t_max){
                DP[i][j]++;
                t_max = arr[j];
            }
            if(DP[i][j] > answer) answer = DP[i][j];
        }
    }
    cout << answer <<"\n";
    return 0;
}