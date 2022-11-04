#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <thread>
#include <iostream>
#include <functional>
#include <mutex>
#include <queue>
#include <condition_variable>
using namespace std;

class thread_pool {
private:
    queue<function<void()>> tasks;  // tasks store the object of function<void()>
                                    // tasks.front()() can execute a function
    mutex lock;
    condition_variable not_empty;   // conditional variable
private:    
    int size;
    static const int default_size = 4;
private:
    bool is_shutdown;
public:
    thread_pool();
    thread_pool(int);
    ~thread_pool();
    void add_job(function<void(void*)>, void*);
private:
    void run();
};

#endif