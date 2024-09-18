//accepted

// C. Little Girl and Maximum Sum
// time limit per test1 second
// memory limit per test256 megabytes
// The little girl loves the problems on array queries very much.

// One day she came across a rather well-known problem: you've got an array of 𝑛
//  elements (the elements of the array are indexed starting from 1); also, there are 𝑞
//  queries, each one is defined by a pair of integers 𝑙𝑖
// , 𝑟𝑖
//  (1≤𝑙𝑖≤𝑟𝑖≤𝑛)
// . You need to find for each query the sum of elements of the array with indexes from 𝑙𝑖
//  to 𝑟𝑖
// , inclusive.

// The little girl found the problem rather boring. She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible. Your task is to find the value of this maximum sum.

// Input
// The first line contains two space-separated integers 𝑛
//  (1≤𝑛≤2⋅105
// ) and 𝑞
//  (1≤𝑞≤2⋅105
// ) — the number of elements in the array and the number of queries, correspondingly.

// The next line contains 𝑛
//  space-separated integers 𝑎𝑖
//  (1≤𝑎𝑖≤2⋅105
// ) — the array elements.

// Each of the following 𝑞
//  lines contains two space-separated integers 𝑙𝑖
//  and 𝑟𝑖
//  (1≤𝑙𝑖≤𝑟𝑖≤𝑛
// ) — the 𝑖
// -th query.

// Output
// In a single line print, a single integer — the maximum sum of query replies after the array elements are reordered.

// Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);  // Array a of size n
    vector<int> b(n, 0);  // Array b initialized with 0 of size n

    // Input elements for array a
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Process m pairs (l1, l2)
    for(int i = 0; i < m; i++) {
        int l1, l2;
        cin >> l1 >> l2;
        l1--;
        l2--;
        b[l1]++; 

        if (l2 + 1 < n) {
            b[l2 + 1]--;  // Stop incrementing after l2
        }
    }
    for (int i = 1; i < n; i++) {
        b[i] += b[i - 1];
    }

    // Sort arrays a and b
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Calculate the sum of products
    long long max_sum = 0;
    for (int i = 0; i < n; i++) {
        max_sum += (long long)a[i] * b[i];
    }

    // Output the result
    cout << max_sum << endl;

    return 0;  // Return 0 to indicate successful execution
}
