// ============================================================================
// Template 5: Two Pointers on Two Separate Sequences
// When to Use:
//   - Merging two sorted arrays/lists (e.g., Merge Sorted Array, Merge Step in MergeSort)
//   - Finding the intersection of two sorted arrays
//   - Checking if one string is a subsequence of another
// Time Complexity: O(n + m)
// Space Complexity: O(1) (excluding output container)
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

// Example: Merge two sorted arrays into a single sorted array
vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int n = arr1.size();
    int m = arr2.size();

    vector<int> merged;
    merged.reserve(n + m);

    // Advance whichever pointer points to the smaller element
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Append any leftover elements from arr1 or arr2
    while (i < n) merged.push_back(arr1[i++]);
    while (j < m) merged.push_back(arr2[j++]);

    return merged;
}

int main() {
    vector<int> a = {1, 3, 5, 7};
    vector<int> b = {2, 4, 6, 8, 10};
    vector<int> res = mergeSortedArrays(a, b);

    cout << "Merged Array: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
