#include <cstdio>


long long convert(long long n){
    if(n < 7) return n;
    else return convert(n/7)*10 + n%7;
}

long long convert2(long long t, long long i){
    
    if(!t) return 0;
    else return convert2(t/10, i*3) + i*(t%10); 
}

int main(){
    long long n;scanf("%lld",&n);
    long long t7 = convert(n);
    //printf("%d\n",t7);
    printf("%lld\n",convert2(t7, 1));
    return 0;
}