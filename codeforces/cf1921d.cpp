#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(m); 
    for(int i=0; i<n; i++){
        cin >> a[i]; 
    }
    for(int i=0; i<m; i++){
        cin >> b[i]; 
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end()); 

    int al=0, ar=n-1, bl=0, br=m-1;
    ll ans = 0; 
    while(al <= ar){
        // al,br and ar,bl are only 2 potential largest
        int diff1 = abs(a[al] - b[br]), diff2 = abs(a[ar] - b[bl]); 
        if(diff1 >= diff2){
            ans += diff1; 
            al++; 
            br--; 
        }
        else{
            ans += diff2;
            ar--;
            bl++; 
        }
    }
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

// 1
// 4 6
// 6 1 2 4
// 3 5 1 7 2 3