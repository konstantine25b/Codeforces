//accepted


// B. Queries about less or equal elements
// time limit per test2 seconds
// memory limit per test256 megabytes
// You are given two arrays of integers a and b. For each element of the second array bj you should find the number of elements in array a that are less than or equal to the value bj.

// Input
// The first line contains two integers n, m (1 ≤ n, m ≤ 2·105) — the sizes of arrays a and b.

// The second line contains n integers — the elements of array a ( - 109 ≤ ai ≤ 109).

// The third line contains m integers — the elements of array b ( - 109 ≤ bj ≤ 109).

// Output
// Print m integers, separated by spaces: the j-th of which is equal to the number of such elements in array a that are less than or equal to the value bj.

#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);  // Use vector instead of raw array
    vector<int> b(m);  // Use vector instead of raw array

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // Sort the array a
    sort(a.begin(), a.end());

    // Map to cache results for repeated queries
    map<int, int> result_cache;

    // Loop through elements in array b
    for (int i = 0; i < m; ++i) {
        if (result_cache.find(b[i]) == result_cache.end()) {
            // Find number of elements in 'a' that are <= b[i]
            int count = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
            result_cache[b[i]] = count;  // Store the result in cache
        }

        // Output the result for b[i]
        cout << result_cache[b[i]] << " ";
    }

    cout << endl;  // Add newline after the output
    return 0;
}
