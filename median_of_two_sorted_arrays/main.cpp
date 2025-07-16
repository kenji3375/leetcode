#include <iostream>
#include <vector>

using namespace std;


// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     const int len1=nums1.size(), len2=nums2.size();
//     vector<int> merged(nums1.size()+nums2.size(), 0);
    
//     int i = 0;
    
//     const int half = ((len1+len2)/2);
//     int in1=0, in2=0;
    
//     while (i<=half) {
        

//         if(in1<len1 && in2<len2) {      //if neither of them is finished
//             if(nums1[in1] < nums2[in2]) {
//                 merged[i] = nums1[in1];
//                 ++in1;
//             } else if(nums1[in1] > nums2[in2]) {
//                 merged[i] = nums2[in2];
//                 ++in2;
//             } else {
//                 merged[i] = nums1[in1];
//                 ++i;
//                 merged[i] = nums1[in1];
//                 ++in1;
//                 ++in2;
//             }
//         } else if(in1<len1) {           //if only nums2 is finished
//             merged[i] = nums1[in1];
//             ++in1;
//         } else {                        //if only nums1 is finished
//             merged[i] = nums2[in2];
//             ++in2;
//         }

//         ++i;
//     }
    
    
//     return (nums1.size()+nums2.size()) % 2 == 0 ? ((double)merged[half-1]+(double)merged[half])/2 : merged[half];

// }
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    int totalSize = len1+len2;

    int half = totalSize/2;

    int in1 = 0, in2 = 0;
    int current = 0, prev = 0;

    for (int i=0; i<=half; ++i) {
        prev = current;
        if (in1<len1 && (!(in2 < len2) || nums1[in1] < nums2[in2])) {
            current = nums1[in1++];
        } else {
            current = nums2[in2++];
        }
    }

    if(totalSize % 2 == 0) {
        return (current+prev) / 2.0;
    } else {
        return current;
    }

}

int main(int argc, char const *argv[])
{
    
    // vector<int> nums1 = {1,2};
    // vector<int> nums2 = {3,4,5};
    // vector<int> nums1 = {2,2,4,4};
    // vector<int> nums2 = {2,2,4,4};
    vector<int> nums1 = {1};
    vector<int> nums2 = {1};
    

    cout<<findMedianSortedArrays(nums1, nums2);
    // cout<<&nums1[0];


    return 0;
}