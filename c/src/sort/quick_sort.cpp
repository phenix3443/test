// -*- coding:utf-8 -*-

#include <algorithm>

void quicksort(int arr[], int l, int r) {
    if (l < r) {
        int pivot = partition(arr, l, r);
        quicksort(arr, l, pivot-1);
        quicksort(arr, pivot+1, r);
    }
}


int partition(int arr[], int l, int r) {
    int k = l, pivot = arr[r];

    for (int i = l; i < r; ++i) {
        if (arr[i] <= pivot) {
            std::swap(arr[i], arr[k++]);
        }
    }

    // std::swap(arr[k], arr[r]);
    return k;
}
