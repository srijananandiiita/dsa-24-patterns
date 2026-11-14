
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
