#include <iostream>
#include <vector>
using namespace std;

int n,b;
vector<int> road;
vector<pair<int, int>> boots;
bool check[251][250];
int main(){

    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n >> b;
    road.resize(n); boots.resize(b);
    for(int i=0;i<n;i++) cin >> road[i];
    for(int i=0;i<b;i++) cin >> boots[i].first >> boots[i].second;

    check[0][0] = 1;
    for(int i=1;i<=b;i++){
        for(int j=0;j<n;j++){
            if(check[i-1][j]) check[i][j] = true;
            if(!check[i][j]) continue;
            if(road[j] > boots[i-1].first) continue;
            for(int k=1; k<=boots[i-1].second && j+k < n; k++){ 
                if(road[j+k] <= boots[i-1].first ) check[i][j+k] = true;
            }
        }
            
        if(check[i][n-1]) {
            cout << i-1 << "\n";
            return 0;
        }
    }
    return 0;
}

