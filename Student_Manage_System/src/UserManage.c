#include "../include/internal/UserManage.h"
#include "../include/internal/Common.h"
#include "../include/internal/BasicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// ��ѧ����ݵ�¼��֤
// const student pStudentArray[] ����ָ ѧ������
// const size_t len ����ָ ѧ������ĳ���
// size_t *const pIndex ����ָ��֤�ɹ�����ø�ѧ����ѧ�������е��±�
// ��������ֵ bool �ͣ�������ֵΪ�棬���ʾ��֤�ɹ�������ʧ�ܣ�pIndex ֵ������
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

// �Ը���Ա��ݵ�¼��֤
// const counsellor pCounsellorArray[] ����ָ ����Ա����
// const size_t len ����ָ ����Ա����ĳ���
// size_t *const pIndex ����ָ��֤�ɹ�����øø���Ա�ڸ���Ա�����е��±�
// ��������ֵ bool �ͣ� ������ֵΪ�棬���ʾ��֤�ɹ�������ʧ�ܣ�pIndex ֵ������
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
// �Թ���Ա��ݵ�¼��֤
// const admin *const pAdmin ����ָ ����Աָ��
// ��������ֵ bool �ͣ� ������ֵΪ�棬 ���ʾ��֤�ɹ��� ����ʧ��
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

// �޸�����
// ���� ID *const pID Ϊ���޸ĵ��˺�ָ��
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

