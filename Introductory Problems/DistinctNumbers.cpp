#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    long long int N;
    cin>>N;
    set<long long int> s;
    long long int temp;
    while(N--){
        cin>>temp;
        s.insert(temp);
    } 
    cout<<(long long int) s.size();
    return 0;
}