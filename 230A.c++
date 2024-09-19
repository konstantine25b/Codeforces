//ACCEPTED
// A. Dragons
// time limit per test2 seconds
// memory limit per test256 megabytes
// Kirito is stuck on a level of the MMORPG he is playing now. To move on in the game, he's got to defeat all n dragons that live on this level. Kirito and the dragons have strength, which is represented by an integer. In the duel between two opponents the duel's outcome is determined by their strength. Initially, Kirito's strength equals s.

// If Kirito starts duelling with the i-th (1 ≤ i ≤ n) dragon and Kirito's strength is not greater than the dragon's strength xi, then Kirito loses the duel and dies. But if Kirito's strength is greater than the dragon's strength, then he defeats the dragon and gets a bonus strength increase by yi.

// Kirito can fight the dragons in any order. Determine whether he can move on to the next level of the game, that is, defeat all dragons without a single loss.

// Input
// The first line contains two space-separated integers s and n (1 ≤ s ≤ 104, 1 ≤ n ≤ 103). Then n lines follow: the i-th line contains space-separated integers xi and yi (1 ≤ xi ≤ 104, 0 ≤ yi ≤ 104) — the i-th dragon's strength and the bonus for defeating it.

// Output
// On a single line print "YES" (without the quotes), if Kirito can move on to the next level and print "NO" (without the quotes), if he can't.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dr {
    int force;
    int bonus;
} arr[1005];

bool cmp(dr x, dr y) {
    return x.force < y.force; // Sort only by strength
}

int main() {
    int s, n; // s for Kirito's strength
    cin >> s >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].force >> arr[i].bonus;
    }

    sort(arr, arr + n, cmp); // Sort dragons by strength

    for (int i = 0; i < n; i++) {
        if (s > arr[i].force) {
            s += arr[i].bonus; // Increase strength after defeating the dragon
        } else {
            cout << "NO" << endl; // Kirito cannot defeat this dragon
            return 0;
        }
    }

    cout << "YES" << endl; // Kirito defeated all dragons
    return 0;
}
