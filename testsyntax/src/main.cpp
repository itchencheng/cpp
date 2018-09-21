

#include "help.h"


int main() 
{
    for (int i = 1; i < 20; i++)
    {
        int need_w = i, tmp;
        int tmp_res = need_w % 16;
        int tmp_16x = need_w / 16;
        for (need_w = tmp_res ? 1 : 0, tmp = tmp_res; tmp >>= 1; need_w <<= 1);
        need_w = (tmp_16x << 4) + (tmp_res > need_w ? need_w * 2 : need_w) ;
        printf("%d: %d\n", i, need_w);

    }


    return 0;
}