#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int fact(int k){
    int i = 1;
    for(int j = 1; j <= k; j++) i *= k;
    return i;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    string s;
    cin>>s;
    int t[26]{};
    for(char c: s) t[c-'a']++;
    sort(s.begin(), s.end());
    int a = fact(sz(s));
    for(int i )
    cout<<fact(sz(s))<<"\n";
    do{
        cout<<s<<"\n";
    } while(next_permutation(s.begin(), s.end()));
    return 0;
}