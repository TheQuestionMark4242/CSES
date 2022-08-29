#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct DSU{
    int n;
    vector<int> e; //Stores -sizeof(component) for representative elements and repr(x) o/w
    int comp;
    int ms;
    DSU(int n): n(n), e(vector<int>(n, -1)), comp(n), ms(1) {};

    int repr(int x){
        if(e[x] < 0){
            return x;
        }
        return e[x] = repr(e[x]); // Path Compression which forces time complexity to go down to  log*(n)
    }

    bool same_set(int x, int y){
        return repr(x) == repr(y);
    }

    int size(int x){
        return -e[repr(x)];
    }

    void unite(int x, int y){
        x = repr(x); y = repr(y);
        if(x == y) return;
        if(-e[x] < -e[y]) swap(x, y);
        e[x] += e[y];
        ms = max(ms, -e[x]);
        comp--;
        e[y] = x;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    int m;
    cin>>n>>m;
    DSU d(n);
    while(m--){
        int a, b;
        cin>>a>>b;
        a--; b--;
        d.unite(a, b);
        cout<<d.comp<<" "<< d.ms<<"\n";
    }
    return 0;
}