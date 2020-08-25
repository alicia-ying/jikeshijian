/*************************************************************************
	> File Name: ant_problem.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 一  8/24 09:59:13 2020
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
#include <cmath>
using namespace std;

struct Ant { // 记录蚂蚁的逻辑位置和方向
    int ind;
    double pos; // 逻辑上 0 时刻的位置
    int d;   // -1 向左，1 向右
};

struct Data { // 存储到小顶堆中的数据
    int i, j; // 相遇的两只蚂蚁编号
    double d;    // 逻辑上，两只蚂蚁在 0 时刻的距离
    bool operator<(const Data &a) const {
        if (d - a.d) return d < a.d;
        if (i - a.i) return i < a.i;
        return j < a.j;
    }
};

vector<Ant> vec; // 存储蚂蚁的数据
set<Data> heap;  // 模拟过程中的小顶堆

void init_heap() {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].d != 1) continue;
        if (i + 1 == vec.size()) continue;
        if (vec[i + 1].d != -1) continue;
        heap.insert(Data{i, i + 1, double(vec[i + 1].pos - vec[i].pos)});
    }
    return ;
}

void try_insert(int i) {
    int j = i + vec[i].d;
    if (j < 0 || j >= vec.size()) return ;
    if (vec[i].d == vec[j].d) return ;
    if (j < i) swap(i, j);
    int a = vec[i].ind;
    int b = vec[j].ind;
    heap.insert(Data{i, j, fabs(vec[a].pos - vec[b].pos)});
    return ;
}

void simulation() {
    while (heap.size()) {
        int i = heap.begin()->i;
        int j = heap.begin()->j;
        double d = heap.begin()->d;
        heap.erase(heap.begin());
        swap(vec[i].ind, vec[j].ind);
        swap(vec[i].d, vec[j].d);
        cout << i << " 与 " << j << " 相撞, " << d / 2.0 << "s" << endl;
        try_insert(i);
        try_insert(j);
    }
    return ;
}

int main() {
    int n;
    cout << "请输入蚂蚁数量："; cin >> n;
    cout << "请依次输入每只蚂蚁的初识位置和方向(-1:向左, 1:向右)" << endl;
    for (int i = 0; i < n; i++) {
        double pos;
        int d;
        cin >> pos >> d;
        vec.push_back(Ant{i, pos, d});
    }
    init_heap();  // 初始化小顶堆的中的数据
    simulation(); // 模拟全过程
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].d == -1) cout << i << " 左侧掉落" << endl;
        else cout << i << " 右侧掉落" << endl;
    }
    return 0;
}
