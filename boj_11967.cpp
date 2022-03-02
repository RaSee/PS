#include <cstdio>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

/*
0 : turn off
1 : turn on
2 : will visit
*/
int arr[100][100];
int n,m,answer;
vector<pair<int, int>> parr[100][100];
set<pair<int, int>> s;


int main(){
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<m;i++){
        int x, y, a, b;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        parr[x-1][y-1].push_back({a-1,b-1});
    }
    queue<pair<int, int>> q;
    q.push({0,0});
    arr[0][0] = 2;

    int answer = 1;
    while(q.size()){
        int qsize = q.size();

        for(int i=0;i<qsize;i++){
            int nowr = q.front().first;
            int nowc = q.front().second;
            q.pop();
            
            //printf("%d %d\n",nowr + 1, nowc + 1);

            for(auto light : parr[nowr][nowc]){
                if(!arr[light.first][light.second]){ 
                    answer += 1;
                    arr[light.first][light.second] = 1; //turn on
                    
                    //printf("    turn on %d %d\n",light.first + 1, light.second + 1);
                }
            }

            for(int i=0;i<4;i++){
                int nextr = nowr + dr[i];
                int nextc = nowc + dc[i];
                if(nextr >= n || nextc >= n || nextr < 0 || nextc < 0) continue;
                
                auto it = s.find({nextr, nextc});
                switch(arr[nextr][nextc]){
                case 0:
                    s.insert({nextr, nextc});
                    break;
                case 1:
                    q.push({nextr, nextc});
                    arr[nextr][nextc] = 2;
                case 2:
                    if(it != s.end()) s.erase(it);
                    break;
                default:
                    break;
                }
            }
        }
        
        for(auto it = s.begin(); it != s.end(); ++it){
            if(arr[(*it).first][(*it).second] == 1){
                arr[(*it).first][(*it).second] = 2;
                q.push({(*it).first,(*it).second});
                //printf("Add %d %d\n",(*it).first + 1, (*it).second + 1);
            }
        }
    }

    printf("%d\n",answer);

}