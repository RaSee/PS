#include <cstdio>


int n, l;

int main(){

  scanf("%d%d",&n,&l);

  for(;l<=100;l++){
    int son = 2*n - l*l + l;
    int mother = 2*l;

    int start = son/mother;
    if(start >= 0 && son%mother == 0){
      for(int i=0;i<l;i++){
        printf("%d ", start+i );
      }
      break;
    }
  }
  if(l > 100){
    printf("-1");
  }
  return 0;

}