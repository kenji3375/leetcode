#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
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
    
    const int plen = p.size();
    const int slen = s.size();

    vector<vector<bool>> dp(plen+1, vector<bool>(slen+1, false));


    // bool correct = true;
    // int i = 0;
    dp[0][0]=true;
    for (int y=0; y<=plen; ++y) {
        for(int x=0; x<=slen; ++x) {
            if(y>1 && p[y-1] == '*') {
                // dp[y][x]=true;
                if(dp[y-2][x]) {
                    dp[y][x] = true;
                } else if(x>0 && dp[y][x-1] && (s[x-1] == p[y-2] || p[y-2] == '.')) {
                    dp[y][x] = true;
                } 
                // else {
                //     // cout<<endl<<s[x-1]<<" "<<p[y-1]<<endl;
                // }
            } else if (y>0 && x>0 && dp[y-1][x-1] && (s[x-1] == p[y-1] || p[y-1] == '.')) {
                dp[y][x] = true;
            }
        }
    }

    // cout<<s<<endl<<endl;
    // cout<<" ";
    // for (int y=0; y<=plen; ++y) {
    //     cout<<p[y-1]<<":   ";
    //     for (int x=0; x<=slen; ++x) {
    //         cout<<(dp[y][x] ? "T":"_")<<".";
    //     }
    //     cout<<endl;
    // }

    return dp[plen][slen];
        
}

/*
//this one has given me 'beats 100%' on leetcode

bool isMatch(string s, string p) {
    
    const int plen = p.size();
    const int slen = s.size();

    vector<vector<bool>> dp(plen+1, vector<bool>(slen+1, false));

    dp[0][0]=true;
    for (int y=0; y<=plen; ++y) {
        for(int x=0; x<=slen; ++x) {
            if(y>1 && p[y-1] == '*') {
                if(dp[y-2][x]) dp[y][x] = true;    
                else if(x>0 && dp[y][x-1] && (s[x-1] == p[y-2] || p[y-2] == '.')) dp[y][x] = true;
                
            } else if (y>0 && x>0 && dp[y-1][x-1] && (s[x-1] == p[y-1] || p[y-1] == '.')) {
                dp[y][x] = true;
            }
        }
    }
    return dp[plen][slen];  
}

*/

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
