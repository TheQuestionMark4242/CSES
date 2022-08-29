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
    int n, m;
    cin>>n>>m;
    multiset<int> s;
    int temp;
    rep(i, 0, n){
        cin>>temp;
        s.insert(temp);
    }
    rep(i, 0, m){
        cin>>temp;
        auto it = s.lower_bound(temp);
        if(*it == temp){
            cout<<temp;
            s.erase(it);
        }
        else if(it == s.begin()){
            cout<<-1;
        }
        else {
            advance(it, -1);
            cout<<*it;
            s.erase(it);
        }

        cout<<"\n";
    }
    return 0;
}