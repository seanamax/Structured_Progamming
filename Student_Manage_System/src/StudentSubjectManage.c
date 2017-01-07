#include "../include/internal/StudentSubjectManage.h"
#include "../include/internal/BasicFunc.h"
#include "../include/internal/StudentInfoManage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

// ɾ������ѧ����Ŀ��Ϣ�� ͨ�� ��� flag ����ɾ��
// student pStudentArray[] ����ָѧ������ָ��
// const size_t Len ����ָ ѧ������ĳ���
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

// �������ѧ����Ŀ��Ϣ��ͨ���޸��ѱ��ɾ���Ŀ�Ŀ�������·���ռ�
// student pStudentArray[] ����ָ ѧ������ָ��
// const size_t len ����ָ ѧ��������ĳ���
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




// �޸�����ѧ����Ŀ��Ϣ��ͨ������ÿ��ѧ���Ŀ�Ŀ��Ϣ�������ҵ����ϵĿ�Ŀ��Ϣ�����޸ġ�
// student pStudentArray[] ����ָ ѧ������ָ��
// const size_t len ����ָ ѧ��������ĳ���
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

// ɾ������ѧ����Ŀ��Ϣ�� ͨ�� ��� flag ����ɾ��
// const Student *const pStudent ����ָѧ��ָ��
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


// ��ӵ���ѧ����Ŀ��Ϣ��ͨ���޸��ѱ��ɾ���Ŀ�Ŀ�������·���ռ�
// const student *const pStudent ����ָ ѧ��ָ��
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



// �޸ĵ���ѧ����Ŀ��Ϣ��ͨ�����Ҹ�ѧ���Ŀ�Ŀ��Ϣ�������ҵ����ϵĿ�Ŀ��Ϣ�����޸ġ�
// student pStudent[] ����ָ ѧ��ָ��
// ��������ֵ bool ��Ϊ�棬 ���޸ĳɹ��������޸�ʧ�ܻ�û���ҵ����ϵĿ�Ŀ
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
