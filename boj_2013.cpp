#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else  return gcd(b, a%b);
}

void scan(int& a, int& b){
  char s[8];
  scanf("%s",s);
  a = 0, b = 0;
  int index=0;
  for(;s[index] && s[index] != '.'; index++){
    a *= 10;
    a += s[index] - '0';
  }
  if(!s[index]) return;

  ++index;
  for(int i=0; i<2; i++){
    b *= 10;
    if(s[index+i]) b += s[index+i] - '0';
  }
}

int main(){
    
    
    int n; scanf("%d",&n);
    int answer = 0;

    map<pair<pair<int, int>, pair<int, int>>, priority_queue<pair<int, int>>> m;
    
    for(int i=0;i<n;i++){
        
        int x11, x12, y11, y12, x21, x22, y21, y22;
        scan(x11, x12);
        scan(y11, y12);
        scan(x21, x22);
        scan(y21, y22);
        
        int b = (y21*100 + y22) - (y11*100 + y12);
        int a = (x21*100 + x22) - (x11*100 + x12);

        if(a == 0){
            b = 1;
        }
        else if(b == 0){
            a = 1;
        }
        else{
            int g = gcd( abs(b), abs(a));
            a /= g, b /= g;
            if(a < 0){
                a = -a, b = -b;
            }
        }
        //x = 1 같은 그래프 처리 기울기 무한대

        int c = (-b*(x21*100 + x22) + a*(y21*100 + y22));
        int d = 100*a;

        if(c == 0){
            d = 1;
        }
        else if(d == 0){
            c = (x21*100 + x22);
        }
        else{
            int g2 = gcd(abs(c),abs(d));
            c /= g2, d /= g2;
            if(c < 0){
                c = -c, d = -d;
            }
        }
        pair<pair<int, int>, pair<int, int>> k = {{a,b}, {c,d}};
        if(m.find({{a,b}, {c,d}}) == m.end()){
            m[k] = priority_queue<pair<int, int>>();
        }
        int x1 = x11*100+x12;
        int x2 = x21*100+x22;
        if (x1 == x2){
          x1 = y11*100 + y12;
          x2 = y21*100 + y22;
        }
        
        if(x1 > x2 )
            m[k].push({x1, x2});
        else
            m[k].push({x2, x1});
    }
    
    int idx = 0;
    for(auto it = m.begin(); it!= m.end(); ++it){

        auto before = it->second.top();
        int min = before.second;
        int max = before.first;
        answer += it->second.size();
        it->second.pop();
        while(it->second.size()){
          auto after = it->second.top();
          if(max >= after.first && after.first >= min){
            answer -= 1;
            if(min > after.second)
              min = after.second;
          }
          else{
            max = after.first;
            min = after.second;
          }
          before = after;
          it->second.pop();
        }
    }

    printf("%d\n", answer);

    return 0;
}

