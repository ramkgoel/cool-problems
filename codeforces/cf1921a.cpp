#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int x, y, minx=1000, miny=1000, maxx=-1000, maxy=-1000; 
    for(int i=0; i<4; i++){
        cin>>x>>y; 
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y); 
        maxy = max(maxy, y); 
    }
    int ans = (int)pow(maxx-minx, 2); 
    cout << ans << endl; 
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    
    while (t--)
        solve();
 
    return 0;
}