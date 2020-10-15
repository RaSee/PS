#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;scanf("%d",&n);
    vector<pair<int, pair<int, int>>> platform(n);
    
    for(int i=0;i<n;i++){
        scanf("%d%d%d", &platform[i].first, 
                        &platform[i].second.first, 
                        &platform[i].second.second);
    }
    
    sort(platform.begin(), platform.end());
    int answer = 0;
    for(int i=0;i< platform.size();i++){
        int a, b;
        int start = platform[i].second.first;
        int end   = platform[i].second.second;
        a = b = platform[i].first;
        for(int j=0;j<i;j++){
            if(platform[j].second.first <= start && start < platform[j].second.second ){
                a = platform[i].first - platform[j].first;
            }
            if(platform[j].second.first < end && end <= platform[j].second.second ){
                b = platform[i].first - platform[j].first;
            }
        }
        answer += (a+b);
    }

    printf("%d\n",answer);
    return 0;
}