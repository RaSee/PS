#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer, totalLength;
vector<pair<int, int >> point;
vector<pair<int, int >> pointPrimary;

int DP[2][1000000];

int main(){

    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;
    point.resize(n);
    for(int i=0;i<n;i++) cin >> point[i].first >> point[i].second;
    
    if(n == 1){
        cout << 0 <<"\n";
        return 0;
    }
    
    sort(point.begin(), point.end());
    int start = -1 , end = -1; //point[0].first, end = point[0].second;
    int beforeLength = 0, idx = 0;
    totalLength = end - start;
    bool in = false;
    //DP[0][idx] = totalLength;
    for(int i=0;i<n;i++){
        //always point[i].first <= point[i].second
        if(point[i].second <= end) in = true;
        else{
            if(point[i].first < end) end = point[i].second;
            else{
                totalLength += (end - start);
                start = point[i].first;
                end   = point[i].second;
            }
            pointPrimary.push_back(point[i]);
            DP[0][idx++] = totalLength + (end - start);
        }
    }
    

    totalLength += (end - start);
    if(in){
        cout << totalLength << "\n";
        return 0;
    }


    int N = idx = pointPrimary.size();
    start = 1000000001, end = 1000000001;
    totalLength = 0;
    for(auto it = pointPrimary.rbegin(); it != pointPrimary.rend(); ++it){
        
        if(end < it->second) end = it->first;
        else{
            totalLength += (start - end);
            start = it->second;
            end = it->first;
        }
        DP[1][--idx] = totalLength + (start - end);
    }
    int answer = max(DP[0][1], DP[1][N-1]);
    for(int i=0;i<N-1;i++){
        int t = DP[0][i] + DP[1][i+2];
        int t2 = pointPrimary[i].second - pointPrimary[i+2].first;
        answer = max(answer, t2 > 0 ? t - t2 : t);
    }
    
    cout << answer << "\n";
    return 0;
}