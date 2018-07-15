
#ifndef __HELPER_H_
#define __HELPER_H_

struct Context_t {
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
};

#endif
