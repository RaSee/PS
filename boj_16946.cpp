
#include <cstdio>
#include <vector>
using namespace std;

int n,m;
char map[1000][1001];
int visited[1000][1000];

vector<int> v;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int dfs(int r, int c, int num){
  if(visited[r][c]) return 0;
  if(map[r][c] == '1') return 0;

  int cnt = 1;
  visited[r][c] = num;

  for(int i=0;i<4;i++){
    int nextr = r + dr[i];
    int nextc = c + dc[i];
    if(nextr <0||nextc <0 || nextr >= n || nextc >= m ) continue;
    cnt += dfs(nextr, nextc, num);
  }
  return cnt;
}

int get_movable_cell_cnt(int r, int c){

  int cnt = 1;
  int num[4] = {0,};
  for(int i=0;i<4;i++){
    int nextr = r + dr[i];
    int nextc = c + dc[i];
    if(nextr <0||nextc <0 || nextr >= n || nextc >= m ) continue;
    if(map[nextr][nextc] == '1') continue;
    int cell_num = visited[nextr][nextc];
    num[i] = cell_num;

    for(int j=0;j<i;j++){
      if(num[j] == cell_num){
        cell_num = 0;
        break;
      }  
    }
    cnt += v[cell_num];
  }
  return cnt%10;
}

int main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%s",map[i]);
  }

  int num=1;
  v.push_back(0); //dummy
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!visited[i][j] && map[i][j] == '0') {
        int cnt = dfs(i,j, num++);
        v.push_back(cnt);
      }
    }
  }
  /*
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        printf("%d ",visited[i][j]);
    }
    printf("\n");
  }

  for(auto c : v){
      printf("%d ", c);
  }
  printf("\n");
*/

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j] == '0') printf("0");
      else{
        printf("%d",get_movable_cell_cnt(i, j));
      }
    }
    printf("\n");
  }

  return 0;
}