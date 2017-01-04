#include "../include/internal/BasicFunc.h"
#include "stdio.h"


inline void PrintSplitLine()
{
    puts("--------------------------------------------------------------");
}


inline bool YesOrNo()
{
    char ch = '0';
    while(ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n') {
        ch = getchar();
    }

    if(ch == 'y' || ch == 'Y') {
        return true;
    }

    return false;
}


