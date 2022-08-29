#include<bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 200020;
vector<int> adj[MAXN];
vector<int> sub(MAXN, 1);
void dfs(int s){
    for(int v: adj[s]){
        dfs(v);
        sub[s] += sub[v];
    }
}
int main(){
    cin>>n;
    for(int i = 1; i < n; i++){
        int a;
        cin>>a;
        a--;
        adj[a].push_back(i);
    }
    dfs(0);
    for(int i = 0; i < n; i++){
        cout<<sub[i]-1<<" ";
    }
    return 0;
}