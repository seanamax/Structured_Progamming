#include "../include/internal/StudentSubjectManage.h"
#include "../include/internal/BasicFunc.h"
#include "../include/internal/StudentInfoManage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

// 删除所有学生科目信息， 通过 标记 flag 惰性删除
// student pStudentArray[] 参数指学生数组指针
// const size_t Len 参数指 学生数组的长度
void DeleteAllStudentSubjectInfo(student pStudentArray[], const size_t len)
{

    size_t i,j,b;
    char a[STRINGBUFFERLEN];

    PrintSplitLine();
    PrintSplitLine();

    puts("Please input the name of subject.\n");
    scanf("%s", a);

    puts("Are you sure delete the subject for all students? y/n\n");

    b = YesOrNo();
    if(b == true)
    {
        for(i=0; i < len; ++i)
        {
            for(j=0 ; j < pStudentArray[i].subjectNum; ++j)
            {
                if(pStudentArray[i].pSubject[j].flag && !strcmp(a , pStudentArray[i].pSubject[j].name))
                {
                    pStudentArray[i].pSubject[j].flag = false;
                }
            }
        }
    }
    else
        getchar();

    puts("Delete succeed!\n");
    PrintSplitLine();
    PrintSplitLine();
}

// 添加所有学生科目信息，通过修改已标记删除的科目或者重新分配空间
// student pStudentArray[] 参数指 学生数组指针
// const size_t len 参数指 学生是数组的长度
void AddAllStudentSubjectInfo(student pStudentArray[], const size_t len)
{
    size_t i,j,b;
    char _subject_[STRINGBUFFERLEN];
    bool Addedflag;

    PrintSplitLine();
    PrintSplitLine();

    puts("Please input the name of subject.\n");
    scanf("%s", _subject_);

    puts("Are you sure add the subject for all students? y/n\n");

    b = YesOrNo();
    if(b == true)
    {
        //puts("Input the name of subject!\n");
        //scanf("%s" , &a);
        for(i = 0 ; i < len ; ++i)
        {
            Addedflag = false;
            for(j = 0 ; j < pStudentArray[i].subjectNum; ++j)
            {
                if(!pStudentArray[i].pSubject[j].flag)
                {
                    //strcmp()
                    Addedflag = true;
                    strcpy(pStudentArray[i].pSubject[j].name , _subject_);
                    pStudentArray[i].pSubject[j].mark = 0.0f;
                    pStudentArray[i].pSubject[j].flag = true;

                    break;
                }

            }

            if(!Addedflag) {
                pStudentArray[i].pSubject = realloc(pStudentArray[i].pSubject, (pStudentArray[i].subjectNum + 1) * sizeof(subject));/*malloc free copy*/
                assert(pStudentArray[i].pSubject && "the pointer is NULL!");

                strcpy(pStudentArray[i].pSubject[pStudentArray[i].subjectNum].name, _subject_);
                pStudentArray[i].pSubject[pStudentArray[i].subjectNum].flag = true;
                pStudentArray[i].pSubject[pStudentArray[i].subjectNum].mark = 0.0f;
                pStudentArray[i].subjectNum += 1;

            }
        }
    }

    puts("Add succeed!\n");
    PrintSplitLine();
    PrintSplitLine();

}




// 修改所有学生科目信息，通过查找每个学生的科目信息，如若找到符合的科目信息，则修改。
// student pStudentArray[] 参数指 学生数组指针
// const size_t len 参数指 学生是数组的长度
void ChangeAllStudentSubjectInfo(student pStudentArray[], const size_t len)
{
    size_t i,j,b;
    bool setZeroFlag;

    char _subject_1[STRINGBUFFERLEN];
    char _subject_2[STRINGBUFFERLEN];

    PrintSplitLine();
    PrintSplitLine();

    puts("Please input the name of subject!\n");
    puts("The first is the subject you want to modify,\n");
    puts("The second is the subject you want to change to.\n");
    scanf("%s %s", _subject_1, _subject_2);

    puts("Are you sure modify the subject for all students? y/n\n");


    b = YesOrNo();
    if(b == true)
    {
        puts("Are you sure modify the subject's mark for '0'? y/n\n");


        setZeroFlag = YesOrNo();
        for(i = 0; i < len; ++i)
        {
            for(j=0 ; j<pStudentArray[i].subjectNum ; ++j)
            {

                if(pStudentArray[i].id.flag && pStudentArray[i].pSubject[j].flag && !strcmp(pStudentArray[i].pSubject[j].name, _subject_1))
                {

                    strcpy(pStudentArray[i].pSubject[j].name, _subject_2);

                    if(setZeroFlag)
                    {
                        pStudentArray[i].pSubject[j].mark = 0.0f;
                    }
                }
            }
        }

    }


    puts("Modify succeed!\n");
    PrintSplitLine();
    PrintSplitLine();
}

