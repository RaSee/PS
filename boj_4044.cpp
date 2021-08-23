#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> dfs(vector<int> dp[4][4], int r, int c){

    if(r == c){
        return dp[r][c];
    }
    for(int i=0;r +i+1<=c; i++){
        vector<int> left = dfs(dp, r, r+i);
        vector<int> right = dfs(dp, r+i+1,c);

        printf("%d %d\n", r, c);
        printf("[");
        for(int a : left){
            printf(" %d",a);
        }
        printf("]");
        printf(" [");
        for(int a : right){
            printf(" %d",a);
        }
        printf("]\n");

        for(int a : left){
            for(int b : right){
                dp[r][c].push_back(a*b);
                dp[r][c].push_back(a-b);
                dp[r][c].push_back(a+b);
                if(b &&!(a%b)) {
                    dp[r][c].push_back(a/b);
                }
            }
        }
    }
    return dp[r][c];
}

void solve(vector<int> arr, vector<int>& v){

    sort(arr.begin(), arr.end());
    vector<int> dp[4][4];
    for(int i=0;i<4;i++){
        dp[i][i].push_back(arr[i]);
    }
    
    do{
        printf("----");
        for(int a : arr){
            printf("%d ",a);
        }
        printf("\n");
        dfs(dp, 0, 3);
        v.insert(v.end(), dp[0][3].begin(), dp[0][3].end());
        
    }while(next_permutation(arr.begin(), arr.end()));


}


int main(){

    for(int i=1;;i++){
        vector<int> arr;
        vector<int> v;
        for(int i=0;i<4;i++) {
            int t;
            scanf("%d", &t);
            arr.push_back(t);
            printf("%d\n",arr[i]);
        }
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0) break;

        solve(arr, v);
        sort(v.begin(), v.end());
        int answer, local_answer = 1;
        int max, min, local_max, local_min;
        max = min = local_min = local_max = v[0];

        
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1] == 1){
                local_answer++;
                local_max = v[i];
            }
            else{
                if(local_answer >= answer){
                    answer = local_answer;
                    max = local_max;
                    min = local_min;
                    local_min = local_max = v[i];
                }
            }
        }

        printf("Case %d: %d to %d\n", i,min,max);
    }

    return 0;
}