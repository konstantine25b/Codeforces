//ACCEPTED
// B. Build a Contest
// time limit per test1 second
// memory limit per test256 megabytes
// Arkady coordinates rounds on some not really famous competitive programming platform. Each round features 𝑛
//  problems of distinct difficulty, the difficulties are numbered from 1
//  to 𝑛
// .

// To hold a round Arkady needs 𝑛
//  new (not used previously) problems, one for each difficulty. As for now, Arkady creates all the problems himself, but unfortunately, he can't just create a problem of a desired difficulty. Instead, when he creates a problem, he evaluates its difficulty from 1
//  to 𝑛
//  and puts it into the problems pool.

// At each moment when Arkady can choose a set of 𝑛
//  new problems of distinct difficulties from the pool, he holds a round with these problems and removes them from the pool. Arkady always creates one problem at a time, so if he can hold a round after creating a problem, he immediately does it.

// You are given a sequence of problems' difficulties in the order Arkady created them. For each problem, determine whether Arkady held the round right after creating this problem, or not. Initially the problems pool is empty.

// Input
// The first line contains two integers 𝑛
//  and 𝑚
//  (1≤𝑛,𝑚≤105
// ) — the number of difficulty levels and the number of problems Arkady created.

// The second line contains 𝑚
//  integers 𝑎1,𝑎2,…,𝑎𝑚
//  (1≤𝑎𝑖≤𝑛
// ) — the problems' difficulties in the order Arkady created them.

// Output
// Print a line containing 𝑚
//  digits. The 𝑖
// -th digit should be 1
//  if Arkady held the round after creation of the 𝑖
// -th problem, and 0
//  otherwise.

#include <iostream>
#include <vector>
#include <algorithm> 
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int m;
  cin>>m;
  int count=0;
  map<int,int> freq;
  map<int,int> contests;

  for(int i = 0 ; i< m ;i++){
    int k;
    cin>>k;
    freq[k]++;
    contests[freq[k]]++;
    
    if(contests[count+1]==n){
        count++;
        cout<<1;
    }else{
      cout<<0;
    }
    
  }
  
  return 0;  
}