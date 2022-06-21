#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull answer = 0;
int n;
pair<int, int> arr[200000];
vector<pair<int, int>> info;

void update(int now, int s, int e, int v, int i){
    if(s == e && s == i) arr[now].first = arr[now].second = v;
    else if(i < s || e < i) return;
    else{
        int mid = (s+e)/2;
        update(now*2, s, mid, v, i); update(now*2+1, mid+1, e, v, i);
        arr[now].first = max(arr[now*2].first, arr[now*2+1].first);
        arr[now].second = min(arr[now*2].second, arr[now*2+1].second);
    }
}
pair<int, int> get(int now, int s, int e, int f, int l){

    if( l < s || e < f) return {-1, 2000000000};
    else if( s <= f && l <= e) return arr[now];
    int mid = (s+e)/2;
    auto left  = get(now*2  , s    , mid, f, l);
    auto right = get(now*2+1, mid+1, e  , f, l);
    pair<int, int> ret;

    ret.first  = max(left.first, right.first);
    ret.second = min(left.second, right.second);
    return ret;
}


int main(){
    int xl = 2000000000, xh=0, yl=2000000000, yh=0;
    ull area = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x, y; scanf("%d%d",&x,&y);
        info.push_back({x,y});
        if(x < xl) xl = x;
        if(x > xh) xh = x;
        if(y < yl) yl = y;
        if(y > yh) yh = y;
    }
    area = (ull)(xh - xl) * (ull)(yh - yl);

    //x 기준 정렬
    sort(info.begin(), info.end());
    for(int i=0;i<n;i++) update(1,1,n,info[i].second, i+1);


    for(int i=1;i<n;i++){
        if(info[i-1].first == info[i].first) continue;
        auto a = get(1,1,n, 1,  i);
        auto b = get(1,1,n, i+1,n);

        ull aa, ab;
        aa = (ull)(a.first - a.second) * (ull)(info[i-1].first - info[0].first);
        ab = (ull)(b.first - b.second) * (ull)(info[i].first   - info[n-1].first);
        if(area - (aa+ab) > answer) answer = area - (aa+ab);
    }

    //y기준 정렬
    sort(info.begin(), info.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    for(int i=0;i<n;i++) update(1,1,n,info[i].first, i+1);

    for(int i=1;i<n;i++){
        if(info[i-1].second == info[i].second) continue;
        auto a = get(1,1,n, 1,  i);
        auto b = get(1,1,n, i+1,n);

        ull aa, ab;
        aa = (ull)(a.first - a.second) * (ull)(info[i-1].second - info[0].second);
        ab = (ull)(b.first - b.second) * (ull)(info[i].second   - info[n-1].second);
        if(area - (aa+ab) > answer) answer = area - (aa+ab);
    }
    
    printf("%llu\n",answer);

    return 0;
}