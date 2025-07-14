#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    
    const int plen = p.size();
    const int slen = p.size();

    vector<vector<int>> dp;

    /*


does it fit from x to y
  a a a b
a T
a 
*
b

    */
    
    for (int y=0; y<plen; ++y) {
        for (int x=0; x<slen; ++x) {
            
        }
    }

    
    return false;
}


int main (void) {
    string test1="aa",test2="a*";
    test1="aa",test2="a.";
    

    cout<<test1<<" <---> "<<test2<<endl<<(isMatch(test1,test2) ? "match":"don't match")<<endl;
}
