#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

class HashedString {
	private:
		// change M and P if you want
		static const long long M = 1e9 + 9;
		static const long long P = 9973;

		// pow[i] contains P^i % M
		static vector<long long> pow;

		// p_hash[i] is the hash of the first i characters of the given string
		vector<long long> p_hash;
	public:
		HashedString(const string& s) : p_hash(s.size() + 1) {
			while (pow.size() < s.size()) {
				pow.push_back((pow.back() * P) % M);
			}

			p_hash[0] = 0;
			for (int i = 0; i < s.size(); i++) {
				p_hash[i + 1] = ((p_hash[i] * P) % M + s[i]) % M;
			}
		}

		long long getHash(int start, int end) {
			long long raw_val = (
				p_hash[end + 1] - (p_hash[start] * pow[end - start + 1])
			);
			return (raw_val % M + M) % M;
		}
};
vector<long long> HashedString::pow = {1};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    string s;
    cin>>s;
    int n = sz(s);
    HashedString h(s);
    for(int i = 0; i < n; i++){
        if(h.getHash(0, i) == h.getHash(n-i-1, n-1)){
            if()
        }
    }
}