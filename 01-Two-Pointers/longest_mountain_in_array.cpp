/*
      Leetcode Problem:845
*/

//O(n square solution)
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int mx=0;
        for(int index=0;index<n;index++){
            int left=0; int right=0;
            int i=index;
            int j=index;
            while(i>0 && arr[i-1]<arr[i]){
                i--;
            }
            while(j<n-1 && arr[j+1]<arr[j]){
                j++;
            }
            int total = (i==index || j==index) ? 0:(j-i+1);
            mx=max(total,mx);
        }
        return mx;
    }
};

//Optimal Approach 
class Solution {
      public:
          int longestMountain(vector<int>& arr) {
              int n = arr.size();
              int maxLen = 0;
              int base = 0;
      
              while (base < n) {
                  int end = base;
      
                  // 1. Check if `base` can start an upward slope
                  if (end + 1 < n && arr[end] < arr[end + 1]) {
                      // Walk up to the peak
                      while (end + 1 < n && arr[end] < arr[end + 1]) {
                          end++;
                      }
      
                      // 2. Check if the peak actually has a downward slope
                      if (end + 1 < n && arr[end] > arr[end + 1]) {
                          // Walk down to the right base
                          while (end + 1 < n && arr[end] > arr[end + 1]) {
                              end++;
                          }
                          maxLen = max(maxLen, end - base + 1);
                      }
                  }
      
                  // Jump to the end of the current mountain (or advance by 1 if flat/downhill)
                  base = max(end, base + 1);
              }
      
              return maxLen;
          }
      };