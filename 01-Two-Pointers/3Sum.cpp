/*
Leetcode Problem: 15. 3Sum
Leetcode Link: https://leetcode.com/problems/3sum/
*/

class Solution {
      public:
          vector<vector<int>> threeSum(vector<int>& nums) {
              vector<vector<int>>ans;
              int sum,target,left,right;
              sort(nums.begin(),nums.end());
              int n=nums.size();
              for(int i=0;i<n;i++){
                  if(i>0 && nums[i]==nums[i-1]) continue;
                  target=-1*nums[i];
                  left=i+1;
                  right=n-1;
                  while(left<right){
                      sum = nums[left] + nums[right];
                      if(sum>target){
                          right--;
                      }
                      else if(sum<target){
                          left++;
                      }
                      else{
                          ans.push_back({nums[i],nums[left],nums[right]});
                          //To avoid duplicate enteries of triplets 
                          while(left<right && nums[left]==nums[left+1]) left++;
                          while(left<right && nums[right]==nums[right-1]) right--;
                          //To avoid infinite loops or updation 
                          left++; right--;
                      }
                  }
              }
              return ans;
          }
      };