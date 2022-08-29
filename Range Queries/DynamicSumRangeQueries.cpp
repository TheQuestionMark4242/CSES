#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5 + 5;
int segTree[4*MAX];

void buildTree(int s, int e, int idx) {
	if(s == e) { segTree[idx] = A[s]; return; }

	int mid = (s + e) >> 1;
	buildTree(s, mid, 2*idx+1);
	buildTree(mid+1, e, 2*idx+2);

	segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
}

int query(int s, int e, int idx, int l, int r) {
	if(r < s || e < l || r < l) { return 0; }
	else if(s >= l && e <= r) { return segTree[idx]; }

	int mid = (s + e) >> 1;
	return query(s, mid, 2*idx+1, l, r) + query(mid+1, e, 2*idx+2, l, r);
}

void update(int s, int e, int idx, int pnt, int val) {
	if(s == e) { segTree[idx] = val; return; }

	int mid = (s + e) >> 1;
	if(pnt <= mid) {
		update(s, mid, 2*idx+1, pnt, val);
	}
	else {
		update(mid+1, e, 2*idx+2, pnt, val);
	}

	segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int T;
	cin>>T;
	while(T--){
		
	}
	return 0;
}