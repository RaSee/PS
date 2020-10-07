#include <cstdio>

/*
Solution : Modular 연산

시간복잡도 : O(k)
*/

int main(){

    bool mod[100000] = {false,};
    unsigned long long int n, k;
    scanf("%llu%llu",&n,&k);

    long long int sum = n % k, len = 0, t=1;
    int answer = 0;
    for(int i=n;i;i/=10,len++, t*=10);
    t %= k;
    while(true){
        answer += 1;
        if(sum == 0){
            printf("%d\n",answer);
            return 0;
        }
        if(mod[sum]){
            printf("-1\n");
            return 0;
        }
        mod[sum] = true;
        sum = (sum*t + n)%k;
    }
}