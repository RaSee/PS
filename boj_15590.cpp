#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int n,m,r;
ll answer;

vector<ll> neighbor;
vector<ll> cow;
vector<pair<ll,ll>> store;
vector<ll> store_cost_psum, store_gallon_psum;

int now_store = 0;
ll get_milk_cost(ll milk_gallon){
    ll milk_cost = 0;
    while(true){
        if(store_gallon_psum[now_store + 1] <= milk_gallon){
            milk_cost = store_cost_psum[now_store + 1] + store[now_store].second * min(store[now_store].first, milk_gallon - store_gallon_psum[now_store + 1]);
            break;
        }
        else{
            now_store += 1;
        }
    }

    return milk_cost;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> r;

    cow.resize(n);
    store.resize(m);
    store_cost_psum.resize(m);
    store_gallon_psum.resize(m);
    neighbor.resize(r);

    for(int i=0;i<n;i++) cin >> cow[i];
    for(int i=0;i<m;i++) cin >> store[i].first>> store[i].second; //gallon, cost
    for(int i=0;i<r;i++) cin >> neighbor[i];

    sort(neighbor.begin(), neighbor.end(), greater<>());
    sort(cow.begin(), cow.end());
    sort(store.begin(), store.end(), [](pair<ll, ll> lhs, pair<ll, ll> rhs){return lhs.second < rhs.second;}); //오름차순

    ll rent_cost = 0, milk_gallon = 0, milk_cost = 0;
    for(ll c : cow)  milk_gallon += c;

    /*
    store_cost_psum[i] : i ~ m-1 까지의 총 수익
    store_gallon_psum[i] : i ~ m-1 까지의 총 gallon 수
    */
    
    store_cost_psum[m-1] = store[m-1].second * store[m-1].first;
    store_gallon_psum[m-1] = store[m-1].first; 
    for(int i=m-2;i>=0;i--){
        store_cost_psum[i] = store_cost_psum[i+1] + store[i].first * store[i].second;
        store_gallon_psum[i] = store_gallon_psum[i+1] + store[i].first;
    }
    store_gallon_psum.push_back(0);
    store_cost_psum.push_back(0);


    answer = get_milk_cost(milk_gallon);
    //0~i : rent, i+1 ~ n : milk
    for(int i=0;i<n;i++){
        milk_gallon -= cow[i];
        if(i < r) rent_cost += neighbor[i];
        milk_cost = get_milk_cost(milk_gallon);
        if(rent_cost + milk_cost > answer) answer = rent_cost + milk_cost;
    }
    
    cout << answer << "\n";
    return 0;
}