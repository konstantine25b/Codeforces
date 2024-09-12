// ACCEPTED

// A. Counting Kangaroos is Fun
// time limit per test1 second
// memory limit per test256 megabytes
// There are n kangaroos with pockets. Each kangaroo has a size (integer number). A kangaroo can go into another kangaroo's pocket if and only if the size of kangaroo who hold the kangaroo is at least twice as large as the size of kangaroo who is held.

// Each kangaroo can hold at most one kangaroo, and the kangaroo who is held by another kangaroo cannot hold any kangaroos.

// The kangaroo who is held by another kangaroo cannot be visible from outside. Please, find a plan of holding kangaroos with the minimal number of kangaroos who is visible.

// Input
// The first line contains a single integer — n (1 ≤ n ≤ 5·105). Each of the next n lines contains an integer si — the size of the i-th kangaroo (1 ≤ si ≤ 105).

// Output
// Output a single integer — the optimal number of visible kangaroos.



#include<iostream>
#include <vector>
#include <algorithm> 
using namespace std;


main(){
    int n;
    cin>>n;
    int count = 0;
    vector<int> num(n);
    for (int i = 0 ; i < n;i++){
        cin >> num[i]; 
    }
    int j = n/2;
    sort(num.begin(), num.end());
    for(int i = 0 ; i< n/2 ; i++){
        if(j>=n){
            break;
        }
        if(num[i]*2<=num[j]){
          count++;
          j++;
          
        }
        else{
            while(num[i]*2>num[j]){
               if(j>=n){
                 break;
               }
               j++;   
            }
            if(j>=n){
                 break;
            }
            if(num[i]*2<=num[j]){
              count++;
              j++; 
            }

        }
       
        
    }
    cout << n-count << endl;  // Output the result
    return 0;
}