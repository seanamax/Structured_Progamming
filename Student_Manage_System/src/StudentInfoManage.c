#include "../include/internal/StudentInfoManage.h"
#include "../include/internal/BasicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ��ʾѧ����Ϣ
// const student *pStudent ����ָ��Ҫ��ʾ��ѧ��ָ��
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


// ��ʾ����ѧ����Ϣ
// const student *pStudentArray ����ָ��Ҫ��ʾ��ѧ������ָ��
// const size_t conLen ����ָ��Ҫ��ʾ��ѧ������ĳ���
void DispAllStudentInfo(const student *const pStudentArray, const size_t conLen)
{
    size_t i;

    for(i=0; i < conLen; ++i) {

        PrintSplitLine();
        printf("The number of student array is: %u\n", i+1);
        DispStudentInfo(pStudentArray + i);
        putchar('\n');

    }
}
