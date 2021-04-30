#include <cstdio>
#define min(a, b) (((a) < (b)) ? (a) : (b))
int DP[2001];



int main(){

    int s; scanf("%d",&s);
    DP[1] = 0;
    for(int i=2;i<=2000;i++) DP[i] = i;
                           
    for(int i=2;i<=2000;i++){
        for(int j=2;j*i<=2000;j++){
            DP[i*j] = min(DP[i*j], DP[i]+j);
        }
        /*
        수정 전
        for(int j=1;i-j>=2;j++)
            DP[i-j] = min(DP[i-j], DP[i]+j);
        
        */
       for(int j = 1999; j > i; j--){
            DP[j] = min(DP[j], DP[j+1] + 1);
       }
    }
    DP[1] = 0;


    printf("%d\n",DP[s]);


    return 0;
}