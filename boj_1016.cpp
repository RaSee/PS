#include <cstdio>


long long power[1000001];
bool arr[1000001];

int main(){

    long long min, max; scanf("%llu%llu",&min, &max) ;
    int size = max - min + 1, answer = 0;
    for(long long i=2;i*i<=max; i++){
        power[i] = i*i;
    }

    for(int i=2; power[i];i++){
        long long a = (min / power[i]), start;
        start = power[i]*a;
        while(start <= max){
            if(start-min < 0){
                start += power[i];
                continue;
            }
            if(arr[start-min]) 
                break;
            else{
            }
            arr[start-min] = true;
            start += power[i];
        }
    }
    for(int i=0;i<size;i++){
        if(!arr[i])
            ++answer;
    }
    printf("%d\n", answer);
    return 0;
}