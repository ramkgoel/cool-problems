#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cmath>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

bool sortByFirst(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first; 
}

bool sortBySecond(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second; 
}

ll grid[2505][2505]; 
ll rgrid[2505][2505]; 

ll p[2505][2505]; 
ll rp[2505][2505]; 

void solve() {
    int N; 
    ll ans = 0; 
    cin>>N; 
    vector<pair<int,int> > points(N), rpoints(N); 
    for(int i=0; i<N; i++){
        int x,y;
        cin>>x>>y; 
        points[i] = make_pair(x, y); 
    }

    sort(points.begin(), points.end(), sortByFirst); 
    for(int i=1; i<N+1; i++){
        points[i-1].first = i; 
    }
    sort(points.begin(), points.end(), sortBySecond); 
    for(int i=1; i<N+1; i++){
        points[i-1].second = i; 
    }
    for(int i=0; i<N; i++){
        grid[points[i].first][points[i].second] = 1; 
        rgrid[N+1-points[i].first][points[i].second] = 1; 
        // rpoints[i] = make_pair(N+1-points[i].first, points[i].second); 
    }

    // cout << endl;
    // for(int i=0; i<N; i++){
    //     cout << points[i].first << " " << points[i].second << endl; 
    //     cout << rpoints[i].first << " " << rpoints[i].second << endl; 
    //     cout << endl; 
    // }

    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + grid[i][j]; 
            rp[i][j] = rp[i-1][j] + rp[i][j-1] - rp[i-1][j-1] + rgrid[i][j]; 
        }
    }

    // for(int i=0; i<N+1; i++){
    //     for(int j=0; j<N+1; j++){
    //         cout << grid[i][j] << " "; 
    //     }
    //     cout << endl; 
    // }

    // cout << endl; 

    // for(int i=0; i<N+1; i++){
    //     for(int j=0; j<N+1; j++){
    //         cout << rgrid[i][j] << " "; 
    //     }
    //     cout << endl; 
    // }

    // cout << endl;

    // for(int i=0; i<N+1; i++){
    //     for(int j=0; j<N+1; j++){
    //         cout << p[i][j] << " "; 
    //     }
    //     cout << endl; 
    // }

    // cout << endl; 

    // for(int i=0; i<N+1; i++){
    //     for(int j=0; j<N+1; j++){
    //         cout << rp[i][j] << " "; 
    //     }
    //     cout << endl; 
    // }

    sort(points.begin(), points.end(), sortByFirst); 

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(i==j){continue;}
            int a = points[i].first, b = points[i].second; 
            int c = points[j].first, d = points[j].second;
            ll add = 0; 
            
            if(b>d){
                add = p[a][b] * p[c][d]; 
                cout << "b>d" << p[a][b] << " " << p[c][d] << endl;
            }
            else{
                add = rp[N+1-a][b] * rp[N+1-c][d]; 
                cout << "b<d" << rp[N+1-a][b] << " " << rp[N+1-c][d] << endl;
            }

            ans += add; 
            
        }
    }

    cout << ans + (N+1); 



    


}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    solve(); 
 
    return 0;
}