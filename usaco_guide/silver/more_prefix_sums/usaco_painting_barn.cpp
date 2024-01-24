#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

int prefix_d[1005][1005]; 
int prefix[1005][1005]; //prefix[i][j] = sum of {0..i}x{0..j}
int my_prefix[1005][1005]; 



void solve() {
    int n, k;
    cin >> n >> k;
    int x1, y1, x2, y2, max_coord=0, ans = 0; 
    for(int i=0; i<n; i++){
        cin>>x1>>y1>>x2>>y2; 
        x2--; 
        y2--;
        max_coord = max({max_coord, x1, y1, x2, y2}); 
        prefix_d[x1][y1]++; 
        prefix_d[x1][y2+1]--; 
        prefix_d[x2+1][y1]--; 
        prefix_d[x2+1][y2+1]++; 
    }

    // cout << prefix[-1][5] << endl;
    // cout << prefix[5][-1] << endl;
    
    int my_ans=0; 
    for(int i=0; i<max_coord+1; i++){
        for(int j=0; j<max_coord+1; j++){
            my_prefix[i][j] = my_prefix[i-1][j] + my_prefix[i][j-1] - my_prefix[i-1][j-1] + prefix_d[i][j];
            
            if(i) prefix[i][j] += prefix[i-1][j];
            if(j) prefix[i][j] += prefix[i][j-1];
            if(i&&j) prefix[i][j] -= prefix[i-1][j-1]; 
            prefix[i][j] += prefix_d[i][j];

            // if(my_prefix[i][j] != prefix[i][j]){
            //     if(i<17 && j<225){
            //         cout << "contradiction " << i << " " << j << endl;
            //         cout << my_prefix[i][j] << " " << prefix[i][j] << endl;
            //         cout << my_prefix[i-1][j] << my_prefix[i][j-1] << my_prefix[i-1][j-1] << prefix_d[i][j] << endl;
            //         cout << prefix[i-1][j] << prefix[i][j-1] << prefix[i-1][j-1] << prefix_d[i][j] << endl;
            //     }
                    
            // }
            
            if(my_prefix[i][j] == k) my_ans++;
            if(prefix[i][j] == k) ans++;
        }
    }

    cout << ans << endl;
    cout << my_ans << endl; 


}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
 
    solve(); 
 
    return 0;
}