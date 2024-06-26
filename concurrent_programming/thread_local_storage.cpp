/** thread can have their own local var */
#include <iostream>
#include <thread>
using namespace std;

thread_local int threadLocalValue = 0;

void increamentThreadLocal() {
    threadLocalValue++;
    // noting we use this_thread::get_id(), its a namespace, not an obj
    cout << "Thread local value in thread " << this_thread::get_id() << " is " 
    << threadLocalValue << endl;
    cout << endl;
}

int main() {
    thread t1(increamentThreadLocal);
    thread t2(increamentThreadLocal);
    t1.join();
    t2.join();
    cout << "Main thread local value: " << threadLocalValue << endl;
    return 0;
}
/**
 * Thread local value in thread 140737345746496 is 1

Thread local value in thread 140737337353792 is 1

Main thread local value: 0  (用vs compile才有这个规整的结果。否则两句话是混乱的顺序)
 */