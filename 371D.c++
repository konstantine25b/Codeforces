// D. Vessels
// time limit per test2 seconds
// memory limit per test256 megabytes
// There is a system of n vessels arranged one above the other as shown in the figure below. Assume that the vessels are numbered from 1 to n, in the order from the highest to the lowest, the volume of the i-th vessel is ai liters.


// Initially, all the vessels are empty. In some vessels water is poured. All the water that overflows from the i-th vessel goes to the (i + 1)-th one. The liquid that overflows from the n-th vessel spills on the floor.

// Your task is to simulate pouring water into the vessels. To do this, you will need to handle two types of queries:

// Add xi liters of water to the pi-th vessel;
// Print the number of liters of water in the ki-th vessel.
// When you reply to the second request you can assume that all the water poured up to this point, has already overflown between the vessels.

// Input
// The first line contains integer n — the number of vessels (1 ≤ n ≤ 2·105). The second line contains n integers a1, a2, ..., an — the vessels' capacities (1 ≤ ai ≤ 109). The vessels' capacities do not necessarily increase from the top vessels to the bottom ones (see the second sample). The third line contains integer m — the number of queries (1 ≤ m ≤ 2·105). Each of the next m lines contains the description of one query. The query of the first type is represented as "1 pi xi", the query of the second type is represented as "2 ki" (1 ≤ pi ≤ n, 1 ≤ xi ≤ 109, 1 ≤ ki ≤ n).

// Output
// For each query, print on a single line the number of liters of water in the corresponding vessel.


#include <iostream>
#include <vector>
#include <algorithm> 
#include <set>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> a(n+1);
  set<int> all;
  for(int i = 1 ; i<= n ; i++){
    cin>>a[i];
    all.insert(i);
  }
  int m;
  cin>>m;
  int q;
  vector<int> b(n+1,0);




  for(int i =0; i< m;i++){
    cin>>q;
    if(q == 2)
    
    {

        int kitxva;
        cin>>kitxva;
        cout<<b[kitxva];
        

    }
    else
    {
        int num;
        cin>>num;
        int size;
        cin>>size;
        set<int>::iterator it;
        it = all.lower_bound(num);
        while(size>0){
            if(it==all.end()){
                break;
            }
            if(size >= a[*it]-b[*it]){
                size=size- (a[*it]-b[*it]);
                b[*it]=a[*it];
                it=erase(it++);

            }
            else{
                b[*it]+=size;
                size=0;
            }
        }




    }

    
  }

  return 0;

}