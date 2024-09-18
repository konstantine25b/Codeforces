// E. Subsegments
// time limit per test1 second
// memory limit per test256 megabytes
// Programmer Sasha has recently begun to study data structures. His coach Stas told him to solve the problem of finding a minimum on the segment of the array in , which Sasha coped with. For Sasha not to think that he had learned all, Stas gave him a new task. For each segment of the fixed length Sasha must find the maximum element of those that occur on the given segment exactly once. Help Sasha solve this problem.

// Input
// The first line contains two positive integers n and k (1 ≤ n ≤ 105, 1 ≤ k ≤ n) — the number of array elements and the length of the segment.

// Then follow n lines: the i-th one contains a single number ai ( - 109 ≤ ai ≤ 109).

// Output
// Print n–k + 1 numbers, one per line: on the i-th line print of the maximum number of those numbers from the subarray ai ai + 1 … ai + k - 1 that occur in this subarra

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);  // Input array of size n
    map<int, int> freq;  // Frequency map
    set<int> unique_elements;  // Set to store elements that appear exactly once

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initialize the first window of size k
    for (int i = 0; i < k; i++) {
        freq[a[i]]++;
        if (freq[a[i]] == 1) {
            unique_elements.insert(a[i]);  // Insert if the element appears exactly once
        } else {
            unique_elements.erase(a[i]);  // Remove if its frequency is more than 1
        }
    }

    // Print the maximum element from unique_elements for the first window
    if (!unique_elements.empty()) {
        cout << *unique_elements.rbegin() << endl;  // Maximum element
    } else {
        cout << "Nothing" << endl;  // No unique element in the window
    }

    // Slide the window over the rest of the array
    for (int i = k; i < n; i++) {
        // Remove the element going out of the window
        int old_element = a[i - k];
        freq[old_element]--;
        if (freq[old_element] == 1) {
            unique_elements.insert(old_element);  // If it now occurs exactly once, insert it
        } else if (freq[old_element] == 0) {
            unique_elements.erase(old_element);  // If its frequency is 0, remove it
        } else {
            unique_elements.erase(old_element);  // If its frequency > 1, make sure it's not in the set
        }

        // Add the new element coming into the window
        int new_element = a[i];
        freq[new_element]++;
        if (freq[new_element] == 1) {
            unique_elements.insert(new_element);  // Insert if it occurs exactly once
        } else {
            unique_elements.erase(new_element);  // Remove if it occurs more than once
        }

        // Print the result for the current window
        if (!unique_elements.empty()) {
            cout << *unique_elements.rbegin() << endl;  // Maximum element
        } else {
            cout << "Nothing" << endl;  // No unique element in the window
        }
    }

    return 0;
}
