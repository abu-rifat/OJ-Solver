#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bp(ll b,ll p,ll m){
    b%=m;ll r=1;
    while(p>0){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}
    return r;
}
int main(){
    ll t;cin>>t;ll a,b;
    while(t--){cin>>a>>b;ll o=bp(a,b,10);cout<<o<<"\n";}
    return 0;
}