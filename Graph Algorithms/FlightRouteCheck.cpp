#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, m;
vector<int> adj1[MAXN];
vector<int> adj2[MAXN];
bool v1[MAXN]{};
bool v2[MAXN]{};
void dfs1(int start){
    v1[start] = true;
    for(int v: adj1[start]){
        if(!v1[v]) dfs1(v); 
    }
}
void dfs2(int start){
    v2[start] = true;
    for(int v: adj2[start]){
        if(!v2[v]) dfs2(v); 
    }
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        a--;b--;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    dfs1(0);
    dfs2(0);
    bool flag = true;
    pair<int, int> c;
    for(int i = 0; i < n; i++){
        flag &=(v1[i]&v2[i]);
        if(v1[i] == false) c = {1, i+1};
        if(v2[i] == false) c = {i+1, 1};
    }
    if(flag) cout<<"YES";
    else{
        cout<<"NO"<<"\n"<<c.first<<" "<<c.second;
    }
    return 0;
}