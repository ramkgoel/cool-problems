#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int n, m, hn, hm, xb, yb; 
    cin >> n >> m; 
    vector<vector<int> > a(n+2, vector<int>(m+2)); 
    

    for(int i=0; i<hn+1; i++){
        for(int j=0; j<hm+1; j++){
            if((i+j)%2==1){
                a[2*i][2*j] = 1;
                a[2*i][2*j+1] = 1;
                a[2*i+1][2*j] = 1;
                a[2*i+1][2*j+1] = 1;
            }
        }
    }

    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++){
            cout << a[i][j] << " "; 
        }
        cout << endl; 
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