// 删除单个学生科目信息， 通过 标记 flag 惰性删除
// const Student *const pStudent 参数指学生指针
void DeleteSingleStudentSubjectInfo(student *const pStudent)
{
    assert(pStudent && "Can't find the student!\n");

    size_t j,b;
    char a[STRINGBUFFERLEN];

    PrintSplitLine();
    PrintSplitLine();

    puts("Please input the name of subject.\n");
    scanf("%s" , a);

    puts("Are you sure delete the subject for the student? y/n\n");

    b = YesOrNo();
    if(b == true)
    {
            for(j=0 ; j < pStudent->subjectNum; ++j)
            {
                if(pStudent->pSubject[j].flag && !strcmp(a , pStudent->pSubject[j].name))
                {
                    pStudent->pSubject[j].flag = false;
                }
            }
    }


    puts("Delete succeed!\n");
    PrintSplitLine();
    PrintSplitLine();
}


// 添加单个学生科目信息，通过修改已标记删除的科目或者重新分配空间
// const student *const pStudent 参数指 学生指针
void AddSingleStudentSubjectInfo(student *const pStudent)
{
    assert(pStudent && "The pointer is NULL!\n");

    size_t j,b;
    char _subject_[STRINGBUFFERLEN];
    bool Addedflag;

    PrintSplitLine();
    PrintSplitLine();

    puts("Please input the name of subject.\n");
    scanf("%s", _subject_);

    puts("Are you sure add the subject for the student? y/n\n");

    b = YesOrNo();
    if(b == true)
    {
        //puts("Input the name of subject!\n");
        //scanf("%s" , &a);
            Addedflag = false;
            for(j = 0 ; j < pStudent -> subjectNum; ++j)
            {
                if(!pStudent -> pSubject[j].flag)
                {
                    //strcmp()
                    Addedflag = true;
                    strcpy(pStudent -> pSubject[j].name , _subject_);
                    pStudent -> pSubject[j].mark = 0.0f;
                    pStudent -> pSubject[j].flag = true;
                    break;
                }

            }

            if(!Addedflag) {
                pStudent -> pSubject = realloc(pStudent -> pSubject, (pStudent -> subjectNum + 1) * sizeof(subject));/*malloc free copy*/
                assert(pStudent -> pSubject && "the pointer is NULL!");

                strcpy(pStudent -> pSubject[pStudent -> subjectNum].name, _subject_);
                pStudent -> pSubject[pStudent -> subjectNum].flag = true;
                pStudent -> pSubject[pStudent -> subjectNum].mark = 0.0f;
                pStudent -> subjectNum += 1;

            }
    }

    puts("Add succeed!\n");
    PrintSplitLine();
    PrintSplitLine();
}



// 修改单个学生科目信息，通过查找该学生的科目信息，如若找到符合的科目信息，则修改。
// student pStudent[] 参数指 学生指针
// 函数返回值 bool 若为真， 则修改成功，否则修改失败或没有找到符合的科目
bool ChangeSingleStudentSubjectInfo(student *const pStudent)
{
    assert(pStudent && "The pointer is NULL!\n");

    size_t j,b;
    bool setZeroFlag;
    bool changeFlag;

    char _subject_1[STRINGBUFFERLEN];
    char _subject_2[STRINGBUFFERLEN];

    PrintSplitLine();
    PrintSplitLine();

    puts("Please input the name of subject!\n");
    puts("The first is the subject you want to modify,\n");
    puts("The second is the subject you want to change to.\n");
    scanf("%s %s" , _subject_1 , _subject_2);

    puts("Are you sure modify the subject for the students? y/n\n");

    changeFlag = false;
    b = YesOrNo();
    if(b == true)
    {
        puts("Are you sure modify the subject's mark for '0'? y/n\n");
        setZeroFlag = YesOrNo();

        for(j=0 ; j < pStudent -> subjectNum ; ++j)
            {
                if(pStudent -> pSubject[j].flag && !strcmp(pStudent -> pSubject[j].name, _subject_1))
                {
                    changeFlag = true;
                    strcpy(pStudent -> pSubject[j].name, _subject_2);
                    if(setZeroFlag)
                    {
                        pStudent -> pSubject[j].mark = 0.0f;
                    }
                }
            }


    }


    puts("Modify succeed!\n");
    PrintSplitLine();
    PrintSplitLine();

    return changeFlag;
}
