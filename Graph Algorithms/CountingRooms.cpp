#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int n, m;
int a[MAXN][MAXN];
bool visited[MAXN][MAXN];
int rooms = 0;
void floodfill(int r, int c, int color){
    if(
        r < 0 || r > n ||
        c < 0 || c > m ||
        a[r][c] != color ||
        visited[r][c]
    ) return;
    visited[r][c] = true;
    floodfill(r-1, c, color);
    floodfill(r+1, c, color);
    floodfill(r, c-1, color);
    floodfill(r, c+1, color);
}
int main(){
    cin>>n>>m;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            char temp;
            cin>>temp;
            a[r][c] = ((temp == '#')? 0: 1);
        }
    }
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(!visited[r][c] && a[r][c] == 1){
                floodfill(r, c, 1);
                rooms++;
            }
        }
    }
    cout<<rooms;
    return 0;
}