#include <cstdio>
#include <vector>

#define MOD 1000000007
using namespace std;

int len[9] = {0,2,3,4,4,4,3,2,2};
int dp[2][9];
int arr[9][8] = {
  0,0,0,0,0,0,0,0,
  2,3,0,0,0,0,0,0,
  1,3,4,0,0,0,0,0,
  1,2,4,5,0,0,0,0,
  2,3,5,6,0,0,0,0,
  3,4,6,7,0,0,0,0,
  4,5,8,0,0,0,0,0,
  5,8,0,0,0,0,0,0,
  6,7,0,0,0,0,0,0
};
int main(){
  int t,answer =0; scanf("%d",&t);
  bool flag = 0;
  dp[flag][1] = 1;
  for(int i=1;i<=t;i++){
    flag = !flag;
    for(int j=1;j<=8;j++){
      dp[flag][j] = 0;
      for(int k=0;k<len[j]; k++){
        dp[flag][j] += dp[!flag][arr[j][k]];
        dp[flag][j] %= MOD;
      }
    }
  }

  printf("%d\n",dp[flag][1]);
  return 0;
}