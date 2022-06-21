#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef unsigned long long ull;

int n;
ull visited[100][100][3], map[100][100], t;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int main(){
    scanf("%d%llu", &n,&t);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%llu",&(map[i][j]));
            for(int k=0;k<3;k++) visited[i][j][k] = 0xffffffffffffffff;
        }
    }

    priority_queue<pair<ull, pair<pair<int, int>, int>>>  q; //row, col, cnt
    
    visited[0][0][0] = 0;
    q.push({0,{{0,0},0}});

    while(q.size()){
        auto now = q.top();
        q.pop();
        ull nowd = -now.first;
        int nowr = now.second.first.first;
        int nowc = now.second.first.second;
        int nowcnt = now.second.second;

        if(nowr == n-1 && nowc == n-1){
            printf("%llu\n", nowd);
            break;
        }

        for(int i=0;i<4;i++){
        
            int nextr = nowr + dr[i];
            int nextc = nowc + dc[i];

            if(nextr >= n || nextc >= n || nextr < 0 || nextc < 0) continue;

            int nextcnt = nowcnt + 1;
            ull nextv = nowd + t;
            if(nextcnt >= 3){
                nextv += map[nextr][nextc];
                nextcnt %= 3;
            }

            if(visited[nextr][nextc][nextcnt] > nextv){
                visited[nextr][nextc][nextcnt] = nextv;
                q.push({-nextv, {{nextr, nextc}, nextcnt}});
            }
        }        
    }

    return 0;
}