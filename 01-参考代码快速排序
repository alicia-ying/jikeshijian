/*************************************************************************
	> File Name: quick_sort.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 五  5/ 8 02:52:17 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define MAX_N 10000

// arr    : 用来存储待排序的元素
// n      : 代表元素数量
// output : 输出过程中的调试信息
// DEBUG = 1 开启调试信息
// DEBUG = 0 关闭调试信息
int arr[MAX_N + 5];
int n;
#define DEBUG 1
void output(int, int, int);

// 快速排序：对 arr 中 l 到 r 位进行排序
// arr : 待排序数组
// l   : 待排序区间起始坐标
// r   : 待排序区间结束坐标
void quick_sort(int *arr, int l, int r) {
    // 递归的边界条件是区间中只有一个元素
    // x  : 记录从前向后扫描的位置
    // y  : 记录从后向前扫描的位置
    // z  : 基准值，选择待排序区间的第一个元素
    // while 循环中是 partition 过程
    // 每一轮，先从后向前扫，再从前向后扫
    if (l >= r) return ;
    int x = l, y = r, z = arr[l]; 
    while (x < y) {
        while (x < y && arr[y] >= z) --y;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if (x < y) arr[y--] = arr[x];
    }

    // 将基准值 z 放入其正确位置数组的 x 位
    // 其实，此时 x==y，所以写成 arr[y] = z 也行
    // 再分别对左右区间，进行快速排序
    arr[x] = z;
    output(l, x, r);
    quick_sort(arr, l, x - 1);
    quick_sort(arr, x + 1, r);
    return ;
}

/*-----------华丽的分割线----------*/

void output(int l, int x, int r) {
    if (!DEBUG) return ;
    printf("\n待排序区间范围 [%d, %d]\n", l, r);
    printf("基准值：%d\n", arr[x]);
    
    char str[30];
    int cnt = 1;
    for (int i = 1; i < x; i++) {
        cnt += sprintf(str, "%d ", arr[i]);
    }
    for (int i = 1; i < l; i++) printf("%d ", arr[i]);
    printf("[");
    for (int i = l; i <= r; i++) {
        printf("%d ", arr[i]);
    }
    printf("]");
    for (int i = r + 1; i <= n; i++) printf("%d ", arr[i]);
    printf("\n");
    for (int i = 0; i < cnt; i++) printf(" ");
    printf("^\n");
    for (int i = 0; i < cnt; i++) printf(" ");
    printf("|\n");
    printf("\n");
    printf("按回车继续...");
    while (getchar() != '\n') ;
    return ;
}

void read_data() {
    printf("请输入元素数量：");
    scanf("%d", &n);
    printf("请输入 %d 个整数：\n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    while (getchar() != '\n') ;
    return ;
}

int main() {
    read_data();
    quick_sort(arr, 1, n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
