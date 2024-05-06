//centroid decomposition
//solved problem: Xenia and Tree
#include<bits/stdc++.h>
using namespace std;
const int N=100050,lg=18;
int timer=0,sz[N],parent[N][lg],centroid_parent[N],In[N],out[N],level[N],vis[N],best_dist[N];
vector<int>edges[N];
void dfs(int source,int P){
    level[source]=level[P]+1;
    parent[source][0]=P;
    In[source]=timer++;
    for(int i=1;i<lg;i++){
        parent[source][i]=parent[parent[source][i-1]][i-1];
    }
    for(int x:edges[source]){
        if(x!=P){
            dfs(x,source);
        }
    }
    out[source]=timer++;
}
bool is(int A,int B){return In[A]<=In[B] && out[A]>=out[B];}
int lca(int A,int B){
    if(is(A,B))return A;
    if(is(B,A))return B;
    for(int i=lg-1;i>=0;i--){
        if(!is(parent[A][i],B)){
            A=parent[A][i];
        }
    }
    return parent[A][0];
}
int dist(int A,int B){
    return level[A]+level[B]-2*level[lca(A,B)];
}
void szdfs(int source,int P=-1){
    if(vis[source])return;
    sz[source]=1;
    for(int x:edges[source]){
        if(x!=P and !vis[x]){
            szdfs(x,source);
            sz[source]+=sz[x];
        }
    }
}
int find_centroid(int source,int p,int SZ){
    for(int x:edges[source]){
        if(x!=p && !vis[x] && sz[x]>(SZ>>1)){
            return find_centroid(x,source,SZ);
        }
    }
    return source;
}
void centroid_initialzation(int source,int P=-1){
    szdfs(source);
    int centoird=find_centroid(source,-1,sz[source]);
    vis[centoird]=true;centroid_parent[centoird]=P;
    for(int x:edges[centoird]){
        if(!vis[x])centroid_initialzation(x,centoird);
    }
}
void upd(int V){
    best_dist[V]=0;
    int U=V;
    while(centroid_parent[U]!=-1){
        U=centroid_parent[U];
        best_dist[U]=min(best_dist[U],dist(U,V));
    }
}
int Qry(int V){
    int ans=best_dist[V];
    int U=V;
    while(centroid_parent[U]!=-1){
        U=centroid_parent[U];
        ans=min(ans,best_dist[U]+dist(U,V));
    }
    return ans;
}
int main(){
    int X,Y,n,Q;cin>>n>>Q;
    for(int i=1;i<n;i++){
        best_dist[i]=N;
        cin>>X>>Y;
        edges[X].push_back(Y);edges[Y].push_back(X);
    }
    best_dist[n]=N;
    dfs(1,1);
    centroid_initialzation(1);
    upd(1);
    while(Q--){
        int choice,v;cin>>choice>>v;
        if(choice==1){
            upd(v);
        }else{
            cout<<Qry(v)<<endl;
        }
    }
}
