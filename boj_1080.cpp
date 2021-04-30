#include <cstdio>

int n,m;
char arr[50][51];
char target[50][51];
void inverse(int r, int c){
  for(int i=r;i<r+3;i++){
    for(int j=c;j<c+3;j++){
      if(arr[i][j]=='0')
        arr[i][j] = '1';
      else
        arr[i][j] = '0';
    }
  }
}

void p(char a[][51]){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%c",a[i][j]);
    } 
    printf("\n");
  }
}

int get_answer(){
  int answer = 0;
  for(int i=0;i<n-2;i++){
    for(int j=0;j<m-2;j++){
      if(arr[i][j]!= target[i][j]){
        inverse(i,j);
        ++answer;
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]!= target[i][j]){
        return -1;
      }
    }
  }
  
  return answer;
}


int main(){

  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%s",arr[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%s",target[i]);
  }

  printf("%d\n",get_answer());
}