#include <cstdio>

int arr[100010];

int main(){

    int n,k,b, answer = 0xfffffff;
    scanf("%d%d%d",&n,&k,&b);
    for(int i=1;i<=n;i++) arr[i] = 1;

    for(int i=0;i<b;i++){
        int t; scanf("%d",&t);
        arr[t-1] = 0;
    }
    int s = 0, e = 1; //arr[s:e)

    /*
    0 0 1 1 0 1 1 1 0 0 
    */
    int cnt = arr[s] ? 0 : 1;
    while(e <= n){
        if(e - s < k){
            //printf("0 : %d %d %d\n",s,e,cnt);
            if(!arr[e]) cnt++;
            e++;
        }
        else{
            
            if((s == 0 || !arr[s-1]) && !arr[e] ) {
                //printf("3 : %d %d %d\n",s,e,cnt);
            }
            
            answer = cnt < answer ? cnt : answer;
            //printf("2 : %d %d %d\n",s,e,cnt);
            if(!arr[s]) cnt--;
            s++;
        }
    }

    printf("%d\n",answer);

    return 0;
}