#include <cstdio>

/*
solution : find sequence
*/
int main(){
    unsigned long long n;scanf("%lld",&n);
    unsigned long long answer = n*((n%2)?n/2:(n/2)-1);
    if(n%3==0){
        answer -= n;
        answer += n/3;
    }
    printf("%llu\n",answer);
    return 0;
}