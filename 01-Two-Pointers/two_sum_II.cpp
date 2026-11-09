/*
 * Problem: Two Sum II - Input Array Is Sorted
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 * Problem Number: Leetcode 167
 * Pattern: 01 - Two Pointers
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * Key Note: Use two pointers to find the target sum in a sorted array.
 */

class Solution {
      public:
          vector<int> twoSum(vector<int>& numbers, int target) {
              int n = numbers.size();
              int i = 0;
              int j = n-1;
              while(i<j){
                  if(numbers[i]+numbers[j]==target){
                      return{i+1,j+1};
                  }
                  else if(numbers[i]+numbers[j]<target){
                      i++;
                  }
                  else{
                      j--;
                  }
              }
              return {};
          }
      };