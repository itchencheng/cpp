/*******************************************************
* filename    :    multiThread.h
* description :    cpp file
* author      :    chencheng
* date        :    20180716
*******************************************************/

#ifndef __XX_H_
#define __XX_H_

#include <cstdio>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

typedef struct {
    bool                     main_done_flag;
    std::mutex               main_done_mutex;
    std::condition_variable  main_done_cv;    

    bool                     A_done_flag;
    std::mutex               A_done_mutex;
    std::condition_variable  A_done_cv;

    bool                     B_done_flag;
    std::mutex               B_done_mutex;
    std::condition_variable  B_done_cv;

    bool                     C_done_flag;
    std::mutex               C_done_mutex;
    std::condition_variable  C_done_cv;
} Context_t, *pContext_t;



void task1(void * ptr);

void task2(void * ptr);



#endif //__XX_H_
