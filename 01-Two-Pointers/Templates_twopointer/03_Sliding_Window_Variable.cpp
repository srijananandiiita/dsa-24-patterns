// ============================================================================
// Template 3: Variable-Size Sliding Window
// When to Use:
//   - Finding longest/shortest contiguous subarray or substring meeting a condition
//   - Counting subarrays that satisfy a constraint (e.g., sum <= k, at most k distinct)
// Classic Problems: Longest Substring Without Repeating Characters, Max Consecutive Ones III
// Time Complexity: O(n) - Each element is visited at most twice (once by right, once by left)
// Space Complexity: O(1) or O(k) depending on window state tracking
// ============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Example: Longest subarray with sum <= k (for non-negative numbers)
int longestSubarrayWithSumAtMostK(const vector<int>& nums, int k) {
    int left = 0;
    int currentWindowSum = 0;
    int maxLength = 0;

    // 'right' pointer expands the window one element at a time
    for (int right = 0; right < nums.size(); right++) {
        // 1. Expand window by including nums[right]
        currentWindowSum += nums[right];

        // 2. Shrink window from the left while the constraint is broken
        while (currentWindowSum > k && left <= right) {
            currentWindowSum -= nums[left];
            left++;
        }

        // 3. Window [left...right] is now valid; update the best answer
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    vector<int> nums = {3, 1, 2, 7, 4, 2, 1, 1, 5};
    int k = 8;
    cout << "Max Window Length with sum <= " << k << ": " 
         << longestSubarrayWithSumAtMostK(nums, k) << endl;
    return 0;
}
