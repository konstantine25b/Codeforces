//ACCEPTED
// B. Powers of Two
// time limit per test3 seconds
// memory limit per test256 megabytes
// You are given n integers a1, a2, ..., an. Find the number of pairs of indexes i, j (i < j) that ai + aj is a power of 2 (i. e. some integer x exists so that ai + aj = 2x).

// Input
// The first line contains the single positive integer n (1 ≤ n ≤ 105) — the number of integers.

// The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

// Output
// Print the number of pairs of indexes i, j (i < j) that ai + aj is a power of 2.

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long count =0;
    map<int,int> a;
    vector<int> b(n);
    vector<long long> c;
    long long j=2;
    while(j<=2000000000){
        c.push_back(j);
        j=j*2;
    }
    for(int i = 0 ; i< n ;i++){
        int k;
        cin>>k;
        a[k]++;
        b[i]=k;
    }

    for(int i = 0 ; i< n;i++){
        for (long long p : c) {
            int needed = p - b[i];
            if (a.find(needed) != a.end()) {
                 int needed_count = a[needed];

                if (needed == b[i]) {
                    needed_count--;
                } 
                count += needed_count;
            }
        }
        a[b[i]]--; 
        

    }
    

    cout<<count<<endl;

    return 0;

}