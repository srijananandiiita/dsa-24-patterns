// ============================================================================
// Template 6: Three Pointers (Dutch National Flag Algorithm)
// When to Use:
//   - Sorting an array with exactly 3 distinct values/buckets in a single pass
//   - 3-way partitioning around a pivot (QuickSort with duplicate handling)
// Classic Problems: Sort Colors (LeetCode 75), Partition Array According to Given Pivot
// Time Complexity: O(n) - Single pass
// Space Complexity: O(1) - In-place swaps
// ============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortColors(vector<int>& nums) {
    // Invariant regions:
    // [0 ... low - 1]     -> All 0s
    // [low ... mid - 1]   -> All 1s
    // [mid ... high]      -> Unprocessed elements
    // [high + 1 ... n - 1]-> All 2s
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Belongs in the 'low' region; swap and advance both low and mid
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            // Belongs in the middle region; already in place, just advance mid
            mid++;
        } else {
            // nums[mid] == 2: Belongs in the 'high' region.
            // Swap with high and decrement high.
            // IMPORTANT: Do NOT increment mid yet because the swapped element from
            // 'high' hasn't been inspected yet!
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    cout << "Sorted Colors: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    return 0;
}
