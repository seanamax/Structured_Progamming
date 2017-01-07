#include "../include/internal/StudentInfoManage.h"
#include "../include/internal/BasicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("Sex: %s\n", pStudent->sex == Male ? "male" : "female");
    printf("Native place: %s\n", pStudent->nativePlace);
    printf("Birthday: %s\n", pStudent->birthday);
    printf("Major: %s\n", pStudent->major);
    printf("Year of enrollment: %s\n", pStudent->YearOfEnrollment);
    printf("Class: %s\n", pStudent->class);

    printf("Status: ");
    switch(pStudent->status) {

    case Be_Studying_At_School:
        puts("Be studying at school");

        break;



    case Suspension_of_Schooling:
        puts("Suspension of schooling");

        break;



    case Leavel_School:
        puts("Leavel school");

        break;



    case Serve_in_Army:
        puts("Serve in army");

        break;


    default:
        puts("none\n");
        break;
    }

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
        //printf("The number of student array is: %u\n", i+1);
        DispStudentInfo(pStudentArray + i);
        putchar('\n');

    }
}





// ɾ�� ѧ��������Ϣ
// student **pStudentArray ����ָ ָ��ѧ������ָ���ָ��
// size_t *pLen  ����ָ ѧ�����鳤�ȵ�ָ��
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





// ɾ��ѧ����Ϣ�� ͨ�� ��� flag ����ɾ��
// student *const pStudentArray ����ָѧ������ָ��
// const size_t Len ����ָ ѧ������ĳ���
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





// ���ѧ����Ϣ
// student **pStudentArray ����ָ ѧ������ָ���ָ��
// size_t *const pConLen ����ָ ѧ��������ĳ���
void AddStudentInfo(student **pStudentArray, size_t *const pConLen)
{
    assert(pStudentArray && "The pointer is NULL");
    assert(pConLen && "The pointer is NULL");

    size_t i;
    bool inputFlag;
    student inputStudent;
    bool addStudentFlag, findDeletedStudentFlag;

    PrintSplitLine();
    printf("input the ID: ");
    scanf("%s", inputStudent.id.id);

    printf("input the password: ");
    scanf("%s", inputStudent.id.password);

    inputStudent.id.flag = true;

    printf("input the name: ");
    scanf("%s", inputStudent.name);

    printf("choose male or female to sex. Y is male and N is female. ");
    if(YesOrNo()) {
        inputStudent.sex = Male;
    }
    else {
        inputStudent.sex = Female;
    }

    printf("input the native place: ");
    scanf("%s", inputStudent.nativePlace);

    printf("input the birthday: ");
    scanf("%s", inputStudent.birthday);

    printf("input the major: ");
    scanf("%s", inputStudent.major);

    printf("input the year of enrollment: ");
    scanf("%s", inputStudent.YearOfEnrollment);

    printf("input what class hs is belong to: ");
    scanf("%s", inputStudent.class);

    puts("choose status to the student:");
    puts("[1]. Be studying at school.");
    puts("[2]. Suspension of schooling.");
    puts("[3]. Leavel school.");
    puts("[4]. Serve in army.");

    i=0;
    while(i == 0 || i > 4) {
        inputFlag = scanf("%u", &i);
        if(inputFlag != 1) {
            getchar();
        }
    }

    switch(i) {
    case 1:
        inputStudent.status = Be_Studying_At_School;

        break;



    case 2:
        inputStudent.status = Suspension_of_Schooling;

        break;



    case 3:
        inputStudent.status = Leavel_School;

        break;


    case 4:
        inputStudent.status = Serve_in_Army;


    default:
        break;
    }

    printf("input address: ");
    scanf("%s", inputStudent.address);

    printf("input phone-number: ");
    scanf("%s", inputStudent.phoneNumber);

    printf("input the number of subject: ");
    scanf("%u", &inputStudent.subjectNum);

    inputStudent.pSubject = (subject *)malloc(inputStudent.subjectNum * sizeof(subject));
    assert(!(inputStudent.subjectNum != 0 && inputStudent.pSubject == NULL)
           && "Cann't alloc the class memory in AddStudentInfo function!");

    for(i=0; i < inputStudent.subjectNum; ++i) {
        printf("input the subject: ");
        scanf("%s", inputStudent.pSubject[i].name);

        printf("input mark of %s: ", inputStudent.pSubject[i].name);
        scanf("%f", &inputStudent.pSubject[i].mark);

        inputStudent.pSubject[i].flag = true;
    }

    puts("Do you really add this student ? y/n");
    addStudentFlag = YesOrNo();

    if(addStudentFlag) {

        findDeletedStudentFlag = false;
        for(i=0; i < *pConLen; ++i) {
            if(!(*pStudentArray[i]).id.flag) {
                findDeletedStudentFlag = true;
                free((*pStudentArray)[i].pSubject);
                (*pStudentArray)[i] = inputStudent;
                break;
            }
        }

        if(!findDeletedStudentFlag) {
            *pStudentArray = realloc(*pStudentArray, (*pConLen + 1) * sizeof(student));

            assert(*pStudentArray && "Cann't realloc the memory of student array");

            (*pStudentArray)[*pConLen] = inputStudent;

            *pConLen += 1;
        }
    }

    else {
        free(inputStudent.pSubject);
    }

}




