#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    vector<int> a(n, 0);
    for(auto& i: a) cin>>i;
    bool flag = true;
    unordered_map<int, pair<int, int>> m;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(m.find(a[i]+a[j]) == m.end()) m[a[i]+a[j]] = {i, j};
        }
    }
    for(int i = 0; i < n; i++){
        if(m.find(x-a[i]) != m.end()){
            if(m[x-a[i]].first != i && m[x-a[i]].second != i){
                cout<<i<<" "<<m[x-a[i]].first<<" "<<m[x-a[i]].second;
                flag = true  ;
            }
        }
    }
    if(flag) cout<<"IMPOSSIBLE";
    return 0;
}