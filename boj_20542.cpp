#include <cstdio>
#include <vector>

using namespace std;

int n,m;
char an[1000001];
char am[1000001];


bool same(char input, char answer){

    if(input == answer) return true;
    if(input == 'i' && (answer == 'j' || answer == 'l')) return true;
    if(input == 'v' && answer == 'w') return true;
    return false;

}

int main(){
    vector<vector<int>> dp;

    scanf("%d%d",&n,&m);
    scanf("%s",an);
    scanf("%s",am);

    dp.resize(n+1);
    for(int i=0;i<=n;i++){
        dp[i].resize(m+1);
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }

    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=m;j++){
            if(same(an[i-1], am[j-1])) 
                dp[i][j] = dp[i-1][j-1]; 
            else 
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }

  
    
    printf("%d\n",dp[n][m]);

    return 0;
}