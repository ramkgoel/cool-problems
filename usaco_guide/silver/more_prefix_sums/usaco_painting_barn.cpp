#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

int prefix_d[1005][1005]; 
int prefix[1005][1005]; //prefix[i][j] = sum of {0..i}x{0..j}
 
void solve() {
    int n, k;
    cin >> n >> k;
    int x1, y1, x2, y2, max_coord=0, ans = 0; 
    for(int i=0; i<n; i++){
        cin>>x1>>y1>>x2>>y2; 
        max_coord = max({max_coord, x1, y1, x2, y2}); 
        prefix_d[x1][y1] += 1; 
        prefix_d[x1][y2+1] -= 1; 
        prefix_d[x2+1][y1] -= 1; 
        prefix_d[x2+1][y2+1] += 1; 
    }
    
    for(int i=0; i<max_coord+1; i++){
        for(int j=0; j<max_coord+1; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + prefix_d[i][j];
            if(prefix[i][j] == k){
                ans += 1;
            }
        }
    }

    cout << ans; 


}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    solve(); 
 
    return 0;
}