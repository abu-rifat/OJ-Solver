#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ll t;
    cin>>t;
    ll n, k, m;
    while(t--)
    {
        cin>>n>>k>>m;
        m/=n;
        ll ct=0;
        while(m>=k){
            m/=k;
            ct++;
        }
        cout<<ct<<endl;
    }
 
    return 0;
}