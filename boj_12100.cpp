#include <cstdio>
#include <vector>

using namespace std;

enum{
    up = 0,
    down,
    left,
    right
};

const int command_count = 5;
int command[5];
int n;
int board[20][20];


vector<int> merge(vector<int> v){
    vector<int> merged(n, 0);
    int now_index = 0;
    for(int num : v){
        if(num == 0) continue;
        else if(merged[now_index] == 0) merged[now_index] = num;
        else if(num == merged[now_index]){
            merged[now_index] += num;
            now_index += 1;
        }
        else{
            now_index += 1;
            merged[now_index] = num;
        }
    }
    return merged;
}


int DFS(int now){
    if(now == command_count){
        int m = 0;

        int tboard[20][20]={0,};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tboard[i][j] = board[i][j];
            }
        }

        for(int a=0;a<command_count;a++){

            if(command[a] == up){
                for(int i=0;i<n;i++){
                    vector<int> v(n, 0);
                    for(int j=0;j<n;j++){
                        v[j] = tboard[j][i];
                    }
                    vector<int> merged = merge(v);
                    for(int j=0;j<n;j++){
                        tboard[j][i] = merged[j];
                    }
                }
            }

            if(command[a] == down){
                for(int i=0;i<n;i++){
                    vector<int> v(n, 0);
                    for(int j=n-1;j>=0;j--){
                        v[n-1-j] = tboard[j][i];
                    }
                    vector<int> merged = merge(v);
                    for(int j=n-1;j>=0;j--){
                        tboard[j][i] = merged[n-1-j];
                    }
                }
            }

            if(command[a] == left){
                for(int i=0;i<n;i++){
                    vector<int> v(n, 0);
                    for(int j=0;j<n;j++){
                        v[j] = tboard[i][j];
                    }
                    vector<int> merged = merge(v);
                    for(int j=0;j<n;j++){
                        tboard[i][j] = merged[j];
                    }
                }
            }

            if(command[a] == right){
                for(int i=0;i<n;i++){
                    vector<int> v(n, 0);
                    for(int j=n-1;j>=0;j--){
                        v[n-1-j] = tboard[i][j];
                    }
                    vector<int> merged = merge(v);
                    for(int j=n-1;j>=0;j--){
                        tboard[i][j] = merged[n-1-j];
                    }
                }
            }

        }
        //printf("\n\n");

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //printf("%d ",tboard[i][j]);
                if(tboard[i][j]> m){
                    m = tboard[i][j];
                }
            }
            //printf("\n");
        }
        return m;
    }

    int a = 0;
    for(int i=0;i<4;i++){
        command[now] = i;
        int t = DFS(now+1);
        if(t > a ) a = t;
    }
    return a;
}


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&(board[i][j]));
        }
    }

    printf("%d\n",DFS(0));

    return 0;
}