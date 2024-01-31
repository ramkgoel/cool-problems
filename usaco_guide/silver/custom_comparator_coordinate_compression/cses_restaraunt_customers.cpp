#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cmath>
#include <map>

using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int n,a,b;
    cin >> n;
    vector<pair<int,int> > queries; 
    vector<int> indices; 
    for(int i=0; i<n; i++){
        cin>>a>>b;
        queries.push_back({a,b}); 
        indices.push_back(a); 
        indices.push_back(b); 
    }
    sort(indices.begin(), indices.end()); 
    int k = indices.size(); 
    map<int,int> idx; 
    for(int i=0; i<k; i++){
        idx[indices[i]] = i; 
    }
    vector<int> delta(k), nums(k); 
    for(int i=0; i<n; i++){
        a = queries[i].first; 
        b = queries[i].second; 
        delta[idx[a]]++; 
        delta[idx[b]]--; 
    }
    nums[0] = delta[0]; 
    int ans = 0; 
    for(int i=1; i<k; i++){
        nums[i] = nums[i-1] + delta[i];
        ans = max(ans, nums[i]); 
    }
    cout << ans << endl;

}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    solve();
 
    return 0;
}