#include <cstdio>
#include <vector>

using namespace std;
/*
bit 1111: 상하좌우 가능
d(0-based)
0 : 오른쪽
1 : 왼쪽
2 : 위
3 : 아래
*/
int dr[4] = {0,0,-1,1}; //0-based
int dc[4] = {1,-1,0,0};

vector<pair<int, int>> checkPoint;
vector<pair<pair<int, int>, int>> fan;

int R, C, K, W;
int board[20][20];
int wall[20][20];
bool check(int r, int c){
    if(r >= R || c >= C || r <0 || c < 0) return false;
    else return true;
}

int get_bit(int target, int n){
    return (target >> n) & 1;
}

void printBoard(){
    
    for(int i=0;i<R;i++){
    	for(int j=0;j<C;j++){
    		printf("%d ",board[i][j]);
    	}
    	printf("\n");
    }
    printf("\n");
}

void dfs(int r, int c, int d, bool visited[20][20], int depth){

    if(visited[r][c]) return;
    if(!depth) return;

    visited[r][c] = true;
    board[r][c] += depth;
    if(d <= 1){ //좌우 방향
        for(int i=0;i<3;i++){
            int nextr = r + dr[d] + i - 1;
            int nextc = c + dc[d];
            if(!check(nextr, nextc)) continue;
            if(d == 1){//좌
                if(i == 0 && ( get_bit(wall[r-1][c], 3) || get_bit(wall[r-1][c], 1))) continue;
                if(i == 1 && get_bit(wall[r][c], 1)) continue;
                if(i == 2 && ( get_bit(wall[r+1][c], 2) || get_bit(wall[r+1][c], 1))) continue;
            }
            else{//우
                if(i == 0 && ( get_bit(wall[r-1][c], 3) || get_bit(wall[r-1][c], 0))) continue;
                if(i == 1 && get_bit(wall[r][c], 0)) continue;
                if(i == 2 && ( get_bit(wall[r+1][c], 2) || get_bit(wall[r+1][c], 0))) continue;
            }
            //printf("%d %d -> %d %d\n",r,c, nextr, nextc);
            dfs(nextr, nextc, d, visited, depth-1);
        }
    }

    else{ //상하 방향

        for(int i=0;i<3;i++){
            int nextr = r + dr[d];
            int nextc = c + dc[d] + i - 1;
            if(!check(nextr, nextc)) continue;

            if(d == 2){//위
                if(i == 0 && ( get_bit(wall[r][c-1], 0) || get_bit(wall[r][c-1], 2))) continue;
                if(i == 1 && get_bit(wall[r][c], 2)) continue;
                if(i == 2 && ( get_bit(wall[r][c+1], 1) || get_bit(wall[r][c+1], 2))) continue;
            }
            else{//아래
                if(i == 0 && ( get_bit(wall[r][c-1], 0) || get_bit(wall[r][c-1], 3))) continue;
                if(i == 1 && get_bit(wall[r][c], 3)) continue;
                if(i == 2 && ( get_bit(wall[r][c+1], 1) || get_bit(wall[r][c+1], 3))) continue;
            }
            //printf("%d %d -> %d %d\n",r,c, nextr, nextc);
            dfs(nextr, nextc, d, visited, depth-1);
        }
    }

}

void spread(int fanR, int fanC, int d){
    bool visited[20][20] = {false,};
    dfs(fanR + dr[d], fanC + dc[d], d, visited, 5);
}

void wind(){
    for(auto f : fan){
        spread(f.first.first, f.first.second, f.second);
        //printBoard();
    }
}

void adjustBoundary(){

    for(int i=0;i<R;i++){
        if(board[i][0]) --board[i][0];
        if(board[i][C-1]) --board[i][C-1];
    }
    
    for(int j=1;j<C-1;j++){
        if(board[0][j]) --board[0][j];   
        if(board[R-1][j]) --board[R-1][j];   
    }
}

bool checkCheckPoint(){
    
    for(pair<int, int> point : checkPoint){
        if(board[point.first][point.second] < K){
            return false;
        }
    }
    return true;
}

void shake(){

    int diff[20][20] = {0,};

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            for(int k=0;k<4;k++){
                if(get_bit(wall[i][j],k)) continue;
                int nextr = i + dr[k];
                int nextc = j + dc[k];
                if(!check(nextr, nextc))  continue;
                if(board[i][j] <= board[nextr][nextc]) continue;

                int d = (board[i][j] - board[nextr][nextc])/4;
                diff[i][j] -= d;
                diff[nextr][nextc] += d;
            }
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            
            board[i][j] += diff[i][j];
        }
    }
}



int main(){

    scanf("%d%d%d",&R,&C,&K);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf("%d",&(board[i][j]));
            if(board[i][j]){
                if(board[i][j] < 5) fan.push_back({{i,j}, board[i][j] - 1});
                else checkPoint.push_back({i,j});
                board[i][j] = 0;
            }
        }
    }
    int a, b, c; 
    scanf("%d",&W);
    for(int i=0;i<W;i++){
        scanf("%d%d%d",&a,&b,&c);
        --a;--b;
        if(c){//(a,b)|(a,b+1)
            wall[a][b] |= (1);
            wall[a][b+1] |= (1<<1);
        }
        else{//(a,b)|(a-1,b)
            wall[a][b] |= (1<<2);
            wall[a-1][b] |= (1<<3);
        }
    }


    int answer = 0;
    while(true){

        //1. fan
        wind();
        //printBoard();
        //2. 섞임
        shake();
        //printBoard();
        //3. 1이상인 가장 바깥쪽 온도 1 감소
        adjustBoundary();
        //4. 초콜맇 먹음
        answer += 1;
        //5. K 칸 이상인지 확인
        if(answer > 100 || checkCheckPoint()){
            break;
        }
    }

    printf("%d\n",answer);


    //printBoard();

}