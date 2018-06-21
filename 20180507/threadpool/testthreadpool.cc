#include "threadpool.h"
#include <iostream>
#include <memory>
#include <random>
#include <time.h>
#include <unistd.h>
using std::cout;
using std::endl;
using std::unique_ptr;
class mytask : public Task {
public:
    void process()
    {
        // std::uniform_int_distribution<int> u(1, 100);
        // std::default_random_engine e;
        srand(clock());

        cout << rand() % 100 << endl;
    }
};
int main(void)
{
    Threadpool tp(5, 10);
    tp.start();
    unique_ptr<Task> ptask(new mytask());
    for (int i = 0; i != 20; i++)
        tp.addtask(ptask.get());
    tp.stop();
    return 0;
}
