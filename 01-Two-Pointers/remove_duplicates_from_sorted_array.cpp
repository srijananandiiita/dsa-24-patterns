/*
 * Problem: Remove Duplicates from Sorted Array
 * Link:https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 * Problem Number: Leetcode 26
 * Pattern: 01 - Two Pointers
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * Key Note: Slow pointer tracks unique elements; fast pointer scans ahead.
 */

 //Method 1: Fast and Slow Pointer
class Solution {
      public:
          int removeDuplicates(vector<int>& nums) {
              if(!nums.size()) return 0;
              int i=0;
              for(int j=1;j<nums.length();j++){
                  if(nums[j]!=nums[i]){
                      i++;
                      nums[i]=nums[j];
                  }
              }
              return i+1;
          }
      };


