#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
unsigned long long value[26];
bool first[26];
int main(){
    int n; scanf("%d",&n);

    unsigned long long answer = 0;
    
    for(int i=0;i<n;i++){
        char str[51]={0,};
        scanf("%s",str);
        int len = strlen(str);
        first[str[0]-'A'] = true;
        for(int i=0;str[i];i++){
            value[str[i]-'A'] += (unsigned long long)pow(10,len-i-1 );
        }
    }
    
    vector<pair<unsigned long long,int>> v;
    
    for(int i=0;i<26;i++) 
        if(value[i])
            v.push_back({value[i],first[i]});
            
    sort(v.begin(), v.end(),greater<pair<int, int>>());
    for(int i=v.size()-1;i>=1;i--){
    	if(v[i].second == 0){
    		v.push_back(v[i]);
    		v[i].second = -1;
    		break;
    	}
    }
    
    int start = 9;
    for(auto e : v){
    	if(e.second == -1) continue;
    	//printf("%llu\n",e.first);
        answer += start*e.first ;
        start--;
    }
    printf("%llu\n",answer);
    
}