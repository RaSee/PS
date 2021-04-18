#include <cstdio>
#include <vector>

using namespace std;

int n,m,k;
int a,b,c;

//1-based
vector<vector<pair<int, int>>> v;

//row : city num, col : cnt, v alud : cost
int table[301][301];

int main(){


    scanf("%d%d%d",&n,&m,&k);
    v.resize(n+1);
    for(int i=0;i<k;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(a>b) continue;
        if(a>=n) continue;
        v[a].push_back({b,c});
    }

    for(auto info : v[1]){
        if(table[info.first][2] < info.second) 
            table[info.first][2] = info.second;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<m;j++){
            if(!table[i][j]) continue;
            for(auto info: v[i]){
                if(table[info.first][j+1] < table[i][j] + info.second){
                    table[info.first][j+1] = table[i][j] + info.second;
                }
            }
        }
    }

    int answer = 0;
    for(int i=1;i<=m;i++){
        if(answer < table[n][i]) answer = table[n][i];
    }

    printf("%d\n",answer);
    return 0;
}