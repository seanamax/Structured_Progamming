#include "../include/internal/CounsellorInfoManage.h"
#include "../include/internal/BasicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


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



// ɾ������Ա��Ϣ�� ͨ�� ��� flag ����ɾ��
// counsellor pcounsellorArray[] ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
void DeleteCounsellorInfo(counsellor pCounsellorArray[], const size_t len)
{

}



// ��Ӹ���Ա��Ϣ
// counsellor **pCounsellorArray ����ָ ����Ա����ָ���ָ��
// size_t *const pConLen ����ָ ����Ա������ĳ���
void AddCounsellorInfo(counsellor **pCounsellorArray, size_t *const pConLen)
{

}



// �޸ĸ���Ա��Ϣ
// counsellor *const pcounsellor ����ָ�޸ĵ�ǰ����Ա��Ϣ
void ChangeCounsellorInfo(counsellor *const pCounsellor)
{

}



// ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// size_t *const locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfo(const counsellor *const pCounsellorArray, const size_t len, size_t *const pLocateIndex)
{
    return false;
}


// ͨ�� ID ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const ID *const id ����ָ ��Ҫ�ҵ��ĸ���Ա��IDָ��
// size_t *const locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfoByID(const counsellor *const pCounsellorArray, const size_t len, const ID *const pID, size_t *const pLocateIndex)
{
    return true;
}


// ͨ�� ���� ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const char *const name ����ָ ��Ҫ�ҵ��ĸ���Ա������
// size_t *const pLocateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfoByName(const counsellor *const pCounsellorArray, const size_t len, const char *const name, size_t *const pLocateIndex)
{
    return true;
}
