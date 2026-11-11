/*
      Leetcode Problem: 713. Subarray Product Less Than K
      Leetcode Link: https://leetcode.com/problems/subarray-product-less-than-k/
*/

class Solution {
      public:
          int numSubarrayProductLessThanK(vector<int>& nums, int k) {
              long long prdt = 1;
              int left=0; int right=0;
              int count=0;
              for(int right=0; right<nums.size(); right++){
                  prdt*=nums[right];
                  while(prdt>=k && left<=right){
                      prdt/=nums[left];
                      left++;
                  }
                  count+=(right-left+1);
              }
              return count;
          }
      };