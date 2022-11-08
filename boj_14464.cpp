#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int c,n, a,b, answer;
vector<int> chicken;
vector<pair<int, int>> cow;

bool used[20000];

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    
    cin >> c >> n;
    chicken.resize(c);
    cow.resize(n);
    for(int i=0;i<c;i++) cin >> chicken[i];
    for(int i=0;i<n;i++) cin >> cow[i].second >> cow[i].first;

    sort(chicken.begin(), chicken.end());
    sort(cow.begin(), cow.end());

    for(int i=0;i<c;i++){
        for(int j=0;j<n;j++){
            if(cow[j].second <= chicken[i] && chicken[i] <= cow[j].first && !used[j]){
                used[j] = true;
                answer += 1;
                break;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
