#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    
    const int plen = p.size();
    const int slen = s.size();

    vector<vector<int>> dp;

    /*


does it fit from x to y
  a a a b
a T
a 
*
b

    */
    
    // for (int y=0; y<plen; ++y) {
    //     for (int x=0; x<slen; ++x) {
            
    //     }
    // }

    //assuming the p is going to be correct

    bool correct = true;
    int i = 0;
    for (int j=0; j<plen; ++j) {
        if(!correct || i==slen) {
            break;
        }
        correct ^= (bool)(char)1;
        
        // cout<<slen<<endl;
        // cout<<i<<" "<<j<<endl;
        cout<<"i:"<<i<<": "<<s[i]<<"  j:"<<j<<": "<<p[j]<<endl;
        if (j<plen-1) {
            if(p[j+1] == '*') {

                //------
                // here we check if any amount of character before the * fits;
                //------
                
                
                if(s[i] != p[j] && p[j] != '.') {
                    ++i;
                } else {
                    while(s[i] == p[j] || p[j] == '.') {
                        ++i;
                    }
                }
                correct = true;
                //------
                ++j;
            } else {
                if (p[j] == s[i] || p[j] == '.') {
                    correct = true;
                    ++i;
                }
            }
        } else {        //  the last j
            if(j>0 && p[j] == '*') {
                while(i<slen && s[i] == p[j-1]) {
                    ++i;
                }
                if(i == slen)   correct = true;
            }
            else  if(s[i] == p[j])    correct = true;
        }
    }


    return correct;
}


int main (void) {
    string test1="aa",test2="a*";
    
    
    // test1="abbba",test2="aba";
    // cout<<test1<<" <---> "<<test2<<endl<<(isMatch(test1,test2) ? "match":"don't match")<<endl;
    // test1="abbba",test2="ab*a";
    // cout<<test1<<" <---> "<<test2<<endl<<(isMatch(test1,test2) ? "match":"don't match")<<endl;
    // test1="aa",test2="ab*a";
    // cout<<test1<<" <---> "<<test2<<endl<<(isMatch(test1,test2) ? "match":"don't match")<<endl;
    // test1="abbba",test2="aba";
    // cout<<test1<<" <---> "<<test2<<endl<<(isMatch(test1,test2) ? "match":"don't match")<<endl;
    // test1="abbba",test2="aba";
    // cout<<test1<<" <---> "<<test2<<endl<<(isMatch(test1,test2) ? "match":"don't match")<<endl;
    
    while(true) {
        cin >> test1 >> test2;
        cout<<test1<<" <---> "<<test2<<endl<<(isMatch(test1,test2) ? "match":"don't match")<<endl<<endl<<endl;
    }


}
