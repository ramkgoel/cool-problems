#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int n;
    string a,b,c;
    cin >> n;
    cin >> a>>b>>c; 

    bool cfail = false; 

    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            if(c[i] != a[i] && c[i] != b[i]){
                cfail = true; 
            }
        }
        else{
            if(c[i] != a[i]){
                cfail = true; 
            }
        }
    }

    if(cfail){
        cout << "YES" << endl; 
    }
    else{
        cout << "NO" << endl; 
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    
    while (t--)
        solve();
 
    return 0;
}