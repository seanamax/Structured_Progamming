#include "../include/internal/CounsellorInfoManage.h"
#include "../include/internal/BasicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// 显示所有辅导员信息
// const counsellor *pcounsellorArray 参数指需要显示的辅导员数组指针
// const size_t conLen 参数指需要显示的辅导员数组的长度
void DispAllCounsellorInfo(const counsellor *const pCounsellorArray, const size_t conLen)
{
    assert(pCounsellorArray &&
           "the pointer is NULL in DispAllCounsellorInfo function, please check it out!");

    size_t i;

    for(i=0; i < conLen; ++i) {
        DispCounsellorInfo(pCounsellorArray + i);
    }
}



// 显示辅导员信息
// const counsellor *pcounsellor 参数指需要显示的辅导员指针
void DispCounsellorInfo(const counsellor *const pCounsellor)
{
    assert(pCounsellor &&
           "the pointer is NULL in DispCounsellorInfo function, please check it out!");

    size_t i;

    PrintSplitLine();
    printf("ID: %s\n", pCounsellor->id.id);
    printf("Name: %s\n", pCounsellor->name);
    printf("Address: %s\n", pCounsellor->address);
    puts("The manage class of he/she follow:");

    for(i=0; i < pCounsellor->manageClassNum; ++i) {
        if(pCounsellor->pClass[i].flag) {
            printf("%s\n", pCounsellor->pClass[i].name);
        }
    }
    PrintSplitLine();
    putchar('\n');
}


// 删除 辅导员数组信息
// counsellor **pCounsellorArray 参数指 指向辅导员数组指针的指针
// size_t *pLen 参数指 辅导员数组长度的指针
void FreeCounsellorArray(counsellor **pCounsellorArray, size_t *pLen)
{
    assert(pCounsellorArray && "the pointer is NULL");
    assert(pLen && "The pointer is NULL");

    int i;

    if(*pLen) {
        for(i=0; i < *pLen; ++i) {
            if((*pCounsellorArray)[i].manageClassNum) {
                free((*pCounsellorArray)[i].pClass);
            }
        }

        free(*pCounsellorArray);
    }

    *pLen = 0;
    *pCounsellorArray = NULL;
}
