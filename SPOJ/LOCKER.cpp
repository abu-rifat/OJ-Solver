/**      BU_Excalibur      **/
/** University of Barishal **/
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1e9+7;
 
ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    power=power%(mod-1);
    ll result=1;
    while(power>0){
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}
 
ll bigMul(ll a, ll b, ll mod)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)ans=(ans+(b%mod))%mod;
    return ans;
}
 
int main()
{
    /***************************************/
    // Site Name        : SPOJ
    // Problem No/ID    : LOCKER
    /***************************************/
    // your code here   :
    ll t;
    cin>>t;
    ll n;
    while(t--){
        ll ans=1;
        cin>>n;
        if(n<=4){
            cout<<n<<"\n";
            continue;
        }
 
        if(n%3==1){
            ans=4;
            n-=4;
        }else if(n%3==2){
            ans=2;
            n-=2;
        }
        ll pow=n/3;
        ans=(ans*binpow(3,pow,MOD))%MOD;
        cout<<ans<<"\n";
    }
 
    return 0;
}