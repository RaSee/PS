#include <cstdio>

/*
Algorithm Type : Greedy
증명
Pi, Pi+1가 있을 때 Pi는 Pi+1보다 적어도 한칸 더 빠른 index의 햄버거를 먹을 수 있음
따라서 순차적으로 탐색했을 때, 가장 멀리 있는 햄버거부터(혹은 사람) 매칭시켜주는 것이
가장 많은 매칭을 이룰 수 있음
*/

int main(){

    int n, k; char bench[20001];
    scanf("%d%d",&n,&k);
    scanf("%s",bench);

    int b = 0;
    int answer = 0;
    
    for(int i=0;i<n;i++){
        for(int j= (i-k >=0)?(i-k):0;j<i;j++){
            if(bench[j] != bench[i] && bench[j] != 0 && bench[i] != 0){
                bench[j] = 0;
                bench[i] = 0;
                answer++;
                break;
            }
        }
    }
    printf("%d\n",answer);
    return 0;
}