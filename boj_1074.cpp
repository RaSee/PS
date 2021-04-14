#include <cstdio>

int arr[16] = {
  1,2,4,8,
  16,32,64,128,
  256,512,1024,2048,
  4096,8192,16384,32768
};

int main(){

  int n, r, c; scanf("%d%d%d",&n,&r,&c);

  int answer = 0;
  while(n>0){
    
    if(r < arr[n-1] && c < arr[n-1]){
      //empty
    }
    else if(r < arr[n-1] && c >= arr[n-1]){
      answer += arr[n-1]*arr[n-1];
      c -= arr[n-1];
    }
    else if(r >= arr[n-1] && c < arr[n-1]){
      answer += arr[n-1]*arr[n-1]*2;
      r -= arr[n-1];
    }
    else{
      answer += arr[n-1]*arr[n-1]*3;
      c -= arr[n-1];
      r -= arr[n-1];
    }
    --n;
  }

  printf("%d\n",answer);

  return 0;

}