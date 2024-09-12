// ACCEPTED

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