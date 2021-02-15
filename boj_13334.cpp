#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,d,s,e;
int input[100000][2];
vector<int> start;
vector<int> last;
int answer = 0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&(input[i][0]),&(input[i][1]));
        if(input[i][0] > input[i][1]) swap(input[i][0],input[i][1]);
    }
    scanf("%d",&d);
    for(int i=0;i<n;i++){
        if(input[i][1] - input[i][0] > d) continue;
        start.push_back(input[i][0]);
        last.push_back(input[i][1]);
    }


    sort(start.begin(), start.end());
    sort(last.begin(), last.end());
    
    s =0, e=0;
    int local_answer = 0;
    while(true){
        while(e < last.size() && last[e] - start[s]<=d ){
        	//printf("%d %d : %d\n",s, e, start[s]-last[e]);
            ++e;
            ++local_answer;
        }
        if(local_answer > answer) answer = local_answer;
        if(e == last.size()) break;
        ++s;
        --local_answer;
        if(s == start.size()) break;
    }
    

    printf("%d\n",answer);
    return 0;
}