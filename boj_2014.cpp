#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
vector<int> prime;
int k,n,t;
int answer = 0;
int before_answer = 0;
const long long MAX = (1<<31);

int main(){

    scanf("%d%d",&k,&n);
    for(int i=0;i<k;i++){
        scanf("%d",&t);
        prime.push_back(-t);
    }
    priority_queue<int> pq;
    
    for(auto p : prime){
        pq.push(p);
    }
    for(int i=0;i<n;i++){
        answer = -pq.top();
        pq.pop();
        if(before_answer == answer){
            --i;
            continue;
        }
        //overflow
        for(auto p : prime){
            long long t = (long long)answer * (long long) p;
            if(t >= MAX)
                pq.push(answer * p);
        }
        printf("%d : %d\n",i+1, answer);
        before_answer = answer;
    }

    printf("%d\n",answer);
    return 0;

}