#include <iostream>

using namespace std;

int DP[1001][1001]={0,};

int main(){
    ios::sync_with_stdio(false);

    string a,b;
    std::cin >> a >> b;

    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }
    cout<<DP[a.size()][b.size()]<<"\n";

    return 0;
}