#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    map<int, int> dict; 
    for(int i=0; i<n; i++){
        cin >> a[i]; 
        dict[a[i]] += 1;
    }
    
    vector<int> nums;
    for (const auto& pair : dict) {
        nums.push_back(pair.second);
    }

    int k = nums.size();
    vector<ll> prefix(k); 
    prefix[0] = nums[0]; 
    for(int i=1; i<k; i++){
        prefix[i] = prefix[i-1] + nums[i]; 
    }

    ll ans = 0;
    for(int i=1; i<k; i++){
        ans += (nums[i] * (nums[i]-1))/2 * prefix[i-1];
    }

    for(int i=0; i<k; i++){
        ans += (nums[i] * (nums[i]-1) * (nums[i]-2))/6;
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
// 11
// 1 1 2 2 3 3 3 4 4 5 6