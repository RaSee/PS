#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;
int n,xl,yl,xb,yb;
vector<pair<pair<int,int>,int>> points;
vector<int> X, Y;
int visited[100002][4];

int mirrored[4][2] = {
    1,3, 0,2, 1,3, 0,2
};
vector<vector<int>> graph;

int main(){

    scanf("%d%d%d%d%d",&n,&xl,&yl,&xb,&yb);
    X.push_back(xl); X.push_back(xb);
    Y.push_back(yl); Y.push_back(yb);

    points.push_back({{xl,yl}, 0});
    for(int i=1;i<=n;i++){
        int a, b; scanf("%d%d",&a,&b);
        points.push_back({{a,b},i});
        X.push_back(a);
        Y.push_back(b);
    }
    points.push_back({{xb,yb}, n+1});

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
     
    for(auto& p : points){
        p.first.first = lower_bound(X.begin(), X.end(), p.first.first) - X.begin();
        p.first.second = lower_bound(Y.begin(), Y.end(), p.first.second) - Y.begin();
    }
    
    graph.resize(n+2);
    //vertical 정렬, 첫번째 값(X) 이 똑같음, 두번째 값(Y)값이 다름
    sort(points.begin(), points.end());
    for(int i=0;i<n+2;i++){
        if(i+1 < n+2 && points[i].first.first == points[i+1].first.first){
            graph[points[i].second].push_back(points[i+1].second);
            graph[points[i+1].second].push_back(points[i].second);
        }
    }

    

    

    //horizon 정렬, 두번째 값(Y)값이 같음, 첫번째 값(X)값이 다름
    sort(points.begin(), points.end(), [](auto& l, auto& r){
        if(l.first.second != r.first.second) return l.first.second < r.first.second;
        else return l.first.first < r.first.first;
    });
    for(int i=0;i<n+2;i++){
        if(i+1 < n+2 && points[i].first.second == points[i+1].first.second){
            graph[points[i].second].push_back(points[i+1].second);
            graph[points[i+1].second].push_back(points[i].second);
        }
    }
    sort(points.begin(), points.end(), [](auto& l, auto& r){
        return l.second < r.second;
    });
    priority_queue<pair<int, pair<int, int>>> pq;
    //0 : up, 1 : right, 2 : left, 3 : down
    for(int i=0;i<4;i++) pq.push({0,{0,i}});
    for(int i=0;i<n+2;i++) for(int j=0;j<4;j++) visited[i][j] = 0xfffffff;

    
    int answer = -1;
    while(pq.size()){
        int nowd = pq.top().second.second;
        int nowi = pq.top().second.first;
        int nowm = -pq.top().first; //minus 
        pq.pop();

        int nowx = points[nowi].first.first, nowy = points[nowi].first.second;

        //printf("now idx : %d, now mirror : %d direction : %d\n", nowi, nowm, nowd);

        if(nowi == n+1){
            //printf("Find !!\n");
            answer = nowm; break;
        }

        for(int& nexti : graph[nowi]){
            int nextx = points[nexti].first.first, nexty = points[nexti].first.second;
            //not turned
            
            if( (nowd == 0 && nowx == nextx && nowy < nexty) ||
                (nowd == 2 && nowx == nextx && nowy > nexty) ||
                (nowd == 1 && nowy == nexty && nowx < nextx) ||
                (nowd == 3 && nowy == nexty && nowx > nextx) ){
                    
                if(visited[nexti][nowd] > nowm){
                    //printf("    next i : %d d : %d\n",nexti, nowd);
                    visited[nexti][nowd] = nowm;
                    pq.push({-nowm, {nexti, nowd}});
                }

                if(nexti != 0){
                    for(int nextd : mirrored[nowd]){
                        if(visited[nexti][nextd] > nowm + 1){
                            visited[nexti][nextd] = nowm + 1;
                            //printf("    turned next i : %d d : %d\n",nexti, nextd);
                            pq.push({-nowm-1, {nexti, nextd}});
                        }
                    }
                }
            }
        }
    }

    printf("%d\n",answer);
    return 0;
}