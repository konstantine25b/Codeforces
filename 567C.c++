//ACCEPTED
// C. Geometric Progression
// time limit per test1 second
// memory limit per test256 megabytes
// Polycarp loves geometric progressions very much. Since he was only three years old, he loves only the progressions of length three. He also has a favorite integer k and a sequence a, consisting of n integers.

// He wants to know how many subsequences of length three can be selected from a, so that they form a geometric progression with common ratio k.

// A subsequence of length three is a combination of three such indexes i1, i2, i3, that 1 ≤ i1 < i2 < i3 ≤ n. That is, a subsequence of length three are such groups of three elements that are not necessarily consecutive in the sequence, but their indexes are strictly increasing.

// A geometric progression with common ratio k is a sequence of numbers of the form b·k0, b·k1, ..., b·kr - 1.

// Polycarp is only three years old, so he can not calculate this number himself. Help him to do it.

// Input
// The first line of the input contains two integers, n and k (1 ≤ n, k ≤ 2·105), showing how many numbers Polycarp's sequence has and his favorite number.

// The second line contains n integers a1, a2, ..., an ( - 109 ≤ ai ≤ 109) — elements of the sequence.

// Output
// Output a single number — the number of ways to choose a subsequence of length three, such that it forms a geometric progression with a common ratio k.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    long long m; // Use long long for m to avoid overflow
    cin >> n >> m; // n = number of elements, m = common ratio
    vector<long long> a(n); // Use long long for the array elements

    // Maps to store occurrences of elements in the left and right portions of the array
    map<long long, long long> left, right;

    // Reading input and initializing the right map with counts of elements
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        right[a[i]]++;
    }

    long long count = 0;

    // Traverse each element to check for valid geometric progressions
    for (int i = 0; i < n; ++i) {
        right[a[i]]--;  // We are processing this element, so reduce its count in the right map

        // We check for a valid geometric progression: left_value * m = current_value, current_value * m = right_value
        if (a[i] % m == 0) {  // Ensure the current element is divisible by m to prevent invalid divisions
            long long prev = a[i] / m;  // The previous value in the geometric progression
            long long next = a[i] * m;  // The next value in the geometric progression

            // If the previous value exists in the left map and the next value exists in the right map, add to count
            if (left.find(prev) != left.end() && right.find(next) != right.end()) {
                count += left[prev] * right[next];
            }
        }

        // After processing a[i], add it to the left map
        left[a[i]]++;
    }

    cout << count << endl;  // Output the total count of valid geometric progressions
    return 0;
}
