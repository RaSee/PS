#include <cstdio>
#include <algorithm>

int main(){
    int n;
    int arr[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    
    if(arr[0] >= 0 && arr[1] >= 0){
        printf("%d %d\n",arr[0],arr[1]);
    }
    else if(arr[n-1]<= 0&& arr[n-2] <= 0){
        printf("%d %d\n",arr[n-2],arr[n-1]);
    }
    else{
        int i = 0, j = n-1;
        int sum = std::abs(arr[0] + arr[n-1]);
        int answer1 = arr[0], answer2 = arr[n-1];

        while(i<j){

            if( std::abs(arr[i] + arr[j]) < sum ){
                answer1 = arr[i];
                answer2 = arr[j];
                sum = std::abs(arr[i]+ arr[j]);
            }


            if(arr[i]+arr[j] == 0){
                break;
            }
            else if(std::abs(arr[i]) > std::abs(arr[j])){
                i++;
            }
            else if(std::abs(arr[i]) < std::abs(arr[j])){
                j--;
            }
        }
        printf("%d %d\n",answer1, answer2);
    }


    return 0;
}