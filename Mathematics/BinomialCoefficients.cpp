#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int mod = 1000000007;

int factmod(int f){
    int i = 1;
    while(f-1){
        (i *= f)%=mod;
        f--;
    }
    return i;
}
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int modinv(int a){
    int x, y;
    int d = gcd(a, mod, x, y);
    ((x %= mod) += mod )%= mod;
    return x;
}
int binom(int n, int k){
    int b = factmod(n);
    ((b *= modinv(factmod(k))) += mod) %= mod;
    ((b *= modinv(factmod(n-k))) += mod) %= mod;
    return b;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<binom(a, b)<<"\n";
    }
    return 0;
}