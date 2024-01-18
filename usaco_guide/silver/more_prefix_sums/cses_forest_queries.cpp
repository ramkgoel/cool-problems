#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve(){
    int n, q;
    string row; 
    cin >> n >> q;
    vector<vector<int> > a(n+1, vector<int>(n+1)), p(n+1, vector<int>(n+1));
    for(int i=1; i<n+1; i++){
        cin >> row; 
        for(int j=1; j<n+1; j++){
            a[i][j] = (row[j-1] == '*') ? 1 : 0; 
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j]; 
        }
    }

    int y1, x1, y2, x2;
    for(int i=0; i<q; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        cout << p[y2][x2] - p[y1-1][x2] - p[y2][x1-1] + p[y1-1][x1-1] << endl;  
    }
    
}

 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    solve(); 
     
    return 0;
}