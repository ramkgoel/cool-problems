#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cmath>
#include <map>

using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

bool compDec(int x, int y){
    return x > y;
}

bool compDecPairs(pair<int,int> x, pair<int,int> y){
    return x.first > y.first; 
}
 
void solve() {
    int N, M, R;
    cin>>N>>M>>R;
    vector<int> c(N), r(R); 
    vector<pair<int,int> > pq(M); 
    for(int i=0; i<N; i++){cin>>c[i];}
    for(int i=0; i<M; i++){
        int qi, pi;
        cin>>qi>>pi;
        pq[i] = make_pair(pi, qi);  
    }
    for(int i=0; i<R; i++){cin>>r[i];}

    sort(c.begin(), c.end(), compDec);
    sort(r.begin(), r.end(), compDec); 
    sort(pq.begin(), pq.end()); 



}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    solve(); 
 
    return 0;
}