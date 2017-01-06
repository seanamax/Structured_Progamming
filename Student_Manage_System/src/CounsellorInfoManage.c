#include "../include/internal/CounsellorInfoManage.h"
#include "../include/internal/Common.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// 删除辅导员信息， 通过 标记 flag 惰性删除
// counsellor pcounsellorArray[] 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
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

// 添加辅导员信息
// counsellor **pCounsellorArray 参数指 辅导员数组指针的指针
// size_t *const pConLen 参数指 辅导员是数组的长度
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


// 修改辅导员信息
// counsellor *const pcounsellor 参数指修改当前辅导员信息
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


// 通过 ID 查找辅导员信息
// const counsellor *const pCounsellorArray 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
// const ID *const id 参数指 需要找到的辅导员的ID指针
// size_t *const locateIndex  参数 指 找到辅导员在数组中的下标
// 函数返回值 bool 值 指是否在辅导员数组中找到该辅导员信息，若没有找到，locateIndex 值没有意义
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

// 通过 姓名 查找辅导员信息
// const counsellor *const pCounsellorArray 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
// const char *const name 参数指 需要找到的辅导员的姓名
// size_t *const pLocateIndex  参数 指 找到辅导员在数组中的下标
// 函数返回值 bool 值 指是否在辅导员数组中找到该辅导员信息，若没有找到，locateIndex 值没有意义
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

// 查找辅导员信息
// const counsellor *const pCounsellorArray 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
// size_t *const locateIndex  参数 指 找到辅导员在数组中的下标
// 函数返回值 bool 值 指是否在辅导员数组中找到该辅导员信息，若没有找到，locateIndex 值没有意义
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

