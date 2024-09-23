//ACCEPTED
// B. PolandBall and Game
// time limit per test1 second
// memory limit per test256 megabytes
// PolandBall is playing a game with EnemyBall. The rules are simple. Players have to say words in turns. You cannot say a word which was already said. PolandBall starts. The Ball which can't say a new word loses.

// You're given two lists of words familiar to PolandBall and EnemyBall. Can you determine who wins the game, if both play optimally?

// Input
// The first input line contains two integers n and m (1 ≤ n, m ≤ 103) — number of words PolandBall and EnemyBall know, respectively.

// Then n strings follow, one per line — words familiar to PolandBall.

// Then m strings follow, one per line — words familiar to EnemyBall.

// Note that one Ball cannot know a word more than once (strings are unique), but some words can be known by both players.

// Each word is non-empty and consists of no more than 500 lowercase English alphabet letters.

// Output
// In a single line of print the answer — "YES" if PolandBall wins and "NO" otherwise. Both Balls play optimally.
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
    int n,m;
    cin >> n>>m;
    vector<string> a;
    vector<string> b;

    set<string> aWords;
    set<string> bWords;

    for(int i = 0 ; i< n ;i++){
        string k;
        cin>>k;
        if(aWords.find(k)==aWords.end()){
           a.push_back(k);
        }
        aWords.insert(k);
    }
    for(int i = 0 ; i< m ;i++){
        string k;
        cin>>k;
        if(bWords.find(k)==bWords.end()){
           b.push_back(k);
        }
        bWords.insert(k);
    }
    int aNum = aWords.size();
    int bNum = bWords.size();
    int common = 0;

    for(int i = 0 ; i< a.size() ; i++){
        if(bWords.find(a[i])!=bWords.end()){
          common++;
        }
    }

    common = common %2;

    if(aNum+common>bNum){
        cout<<"YES"<<endl;

    }
    else{
        cout<<"NO"<<endl;
    }



    return 0;
}
