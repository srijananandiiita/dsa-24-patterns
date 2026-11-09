/*
 * Problem: Container With Most Water
 * Link: https://leetcode.com/problems/container-with-most-water/description/
 * Pattern: 01 - Two Pointers
 * Problem Number: Leetcode 11
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * Key Note: Use two pointers, one at the start and one at the end, and move the pointer with the smaller height inward.
 */
//Method 1:
class Solution {
      public:
          int maxArea(vector<int>& height) {
              int ans = INT_MIN;
              for(int i=0;i<height.size();i++){
                  for(int j=0;j<height.size();j++){
                      ans = max(min(height[i],height[j])*abs(j-i),ans);
                  }
              }
              return ans;
          }
      };

//Method 2: Two Pointer Approach
class Solution {
      public:
          int maxArea(vector<int>& height) {
              int ans = INT_MIN;
              int i=0; int j=height.size()-1;
              while(i<j){
                  ans = max(min(height[i],height[j])*(j-i),ans);
                  if(height[i]>height[j]) j--;
                  else i++;
              }
              return ans;
          }
      };