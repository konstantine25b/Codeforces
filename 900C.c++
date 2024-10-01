//6th test fail
// # // C. Remove Extra One
// # // time limit per test2 seconds
// # // memory limit per test256 megabytes
// # // You are given a permutation p of length n. Remove one element from permutation to make the number of records the maximum possible.

// # // We remind that in a sequence of numbers a1, a2, ..., ak the element ai is a record if for every integer j (1 ≤ j < i) the following holds: aj < ai.

// # // Input
// # // The first line contains the only integer n (1 ≤ n ≤ 105) — the length of the permutation.

// # // The second line contains n integers p1, p2, ..., pn (1 ≤ pi ≤ n) — the permutation. All the integers are distinct.

// # // Output
// # // Print the only integer — the element that should be removed to make the number of records the maximum possible. If there are multiple such elements, print the smallest one.

#include <iostream>
#include <vector>
#include <algorithm> 
#include <set>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> freq(n,0);
  vector<int> arr(n);
  set<int> mS;
  int cur=0;
  cin>>arr[0];
  mS.insert(arr[0]);

  for (int i = 1 ; i< n; i++){
    int k;
    cin>>k;
    arr[i]=k;
    mS.insert(k);
    auto it = prev(prev(mS.end()));
    if(*it==k){
        freq[cur]++;
    }
    if(k>arr[cur]){
        cur=i;
    }

  }
  int l=0;
  int count=0;

  for(int i =0 ; i< n; i++){
    if(freq[i]>freq[l]){
        
            l = i;
        
     }
     else if(freq[i]>freq[l]){
      if(arr[i]<arr[l]){
        l =i;
      }
     }
     if(freq[i]!=0){
      count++;
     }
  }
  int ans = arr[l];
  if(count ==1 || count ==0){
    if(freq[0]==1){
        
      for(int i =1 ; i < arr.size(); i++){
         ans = min(ans, arr[i]);
      }
    }
    
  }
  
  cout<<ans<<endl;

  return 0;  
}