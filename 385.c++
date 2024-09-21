// C. Bear and Prime Numbers
// time limit per test2 seconds
// memory limit per test512 megabytes
// Recently, the bear started studying data structures and faced the following problem.

// You are given a sequence of integers x1, x2, ..., xn of length n and m queries, each of them is characterized by two integers li, ri. Let's introduce f(p) to represent the number of such indexes k, that xk is divisible by p. The answer to the query li, ri is the sum: , where S(li, ri) is a set of prime numbers from segment [li, ri] (both borders are included in the segment).

// Help the bear cope with the problem.

// Input
// The first line contains integer n (1 ≤ n ≤ 106). The second line contains n integers x1, x2, ..., xn (2 ≤ xi ≤ 107). The numbers are not necessarily distinct.

// The third line contains integer m (1 ≤ m ≤ 50000). Each of the following m lines contains a pair of space-separated integers, li and ri (2 ≤ li ≤ ri ≤ 2·109) — the numbers that characterize the current query.

// Output
// Print m integers — the answers to the queries on the order the queries appear in the input.


#include <iostream>
#include <vector>
#include <algorithm> 
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int k;
  int m1[10000001];
  int m[10000001];

  for(int i =0 ; i< n; i++){
    scanf("%d", &k);
    m1[k]++;
  }

  for(int i = 2; i< 10000000 ;i++){
    if(m[i]==0){
      for(int j = i ;j<=10000000;j+=i ){
         m[i]+=m1[j];
         if(i!=j){
          m[j]=-1;
         }
      }
    }
  }
  for(int i = 1 ; i<= 10000000;i++){
    if(m[i+1]==-1) {m[i+1]=0;}
    m[i] += m[i-1];

  }

  int q;
  cin>>q;
  for(int i = 0 ; i<q;i++){
    int num1;
    cin>>num1;
    int num2;
    cin>>num2;
    if(num1>10000000) num1=10000000;
    if(num2>10000000) num2=10000000;
    cout<<m[num2]-m[num1-1]<<endl;

  }


  return 0; 
}