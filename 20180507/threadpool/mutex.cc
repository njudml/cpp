#include "mutex.h"
Mutex::Mutex()
    : _islocked(false)
{
    pthread_mutex_init(&_mutex, NULL);
}
Mutex::~Mutex()
{
    pthread_mutex_destroy(&_mutex);
}

void Mutex::lock()
{
    pthread_mutex_lock(&_mutex);
    _islocked = true;
}
void Mutex::unlock()
{
    pthread_mutex_unlock(&_mutex);
    _islocked = false;
}
