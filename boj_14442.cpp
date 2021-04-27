#include <cstdio>
#include <queue>

using namespace std;

int n, m, k;
int map[1000][1000];
int cost[1000][1000][11];


const int INF = 1e31;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int solve(){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int a=0;a<=k;a++)
                cost[i][j][a] = INF;
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0,{0,0}});
    cost[0][0][0] = 1;

    while(q.size()){


        int nowk = q.front().first;
        int nowr = q.front().second.first;
        int nowc = q.front().second.second;
        int nowcost = cost[nowr][nowc][nowk];
        
        q.pop();
        //printf("%d %d %d %d\n", nowr, nowc, nowcost, nowk); 
        if(nowr == n-1 && nowc == m-1){
            return nowcost;
        }

        

        for(int i=0;i<4;i++){

            int nextr = nowr + dr[i];
            int nextc = nowc + dc[i];

            if(nextr >= n || nextc >= m || nextr <0 || nextc < 0) continue;
            
            int nextk = map[nextr][nextc] + nowk;
            if(nextk > k) continue;


            //printf("next : %d %d %d\n",nextr, nextc, nextk);
            //printf("%d\n",cost[nextr][nextc][nextk]);
            if(cost[nextr][nextc][nextk] > nowcost + 1){
                q.push({nextk,{nextr, nextc}});
                cost[nextr][nextc][nextk] = nowcost + 1 ;
                
            }
        }

    }

    return -1;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",map[i]+j);
        }
    }

    printf("%d\n",solve());
    
    
    return 0;
}


/*
6 4 2
0110
1110
1000
0000
1111
0000


1 1
0


10 10 10
0111111111
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000




*/