// �޸�ѧ����Ϣ
// student *const pStudent ����ָ�޸ĵ�ǰѧ����Ϣ
void ChangeStudentInfo(student *const pStudent)
{
    assert(pStudent && "the pointer is NULL");

    student inputStudent;
    bool changeFlag;

    inputStudent = *pStudent;
    DispStudentInfo(pStudent);

    PrintSplitLine();
    printf("Do you change the name ? y/n  ");
    changeFlag = YesOrNo();
    if(changeFlag) {
        printf("input the name: ");
        scanf("%s", inputStudent.name);
    }

    printf("Do you change the id ? y/n  ");
    changeFlag = YesOrNo();
    if(changeFlag) {
        printf("input the id: ");
        scanf("%s", inputStudent.id.id);
    }

    printf("Do you change the address ? y/n  ");
    changeFlag = YesOrNo();
    if(changeFlag) {
        printf("input the address: ");
        scanf("%s", inputStudent.address);
    }

    printf("Do you change the class? y/n  ");
    changeFlag = YesOrNo();
    if(changeFlag) {
        printf("input the class: ");
        scanf("%s", inputStudent.class);
    }


    printf("Do you change the phone-number ? y/n  ");
    changeFlag = YesOrNo();
    if(changeFlag) {
        printf("input the phone-number: ");
        scanf("%s", inputStudent.phoneNumber);
    }

    puts("Do you really change for these ? y/n");
    changeFlag = YesOrNo();
    if(changeFlag) {
        *pStudent = inputStudent;
    }
}




// ͨ�� ID ����ѧ����Ϣ
// const student *const pStudentArray ����ָѧ������ָ��
// const size_t len ����ָ ѧ������ĳ���
// const ID *const id ����ָ ��Ҫ�ҵ���ѧ����IDָ��
// size_t *const locateIndex  ���� ָ �ҵ�ѧ���������е��±�
// ��������ֵ bool ֵ ָ�Ƿ���ѧ���������ҵ���ѧ����Ϣ����û���ҵ���locateIndex ֵû������
bool LocateStudentInfoByID(const student *const pStudentArray, const size_t len, const ID *const pID, size_t *const pLocateIndex)
{
    assert(pStudentArray && "the pointer is NULL");
    assert(pID && "the pointer is NULL");

    size_t i;
    for(i=0; i < len; ++i) {
        if(pStudentArray[i].id.flag && !strcmp(pID->id, pStudentArray[i].id.id)) {
            *pLocateIndex = i;
            return true;
        }
    }

    return false;
}




// ͨ�� ���� ����ѧ����Ϣ
// const student *const pStudentArray ����ָѧ������ָ��
// const size_t len ����ָ ѧ������ĳ���
// const char *const name ����ָ ��Ҫ�ҵ���ѧ��������
// size_t *const pLocateIndex  ���� ָ �ҵ�ѧ���������е��±�
// ��������ֵ bool ֵ ָ�Ƿ���ѧ���������ҵ���ѧ����Ϣ����û���ҵ���locateIndex ֵû������
bool LocateStudentInfoByName(const student *const pStudentArray, const size_t len, const char *const name, size_t *const pLocateIndex)
{
    assert(pStudentArray && "the pointer is NULL");

    size_t i;
    for(i=0; i < len; ++i) {
        if(pStudentArray[i].id.flag && !strcmp(name, pStudentArray[i].name)) {
            *pLocateIndex = i;
            return true;
        }
    }

    return false;
}




// ����ѧ����Ϣ
// const student *const pStudentArray ����ָѧ������ָ��
// const size_t len ����ָ ѧ������ĳ���
// size_t *const locateIndex  ���� ָ �ҵ�ѧ���������е��±�
// ��������ֵ bool ֵ ָ�Ƿ���ѧ���������ҵ���ѧ����Ϣ����û���ҵ���locateIndex ֵû������
bool LocateStudentInfo(const student *const pStudentArray, const size_t len, size_t *const pLocateIndex)
{
    assert(pStudentArray && "the pointer is NULL");
    assert(pLocateIndex && "the pointer is NULL");

    size_t chooseMode;
    char inputBuffer[STRINGBUFFERLEN];
    char inputFlag;
    ID id;

    PrintSplitLine();
    puts("Choose the mode how to locating information of students");
    puts("[1]. Student's name.");
    puts("[2]. Student's ID.");
    puts("[3]. Cancel.");

    chooseMode = 0;
    while(chooseMode != 1 && chooseMode != 2 && chooseMode != 3) {
        inputFlag  = scanf("%u", &chooseMode);
        if(inputFlag != 1) {
            getchar();
        }
    }

    switch(chooseMode) {

    case 1:
        PrintSplitLine();
        puts("Please input the student's name.");
        scanf("%s", inputBuffer);
        return LocateStudentInfoByName(pStudentArray, len, inputBuffer, pLocateIndex);


    case 2:
        PrintSplitLine();
        puts("Please input the student's ID.");
        scanf("%s", inputBuffer);
        strcpy(id.id, inputBuffer);
        return LocateStudentInfoByID(pStudentArray, len, &id, pLocateIndex);

    case 3:
        return false;
    }

    return false;
}


















































