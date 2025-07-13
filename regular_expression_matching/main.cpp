#include <iostream>
using namespace std;

bool isMatch(string s, string p) {
    
    const int plen = p.size();
    const int slen = p.size();

    if (s == p) {
        return true;
    } else {
        
    }

    
    return false;
}


int main (void) {
    string test1="aa",test2="a*";
    test1="aa",test2="a*";

    cout<<test1<<" <---> "<<test2<<endl<<(isMatch(test1,test2) ? "match":"don't match")<<endl;
}