#include<bits/stdc++.h>
#define ll long long
const int MOD=1e9+7;
using namespace std;

int t, ans;
ll n;
ll uoc[10005], sl[10005];
int main(){
  cin >> t;
  while(t--){
    cin >> n;
    ll m=n;
    ans=0;
    ll mx = -1;
    if(m%2==0){
        ans++;
        while(m%2==0){
            m/=2;
            uoc[ans]=2;
            sl[ans]++;
            mx = max(mx,sl[ans]);
        }
    }

    for(int i=3; i<=sqrt(m); i+=2){
        if(m%i==0){
            ans++;
            ll dem=0;
            while(m%i==0) m/=i, dem++;
            uoc[ans]=i, sl[ans]=dem;
            mx = max(dem,mx);
        }
    }
    if(m!=1) uoc[++ans]=m, sl[ans]=1, mx = max(mx,sl[ans]);
    //cout<<ans<<'\n';
    for(int i=1; i<=ans; ++i)
        if(sl[i] == mx) {cout<<uoc[i]<<" "<<sl[i]<<'\n'; break;}
    for(int i=1; i<=ans; ++i) uoc[i]=0, sl[i]=0;
  }

return 0;
}