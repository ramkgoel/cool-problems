#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve_dp() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){cin>>a[i];}

    ll dp = a[0];
    ll ans = a[0];
    for(int i=1; i<n; i++){
        dp = (dp > 0) ? (dp + a[i]) : a[i];
        ans = max(ans, dp); 
    }

    cout << ans << endl;
}

void solve_prefix_min() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){cin >> a[i];}

    vector<ll> prefix(n+1); // prefix[i] = sum a[0:i]
    for(int i=1; i<n+1; i++){
        prefix[i] = prefix[i-1] + a[i-1];
    }

    vector<ll> min_prefix(n+1); // min_prefix[i] = min p[0:i]
    for(int i=1; i<n+1; i++){
        min_prefix[i] = min(min_prefix[i-1], prefix[i-1]);
    }

    ll ans = a[0];
    for(int j=1; j<n+1; j++){
        ans = max(ans, prefix[j] - min_prefix[j]);
    }

    cout << ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    solve_prefix_min();
     
    return 0;
}