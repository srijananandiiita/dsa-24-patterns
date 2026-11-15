class Solution {
      public:
          int trap(vector<int>& height) {
              int left = 0, right = height.size() - 1;
              int leftMax = 0, rightMax = 0;
              int water = 0;
      
              while (left < right) {
                  if (height[left] < height[right]) {
                      // We know there is a taller wall on the right, 
                      // so water here is strictly bounded by leftMax
                      if (height[left] >= leftMax) {
                          leftMax = height[left];
                      } else {
                          water += leftMax - height[left];
                      }
                      left++;
                  } else {
                      // We know there is a taller or equal wall on the left,
                      // so water here is strictly bounded by rightMax
                      if (height[right] >= rightMax) {
                          rightMax = height[right];
                      } else {
                          water += rightMax - height[right];
                      }
                      right--;
                  }
              }
              return water;
          }
      };