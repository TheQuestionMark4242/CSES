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
    int x, n;
    cin>>x>>n;
    set<int> s;
    multiset<int> m;
    s.insert(0);
    s.insert(x);
    int temp;
    m.insert(x);
    while(n--){
        cin>>temp;
        s.insert(temp);
        auto l = s.lower_bound(temp);
        l--;
        auto r = s.upper_bound(temp);
        m.erase(m.find(*r-*l));
        m.insert(temp-*l);
        m.insert(*r-temp);
        cout<<*m.rbegin()<<" ";
    
    }
    return 0;
}