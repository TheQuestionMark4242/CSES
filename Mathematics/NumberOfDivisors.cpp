#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll div(ll x){
    ll res = 1;
    for(int i = 2; i*i <= x; i++){
        ll pow = 0;
        while(x%i == 0){
            pow++;
            x /= i;
        }
        res *= (pow+1);
    }
    if(x != 1) res *= 2;  
    return res;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        cout<<div(x)<<"\n";
    }
}