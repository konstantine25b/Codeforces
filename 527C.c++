//ACCEPTED
// C. Glass Carving
// time limit per test2 seconds
// memory limit per test256 megabytes
// Leonid wants to become a glass carver (the person who creates beautiful artworks by cutting the glass). He already has a rectangular w mm  ×  h mm sheet of glass, a diamond glass cutter and lots of enthusiasm. What he lacks is understanding of what to carve and how.

// In order not to waste time, he decided to practice the technique of carving. To do this, he makes vertical and horizontal cuts through the entire sheet. This process results in making smaller rectangular fragments of glass. Leonid does not move the newly made glass fragments. In particular, a cut divides each fragment of glass that it goes through into smaller fragments.

// After each cut Leonid tries to determine what area the largest of the currently available glass fragments has. Since there appear more and more fragments, this question takes him more and more time and distracts him from the fascinating process.

// Leonid offers to divide the labor — he will cut glass, and you will calculate the area of the maximum fragment after each cut. Do you agree?

// Input
// The first line contains three integers w, h, n (2 ≤ w, h ≤ 200 000, 1 ≤ n ≤ 200 000).

// Next n lines contain the descriptions of the cuts. Each description has the form H y or V x. In the first case Leonid makes the horizontal cut at the distance y millimeters (1 ≤ y ≤ h - 1) from the lower edge of the original sheet of glass. In the second case Leonid makes a vertical cut at distance x (1 ≤ x ≤ w - 1) millimeters from the left edge of the original sheet of glass. It is guaranteed that Leonid won't make two identical cuts.

// Output
// After each cut print on a single line the area of the maximum available glass fragment in mm2.

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int n,w,h;
    cin >>w>>h>>n;
    map<int,int> wM;
    map<int,int> hM;
    multiset<int> wS;
    multiset<int> hS;
    wM[0] = w;
    hM[0] = h;
    wS.insert(w);
    hS.insert(h);

    for(int i = 0 ;i< n ;i++){
        string a;
        int k;
        cin >> a >> k;
        if(a=="H"){
            
            auto it = hM.upper_bound(k);
            --it; 
            int first = it->first;
            int second= it->second;
            hS.erase(hS.find(second));
            int dif = k - first;
            int b =second-dif;

            hM[first]=dif;
            hM[k]=b;

            hS.insert(dif);
            hS.insert(b);
           


        }
        else{
          
            auto it = wM.upper_bound(k);
            --it; 
            int first = it->first;
            int second= it->second;
            wS.erase(wS.find(second));
            int dif = k - first;
            int b =second-dif;

            wM[first]=dif;
            wM[k]=b;
          
            wS.insert(dif);
            wS.insert(b);
            

        }
        int wmax = *wS.rbegin();
        int hmax = *hS.rbegin();

        cout<<(long long) wmax*hmax<<endl;
    }


    return 0;
    
}