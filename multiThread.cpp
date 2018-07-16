
#include "multiThread.h"


#define ORDER



void task1(void * ptr)
{
    Context_t * context = (Context_t *)ptr;
#ifdef ORDER
    /* wait for main */
    std::unique_lock<std::mutex> lck1(context->main_done_mutex);
    while (! context->main_done_flag) {
        context->main_done_cv.wait(lck1);
    }
    context->main_done_mutex.unlock();
#endif

    printf("A\n");

#ifdef ORDER
    context->A_done_mutex.lock();
    context->A_done_flag = true;
    context->A_done_mutex.unlock();
    context->A_done_cv.notify_all();

    /* wait for B done */
    std::unique_lock<std::mutex> lck2(context->B_done_mutex);
    while (! context->B_done_flag) {
        context->B_done_cv.wait(lck2);
    }
    context->B_done_mutex.unlock();
#endif

    printf("C\n");

#ifdef ORDER
    context->C_done_mutex.lock();
    context->C_done_flag = true;
    context->C_done_mutex.unlock();
    context->C_done_cv.notify_all();
#endif

    return ;
}


void task2(void * ptr)
{
    Context_t * context = (Context_t *)ptr;
#ifdef ORDER
    /* wait for A done */
    std::unique_lock<std::mutex> lck1(context->A_done_mutex);
    while (! context->A_done_flag) {
        context->A_done_cv.wait(lck1);
    }
    context->A_done_mutex.unlock();
#endif

    printf("B\n");

#ifdef ORDER
    context->B_done_mutex.lock();
    context->B_done_flag = true;
    context->B_done_mutex.unlock();
    context->B_done_cv.notify_all();
#endif

#ifdef ORDER
    /* wait for C done */
    std::unique_lock<std::mutex> lck2(context->C_done_mutex);
    while (! context->C_done_flag) {
        context->C_done_cv.wait(lck2);
    }
    context->C_done_mutex.unlock();
#endif

    printf("D\n");

    return ;
}


