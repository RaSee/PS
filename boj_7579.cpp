#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))

int n,m, total_cost = 0;
int memory[100];
int cost[100];

int dp[100][10001];

int get_answer(){

  int answer = total_cost;

  for(int i=cost[0];i<=total_cost;i++){
    dp[0][i] = memory[0];
  }
  for(int i=1;i<n;i++){
    for(int j=0; j<=total_cost;j++){
      dp[i][j] = dp[i-1][j];
      if(j-cost[i]>=0){
        dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + memory[i]);
      }
      if(dp[i][j] >= m && answer > j){
        answer = j;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<=total_cost;j++){
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
  return answer;
}


int main(){

  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++)
    scanf("%d",memory+i);
  for(int i=0;i<n;i++){
    scanf("%d",cost+i);
    total_cost += cost[i];
  }

  printf("%d\n",get_answer());
}