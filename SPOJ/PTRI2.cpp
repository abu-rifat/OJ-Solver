#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll MX=1e8;
 
bitset<100000009>bs;
vector<ll>primes;
 
void sieve(ll ub)
{
    ub++;
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4;i<=ub;i+=2)bs[i]=0;
    for(ll i=3;i<=ub;i+=2){
        if(bs[i]){
            for(ll j=i*i;j<=ub;j+=i)bs[j]=0;
            primes.push_back(i);
        }
    }
}
 
vector<ll>piramid;
 
void buildP()
{
    ll len=primes.size();
    piramid.push_back(0);
    for(ll i=1;piramid[i-1]<len;i++){
        piramid.push_back(piramid[i-1]+i);
    }
}
 
int main()
{
    sieve(MX);
    buildP();
    ll t;
    cin>>t;
    ll n;
    while(t--){
        cin>>n;
        if(bs[n]){
            ll idx=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
            ll row=upper_bound(piramid.begin(),piramid.end(),idx)-piramid.begin();
            if(idx==piramid[row-1])row--;
            ll col=idx-piramid[row-1];
            cout<<row<<" "<<col<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}