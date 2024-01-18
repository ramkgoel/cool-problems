#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int n; 
    cin >> n; 
    vector<int> b(n);
    for(int i = 0; i<n; i++)
        cin >> b[i];

    vector<int> max_pref(n+1); // max_pref[i] = max b[l]+l in 0..i
    vector<int> max_suff(n+1); // max_suff[i] = max b[r]-r in i..n-1

    max_pref[0] = b[0]+0;
    for(int i=1; i<n; i++){
        max_pref[i] = max(max_pref[i-1], b[i]+i);
    }

    max_suff[n-1] = b[n-1]-(n-1);
    for(int i=n-2; i>=0; i--){
        max_suff[i] = max(max_suff[i+1], b[i]-i);
    }

    int ans = 0;
    for(int i=1; i<n-1; i++){
        ans = max(ans, max_pref[i-1] + b[i] + max_suff[i+1]);
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