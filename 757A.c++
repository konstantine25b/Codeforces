//accepted
// A. Gotta Catch Em' All!
// time limit per test1 second
// memory limit per test256 megabytes
// Bash wants to become a Pokemon master one day. Although he liked a lot of Pokemon, he has always been fascinated by Bulbasaur the most. Soon, things started getting serious and his fascination turned into an obsession. Since he is too young to go out and catch Bulbasaur, he came up with his own way of catching a Bulbasaur.

// Each day, he takes the front page of the newspaper. He cuts out the letters one at a time, from anywhere on the front page of the newspaper to form the word "Bulbasaur" (without quotes) and sticks it on his wall. Bash is very particular about case — the first letter of "Bulbasaur" must be upper case and the rest must be lower case. By doing this he thinks he has caught one Bulbasaur. He then repeats this step on the left over part of the newspaper. He keeps doing this until it is not possible to form the word "Bulbasaur" from the newspaper.

// Given the text on the front page of the newspaper, can you tell how many Bulbasaurs he will catch today?

// Note: uppercase and lowercase letters are considered different.

// Input
// Input contains a single line containing a string s (1  ≤  |s|  ≤  105) — the text on the front page of the newspaper without spaces and punctuation marks. |s| is the length of the string s.

// The string s contains lowercase and uppercase English letters, i.e. .

// Output
// Output a single integer, the answer to the problem.
#include <iostream>
#include <vector>
#include <algorithm> 
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;

  map<char, int> freq;

  for(int i = 0; i < s.size();i++){
     freq[s[i]]++;
  }

  int one = min(freq['b'] , freq['B']);
  one = min(one, freq['r']);
  one = min(one, freq['l']);
  one = min(one, freq['s']);
  one = min(one, freq['s']);
  one = min(one, freq['a']/2);
  one = min(one, freq['u']/2);


  cout<<one<<endl;
  return 0; 

} 