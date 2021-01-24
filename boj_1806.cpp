#include <cstdio>

int n;
unsigned long long arr[100000], s;

int main(){
    scanf("%d%llu",&n,&s);
    for(int i=0;i<n;i++){
        scanf("%llu", arr+i);
    }
    int i=0, j=0, answer = n+1;
    unsigned long long sum = arr[0];
    while(i<n){
        //printf("%d %d\n",i,j);
        if(sum < s){
            if(j+1 < n){
                ++j;
                sum += arr[j];
            }
            else{
                break;
            }
        }
        else{
            answer = answer < (j-i+1) ? answer : (j-i+1);
            sum -= arr[i];
            ++i;
        }
    }
    if(answer <= n)
        printf("%d\n",answer);
    else
        printf("0\n");

    return 0;
}