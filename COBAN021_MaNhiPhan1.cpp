#include <bits/stdc++.h>
#define ms(s,n) memset(s,n,sizeof(s))
using namespace std;
vector<vector<string>> a;
void Inp(){
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    a.push_back(v);
    for(int i = 2; i <= 10; ++i){
        vector<string> b(a[i-2]);
        reverse(b.begin(),b.end());
        vector<string> x;
        for(int j = 0; j < a[i - 2].size(); ++j)
            x.push_back("0" + a[i - 2][j]);
        for(int j = 0; j < b.size(); ++j)
            x.push_back("1" + b[j]);
        a.push_back(x);
    }
}
int main(){
    int t; cin >>t;
    Inp();
    while(t--){
		int n;
		cin >>n;
		for(string x : a[n - 1])
            cout <<x <<" ";
        cout<<endl;
    }
}