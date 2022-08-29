#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1000;
const int a[] = {-1, 0, 1};
int n, m;
char M[MAXN][MAXN];
bool visited[MAXN][MAXN]{};
int dist[MAXN][MAXN]{};
pii parent[MAXN][MAXN];

void bfs(pii start, pii end){
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;
    parent[start.first][start.second] = {-1, -1};
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        for(auto x: a){
            for(auto y: a){
                if(
                    u.first + x < 0  || u.first + x > n-1 ||
                    u.second + y < 0 || u.second + y > m-1 
                ) continue;
                if(M[u.first + x][u.second + y] == '#') continue;
                if(!visited[u.first + x][u.second + y]){
                    visited[u.first + x][u.second + y] = true;
                    dist[u.first + x][u.second + y] = dist[u.first + x][u.second + y]+1;
                    parent[u.first + x][u.second + y] = parent[u.first][u.second];  
                    q.push({u.first + x, u.second + y});
                }
            }
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin>>n>>m;
    pii start, end;
    rep(i, 0, n){
        rep(j, 0, m){
            cin>>M[i][j];
            if(M[i][j] == 'A') start = {i, j};
            if(M[i][j] == 'B') end = {i, j};
        }
    }
    if(visited[end.first][end.second]){
        cout<<"YES\n";
        cout<<dist[end.first][end.second]<<"\n";

    }
    return 0;
}