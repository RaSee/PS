#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int n,m;
int cost[50][50][16];

const int INF = 1e30;

vector<pair<int, int>> food;
int knight_overload, bishop_overload, look_overload;

int knight_dr[8] = {-2,-1,1,2,2,1,-1,-2};
int knight_dc[8] = {-1,-2,-2,-1,1,2,2,1};

int bishop_dr[4] = {-1,1,1,-1};
int bishop_dc[4] = {-1,-1,1,1};

int look_dr[4] = {-1,0,1,0};
int look_dc[4] = {0,-1,0,1};

bool out_of_range(int r, int c){
    if(r >=n || c >= n || r < 0 || c < 0) return true;
    else return false;
}

int get_bit(int r, int c, int f){
    for(int i=0;i<food.size();i++){
        if(r == food[i].first && c == food[i].second){
            return f | ( 1<<i );
        }
    }
    return f;
}


int sr, sc;


int solve(){

    priority_queue<pair<int, pair<int, pair<int, int>>>> pq;
    pq.push({0,{0,{sr,sc}}});
    cost[sr][sc][0] = 0;
    
    while(pq.size()){

        auto t = pq.top();
        pq.pop();

        int nowcost = -t.first;
        int nowr = t.second.second.first;
        int nowc = t.second.second.second;
        int nowf = t.second.first;

        //printf("%d %d %d %d\n", nowcost, nowr, nowc, nowf);

        if(nowf == ((1 << food.size())-1)){
            return nowcost;
        }

        //knight
        int nextcost = nowcost + knight_overload;
        for(int i=0;i<8;i++){
            int nextr = knight_dr[i] + nowr;
            int nextc = knight_dc[i] + nowc;

            if(out_of_range(nextr, nextc)) continue;
            int nextf = get_bit(nextr, nextc, nowf);

            if(nextcost < cost[nextr][nextc][nextf]){
                cost[nextr][nextc][nextf] = nextcost;
                pq.push({-nextcost,{nextf,{nextr, nextc}}});
            }
        }
        //bishop
        nextcost = nowcost + bishop_overload;
        for(int i=0;i<4;i++){

            for(int nextr = bishop_dr[i]+nowr, nextc = bishop_dc[i] + nowc;
                !out_of_range(nextr, nextc); nextr += bishop_dr[i], nextc += bishop_dc[i]){
                
                int nextf = get_bit(nextr, nextc, nowf);
                
                if(nextcost < cost[nextr][nextc][nextf]){
                    cost[nextr][nextc][nextf] = nextcost;
                    pq.push({-nextcost,{nextf,{nextr, nextc}}});
                }
            }
        }

        //look
        nextcost = nowcost + look_overload;
        for(int i=0;i<4;i++){

            for(int nextr = look_dr[i]+nowr, nextc = look_dc[i] + nowc;
                !out_of_range(nextr, nextc); nextr += look_dr[i], nextc += look_dc[i]){
                
                int nextf = get_bit(nextr, nextc, nowf);
                
                if(nextcost < cost[nextr][nextc][nextf]){
                    cost[nextr][nextc][nextf] = nextcost;
                    pq.push({-nextcost,{nextf,{nextr, nextc}}});
                }
            }
        }
    }

    return -1;
}

int main(){
    scanf("%d%d%d%d%d%d",
        &n,&knight_overload, &bishop_overload, &look_overload,&sr, &sc);

    scanf("%d", &m);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        food.push_back({a,b});
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<16;k++)
                cost[i][j][k] = INF;
        }
    }

    printf("%d\n",solve());

}