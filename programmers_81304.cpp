#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<pair<int, int>, int>>> map;
int cost[1001][2000];
int istrap[1001];

inline int get_bit(int target, int idx)   {return (target >> (idx-1)) & 1;}
inline int toggle_bit(int target, int idx){return target ^ (1 << (idx-1));}
inline void my_swap(int& a, int& b){int t = a; a = b; b = t;}

int get_path_type(int a, int b, int visited){
    if(istrap[b]) my_swap(a,b);
    int trap_id_a = istrap[a];
    int trap_id_b = istrap[b];
    
    if(!trap_id_a && !trap_id_b) return 0; //둘다 함정이 아니면, 두 정점을 연결하는 역방향 간선이 없다.
    else if(trap_id_a && trap_id_b){
        int bit_a = get_bit(visited, trap_id_a);
        int bit_b = get_bit(visited, trap_id_b);
        if((bit_a + bit_b) & 1) return 1; //한쪽만 방문한 적이 있으면
        else return 0;
    }
    else{
        int bit_a = get_bit(visited, trap_id_a);
        if(bit_a) return 1;
        else return 0;
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = -1;
    map.resize(n+1);
    for(int i=0;i<traps.size();i++) istrap[traps[i]] = i+1;
    for(auto road : roads){
        map[road[0]].push_back({{road[1], road[2]}, 0});
        map[road[1]].push_back({{road[0], road[2]}, 1}); //역방향
    }
    for(int i=1;i<=n;i++) for(int j=0;j<1024; j++) cost[i][j] = 0xfffffff;
    
    priority_queue<pair<pair<int, int>, int>> pq;
    cost[start][0] = 0;
    pq.push({{0,start},0});
    
    while(pq.size()){
        
        int nown = pq.top().first.second;
        int nowc = -pq.top().first.first;
        int visited_trap  = pq.top().second;
        if(nown == end){
            answer = nowc;
            break;
        }
        pq.pop();
        
        for(auto next : map[nown]){
            int nextn = next.first.first;
            int nextc = next.first.second;
            int nextp = next.second;
            int next_visited_trap = visited_trap;
            int path_type = get_path_type(nown, nextn, visited_trap);
            
            if(nextp != path_type) continue;
            if(istrap[nextn]) next_visited_trap = toggle_bit(visited_trap, istrap[nextn]);
            int tcost = cost[nown][visited_trap] + nextc;
            if(tcost < cost[nextn][next_visited_trap]){
                pq.push({{-tcost,nextn}, next_visited_trap});
                cost[nextn][next_visited_trap] = tcost;
            }
        }
    }
    
    return answer;
}