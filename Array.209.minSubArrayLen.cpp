int minSubArrayLen (int s, int* nums, int numsSize) {
    int result = __INT32_MAX__; //最终结果
    int sum = 0;  //滑动窗口中子序列的数值之和
    int i = 0;   //滑动窗口的起始位置
    int subLength = 0;  //滑动窗口子序列的长度
    for (int j = 0; j < numsSize; j++) { 
        sum += nums[j];
        while (sum >= s) { //一旦发现子序列和超过了s，更新result
            subLength = j - i + 1;
            result = result < subLength ? result : subLength;
            sum -= nums[i++];
        }
    }
    return result == __INT32_MAX__ ? 0 : result;//如果result没有被赋值，就返回0，说明没有符合条件的子序列
}

