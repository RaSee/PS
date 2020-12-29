#include <iostream>
#include <vector>

using namespace std;



int main(){

    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    int arr[1000] = {0,};
    int DP[2][1000] = {0,};
    int answer = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        DP[0][i]=1;
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i]){
                DP[0][i] = max(DP[0][i], DP[0][j] + 1) ;
            }
        }
    }
    
    for(int i=n-1;i>=0;i--){
        DP[1][i]=1;
        for(int j=n-1;j>i;j--){
            if(arr[j] < arr[i]){
                DP[1][i] = max(DP[1][i], DP[1][j] + 1);
            }
        }
    }

    
    for(int i=0;i<n;i++){
        answer = max(answer , DP[1][i] + DP[0][i] - 1);
    }
    
    cout<<answer<<"\n";


    return 0;
}