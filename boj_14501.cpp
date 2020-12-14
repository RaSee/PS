#include <iostream>

int main(){
    int n, answer = 0;
    int arr[15][2];
    int DP[16] = {0,};

    std::cin >> n;

    for(int i=0;i<n;i++){
        std::cin >> arr[i][0] >> arr[i][1];
    }

    for(int i=0;i<n;i++){
        int next = i + arr[i][0] - 1;
        if(next > n) goto END;
        DP[next] = DP[next] > answer + arr[i][1] ? 
                    DP[next] : answer + arr[i][1];
END:
        if(DP[i] > answer) answer = DP[i];
    }

    
    std::cout<<answer;
    return 0;

}