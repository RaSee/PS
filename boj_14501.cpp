#include <iostream>
/*
GOTO문 쓴 이유:
- if(next > n) 인 경우에도 DP[i]가 최대값인지 살펴봐야하는데,  
if(DP[i] > answer) answer = DP[i]; <- 같은 code를 한번 더 써야함.

함수 처리도 가능하지만, nvme-cli에서 봤던 GOTO문 처럼
흐름을 깨지 않으면 좀 더 코드를 간단하게 작성할 수 있어서 사용

지난번 code 보다 나은 점
최대값을 loop문에서 갱신함으로 써,
i-1까지의 max값을 검사할 필요가 없음

*/
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