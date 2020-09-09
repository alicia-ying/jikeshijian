/********************************************************
	> File Name: radix_sort.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 三  9/ 9 04:20:00 2020
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N 10000
int arr[MAX_N + 5], temp[MAX_N + 5];

// 基数排序演示代码
// arr: 待排序数组
// n  : 数组中元素数量
// k  : 数组中的数字最大位数
void radix_sort(int *arr, int n, int k) {
    int cnt[10] = {0};
    // 循环遍历 k 位上的数字
    for (int t = 0, j = 1; t < k; t++, j *= 10) {
        // 统计每一种数字出现的次数
        for (int i = 0; i < n; i++) {
            cnt[(arr[i] / j) % 10] += 1;
        }
        // 统计每一种数字最后出现的位置
        for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];
        // 从后向前，依次性的把每个数字放入 temp 存储区
        for (int i = n - 1; i >= 0; i--) {
            temp[--cnt[(arr[i] / j) % 10]] = arr[i];
        }
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
        for (int i = 0; i < 10; i++) cnt[i] = 0;
    }
    return ;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

int main() {
    int n, k = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (log10(arr[i]) + 1 > k) k = log10(arr[i]) + 1;
    }
    radix_sort(arr, n, k);
    output(arr, n);
    return 0;
}
