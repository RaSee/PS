#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int x,k;

unsigned long long y;

int main(){
    cin >> x >> k;
    string str_x = bitset<32>(x).to_string();
    string str_k = bitset<32>(k).to_string();

    //cout << str_x << "\n";

    int k_idx = str_k.size() - 1;
    for(int i= str_x.size() -1 ; i >= 0;  i--){
        if(str_x[i] == '0' && k_idx >= 0){
            str_x[i] = str_k[k_idx--];
        }
    }
    if(k_idx >= 0){
        str_x = string(str_k, 0, k_idx + 1) + str_x;
    }

    unsigned long long p = 1;
    for(auto it = str_x.rbegin(); it != str_x.rend(); ++it){
        y += (*it - '0')*p;
        p *= 2;
    }
    

    //cout << str_x<<"\n";
    cout << y - (unsigned long long)x <<"\n";
    

    return 0;
}

