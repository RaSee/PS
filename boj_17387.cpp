#include <algorithm>
#include <cstdio>
#include <cassert>

typedef long long ll;

using namespace std;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
	ll t = (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
	if(t>0) return 1;
	else if(t==0) return 0;
	else return -1;
}

bool solve(){
	ll x1,x2,x3,x4, y1,y2,y3,y4;
	scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
	scanf("%lld%lld%lld%lld",&x3,&y3,&x4,&y4);
	
	int a = ccw(x1,y1,x3,y3,x2,y2)*ccw(x1,y1,x4,y4,x2,y2);
	int b = ccw(x3,y3,x1,y1,x4,y4)*ccw(x3,y3,x2,y2,x4,y4);
	
	if(a == 0 && b == 0){
        pair<ll, ll> p1 = {x1, y1};
        pair<ll, ll> p2 = {x2, y2};
        pair<ll, ll> p3 = {x3, y3};
        pair<ll, ll> p4 = {x4, y4};
        
		if(p1 > p2) swap(p1, p2);
		if(p3 > p4) swap(p3, p4);
        
		return p1 <= p4 && p3 <= p2;
	}
	return a <= 0 && b <= 0;
}

int main() {
	printf("%d\n",solve());
}