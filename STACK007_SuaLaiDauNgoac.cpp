#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a; i<=b; ++i)
#define fn(i,a,b) for(int i=a; i>=b; --i)
using namespace std;

int tc, z, ans;
string s;
int main()
{
  cin >> tc;
  while(tc--){
    cin >> s;
    ans=0, z=0;
    f(i,0,s.length()-1){
      if(s[i]=='(') z++;
      else{
        if(z==0) ans++, z++;
        else z--;
      }
    }
    ans+=z/2;
    cout<<ans<<'\n';
  }
return 0;
}