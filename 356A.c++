//Accepted

// A. Knight Tournament
// time limit per test3 seconds
// memory limit per test256 megabytes
// Hooray! Berl II, the king of Berland is making a knight tournament. The king has already sent the message to all knights in the kingdom and they in turn agreed to participate in this grand event.

// As for you, you're just a simple peasant. There's no surprise that you slept in this morning and were late for the tournament (it was a weekend, after all). Now you are really curious about the results of the tournament. This time the tournament in Berland went as follows:

// There are n knights participating in the tournament. Each knight was assigned his unique number — an integer from 1 to n.
// The tournament consisted of m fights, in the i-th fight the knights that were still in the game with numbers at least li and at most ri have fought for the right to continue taking part in the tournament.
// After the i-th fight among all participants of the fight only one knight won — the knight number xi, he continued participating in the tournament. Other knights left the tournament.
// The winner of the last (the m-th) fight (the knight number xm) became the winner of the tournament.
// You fished out all the information about the fights from your friends. Now for each knight you want to know the name of the knight he was conquered by. We think that the knight number b was conquered by the knight number a, if there was a fight with both of these knights present and the winner was the knight number a.

// Write the code that calculates for each knight, the name of the knight that beat him.

// Input
// The first line contains two integers n, m (2 ≤ n ≤ 3·105; 1 ≤ m ≤ 3·105) — the number of knights and the number of fights. Each of the following m lines contains three integers li, ri, xi (1 ≤ li < ri ≤ n; li ≤ xi ≤ ri) — the description of the i-th fight.

// It is guaranteed that the input is correct and matches the problem statement. It is guaranteed that at least two knights took part in each battle.

// Output
// Print n integers. If the i-th knight lost, then the i-th number should equal the number of the knight that beat the knight number i. If the i-th knight is the winner, then the i-th number must equal 0.


#include<iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> beaten_by(n + 1, 0); // +1 to make it 1-indexed
    set<int> active_knights;

    for (int i = 1; i <= n; ++i) {
        active_knights.insert(i);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int k1, k2, w;
        cin >> k1 >> k2 >> w;

        vector<int> to_remove;

        auto it = active_knights.lower_bound(k1);
        while (it != active_knights.end() && *it <= k2) {
            if (*it != w) {
                beaten_by[*it] = w;  // Mark knight as beaten by w
                to_remove.push_back(*it); // Schedule knight for removal
            }
            ++it;
        }

        for (int knight : to_remove) {
            active_knights.erase(knight);
        }
    }

    // Output results
    for (int i = 1; i <= n; i++) {
        cout << beaten_by[i] << " ";
    }

    return 0;
}
