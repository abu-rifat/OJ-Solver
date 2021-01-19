#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 250009
 
ll arr[MX];
vector<ll>Rep;
vector<ll>pos[MX];
map<ll,ll>id;
ll P[MX][22];
ll LG[MX];
map<ll,ll>m;
 
 
void prep(ll n)
{
    LG[0]=0;
    for(ll i=2; i<=n; i++)
    {
        LG[i]=LG[i/2]+1;
    }
    for(ll i=0; i<n; i++)
    {
        P[i][0]=arr[i];
    }
    for(ll j=1; j<=22; j++)
    {
        for(ll i=0; (i+(1<<j))<=n; i++)
        {
            P[i][j]=min(P[i][j-1],P[i+(1<<(j-1))][j-1]);
        }
    }
}
 
ll Query(ll L, ll R)
{
    if(L>R)
        swap(L,R);
    ll j=LG[R-L+1];
    ll minn=min(P[L][j], P[R-(1<<j)+1][j]);
    return minn;
}
 
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    ll ans=n;
    ll idx=1;
    for(ll i=0; i<n; i++)
    {
        ll tmp;
        cin>>tmp>>arr[i];
        if(!id[arr[i]])
        {
            id[arr[i]]=idx;
            idx++;
        }
        if(m[arr[i]]==1)
            Rep.push_back(arr[i]);
        m[arr[i]]++;
        pos[id[arr[i]]].push_back(i);
    }
    prep(n);
    sort(Rep.begin(),Rep.end());
    ll len=Rep.size();
    for(ll i=0; i<len; i++)
    {
        ll idxx=id[Rep[i]];
        ll lj=pos[idxx].size();
        for(ll j=0; j<lj-1; j++)
        {
            ll minn=Query(pos[idxx][j],pos[idxx][j+1]);
            if(minn>=Rep[i])
            {
                ans--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}