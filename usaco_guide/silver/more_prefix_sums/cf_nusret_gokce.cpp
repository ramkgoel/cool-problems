#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cmath>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
 
void solve1() {
    // idea: do a right -> pass, where you only jack up small numbers so made just big enough. 
    // but you could have existing large numbers (ofc weren't jacked up). so essentially all deltas in [-m, infty]. 
    // idea: then do a backwards <- pass, so for the existing big numbers, jack up the small number before it. 
    // this will produce a working array. all decisions were forced: 
    //      - if a number did not need to be jacked up in an optimal solution, it didn't. 
    int n, m; 
    cin>>n>>m;
    vector<int> arr(n); 
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }

    for(int i=1; i<n; i++){
        arr[i] = max(arr[i], arr[i-1] - m); 
    }
    for(int i=n-2; i>=0; i--){
        arr[i] = max(arr[i], arr[i+1] - m);
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " "; 
    }
    
}

void solve() {
    // idea: the max never changes. start with the max. adj numbers are smaller, so we only need to jack up or do nothing.
    // jack up the adj numbers that need to be jacked up, and insert back into the priority queue (initially all (arr[i], i)) pairs.)
    // so by continually doing this, all jack-ups that need to happen do happen, starting with max. 
    // each number jacked up at most once. only jacked up if too small compared to neighbors, and once jacked up, the other neighbor isn't too big since it would've appeared before in pq, so don't need to jack up again ever. 

    int n, m; 
    cin>>n>>m;
    vector<int> arr(n); 
    priority_queue<pair<int,int> > pq; 

    for(int i=0; i<n; i++){
        cin>>arr[i]; 
        pq.push(make_pair(arr[i], i)); 
    }
    while(!pq.empty()){
        pair<int,int> top = pq.top(); 
        pq.pop();
        // cout << top.first << " " << top.second << endl; 
        int val = top.first, idx = top.second; 
        if(idx<n-1){
            if(arr[idx+1] < arr[idx] - m){
                arr[idx+1] = arr[idx] - m; 
                pq.push(make_pair(arr[idx+1], idx+1)); 
            }
        }
        if(idx>0){
            if(arr[idx-1] < arr[idx] - m){
                arr[idx-1] = arr[idx] - m; 
                pq.push(make_pair(arr[idx-1], idx-1)); 
            }
        }
    }


    for(int i=0; i<n; i++){
        cout << arr[i] << " "; 
    }
    
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    solve(); 
 
    return 0;
}