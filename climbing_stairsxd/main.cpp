#include <iostream>

using namespace std;

int climbStairs(int n) {
    if(!n)      return 0;
    if(n==1)    return 1;
    if(n==2)    return 2;
    int here=3, l1=2, l2=1;     // left2=1  left1=2, here = l2+l1
    for(int i=2; i<n; ++i) {
        here = l2+l1;
        l2 = l1;
        l1 = here;
        // cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
    }

    return here;
}

int main(void) {

    int test=3;
    test=4;
    // test=3;
    cout<<test<<endl;
    cout<<climbStairs(test)<<endl;
    return 0;
}