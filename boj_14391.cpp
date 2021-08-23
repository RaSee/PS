#include <cstdio>

int n,m;
int map[4][4];
int answer = 0;

bool checked[4][4];

void dfs(int r, int c, int max){

    if(c >= m){ c = 0; ++r; }
    if(r >= n){
        //printf("temp answer : %d\n", max);
        if(max > answer) answer = max;
        return;
    }
    if(checked[r][c]){
        dfs(r,c+1, max);
        return;
    }

    int t = 0;
    for(int i=0;c+i<m;i++){
        if(checked[r][c+i]) break;
        for(int j=0;j<=i;j++)
            checked[r][c+j] = true;
        t *= 10;
        t += map[r][c+i];

        dfs(r,c+1, max+t);
        for(int j=0;j<=i;j++)
            checked[r][c+j] = false;
    }

    t = 0;
    for(int i=0;r+i<n;i++){
        if(checked[r+i][c]) break;
        for(int j=0;j<=i;j++)
            checked[r+j][c] = true;
        t *= 10;
        t += map[r+i][c];

        dfs(r,c+1, max+t);

        for(int j=0;j<=i;j++)
            checked[r+j][c] = false;
    }
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&(map[i][j]));
        }
    }
    dfs(0,0,0);
    printf("%d\n",answer);
}