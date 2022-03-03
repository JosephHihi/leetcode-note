#include <stdlib.h>
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    //初始化返回的结果数组的大小
    *returnSize = n; // 传入int* returnSize，*returnsize即是地址的值，即是行数
    *returnColumnSizes = (int*)malloc(sizeof(int) * n); // int** returnColumnSizes是地址的地址 *returnColumnSizes 是一维数组（即地址），用来存放每一行的元素个数，即列数
    //初始化返回结果数组ans
    int** ans = (int**)malloc(sizeof(int*) * n);
    int i;
    for(i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n); // 二维数组的每一个元素都是一个一维数组
        (*returnColumnSizes)[i] = n;  // 一维数组的元素，该数组只有一个元素，即列数
    }

    //设置每次循环的起始位置
    int startX = 0; //行
    int startY = 0; //列
    //设置二维数组的中间值，若n为奇数。需要最后在中间填入数字
    int mid = n / 2;
    //循环圈数
    int loop = n / 2;
    //偏移数
    int offset = 1;
    //当前要添加的元素
    int count = 1;

    while(loop) {
        int i = startX;
        int j = startY;
        //模拟上侧从左到右
        for(; j < startY + n - offset; j++) {
            ans[startX][j] = count++;
        }
        //模拟右侧从上到下
        for(; i < startX + n - offset; i++) {
            ans[i][j] = count++;
        }
        //模拟下侧从右到左
        for(; j > startY; j--) {
            ans[i][j] = count++;
        }
        //模拟左侧从下到上
        for(; i > startX; i--) {
            ans[i][j] = count++;
        }
        //偏移值每次加2
        offset += 2;
        //遍历起始位置每次+1
        startX++;
        startY++;
        loop--;
    }
    //若n为奇数需要单独给矩阵中间赋值
    if (n % 2)
        ans[mid][mid] = count;

    return ans;
}