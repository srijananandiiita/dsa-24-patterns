// ============================================================================
// Problem: 42. Trapping Rain Water (LeetCode Hard)
// Technique: Opposite-Ends (Converging) Two Pointers
// Time Complexity: O(n) - Single pass through the elevation map
// Space Complexity: O(1) - Only constant extra variables used
// ============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        
        // Track the tallest boundary seen so far from both ends
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (left < right) {
            // Water trapped at any index is bounded by min(leftMax, rightMax).
            // By always moving the pointer with the smaller height, we guarantee
            // that the opposite side has a wall at least as tall as our current side.
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    // New tallest left wall found; cannot trap water on top of a peak
                    leftMax = height[left];
                } else {
                    // Trapped water is determined by leftMax because right side has a taller wall
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    // New tallest right wall found; cannot trap water on top of a peak
                    rightMax = height[right];
                } else {
                    // Trapped water is determined by rightMax because left side has a taller/equal wall
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height2 = {0, 2, 0}; // Edge case: no right boundary to hold water

    cout << "Test Case 1 Output: " << sol.trap(height1) << " (Expected: 6)" << endl;
    cout << "Test Case 2 Output: " << sol.trap(height2) << " (Expected: 0)" << endl;
    return 0;
}
