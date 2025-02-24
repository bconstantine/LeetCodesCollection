#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findK(vector<int>& nums1, vector<int>&nums2, int &k, int &start1, 
        int &end1, int &start2, int &end2){
            if(start1>end1){
                return nums2[k-start1];
            }else if(start2>end2){
                return nums1[k-start2];
            }

            int midIdx1 = (start1+end1) / 2;
            int midIdx2 = (start2+end2) / 2;
            int midValue1 = nums1[midIdx1];
            int midValue2 = nums2[midIdx2];
            
            if(midIdx1+midIdx2 < k){
                if(midValue1>midValue2){
                    start2 = midIdx2+1;
                    return findK(nums1, nums2, k, start1, end1, start2, end2);
                }else{
                    start1 = midIdx1+1;
                    return findK(nums1, nums2, k, start1, end1, start2, end2);
                }
            }else{
                if(midValue1>midValue2){
                    end1 = midIdx1-1;
                    return findK(nums1, nums2, k, start1, end1, start2, end2);
                }else{
                    end2 = midIdx2-1;
                    return findK(nums1, nums2, k, start1, end1, start2, end2);
                }
            }
        }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int start1 = 0;
        int end1 = nums1.size() - 1;
        int start2 = 0;
        int end2 = nums2.size() - 1;
        double res = 0;
        if(len % 2){
            int targetIdx = len/2;
            res = findK(nums1, nums2, targetIdx, start1, end1, start2, end2);
        }else{
            int targetIdx1 = len/2-1;
            res = findK(nums1, nums2, targetIdx1, start1, end1, start2, end2);
            int targetIdx2 = len/2;
            start1 = 0;
            end1 = nums1.size() - 1;
            start2 = 0;
            end2 = nums2.size() - 1;
            double res2 = findK(nums1, nums2, targetIdx2, start1, end1, start2, end2);
            res+=res2;
            res/=2;
        }
        return res;
    }
};
