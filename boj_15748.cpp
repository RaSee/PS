#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef unsigned long long ull;

int n, l;
ull f, b, answer;

struct{
    ull x; ull c; ull a;
}typedef info;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> l >> n >> f >> b;
    ull diff = f - b; //idx * diff : time to be able to stop
    ull x, c, before = 0;

    stack<info> s;
    s.push({0, 10000000,0});

    for(int i=0;i<n;i++){
        cin >> x >> c;
        if( s.top().c <= c){
            while(s.top().c <= c) s.pop();
        }
        s.push({x, c, (x - s.top().x)*c + s.top().a});

    }

    cout << s.top().a * diff << "\n";

    return 0;
}

/*

입력 조건 : 시작점과 정상에는 stop 이 없다.

0 4 8 12 16 20 24 28 32 36 40
0 3 6  9 12 15 18 21 24 27 30
0 1 2  3 4  5  6  7  8  9  10
                  7*i
                     8*i or before max + 나머지*i

1. 이전  step 보다 이후 step 이 더 유리할 수 있다 (이후 tastiness 가 더 높은 경우)

이부분을 고려 하지 않아 잘못된 코드 작성

안먹고 넘어가는 경우
10 3 2 1
1 100
4 1 
7 2
*/
