int search (int* nums, int numsSize, int target) {
    int left = 0;
    int middle = 0;
    int right = numsSize;
    while (left < right) {
        middle = left + ((right - left)/2);
        if (nums[middle] > target) {
            right = middle;
        }
        else if (nums[middle] < target) {
            left = middle + 1;
        }
        else if (nums[middle] = target) {
            return middle;
        }
    }
    return -1;
}