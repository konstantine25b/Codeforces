// D. Merge Equals
// time limit per test2 seconds
// memory limit per test256 megabytes
// You are given an array of positive integers. While there are at least two equal elements, we will perform the following operation. We choose the smallest value 𝑥
//  that occurs in the array 2
//  or more times. Take the first two occurrences of 𝑥
//  in this array (the two leftmost occurrences). Remove the left of these two occurrences, and the right one is replaced by the sum of this two values (that is, 2⋅𝑥
// ).

// Determine how the array will look after described operations are performed.

// For example, consider the given array looks like [3,4,1,2,2,1,1]
// . It will be changed in the following way: [3,4,1,2,2,1,1] → [3,4,2,2,2,1] → [3,4,4,2,1] → [3,8,2,1]
// .

// If the given array is look like [1,1,3,1,1]
//  it will be changed in the following way: [1,1,3,1,1] → [2,3,1,1] → [2,3,2] → [3,4]
// .

// Input
// The first line contains a single integer 𝑛
//  (2≤𝑛≤150000
// ) — the number of elements in the array.

// The second line contains a sequence from 𝑛
//  elements 𝑎1,𝑎2,…,𝑎𝑛
//  (1≤𝑎𝑖≤109
// ) — the elements of the array.

// Output
// In the first line print an integer 𝑘
//  — the number of elements in the array after all the performed operations. In the second line print 𝑘
//  integers — the elements of the array after all the performed operations.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Node {
    long long fir;
    long long sec;
    bool operator<(const Node& other) const {
        if (fir == other.fir)
            return sec < other.sec;
        return fir < other.fir;
    }
};


int main() {
    long long  n; 
    cin >> n;
    set<Node> arr;
    set<Node> ans;
    for(long long i = 0 ; i < n ; i++){
        long long k;
        cin >>k;
        Node l;
        l.fir=k;
        l.sec=i;
        arr.insert(l);
    }
    auto it = arr.begin();
    while(it!=arr.end()){
      auto next_it = std::next(it); 
      if(next_it != arr.end() && it->fir == next_it->fir){
        Node l;
        l.fir = it->fir * 2;
        l.sec = next_it->sec;
        it = arr.erase(it); 
        arr.insert(l); 
        it = arr.erase(it);
        
      }else{
        it++;
      }
    }
    it = arr.begin();
    while(it!=arr.end()){
      Node l;
      l.fir = it->sec;
      l.sec = it->fir;
      ans.insert(l);
      it++;

      
    }

    
    auto b = ans.begin();
    vector<long long> rame;
    while(b!=ans.end()){
      rame.push_back(b->sec);
      b++;
    }
    cout<<rame.size()<<endl;
    for(long long i = 0 ; i< rame.size();i++){
     cout<<rame[i]<<" ";

    }
    


    return 0;
}