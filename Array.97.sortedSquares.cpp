#include <stdlib.h>
int* sortedSquares (int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize; //返回的数组大小就是原数组大小
    int right = numsSize - 1; //创建两个指针，right指向数组
    int left = 0;

    int* ans = (int*)malloc(sizeof(int) * numsSize); //最后要返回的结果数组
    int index;
    for (index = numsSize - 1; index >= 0; index --) {
        int lSquare = nums[left] * nums[left]; //左指针指向元素的平方
        int rSquare = nums[right] * nums[right]; //右指针指向元素的平方
        if (lSquare < rSquare) {
            ans[index] = lSquare;
            left++;
        }
        else {
            ans[index] = rSquare;
            right --;
        }

    }
    return ans; //返回结果数组
}