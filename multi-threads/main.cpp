#include "multiThread.h"

int main()
{
    Context_t * context;
    context = (Context_t *)malloc(sizeof(Context_t));

    context->main_done_flag = false;
    context->A_done_flag    = false;
    context->B_done_flag    = false;
    context->C_done_flag    = false;

    void * ptr;
    ptr = (void *)context;

    std::thread thread1(task1, ptr);
    std::thread thread2(task2, ptr);

    printf("lets begin:\n");
    context->main_done_mutex.lock();
    context->main_done_flag = true;
    context->main_done_mutex.unlock();
    context->main_done_cv.notify_all();

    if (thread1.joinable()) {
        thread1.join();
    }

    if (thread2.joinable()) {
        thread2.join();
    }    

    printf("all done !\n");

    free(context);

    return 0;
}
