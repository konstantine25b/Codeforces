//accepted

// B. Physics Practical
// time limit per test1 second
// memory limit per test256 megabytes
// inputinput.txt
// outputoutput.txt
// One day Vasya was on a physics practical, performing the task on measuring the capacitance. He followed the teacher's advice and did as much as n measurements, and recorded the results in the notebook. After that he was about to show the results to the teacher, but he remembered that at the last lesson, the teacher had made his friend Petya redo the experiment because the largest and the smallest results differed by more than two times. Vasya is lazy, and he does not want to redo the experiment. He wants to do the task and go home play computer games. So he decided to cheat: before Vasya shows the measurements to the teacher, he will erase some of them, so as to make the largest and the smallest results of the remaining measurements differ in no more than two times. In other words, if the remaining measurements have the smallest result x, and the largest result y, then the inequality y ≤ 2·x must fulfill. Of course, to avoid the teacher's suspicion, Vasya wants to remove as few measurement results as possible from his notes.

// Help Vasya, find what minimum number of measurement results he will have to erase from his notes so that the largest and the smallest of the remaining results of the measurements differed in no more than two times.

// Input
// The first line contains integer n (2 ≤ n ≤ 105) — the number of measurements Vasya made. The second line contains n integers c1, c2, ..., cn (1 ≤ ci ≤ 5000) — the results of the measurements. The numbers on the second line are separated by single spaces.

// Output
// Print a single integer — the minimum number of results Vasya will have to remove.



#include<iostream>
#include <vector>
#include <algorithm> 
using namespace std;

main(){
    int i1 = 0, d=0, i2, mx;

    freopen("input.txt", "r" , stdin);
      freopen("output.txt", "w" , stdout);

    int n;
    cin>>n;
    vector<int> num(n);

    for(int i = 0 ; i < n; i++){
        cin >> num[i]; 
    }
    sort(num.begin(), num.end());
    
    
    i2=0;
    mx=0;

    while(i1 < n){
        
        
        for(int i = i2 ; i<n; i++){

         if(num[i1]*2<num[i]){
            break;
         }else{
            i2++;
         }
        }
        d= i2-i1;
        mx = max(mx, d);
        i1++;
    }

    cout <<( n-mx )<< endl; 

    return 0;
}