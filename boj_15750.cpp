#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

typedef unsigned long long ll;

using namespace std;

int n;
ll answer=0xffffffffffffffff, total;
vector<pair<int, int>> points;
map<int, int> delta;

int main(){

    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    points.resize(n);
    for(int i=0;i<n;i++) {
        int a, b; cin >> a >> b;
        total += abs(a-b);

        /* 1) 0 <= b <= a
           2) a <= b <= 0 
           3) 0 <= a <= b && (b-a) < a
           4) b <= a <= 0 && abs(b-a) < a
        */
        if(abs(a) > abs(a-b)) continue;

        delta[b] += 2;
        if(b <= 0 && 0 <= a){
            delta[0] -= 1;
            delta[2*b] -= 1;
        }
        else if(a <= 0 && 0 <= b){
            delta[0] -= 1;
            delta[2*b] -= 1;
        }
        else if(0 <= a && a <= b){
            delta[2*a] -= 1;
            delta[2*b - 2*a] -= 1; //b + (b-2a)
        }
        else if(b <= a && a <= 0){
            delta[2*a] -= 1;
            delta[2*b - 2*a] -= 1;
        }
    }

    int beforex = -2000000000, totalDelta = 0;
    for(auto p : delta){
        int nowx = p.first, nowd = p.second;
        total += (ll)(nowx - beforex)*(ll)totalDelta;
        //cout << nowx << " " << totalDelta << " " << total << "\n";
        if(total < answer) answer = total;
        totalDelta += nowd;
        beforex = nowx;
    }

    cout << answer << "\n";
    return 0;
}