#include <cstdio>
#include <algorithm>

long long AB[16000000], CD[16000000];
long long A[4000], B[4000], C[4000], D[4000];
long long answer = 0;


void sum(long long* a, 
         long long* b, 
         long long* result, 
         int n){

    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[index++] = a[i] + b[j];
        }
    }
    std::sort(result, result + n*n);

}

int main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld%lld%lld",A+i, B+i, C+i, D+i);
    }
    sum(A,B,AB, n);
    sum(C,D,CD, n);


    int i=0, j = n*n -1;
    
    while(i < n*n && j >= 0){
        
        int local_sum = AB[i] + CD[j];
        if(local_sum > 0) --j;
        else if(local_sum < 0) i++;
        else{
            long long count1 = 1;
            long long count2 = 1;
            ++i, --j;
            while(i < n*n && AB[i] == AB[i-1]){ 
                ++i, ++count1;
            }
            while(j >= 0 && CD[j] == CD[j+1]){
                --j, ++count2;
            }
            
            answer += count1*count2;
        }
    }
    printf("%lld\n",answer);
    

}