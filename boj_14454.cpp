#include <iostream>
#include <string>
 
typedef unsigned long long ull;
using namespace std;
 
char get_char(const string& s, ull offset, ull size){
    if(size == s.size()) return s[offset];
    else{
        if(offset < (size / 2) ) {}
        else if(offset == (size / 2)) offset = (size / 2) - 1;
        else offset -= ((size / 2) + 1);
        return get_char(s, offset, size / 2);
    }
}
 
int main(){
 
    string s; ull n;
    cin >> s >> n; 
    ull length = s.size();
    while(length < n) length *= 2;
    n -= 1;
 
    cout << get_char(s, n,length) << "\n";
    return 0;
}