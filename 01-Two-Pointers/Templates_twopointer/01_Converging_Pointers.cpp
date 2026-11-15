// ============================================================================
// Template 1: Opposite-Ends (Converging) Pointers
// When to Use:
//   - Finding pairs/triplets in a sorted array (e.g., Two Sum II, 3Sum)
//   - Checking palindromes or reversing arrays/strings
//   - Boundary optimization problems (e.g., Container With Most Water)
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

// Generic Template
void convergingPointersTemplate(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == target) {
            // Pair found! Process indices 'left' and 'right'
            cout << "Pair found at indices [" << left << ", " << right << "]" << endl;
            left++;
            right--;
        } else if (currentSum < target) {
            // Sum is too small; move left pointer right to increase sum (since array is sorted)
            left++;
        } else {
            // Sum is too large; move right pointer left to decrease sum
            right--;
        }
    }
}

int main() {
    vector<int> sortedArr = {1, 2, 4, 6, 8, 9, 14, 15};
    int target = 13;
    convergingPointersTemplate(sortedArr, target);
    return 0;
}
