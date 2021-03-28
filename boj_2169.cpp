#include <cstdio>

int n,m;
int map[1001][1001];
int total_value[1001][1001];

int my_max(const int a, const int b){
  return a > b ? a : b;
}

int main(){

  scanf("%d%d",&n,&m);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%d",&(map[i][j]));
    }
  }

  for(int i=1;i<=m;i++){
    total_value[1][i] = total_value[1][i-1] + map[1][i];
  }
  
  int arr[1001][3]={0,};
  for(int i=2;i<=n;i++){

    arr[1][1] = total_value[i-1][1] + map[i][1];
    for(int j=2;j<=m;j++){
      arr[j][1] = my_max(total_value[i-1][j], arr[j-1][1]) + map[i][j];
    }
    arr[m][2] = total_value[i-1][m] + map[i][m];
    for(int j=m-1;j>=1;j--){
      arr[j][2] = my_max(total_value[i-1][j], arr[j+1][2]) + map[i][j];
    }
    for(int j=1;j<=m;j++){
      total_value[i][j] = my_max(arr[j][1], arr[j][2]);
    }
  }


  printf("%d\n",total_value[n][m]);

  return 0;
}