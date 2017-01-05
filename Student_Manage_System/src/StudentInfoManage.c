#include "../include/internal/StudentInfoManage.h"
#include "../include/internal/BasicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 显示学生信息
// const student *pStudent 参数指需要显示的学生指针
void DispStudentInfo(const student *const pStudent)
{
    assert(pStudent && "The pointer is NULL in DispStudentInfo function, please check it out!");

    size_t i;

    PrintSplitLine();
    printf("ID: %s\n", pStudent->id.id);
    printf("Name: %s\n", pStudent->name);
    printf("Belong to Class: %s\n", pStudent->class);
    printf("Address: %s\n", pStudent->address);
    printf("Phone-Number: %s\n", pStudent->phoneNumber);
    puts("The subject(s) of he/she follow:");

    for(i=0; i < pStudent->subjectNum; ++i) {
        if(pStudent->pSubject[i].flag) {
            printf("%s\t%.2f\n", pStudent->pSubject[i].name, pStudent->pSubject[i].mark);
        }
    }

    PrintSplitLine();
}


// 显示所有学生信息
// const student *pStudentArray 参数指需要显示的学生数组指针
// const size_t conLen 参数指需要显示的学生数组的长度
void DispAllStudentInfo(const student *const pStudentArray, const size_t conLen)
{
    size_t i;

    for(i=0; i < conLen; ++i) {

        PrintSplitLine();
        //printf("The number of student array is: %u\n", i+1);
        DispStudentInfo(pStudentArray + i);
        putchar('\n');

    }
}



// 删除 学生数组信息
// student **pStudentArray 参数指 指向学生数组指针的指针
// size_t *pLen  参数指 学生数组长度的指针
void FreeStudentArray(student **pStudentArray, size_t *pLen)
{
    assert(pStudentArray && "the pointer is NULL");
    assert(pLen && "The pointer is NULL");

    int i;

    if(*pLen) {
        for(i=0; i < *pLen; ++i) {
            if((*pStudentArray)[i].subjectNum) {
                free((*pStudentArray)[i].pSubject);
            }
        }

        free(*pStudentArray);
    }

    *pLen = 0;
    *pStudentArray = NULL;
}



// 删除学生信息， 通过 标记 flag 惰性删除
// student *const pStudentArray 参数指学生数组指针
// const size_t Len 参数指 学生数组的长度
void DeleteStudentInfo(student *const pStudentArray, const size_t len)
{
    assert(pStudentArray && "the pointer is NULL!");

    char findID[STRINGBUFFERLEN];
    bool deleteFlag, findFlag;
    size_t i;

    PrintSplitLine();
    printf("Please input student ID: ");

    scanf("%s", findID);

    printf("Do you really delete ID: %s ?(y/n)\n", findID);

    deleteFlag = YesOrNo();

    if(deleteFlag) {

        findFlag = false;
        for(i=0; i < len; ++ i) {
            if(pStudentArray[i].id.flag && !strcmp(pStudentArray[i].id.id, findID)) {
                findFlag = true;
                pStudentArray[i].id.flag = false;
            }
        }

        if(findFlag) {
            puts("Delete success!");
        }
        else {
            puts("Cann't find this ID, please check it out!");
        }
    }

    PrintSplitLine();
}
