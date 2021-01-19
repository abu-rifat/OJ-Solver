/**      BU_Excalibur      **/
/** University of Barishal **/
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
constexpr ll MOD = 1e7+7;
 
ll binpow(ll base, ll pow, ll mod)
{
    base%=mod;
    //if mod is prime, pow%=(mod-1);
    ll res=1;
    while(pow>0){
        if(pow&1)res=(res*base)%mod;
        base=(base*base)%mod;
        pow>>=1;
    }
    return res;
}
 
ll bigMul(ll a, ll b, ll mod)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)ans=(ans+(b&mod))&mod;
    return ans;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, k;
    while(cin>>n){
        cin>>k;
        if(n==0&&k==0)break;
        ll ans1=binpow(n-1,k,MOD);
        ans1=(2*ans1)%MOD;
        ll ans2=binpow(n,k,MOD);
        ll ans3=binpow(n-1,n-1,MOD);
        ans3=(2*ans3)%MOD;
        ll ans4=binpow(n,n,MOD);
        ll ans=(ans1+ans2+ans3+ans4)%MOD;
        cout<<ans<<"\n";
    }
    return 0;
}