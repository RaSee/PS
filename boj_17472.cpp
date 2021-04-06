#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> edge;
vector<pair<int, int>> node;
int parent[7] {0,1,2,3,4,5,6}; //1-based

int n,m;
int map[10][10];
bool visited[10][10];

int answer = 0;


int dr[4]={1,-1,0,0};
int dc[4]={0,0,-1,1};

int find(int a){
    if(parent[a] != a) return parent[a] = find(parent[a]);
    else return a;
}

void merge(int a, int b, int c){
    a = find(a);
    b = find(b);

    if(a == b) return;
    else{
        parent[b] = a;
        answer += c;
    }
}

void dfs(int r, int c, int num){

    if(r >= n || r < 0 || c >= m || c < 0) return;
    if(!map[r][c]) return;
    if(visited[r][c]) return;
    map[r][c] = num;
    visited[r][c] = true;
    for(int i=0;i<4;i++){
        int nextr = r + dr[i];
        int nextc = c + dc[i];
        dfs(nextr, nextc, num);
    }
}

void make_edge(int r, int c, int num){

    visited[r][c] = true;
    for(int i=0;i<4;i++){
        int nextr = r + dr[i];
        int nextc = c + dc[i];
        
        if(nextr >= n || nextr < 0 || nextc >= m || nextc < 0) continue;
        if(visited[nextr][nextc]) continue;
        if(map[nextr][nextc]==num)
            make_edge(nextr, nextc, num);
        else{
            int count = 0;
            while(true){
                nextr += dr[i];
                nextc += dc[i];
                count += 1;

                if(nextr >= n || nextr < 0 || nextc >= m || nextc < 0) break;
                if(map[nextr][nextc]){
                    if(count >= 2){
                        edge.push_back({count, {num, map[nextr][nextc]}});
                        //printf("count : %d, direction : %d, (%d, %d) %d<=>%d\n", count, i, r, c, num, map[nextr][nextc]);
                    }
                    break;
                }
            }
        }
    }
}

bool check(){
    int target = find(1);
    for(int i=2;i<=node.size();i++){
        if(find(i)!=target) return false;
    }
    return true;
}

int main(){

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",map[i]+j);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] && !visited[i][j]){
                node.push_back({i,j});
                dfs(i,j, node.size());
            }
        }
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            visited[i][j] = false;
    for(int i=0;i<node.size();i++){
        make_edge(node[i].first, node[i].second, i+1);
    }

    sort(edge.begin(), edge.end());

    for(auto e : edge){
        merge(e.second.first, e.second.second, e.first);
    }

    if(check()) printf("%d\n",answer);
    else printf("-1\n");
    
    return 0;
}
