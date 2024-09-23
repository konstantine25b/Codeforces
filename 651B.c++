//ACCEPTED
// B. Beautiful Paintings
// time limit per test1 second
// memory limit per test256 megabytes
// There are n pictures delivered for the new exhibition. The i-th painting has beauty ai. We know that a visitor becomes happy every time he passes from a painting to a more beautiful one.

// We are allowed to arranged pictures in any order. What is the maximum possible number of times the visitor may become happy while passing all pictures from first to last? In other words, we are allowed to rearrange elements of a in any order. What is the maximum possible number of indices i (1 ≤ i ≤ n - 1), such that ai + 1 > ai.

// Input
// The first line of the input contains integer n (1 ≤ n ≤ 1000) — the number of painting.

// The second line contains the sequence a1, a2, ..., an (1 ≤ ai ≤ 1000), where ai means the beauty of the i-th painting.

// Output
// Print one integer — the maximum possible number of neighbouring pairs, such that ai + 1 > ai, after the optimal rearrangement.

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> b;
    for(int i = 0 ; i< n ;i++){
        int k;
        cin>>k;
        a[i]=k;
        b[k]++;
    }

    auto it = b.begin();
    int max_value =0;
    while(it != b.end()){
        if (it->second > max_value) {  
            max_value = it->second;
        }
        ++it;
    }
    cout<<n-max_value<<endl;

    return 0;
}