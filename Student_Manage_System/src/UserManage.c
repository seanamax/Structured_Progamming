#include "../include/internal/UserManage.h"
#include "../include/internal/Common.h"
#include "../include/internal/BasicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// 以学生身份登录认证
// const student pStudentArray[] 参数指 学生数组
// const size_t len 参数指 学生数组的长度
// size_t *const pIndex 参数指认证成功，获得该学生在学生数组中的下标
// 函数返回值 bool 型，若返回值为真，则表示认证成功，否则失败，pIndex 值无意义
bool LoginByStudent(const student pStudentArray[], const size_t len, size_t *const pIndex){

    size_t i,j;
    ID inputID;

    puts("You have only three times try to login or exit!");
    for(i=0; i < 3; ++i) {
        printf("You have %d times try to login!\n", 3-i);

        printf("Input the ID: ");
        scanf("%s", inputID.id);
        printf("Input the password: ");
        scanf("%s", inputID.password);

        for(j=0; j < len; ++j) {
            if(CheckID(&pStudentArray[j].id, &inputID)) {
                *pIndex = j;
                return true;
            }
        }
    }
    return false;
}

// 以辅导员身份登录认证
// const counsellor pCounsellorArray[] 参数指 辅导员数组
// const size_t len 参数指 辅导员数组的长度
// size_t *const pIndex 参数指认证成功，获得该辅导员在辅导员数组中的下标
// 函数返回值 bool 型， 若返回值为真，则表示认证成功，否则失败，pIndex 值无意义
bool LoginByCounsellor(const counsellor pCounsellorArray[], const size_t len, size_t *const pIndex)
{
    size_t i,j;
    ID inputID;

    puts("You have only three times try to login or exit!");
    for(i=0; i < 3; ++i) {
        printf("You have %d times try to login!\n", 3-i);

        printf("Input the ID: ");
        scanf("%s", inputID.id);
        printf("Input the password: ");
        scanf("%s", inputID.password);

        for(j=0; j < len; ++j) {
            if(CheckID(&pCounsellorArray[j].id, &inputID)) {
                *pIndex = j;
                return true;
            }
        }
    }
    return false;
}
// 以管理员身份登录认证
// const admin *const pAdmin 参数指 管理员指针
// 函数返回值 bool 型， 若返回值为真， 则表示认证成功， 否则失败
bool LoginByAdmin(const admin *const pAdmin)
{
    size_t i;
    ID inputID;

    puts("You have only three times try to login or exit!");
    for(i=0; i < 3; ++i) {
        printf("You have %d times try to login!\n", 3-i);

        printf("Input the ID: ");
        scanf("%s", inputID.id);
        printf("Input the password: ");
        scanf("%s", inputID.password);

        if(CheckID(&pAdmin->id, &inputID)) {
                return true;
            }

    }
    return false;
}


bool CheckID(const ID *const pIDA, const ID *const pIDB)
{
    assert(pIDA && "The pointer is NULL");
    assert(pIDB && "The pointer is NULL");

    return  !strcmp(pIDA->id, pIDB->id) && !strcmp(pIDA->password, pIDB->password);


}

// 修改密码
// 参数 ID *const pID 为待修改的账号指针
void ChangePassword(ID *const pID)
{
    assert(pID && "the pointer is NULL");

    bool f;
    ID inputID;
    PrintSplitLine();
    printf("Do you want to change the password? y/n");
    f = YesOrNo();
    if(f){
        printf("Input the new password");
        scanf("%s", inputID.password);
    }
    printf("Are you sure change the password? y/n");
    if(f){
        *pID = inputID;
    }



}

