#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define px second
#define py first
#define MAX 200001;
const ll INF=1e18;
#define pairll pair<long long,long long>
ll compare(pairll a, pairll b)
{ 
        return a.px<b.px; 
}
ll closest_pair(pairll pnts[],ll n)
{
        sort(pnts,pnts+n,compare);
        ll best=INF;
        set<pairll> box;
        box.insert(pnts[0]);
        ll left = 0;
        for (ll i=1;i<n;++i)
        {
            while (left<i && (pnts[i].px-pnts[left].px)*(pnts[i].px-pnts[left].px) > best)
                box.erase(pnts[left++]);
            for(typeof(box.begin()) it=box.lower_bound(make_pair(pnts[i].py-best, pnts[i].px-best));it!=box.end() && pnts[i].py+best>=it->py;it++)
                best = min(best, (pnts[i].py-it->py)*(pnts[i].py - it->py)+(pnts[i].px - it->px)*(pnts[i].px-it->px));
            box.insert(pnts[i]);
        }
        return best;
}
int main(){
    int n;cin>>n;
    pairll pnts[n];
    for(int i=0;i<n;i++){
        cin>>pnts[i].first>>pnts[i].second;
    }
}
