#include <iostream>
#include <string>
#include <set>

using namespace std;

/*
Sol : 중복 순열

최악 10^10 이여서 중복순열 풀이가 아닐 줄 알았는데
시간초과가 안났다.

그래서 naive한 방법으로 모든 경우를 set에 저장하는 방법을 썼는데
메모리 초과가 났다.

그래서 그냥 모두 count 하고, 중복되는 경우를 제거하였다
*/

bool checked[10] = {false,};
void DFS(string& origin, string& rebuild, int depth, int& count){
    if( depth == origin.length()){
        for(int i=1;i<depth;i++){
            if(rebuild[i-1] == rebuild[i])
                return;
        }
        count++;
        return;
    }
    for(int i = 0; i< origin.length();i++){
        if(checked[i] == true)
            continue;
        checked[i] = true;
        rebuild.push_back(origin[i]);
        DFS(origin, rebuild, depth+1, count);
        rebuild.pop_back();
        checked[i] = false;
    }
}

int fac(int a){

    int ret = 1;
    while(a){
        ret *= a;
        a--;
    }
    return ret;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int answer = 0;
    char a[26] = {0,};
    string origin, rebuild;
    set<string> lucky;
    cin >> origin;

    for(int i=0;i<origin.size();i++){
        a[origin[i]-'a']++;
    }

    DFS(origin, rebuild, 0, answer);

    for(int i=0;i<26;i++){
        if(a[i] == 0) continue;
        else answer /= fac((int)a[i]);
    }


    cout << answer ;

    return 0;
}