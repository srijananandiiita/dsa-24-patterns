// ============================================================================
// Template 2: Fast and Slow (Read / Write) Pointers - Array In-Place
// When to Use:
//   - Removing duplicates or filtering elements in-place in O(1) extra space
//   - Moving zeroes to the end while preserving relative order
// Classic Problems: Remove Duplicates from Sorted Array, Move Zeroes, Remove Element
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

// Example: Remove Duplicates from Sorted Array in-place
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    // 'slow' is the writer pointer: tracks the position for the next unique element
    int slow = 0;

    // 'fast' is the reader pointer: scans every element in the array
    for (int fast = 1; fast < nums.size(); fast++) {
        // Condition: We found a new unique element
        if (nums[fast] != nums[slow]) {
            slow++;                  // Advance writer index
            nums[slow] = nums[fast]; // Write the valid element
        }
    }

    // New valid length is (slow + 1)
    return slow + 1;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int newLength = removeDuplicates(nums);

    cout << "New Length: " << newLength << "
Modified Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
