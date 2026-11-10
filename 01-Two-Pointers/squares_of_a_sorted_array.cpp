/*
Leetcode Problem: 977. Squares of a Sorted Array
Leetcode Link: https://leetcode.com/problems/squares-of-a-sorted-array/
*/
class Solution {
      public:
          vector<int> sortedSquares(vector<int>& nums) {
              int split = 0;
              while(split<nums.size() && nums[split]<0) split++;
              for(int i=0;i<nums.size();i++) nums[i]*=nums[i];
              vector<int>temp(nums.size());
              int i=split; int j=split-1;int k=0;
              while(i<nums.size() && j>=0){
                  if(nums[i]<=nums[j]){
                      temp[k]=nums[i];
                      i++;k++;
                  }
                  else{
                      temp[k]=nums[j];
                      j--;k++;
                  }
              }
              while(j>=0){
                  temp[k]=nums[j];
                  j--;k++;
              }
              while(i<nums.size()){
                  temp[k]=nums[i];
                  i++;k++;
              }
              for(int i=0;i<nums.size();i++){
                  nums[i]=temp[i];
              }
              return nums;
          }
      };