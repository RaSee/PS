#include <cstdio>

int arr[191300];
int main(){
    int t,T;scanf("%d",&T);

    arr[0]= 1;
    arr[1]= 1;
    for(int i=2;i<191300;i++) arr[i] = (arr[i-1] + arr[i-2])%1000000007;
    
    while(T--){
        scanf("%d\n",&t);
        printf("%d\n",arr[t]);
    }
    return 0;

}