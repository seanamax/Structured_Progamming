#include "../include/internal/CounsellorInfoManage.h"
#include "../include/internal/Common.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// ɾ������Ա��Ϣ�� ͨ�� ��� flag ����ɾ��
// counsellor pcounsellorArray[] ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
void DeleteCounsellorInfo(counsellor pCounsellorArray[], const size_t len)

{

    assert(pCounsellorArray && "the pointer is NULL!");
    char ID[ID_LEN];
    bool f,k;
    size_t i;

    PrintSplitLine();
    printf("Please input counsellor ID: ");
    scanf("%s", ID);
    printf("Are you sure delete ID: %s ?(y/n)\n", ID);
    f = YesOrNo();
    if(f){
        k = false;
        for(i=0; i < len; ++ i) {
            if(pCounsellorArray[i].id.flag && !strcmp(pCounsellorArray[i].id.id, ID)) {
                k = true;
                pCounsellorArray[i].id.flag = false;
            }
        }
        if(k) {
            puts("Delete success!");
        }
        else {
            puts("Cann't find this ID, please check it out!");
        }

    }
    PrintSplitLine();

}

// ��Ӹ���Ա��Ϣ
// counsellor **pCounsellorArray ����ָ ����Ա����ָ���ָ��
// size_t *const pConLen ����ָ ����Ա������ĳ���
void AddCounsellorInfo(counsellor **pCounsellorArray, size_t *const pConLen)
{
    assert(pCounsellorArray && "The pointer is NULL");
    assert(pConLen && "The pointer is NULL");
    size_t i;
    counsellor inputCounsellor;
    bool AddFlag, DelFlag;


    PrintSplitLine();
    printf("input the ID: ");
    scanf("%s", inputCounsellor.id.id);

    printf("input the password: ");
    scanf("%s", inputCounsellor.id.password);

    inputCounsellor.id.flag = true;

    printf("input the name: ");
    scanf("%s", inputCounsellor.name);

    printf("input address: ");
    scanf("%s", inputCounsellor.address);

    printf("input the number of class: ");
    scanf("%u", &inputCounsellor.manageClassNum);

    inputCounsellor.pClass = (class *)malloc(inputCounsellor.manageClassNum * sizeof(class));
    assert(!(inputCounsellor.manageClassNum != 0 && inputCounsellor.pClass == NULL)
           && "Cann't alloc the class memory in AddStudentInfo function!");



    for(i=0; i < inputCounsellor.manageClassNum; ++i) {
        printf("input the class: ");
        scanf("%s", inputCounsellor.pClass[i].name);

        inputCounsellor.pClass[i].flag = true;
    }
    puts("Do you really add this counsellor ? y/n");
    AddFlag = YesOrNo();

    if(AddFlag) {

        DelFlag = false;
        for(i=0; i < *pConLen; ++i) {
            if(!(*pCounsellorArray[i]).id.flag) {
                DelFlag = true;
                free((*pCounsellorArray)[i].pClass);
                (*pCounsellorArray)[i] = inputCounsellor;
                break;
            }
        }
        if(!DelFlag) {
            *pCounsellorArray = realloc(*pCounsellorArray, (*pConLen + 1) * sizeof(counsellor));

            assert(*pCounsellorArray && "Cann't realloc the memory of Counsellor array");

            (*pCounsellorArray)[*pConLen] = inputCounsellor;

            *pConLen += 1;
        }
        else {
           free(inputCounsellor.pClass);
    }

  }
}


// �޸ĸ���Ա��Ϣ
// counsellor *const pcounsellor ����ָ�޸ĵ�ǰ����Ա��Ϣ
void ChangeCounsellorInfo(counsellor *const pCounsellor)
{

    assert(pCounsellor && "the pointer is NULL");

    counsellor inputCounsellor;
    size_t i;
    bool changeFlag;

    inputCounsellor = *pCounsellor;
    DispStudentInfo(pCounsellor);

    PrintSplitLine();
    printf("Do you change the name ? y/n  ");
    changeFlag = YesOrNo();
    if(changeFlag) {
        printf("input the name: ");
        scanf("%s", inputCounsellor.name);
    }

    printf("Do you change the id ? y/n  ");
    changeFlag = YesOrNo();
    if(changeFlag) {
        printf("input the id: ");
        scanf("%s", inputCounsellor.id.id);
    }

    printf("Do you change the address ? y/n  ");
    changeFlag = YesOrNo();
    if(changeFlag) {
        printf("input the address: ");
        scanf("%s", inputCounsellor.address);
    }





    puts("Do you really change for these ? y/n");
    changeFlag = YesOrNo();
    if(changeFlag) {
        *pCounsellor = inputCounsellor;
    }


}


// ͨ�� ID ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const ID *const id ����ָ ��Ҫ�ҵ��ĸ���Ա��IDָ��
// size_t *const locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfoByID(const counsellor *const pCounsellorArray, const size_t len, const ID *const pID, size_t *const pLocateIndex)
{
    assert(pCounsellorArray && "the pointer is NULL");
    assert(pID && "the pointer is NULL");

    size_t i;
    for(i=0; i < len; ++i) {
        if(pCounsellorArray[i].id.flag && !strcmp(pID->id, pCounsellorArray[i].id.id)) {
            *pLocateIndex = i;
            return true;
        }
    }

    return false;
}

// ͨ�� ���� ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const char *const name ����ָ ��Ҫ�ҵ��ĸ���Ա������
// size_t *const pLocateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfoByName(const counsellor *const pCounsellorArray, const size_t len, const char *const name, size_t *const pLocateIndex)
{
    assert(pCounsellorArray && "the pointer is NULL");

    size_t i;
    for(i=0; i < len; ++i) {
        if(pCounsellorArray[i].id.flag && !strcmp(name, pCounsellorArray[i].name)) {
            *pLocateIndex = i;
            return true;
        }
    }

    return false;
}

// ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// size_t *const locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfo(const counsellor *const pCounsellorArray, const size_t len, size_t *const pLocateIndex)
{
    assert(pCounsellorArray && "the pointer is NULL");
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
        return LocateCounsellorInfoByName(pCounsellorArray, len, inputBuffer, pLocateIndex);


    case 2:
        PrintSplitLine();
        puts("Please input the student's ID.");
        scanf("%s", inputBuffer);
        strcpy(id.id, inputBuffer);
        return LocateCounsellorInfoByID(pCounsellorArray, len, &id, pLocateIndex);

    case 3:
        return false;
    }
}




// ��ʾ���и���Ա��Ϣ
// const counsellor *pcounsellorArray ����ָ��Ҫ��ʾ�ĸ���Ա����ָ��
// const size_t conLen ����ָ��Ҫ��ʾ�ĸ���Ա����ĳ���
void DispAllCounsellorInfo(const counsellor *const pCounsellorArray, const size_t conLen)
{
    assert(pCounsellorArray &&
           "the pointer is NULL in DispAllCounsellorInfo function, please check it out!");

    size_t i;

    for(i=0; i < conLen; ++i) {
        DispCounsellorInfo(pCounsellorArray + i);
    }
}




// ��ʾ����Ա��Ϣ
// const counsellor *pcounsellor ����ָ��Ҫ��ʾ�ĸ���Աָ��
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


// ɾ�� ����Ա������Ϣ
// counsellor **pCounsellorArray ����ָ ָ�򸨵�Ա����ָ���ָ��
// size_t *pLen ����ָ ����Ա���鳤�ȵ�ָ��
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

