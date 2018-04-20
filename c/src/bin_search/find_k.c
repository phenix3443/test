/* -*- coding:utf-8 -*- */
/* 给定一个有序的数组，查找 value 是否在数组中，不存在返回 - 1。 */

int binary_search(int array[], int n, int value)
{
    int left = 0;
    int right = n;

    while (left < right)
    {
        int middle = left + ((right - left) >> 1);  //防止溢出，移位也更高效。同时，每次循环都需要更新。
        if (array[middle] > value)
            right = middle;
        else if (array[middle] < value)
            left = middle + 1;
        else
            return middle;

    }
    return -1;
}
