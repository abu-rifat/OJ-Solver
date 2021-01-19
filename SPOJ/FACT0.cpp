#include<bits/stdc++.h>
using namespace std;
//typedef unsigned long long ll;
using ll = uint64_t;
 
ll ckArr[]= {2,3,5,7,11,13,17,19,23,29,31,37};
 
constexpr ll MX=1e6;
 
bitset<1000009>bs;
vector<ll>primes;
set<ll>fact;
unordered_map<ll,ll>factCt;
 
void inis()
{
    fact.clear();
    factCt.clear();
}
 
inline ll bigMul(ll a, ll b, ll mod) {
    if(a==0)
        return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)
        ans=(ans+(b%mod))%mod;
    return ans;
}
 
inline ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    // If mod is prime, power=power%(mod-1);
    ll result=1;
    while(power>0){
        if(power&1)result=bigMul(result,base,mod);
        base=bigMul(base,base,mod);
        power>>=1;
    }
    return result;
}
 
inline bool ckComposite(ll n, ll a, ll d, ll s) {
    ll x=binpow(a, d, n);
    if(x==1||x==n-1)
        return false;
    for(ll r=1;r<s;r++){
        x=bigMul(x,x,n);
        if(x==n-1)
            return false;
    }
    return true;
};
 
bool MillerRabin(ll n) {
    if(n<2)
        return false;
    ll r=0;
    ll d=n-1;
    while((d&1)==0) {
        d>>=1;
        r++;
    }
    for (int a : ckArr) {
        if(n==a)
            return true;
        if(ckComposite(n, a, d, r))
            return false;
    }
    return true;
}
 
void sieve(ll ub) {
    ub++;
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4; i<=ub; i+=2)
        bs[i]=0;
    for(ll i=3; i<=ub; i+=2) {
        if(bs[i]) {
            for(ll j=i*i; j<=ub; j+=i)
                bs[j]=0;
            primes.push_back(i);
        }
    }
}
 
void TrialDiv(ll n) {
    if(n<=MX){
        if(bs[n]){
            factCt[n]++;
            fact.insert(n);
            return;
        }
    }
    for (auto d:primes) {
        if(d*d>n)
            break;
        while(n%d==0) {
            factCt[d]++;
            fact.insert(d);
            n/=d;
        }
    }
    if(n>1) {
        factCt[n]++;
        fact.insert(n);
    }
}
 
inline ll f(ll x, ll c, ll mod) {
    return (bigMul(x, x, mod) + c) % mod;
}
 
ll brent(ll n, ll x0=1, ll c=7) {
    ll x=x0;
    ll g=1;
    ll q=1;
    ll xs, y;
 
    ll m=128;
    ll l=1;
    while(g==1) {
        y=x;
        for(ll i=1; i<l; i++)
            x=f(x,c,n);
        ll k=0;
        while(k<l&&g==1) {
            xs=x;
            for(ll i=0; i<m&&i<l-k; i++) {
                x=f(x,c,n);
                ll dif=(y>x)?(y-x):(x-y);
                q=bigMul(q,dif,n);
            }
            g=__gcd(q,n);
            k+=m;
        }
        l*=2;
    }
    if(g==n) {
        do {
            xs=f(xs,c,n);
            ll dif=(xs>y)?(xs-y):(y-xs);
            g=__gcd(dif,n);
        } while(g==1);
    }
    return g;
}
 
 
int main() {
    sieve(MX);
    ll n;
    while(cin>>n) {
        if(n==0)
            break;
        inis();
        if(MillerRabin(n)){
            cout<<n<<"^1\n";
            continue;
        }
        while(n>1) {
            ll tmp=brent(n);
            TrialDiv(tmp);
            n/=tmp;
            if(MillerRabin(n)){
                factCt[n]++;
                fact.insert(n);
                break;
            }
        }
        bool t=false;
        for(auto u:fact) {
            if(t)
                cout<<" ";
            else
                t=true;
            cout<<u<<"^"<<factCt[u];
        }
        cout<<"\n";
    }
    return 0;
}