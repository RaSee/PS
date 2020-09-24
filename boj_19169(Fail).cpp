#include <cstdio>

int main(){

    unsigned int n,k; scanf("%u%u",&n,&k);
    
    int answer = 3;
    if(k == 0 ){
        printf("0\n");
        return 0;
    }
    if(k == 1) answer --;
    if(n-k == 1) answer--;

    printf("%d\n",answer);
    if(k != 1){
        printf("%u %u\n",n-k, n-1);
    }
    if(n-k != 1){
        printf("0 %u\n",n-k-1);
    }
    printf("0 %u\n",n-1);
    return 0;
}