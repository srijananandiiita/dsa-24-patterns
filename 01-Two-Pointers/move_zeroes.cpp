/*
 * Problem: Move Zeroes
 * Link: https://leetcode.com/problems/move-zeroes/description/
 * Problem Number: Leetcode 283
 * Pattern: 01 - Two Pointers
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * Key Note: Use two pointers to track the position of non-zero elements and swap them with zero elements.
 */
class Solution {
      public:
          void moveZeroes(vector<int>& nums) {
              int i=0;
              for(int i=0;i<nums.size();i++){
                  if(nums[i]==0){
                      break;
                  }
              }
              for(int j=i;j<nums.size();j++){
                  if(nums[j]!=0){
                      swap(nums[i],nums[j]);
                      i++;
                  }
              }
          }
      };