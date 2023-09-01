#include<bits/stdc++.h>
#include <cmath>
#include <utility>
using namespace std;
struct kd{
    struct node{
        array<int,2>P;
        node *L,*R;
        node(){
            P[0]=-1;
            P[1]=-1;
            L=NULL;
            R=NULL;
        }
        node(int x,int y){
            P[0]=x;
            P[1]=y;
        }
    };node* root;
    kd(){
        root=NULL;
    }
    void insert(int _x,int _y){
        root=insrt(root,{_x,_y},0);
    }
    pair<int,int> nearest(int _x,int _y){
        node* ans=NN(root,{_x,_y},0);
        return make_pair(ans->P[0],ans->P[1]);
    }
    node* newnode(array<int,2>point){
        node* temp=new node;
        temp->P[0]=point[0];
        temp->P[1]=point[1];
        temp->L=temp->R=nullptr;
        return temp;
    }
    node* insrt(node *root,array<int,2>point,int depth){
        if(root==NULL)return newnode({point[0],point[1]});
        int cd=depth%2;
        if(point[cd]<root->P[cd]){
            root->L=insrt(root->L,point,depth+1);
        }else{
            root->R=insrt(root->R,point,depth+1);
        }
        return root;
    }
    double dist(array<int,2>a,node* B){
        if(B==NULL){
            return (double)(1<<20);
        }
        int c=(a[0]-B->P[0]);
        int d=(a[1]-B->P[1]);
        return sqrt(c*c+d*d);
    }
    node* closest(array<int,2>a,node* b,node* c){
        if(b==NULL and c==NULL){
            return NULL;
        }
        if(b==NULL and c!=NULL){
            return c;
        }
        if(c==NULL and b!=NULL){
            return b;
        }
        if(dist(a,b)<=dist(a,c)){
            return b;
        }else{
            return c;
        }
    }
    node* NN(node *root,array<int,2>point,int depth){
        if(root==NULL)return NULL; 
        int cd=depth%2;
        node *nextB;
        node *otherB; 
        node* temp;
        node* best;
        if(point[cd]<root->P[cd]){
            nextB=root->L;
            otherB=root->R;
        }else{
            nextB=root->R;
            otherB=root->L;
        }
        double D=(double)(1<<20);
        temp=NN(nextB,point,depth+1);
        best=closest(point,temp,root);
        D=dist(point,best);
        double R=(double)abs(point[cd]-root->P[cd]);
        if(D>=R){
            temp=NN(otherB,point,depth+1);
            best=closest(point,temp,best);
        }
        return best;
    }
    double ndist(int _x,int _y){
        node* ans=NN(root,{_x,_y},0);
        return dist({_x,_y},ans);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,k;
    cin>>k;
    kd tree;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        tree.insert(a,b);
    }
    int x,y;cin>>x>>y;
    auto it=tree.nearest(x,y);
    auto dist=tree.ndist(x,y);
    cout<<it.first<<": "<<it.second<<endl;
    cout<<dist<<endl;
}
