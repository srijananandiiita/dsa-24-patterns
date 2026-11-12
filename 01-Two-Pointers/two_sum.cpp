/*
 Two Sum 
 Leetcode Problem 1
 Leetcode Link: https://leetcode.com/problems/two-sum/
*/

class Solution {
      public:
          vector<int> twoSum(vector<int>& nums, int target) {
              unordered_map<int,int>mp;
              int n=nums.size();
              for(int i=0;i<n;i++){
                  int remaining = target - nums[i];
                  if(mp.find(remaining)!=mp.end() && mp[remaining]!=i){
                      return {i,mp[remaining]};
                  }
                  mp[nums[i]]=i;
              }
              return {};
          }
      };