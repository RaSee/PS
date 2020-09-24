#include <cstdio>
#include <set>

/*
Solution : 최적화
step1. 하나하나씩 simulation하는 것은 시간복잡도 초과
       구슬을 집어넣을 때 : n
       가장 왼쪽 구슬을 칠 때 : n
       T = O(qn) 
step2. 그럼 입력을 할 때 마다 update를 하는 것이 아니라
       정보를 한꺼번에 모아서 할 수 있을까?
       그림을 그려보니 다음과 같이 되더라

       o__o__o__o___o_o___||  roll 0
       __o__o__o___o_o___o||  roll 1
       ____o__o___o_o___oo||  rool 2

       이를 shift시켜보면 다음처럼 됨
       o__o__o__o___o_o___||    roll 0
        __o__o__o___o_o___o||   roll 1
         ____o__o___o_o___oo||  roll 2
        
       여기서 roll을 하는 것은
       맨 앞의 위치 정보를 제거하고 마지막 위치 바로 오른쪽의 정보를 넣는 것과 같다.
       여기에 몇번 roll을 했는지 저장하고 있다면 실제 상태를 원복할 수 있다.
       T = O(1)

       구슬을 집어넣을 때도 roll을 몇번했는지 알고 있다면
       넣을려고 하는 위치에 구슬이 있는지 없는지도 확인할 수 있다.
       중요한 것은, 삽입시 오랜 시간이 걸리면 안된다는것.
       
       roll 시 앞에서 빼서 뒤에 넣으므로 deque, binary tree 구조를 생각해볼 수 있고,
       deque를 사용 시 구슬을 집어넣을 때 O(n) 의 시간복잡도가
       binary tree시 O(log n) 이 걸린다.

       여기서 set을 이용한다면 중복처리에 대해 고민할 필요가 없으므로 set을 사용했다.

       따라서 최종 시간복잡도는 O(q log n) 이 된다.
*/

int main(){
    std::set<int> s;
    int n,q,p; scanf("%d%d%d",&n,&q,&p);
    int acummulation = 0;
    for(int i=0, a;i<n;i++){
        scanf("%d",&a);
        s.insert(a);
    }

    while(q--){
        int cmd; scanf("%d",&cmd);
        if(cmd == 1){
            int a; scanf("%d",&a);
            s.insert(a+acummulation);
        }
        else{
            s.erase(s.begin());
            s.insert(p+acummulation);
            acummulation++;
        }
    }
    for(auto it = s.begin(); it != s.end(); ++it){
        printf("%d ",(*it)-acummulation);
    }

}