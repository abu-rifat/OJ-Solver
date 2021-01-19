/**      BU_Excalibur      **/
/** University of Barishal **/
/**  BFS  **/
 
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
constexpr ll MX=2000010;
bitset<MX>color;
vector<ll>edj[MX];
ll protection[MX];
 
void bfs(ll node, ll power) {
    queue<pair<ll,ll> >q;
    color[node]=true;
    q.push({node,power});
    while(!q.empty()) {
        node=q.front().first;
        power=q.front().second;
        q.pop();
        protection[node]++;
        if(power<=0)continue;
        ll siz=edj[node].size();
        for(ll i=0; i<siz; i++) {
            ll child=edj[node][i];
            if(color[child]==false) {
                color[child]=true;
                q.push({child,power-1});
            }
        }
    }
}
int main() {
 
    /***************************************/
    // Site Name        : SPOJ
    // Problem No/ID    : AKBAR
    /***************************************/
    // your code here   :
 
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll node,edge, guard;
    ll t;
    cin>>t;
    while(t--) {
        cin>>node>>edge>>guard;
        for(ll i=0; i<=node; i++) {
            edj[i].clear();
            protection[i]=0;
        }
        for(ll i=0; i<edge; i++) {
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        ll nowCity, power;
        for(ll i=0;i<guard;i++){
            cin>>nowCity>>power;
            color.reset();
            bfs(nowCity,power);
        }
        ll ck=0;
        for(ll i=1;i<=node;i++){
            if(protection[i]!=1){
                ck=1;
                break;
            }
        }
        if(ck)cout<<"No\n";
        else cout<<"Yes\n";
 
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************///
}