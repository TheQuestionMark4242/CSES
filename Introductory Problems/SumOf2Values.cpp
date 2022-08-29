#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n, x;
    cin>>n>>x;
    vi v(n, 0); 
    map<int, int> m;
    bool isImpossible = true;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(m.find(x-v[i]) != m.end()){
            cout<<m[x-v[i]]+1<<" "<<i+1;
            isImpossible = false;
            break;
        }
        m[v[i]] = i;
    }
    if(isImpossible) cout<<"IMPOSSIBLE";
    return 0;
}