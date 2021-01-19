#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct sfx {
    ll idx;
    ll rk[2];
};
 
ll cmp(struct sfx a, struct sfx b) {
    return  (a.rk[0]==b.rk[0])?
            (a.rk[1]<b.rk[1]?1:0):
            (a.rk[0]<b.rk[0]?1:0);
}
 
vector<ll> buildSuffixArray(string s, ll n) {
    struct sfx suff[n];
    for(ll i=0; i<n; i++) {
        suff[i].idx=i;
        suff[i].rk[0]=s[i];
        suff[i].rk[1]=((i+1)<n)?(s[i+1]):-1;
    }
    sort(suff,suff+n,cmp);
    ll ind[n];
 
    for(ll k=4; k<2*n; k=k*2) {
        ll rk =0;
        ll p_rk=suff[0].rk[0];
        suff[0].rk[0]=rk;
        ind[suff[0].idx]=0;
        for(ll i=1; i<n; i++) {
            if((suff[i].rk[0]==p_rk)&&(suff[i].rk[1]==suff[i-1].rk[1])) {
                p_rk=suff[i].rk[0];
                suff[i].rk[0]=rk;
            } else {
                p_rk=suff[i].rk[0];
                suff[i].rk[0]= ++rk;
            }
            ind[suff[i].idx]=i;
        }
        for(ll i=0; i<n; i++) {
            ll nxt_idx=suff[i].idx+ k/2;
            suff[i].rk[1]=(nxt_idx<n)?suff[ind[nxt_idx]].rk[0] : -1;
        }
        sort(suff,suff+n,cmp);
    }
    vector<ll>suffArr;
    for(ll i=0; i<n; i++)
        suffArr.push_back(suff[i].idx);
    return suffArr;
}
 
 
vector<ll> kasai(string s, vector<ll>suffArr) {
    ll n=suffArr.size();
    vector<ll>lcp(n,0);
    vector<ll>invSuff(n,0);
    for(ll i=0; i<n; i++)
        invSuff[suffArr[i]]=i;
    ll k=0;
    for(ll i=0; i<n; i++) {
        if(invSuff[i]==n-1) {
            k=0;
            continue;
        }
        ll j = suffArr[invSuff[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k])
            k++;
        lcp[invSuff[i]]=k;
        if(k>0)
            k--;
    }
    return lcp;
}
 
ll countDistinctSubstring(string s) {
    ll n=s.size();
    vector<ll>suffArr=buildSuffixArray(s,n);
    vector<ll>lcp=kasai(s,suffArr);
    ll result=n-suffArr[0];
    for(ll i=1; i<lcp.size(); i++) {
        result+=(n-suffArr[i])-lcp[i-1];
    }
 
    //result++; //For empty string
    return result;
}
 
int main() {
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<countDistinctSubstring(s)<<endl;
    }
    return 0;
}