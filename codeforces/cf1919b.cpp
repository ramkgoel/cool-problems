#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int n, ans=0; 
    char c;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>c;
        if(c=='+') ans++; 
        else ans--; 
    }
    cout << abs(ans) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    
    while (t--)
        solve();
 
    return 0;
}