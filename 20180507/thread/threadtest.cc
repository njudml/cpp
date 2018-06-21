#include "thread.h"
#include <iostream>
#include <random>
#include <unistd.h>
using std::cout;
using std::endl;
class Mythread
    : public Thread {
    void run()
    {
        std::uniform_int_distribution<int> u(1, 100);
        std::default_random_engine e;
        for (int i = 0; i != 5; i++) {
            cout << u(e) << endl;
            sleep(1);
        }
    }
};
int main(void)
{
    Mythread mt;
    mt.start();
    mt.join();
    return 0;
}
