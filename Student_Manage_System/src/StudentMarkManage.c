#include "../include/internal/StudentMarkManage.h"
#include "../include/internal/BasicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


// 添加 单个学生的成绩
// const student *const pStudent 参数指学生的指针
void AddMark(student *const pStudent)
{
    assert(pStudent && "The pointer is NULL!\n");

    size_t i;
    bool flag;

    PrintSplitLine();
    PrintSplitLine();

    //puts("Input error,pls input again!\n");

    for(i=0; i < pStudent->subjectNum; ++i)
    {
        if(pStudent->pSubject[i].flag)
        {
            printf("%s: ", pStudent->pSubject[i].name);
            puts("Please input the marks.");

            flag = true;
            while(flag)
            {
                if(scanf("%f", &pStudent->pSubject[i].mark) == 1)
                {
                    flag = false;
                }
                else
                {
                    getchar();
                }
            }
        }
    }

    PrintSplitLine();
    PrintSplitLine();
}



// 修改 单个学生的成绩
// const student *const pStudent 参数指学生的指针
void ChangeMark(student *const pStudent)
{
    PrintSplitLine();
    PrintSplitLine();


    assert(pStudent && "The pointer is NULL!\n");

    size_t i;
    bool Changeflag;
    float mark;

    for(i=0; i < pStudent->subjectNum; ++i)
    {
        //Changeflag = false;
        if(pStudent->pSubject[i].flag)
        {

            printf("%s: ", pStudent -> pSubject[i].name);
            printf("\n");
            printf("%f  ",pStudent -> pSubject[i].mark);
            printf("\n");

            puts("Do you want to skip this subject? y/n\n");
            Changeflag = YesOrNo();

            if(!Changeflag)
            {
                puts("Please input the subject you want to modify.\n");

                printf("Input the %s's mark: ", pStudent->pSubject[i].name);
                scanf("%f", &mark);
                puts("Do you want to modify the mark? y/n\n");

                Changeflag = YesOrNo();
                if(Changeflag)
                {
                    pStudent->pSubject[i].mark = mark;
                }
            }
        }

    }
    puts("Modify succeed!\n");
    PrintSplitLine();
    PrintSplitLine();
}
