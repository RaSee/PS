#include <cstdio>
#include <queue>

using namespace std;

int n;
int visited[50][50][2];
char map[50][51];


int bdirect, edirect; //가로 : 0, 세로 : 1
int br, bc, er, ec;

void set_info(char target, int row, int& r, int& c, int& direct){
  for(int j=0;j<n;j++){
    if(map[row][j] == target){
      if(j < n-1 && map[row][j+1] == target){
        direct = 0;
        r = row;
        c = j+1;
      }else{
        direct = 1;
        r = row+1;
        c = j;
      }
      break;
    }
  }
}

//상 : 1 ,하 : 2, 좌 : 3, 우 : 4
int dr[4] ={-1,1,0,0};
int dc[4] ={0,0,-1,1};


bool over_range(int i, int j){
  if(i < 0 || i >= n || j < 0 || j >= n) return true;
  else return false;
}

bool check_move(int r, int c, bool d){
  
  if(d == 0){
    for(int k=c-1; k<= c+1; k++){
      if(over_range(r, k)) return false;
      if(map[r][k]=='1') return false;
    }
  }
  else{
    for(int k=r-1; k<= r+1; k++){
      if(over_range(k, c)) return false;
      if(map[k][c]=='1') return false;
    }
  }
  return true;
}

bool check_rotation(int r, int c){
  for(int i=r-1;i<=r+1;i++){
    for(int j=c-1;j<=c+1;j++){
      if(over_range(i, j)) return false;
      if(map[i][j] == '1'){
        return false;
      }
    }
  }
  return true;
}

int bfs(){
  queue<pair<pair<int, int>, bool>> q;
  q.push({{br,bc}, bdirect});
  int answer = 0;
  while(q.size()){
    ++answer;
    int qsize = q.size();
    //printf("generation : %d\n", answer);
    for(int i=0;i<qsize;i++){

      int nowr = q.front().first.first;
      int nowc = q.front().first.second;
      bool nowd = q.front().second;

      q.pop();

      //printf("now : %d %d %d\n",nowr,nowc, nowd);

      for(int j=0;j<4;j++){
        int nextr = nowr + dr[j];
        int nextc = nowc + dc[j];
        bool nextd = nowd;

        //printf("check %d %d %d\n",nextr, nextc, nextd);

        if(!check_move(nextr, nextc, nextd)) continue;
        if(visited[nextr][nextc][nextd]) continue;
        
        q.push({{nextr, nextc}, nextd});
        visited[nextr][nextc][nextd] = answer;

        //printf("push %d %d %d\n",nextr,nextc, nextd);
      }

      if(!check_rotation(nowr, nowc)) continue;
      if(visited[nowr][nowc][!nowd]) continue;

      visited[nowr][nowc][!nowd] = answer;
      q.push({{nowr, nowc}, !nowd});
        
      //printf("push %d %d %d\n",nowr,nowc, !nowd);
    
    }
    if(visited[er][ec][edirect]){
      return visited[er][ec][edirect];
    }
  }
  return 0;
}


int main(){

  scanf("%d",&n);
  bdirect = edirect = -1;

  for(int i=0;i<n;i++){
    scanf("%s",map[i]);
    //find tree
    if(bdirect == -1){
      set_info('B', i, br, bc, bdirect);
    }
    if(edirect == -1){
      set_info('E', i,er, ec, edirect);
    }
  }

  //printf("%d %d\n%d %d\n", br, bc, er, ec);
  printf("%d\n",bfs());

  return 0;
}