#include<bits/stdc++.h>
#define ll long long int

using namespace std;
ll bs(ll n,ll l,ll r,vector<ll> &v)
{

    ll mid=l+(r-l)/2;
    if(v[mid]<n && v[mid+1]>n)
    {

        return mid;
    }

    else if(v[mid]>n)
    {
        return bs(n,l,mid-1,v);

    }
    else if(v[mid]<n && v[mid+1]<n)
    {
        return bs(n,mid+1,r,v);

    }

return 0;
}






int main()
{
    vector<ll> v;
    map<ll,ll> mp;
    ll a[5]={2,4,6,8};
    ll p[10];
    p[0]=1;
    for(int i=1;i<10;i++)
    {
        p[i]=p[i-1]*10;

    }

    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    mp[0]=1;mp[2]=1;mp[4]=1;mp[6]=1;mp[8]=1;

    for(int i=1;i<10;i++)
    {
        ll len=v.size();
        for(int j=0;j<4;j++)
        {
            ll k=a[j]*p[i];
            v.push_back(k);
            mp[k]=1;
            for(int m=0;m<len;m++)
            {
                if(v[m]!=0)
                {
                v.push_back(k+v[m]);
                mp[k+v[m]]=1;
                }
            }

        }

    }

  int t;
  cin>>t;
  ll siz=v.size();
  for(int i=1;i<=t;i++)
 {
     ll n;
     cin>>n;
     if(mp[n]==1)
     {
         printf("Case #%d: 0\n",i);
         continue;
     }

     ll key=bs(n,0,siz-1,v);
     cout<<v[key]<<" "<<v[key+1]<<endl;
     ll ans;
     if(n-v[key]<v[key+1]-n)
     {
         ans=n-v[key];

     }
     else
     {

         ans=v[key+1]-n;
     }

     printf("Case #%d: %lld\n",i,ans);

 }

return 0;
}

