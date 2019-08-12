extern void swap(int*, int*);

int partion(int a[], int left, int right) {
    int x = a[right];
    int small = left - 1, big = left; /* small指向最后一个小于等于x的数 */
    while(big < right) {
        if (a[big] < x) {
            ++ small;
            if (small != big) {
                swap(&a[small],&a[big]); /* 将比x小的数换到前面 */
            }
        }
        ++ big;
    }
    ++ small;                   /* 指向x最终应该在的位置 */
    swap(&a[small], &a[right]);

    return small;
}

int quick_sort(int a[], int left, int right) {
    if (left < right) {
        int povit = partion(a, left, right);
        quick_sort(a, left, povit -1);
        quick_sort(a, povit + 1, right);
    }
}
