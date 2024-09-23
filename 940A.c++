// ACCEPTED
// A. Points on the line
// time limit per test1 second
// memory limit per test256 megabytes
// We've got no test cases. A big olympiad is coming up. But the problemsetters' number one priority should be adding another problem to the round.

// The diameter of a multiset of points on the line is the largest distance between two points from this set. For example, the diameter of the multiset {1, 3, 2, 1} is 2.

// Diameter of multiset consisting of one point is 0.

// You are given n points on the line. What is the minimum number of points you have to remove, so that the diameter of the multiset of the remaining points will not exceed d?

// Input
// The first line contains two integers n and d (1 ≤ n ≤ 100, 0 ≤ d ≤ 100) — the amount of points and the maximum allowed diameter respectively.

// The second line contains n space separated integers (1 ≤ xi ≤ 100) — the coordinates of the points.

// Output
// Output a single integer — the minimum number of points you have to remove.

#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
using namespace std;

int main() {
    int n,d;
    cin >> n>>d;
    vector<int> a(n);

    for(int i = 0; i<n;i++ ){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int left = 0 ; 
    int mx = 0;
    int cur = 0;
    
    for(int  i = left; i<n; i++){
        if(a[i]-a[left]<=d){
       
        }else{
            while(a[i]-a[left]>d){
                left++;
            }
        }
        cur = i - left + 1;
        
        mx = max(mx,cur);
    }
    cout<< n-mx<<endl;

    return 0 ; 
}