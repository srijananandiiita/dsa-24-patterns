
int i = 0, j = 0;
int ans = 0;

while (j < n) {
    // 1. Include current element
    // Update sum/frequency/etc.

    // 2. Shrink window if condition is violated
    while (/* condition violated */) {
        // Remove arr[i] from window
        i++;
    }

    // 3. Update answer
    ans = max(ans, j - i + 1);

    // 4. Expand window
    j++;
}

//Example Problem : Maximum Average Subarray I
//Leetcode Probelm Number: 643
class Solution {
      public:
          double findMaxAverage(vector<int>& nums, int k) {
              int i=0; int j=0;
              double sum=0; double ans=INT_MIN;
              int n=nums.size();
              while(j<n){
                  //1.Add the current element
                  sum+=nums[j];
                  //2.Check if window size is k
                  if(j-i+1<k){
                      j++;//j aage wala apna driver
                  }
                  else if(j-i+1==k){
                  //3.Calculate/Update answer
                      ans=max(ans,sum/k);
      
                  //4.Remove the element going out
                      sum-=nums[i];
                  
                  //5.Slide the window
                      i++;
                      j++;
                  }
              }
              return ans;
          }
      };
