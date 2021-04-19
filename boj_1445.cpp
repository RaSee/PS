#include <cstdio>
#include <queue>

using namespace std;


const int INF = 1e60;

int n,m;
int map[50][50];

long long visited[50][50];

char a[51];

int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};

bool out_of_range(int r, int c){

    if(r < 0 || c < 0 || r >= n || c >= m) return true;
    else return false;

}


int sr, sc, er, ec;

int main(){
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++){
        scanf("%s",a);
        for(int j=0;j<m;j++){

            visited[i][j] = INF;
            
            if(a[j]=='g'){
                map[i][j] = 2;

                for(int k=0;k<4;k++){
                    int nextr = i + dr[k];
                    int nextc = j + dc[k];
                    if(out_of_range(nextr,nextc)) continue;
                    if(map[nextr][nextc]) continue;

                    map[nextr][nextc] = 1;
                }
            }
            else if(a[j] == 'S'){
                sr = i, sc = j;
            }
            else if(a[j] == 'F'){
                er = i, ec = j;
            }

        }
    }

    map[sr][sc] = 0;
    map[er][ec] = 0;

    priority_queue< pair<long long, pair<int, int>>> pq;

    pq.push({0, {sr, sc}});

    while(!pq.empty()){

        auto t = pq.top();
        pq.pop();

        int nowr = t.second.first;
        int nowc = t.second.second;

        long long nowt = -t.first;
        
        if(nowr == er && nowc == ec){
            printf("%lld %lld\n", 
                    visited[nowr][nowc]/100000, visited[nowr][nowc]%100000);
            break;
        }
        

        //printf("%d %d %lld\n", nowr, nowc, nowt);

        //if(check({nowt, nowi}, visited[nowr][nowc])) continue;

        for(int i=0;i<4;i++){

            int nextr = nowr + dr[i];
            int nextc = nowc + dc[i];

            long long nextt = nowt;

            if(out_of_range(nextr, nextc)) continue;
            if(map[nextr][nextc] == 2){
                nextt = nowt + 100000;
            }
            else if(map[nextr][nextc] == 1){
                nextt = nowt + 1;
            }

            if(visited[nextr][nextc] > nextt){
                visited[nextr][nextc] = nextt;
                pq.push({-nextt, {nextr, nextc}});
            }

        }
    }

    /*
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            printf("{%lld, %lld} ,", visited[i][j]/100000, visited[i][j]%100000);
        }
        printf("\n");
    }
    */



    return 0;
}

/*

6 6
......
g..F..
....g.
..g...
......
...S.g

6 6
ggggg.
g..F..
ggggg.
..g...
ggg..g
...S.g

6 6
ggggg.
g..F..
gggggg
..g...
ggg..g
...S.g


*/