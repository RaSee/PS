#include <cstdio>



unsigned long long f(unsigned long long n){

    if(n == 1) 
        return 1;
    unsigned long long answer = 1;
    int start = 1;
    int end = 2;
    while(n <= end){
        answer += (answer + (end - start));
        start = end;
        end = end*2;
    }


}

int main(){
    


}