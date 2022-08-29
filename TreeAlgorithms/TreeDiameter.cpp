#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+20;
int n;
vector<int> adj[MAXN];
int toLeaf[MAXN];
int maxLength[MAXN];
int dis;
int e;
void dfs(int s, int p, int depth){
    for(int v: adj[s]){
        if(v==p) continue;
        dfs(v, s, depth+1);
    }
    if(depth > dis){
        dis = depth;
        e = s;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dis = 0;
    dfs(0, -1, 0);
    dis = 0;
    dfs(e, -1, 0);
    cout<<dis;
    return 0;
}