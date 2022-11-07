#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int N,G;
vector<pair<int, pair<int, ll>>> v;



int main(){
    int answer = 0;
    
    multiset<ll> s;
    map<int, ll> p;

    s.insert(0); //At least one of 0 is never erased. Idea 1.

    /*  
        s : gallon 값 
        p : map[cow num] = gallon 
        m : 
    */

    cin >> N >> G;
    int d, num; ll g;
    string sgallon;
    for(int i=0;i<N;i++){
        cin >> d >> num >> g;
        v.push_back({d, {num, g}});
    }

    sort(v.begin(), v.end()); //문제 조건상 day 마다 측정 1회임

    int before_max = 0;
    int before_max_cnt = 0;
    int before_cnt = 0;
    bool overG = false;
    
    
    for(auto i : v){
        int cow = i.second.first;
        int gal = i.second.second;
        int before_gal = 0;

        int local_max = 0, next_max = 0;
        if(!s.empty()) local_max = *s.rbegin(); 
        
        if(p.find(cow) != p.end()){
            auto it = s.find(p[cow]); s.erase(it);
            before_gal = p[cow];
        }
        if(!s.empty()) next_max = *s.rbegin(); 

        //갱신은 하나
        /*
        case 1 : 갱신된 cow 가 최대 중 하나였음 (size 2개이상)
            - 증가/감소 : 무조건 갱신됨
        case 2 : 갱신된 cow 가 유일한 최대 값
            - 증가 : 갱신x
            - 감소 : 최대값들과 비교하여 갱신됨
        case 3 : 갱신될 cow가 최대 값이 아니였음
            - 증가 : 최대값들과 비교하여 갱신됨
        */

        p[cow] = gal + before_gal;    

        if(before_gal == local_max){
            if(next_max == local_max) answer += 1; //case 1
            else if(next_max >= p[cow] ) answer += 1; //case 2-2
        }
        else{//before_gal < local_max
            if(local_max <= p[cow]) answer += 1;
        }

        s.insert(gal + before_gal);

    }

    cout << answer << "\n";
}