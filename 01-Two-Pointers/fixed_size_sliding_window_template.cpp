
int i = 0, j = 0;
int sum = 0;
int ans = 0;

while (j < n) {
    // 1. Add the current element
    sum += arr[j];

    // 2. Check if window size is k
    if (j - i + 1 < k) {
        j++;
    }
    else if (j - i + 1 == k) {
        // 3. Calculate/update answer
        ans = max(ans, sum);

        // 4. Remove the element going out
        sum -= arr[i];

        // 5. Slide the window
        i++;
        j++;
    }
}
