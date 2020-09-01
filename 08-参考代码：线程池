/************************************************************
	> File Name: thread_pool.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 三  6/17 01:56:26 2020
 ************************************************************/

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
#include <thread>
using namespace std;

class Task {
public :
    template<typename Func_T, typename ...ARGS>
    Task(Func_T func, ARGS ...args) {
        this->func = bind(func, forward<ARGS>(args)...);
    }
    void run() {
        this->func();
        return ;
    }
    function<void()> func;
};

template<
    typename T, 
    typename Array=vector<T>, 
    typename compare_T=less<T>
>
class HeapQueue {
public :
    HeapQueue() { elements.clear(); }
    bool empty() { return elements.size() == 0; }
    T front() { return elements[0]; }
    void push(const T &val) {
        elements.push_back(val);
        up_update();
        return ;
    }
    void pop() {
        if (empty()) return ;
        int ind = 0, n = elements.size();
        swap(elements[n - 1], elements[0]);
        elements.pop_back();
        down_update();
        return ;
    }


private:
    Array elements;
    compare_T compare;
    void up_update() {
        int ind = elements.size();
        while (ind > 1 && 
            compare(elements[ind / 2 - 1], elements[ind - 1])) {
            swap(elements[ind / 2 - 1], elements[ind - 1]);
            ind /= 2;
        }
        return ;
    }
    void down_update() {
        int ind = 0, n = elements.size();
        while (ind * 2 + 1 < n) {
            int tind = ind;
            if (compare(elements[tind], elements[ind * 2 + 1])) {
                tind = ind * 2 + 1;
            }
            if (ind * 2 + 2 < n &&
                compare(elements[tind], elements[ind * 2 + 2])) {
                tind = ind * 2 + 2;
            }
            if (ind == tind) break;
            swap(elements[ind], elements[tind]);
            ind = tind;
        }
        return ;
    }
};

template<typename QueueType = queue<Task *>>
class ThreadPool {
public :
    ThreadPool(size_t n) {
        is_running = true;
        for (int i = 0; i < n; i++) {
            threads.push_back(
                new thread(
                    &ThreadPool::thread_worker, this
                )
            );
        }
    }
    void thread_worker() {
        cout << "worker begin" << endl;
        while (is_running) {
            Task *t = this->getOneTask();
            if (t == nullptr) break;
            t->run();
            delete t;
        }
        cout << "worker end" << endl;
        return ;
    }
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex);
        while (is_running && tasks.empty()) m_cond.wait(lock);
        Task *t = nullptr;
        if (is_running) {
            t = tasks.front();
            tasks.pop();
        }
        return t;
    }
    void addOneTask(Task *t) {
        unique_lock<mutex> lock(m_mutex);
        tasks.push(t);
        m_cond.notify_one();
        return ;
    }
    ~ThreadPool() {
        do {
            is_running = false;
            unique_lock<mutex> lock(m_mutex);
            m_cond.notify_all();
        } while (0);
        for (int i = 0; i < threads.size(); i++) {
            threads[i]->join();
            delete threads[i];
        }
        return ;
    }
private:
    vector<thread *> threads;
    QueueType tasks;
    mutex m_mutex;
    condition_variable m_cond;
    bool is_running;
};

void func(int a, int b) {
    cout << a << " + " << b << endl;
    return ;
}

int main() {
    ThreadPool<HeapQueue<Task *>> tp(5);
    this_thread::sleep_for(chrono::seconds(2));
    tp.addOneTask(new Task(func, 3, 4));
    tp.addOneTask(new Task(func, 5, 10));
    tp.addOneTask(new Task(func, 14, 60));
    this_thread::sleep_for(chrono::seconds(2));
    return 0;
}
