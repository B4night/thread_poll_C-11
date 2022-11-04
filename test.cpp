#include "thread_pool.h"
#include <stdio.h>
#include <unistd.h>

void func(void* arg) {
    cout << __func__ << "   " << *(int*)arg << endl;
} 

int main() {
    thread_pool tp;
    for (int i = 0; i < 10; i++) {
        tp.add_job(func, &i);   // the memory's value that i points to is changing all the time
        sleep(1);
    }
    // while (1) ;
    sleep(1);
    return 0;
}