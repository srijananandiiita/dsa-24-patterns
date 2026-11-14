/*
Leetcode Problem: 209
*/

class Solution {
      public:
          int minSubArrayLen(int target, vector<int>& nums) {
              int i=0; int j=0; int n=nums.size(); int ans = INT_MAX; int sum=0;
              while(j<n){
                  sum+=nums[j];
      
                  while(i<=j && sum>=target){
                      sum-=nums[i];
                      i++;
                      ans = min(ans,j-i+1);
                  }
      
      
                  j++;
              }
              return ans == INT_MAX ? 0 : ans;
          }
      };