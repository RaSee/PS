#include <cstdio>

unsigned long long arr[10];


int main(){

    int n; scanf("%d",&n);

    int b = 10;

    while(true){

        int q = n/b;
        int r = n%b;

        if(q != 0){
            for(int i=0;i<10;i++){
                arr[i] += q;
            }
            for(int i=0;i<10;i++){
                arr[i] += q;
            }
        }
        else{
            for(int i=0;i<10;i++){
                arr[i] += (q-1);
            }
            break;
        }
        b *= 10;
    }

    arr[0]--;
    for(int i=0;i<10;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}