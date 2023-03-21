#include <cstdio>
#include <set>

using std::multiset;

int flavor[1000001];
int spicy[1000001];

int tree[4000000];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

long long min(long long a, long long b) {
	if (a < b) return a;
	else return b;
}

int main() {
	int n;
	long long m; scanf("%d%lld", &n, &m);
	long long answer = 0xfffffffffffffff;

	for (int i = 0; i < n; i++) scanf("%d%d", flavor + i, spicy + i);
    
	multiset<int> s;
	long long sum = 0;
	int end = 0;

	for (int i = 0; i < n; i++) {
		while (sum < m && end < n) {
			sum += flavor[end];
			s.insert(-spicy[end]);
			end++;
            //printf("%d %d\n",i, end);
            //if(sum >= m) break;
		}
		if (end == n && sum < m) break;
		answer = min(answer, -(*s.begin()));
		sum -= flavor[i];
		auto it = s.find(-spicy[i]);
        if(it != s.end()) s.erase(it);
	}
	printf("%lld\n", answer);

	return 0;

}