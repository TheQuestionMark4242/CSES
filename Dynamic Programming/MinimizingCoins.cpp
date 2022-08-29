#include<bits/stdc++.h>
using namespace std;
int mc[1000010];
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> coins(n, 0);
    for(auto &c: coins) cin>>c;
    mc[0] = 0;
    for(int i = 1; i <= x; i++){
        mc[i] = INT_MAX-1;
        for(auto &c: coins) mc[i] = min(mc[i], ((i-c >= 0)?(mc[i-c]+1): INT_MAX));
    }
    if(mc[x] != INT_MAX-1) cout<<mc[x];
    else cout<<-1;
    return 0;
}