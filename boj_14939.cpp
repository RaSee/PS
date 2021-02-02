#include <cstdio>
#include <set>

using namespace std;

const int INF = 1e8;
char board[10][11];
char temp[10][11];
int n = 10;
int answer = INF;

void toggle(char t[10][11], int i, int j){

    if(t[i][j] == 'O') t[i][j] = '#';
    else t[i][j] = 'O';

}

void change(char t[10][11], int i, int j){

    if(i>=1) toggle(t,i-1, j);
    if(j>=1) toggle(t, i, j-1);
    toggle(t, i, j);
    if(j<n-1) toggle(t, i, j+1);
    if(i<n-1) toggle(t, i+1, j);

}

int main(){
    for(int i=0;i<n;i++){
        scanf("%s",board[i]);
    }
    
    for(int i=0;i < (1<<n) ;i++){

        int local = 0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                temp[j][k] = board[j][k];
            }
        }

        int index=0;
        //첫번쩨 줄 경우의수
        for(int j=i;j!=0;j >>= 1, index++){
            if(j&1){
                change(temp, 0, index);
                local += 1;
            }
        }

        
        for(int j=1;j<n;j++){
            for(int k=0;k<n;k++){
                if(temp[j-1][k] == 'O'){
                    change(temp, j, k);
                    local += 1;
                }
            }
            /*
            for(int a=0;a<n;a++){
                for(int b=0;b<n;b++){
                    printf("%c", temp[a][b]);
                }
                printf("\n");
            }
            */
        }


        for(int j=0;j<n;j++){
            if(temp[n-1][j] == 'O'){
                local = INF;
                break;
            }
        }
        answer = answer > local ? local : answer;

    }
    if(answer != INF) printf("%d\n",answer);
    else printf("-1\n");

    return 0;
}