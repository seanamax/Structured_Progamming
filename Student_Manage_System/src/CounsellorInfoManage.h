#ifndef COUNSELLORINFOMANAGE_H
#define COUNSELLORINFOMANAGE_H

#include "common.h"

// ɾ������Ա��Ϣ�� ͨ�� ��� flag ����ɾ��
// const counsellor *pcounsellorArray ����ָ����Ա����ָ��
// const size_t Len ����ָ ����Ա����ĳ���
void DeleteCounsellorInfo(const counsellor *pCounsellorArray, const size_t len);



// ��Ӹ���Ա��Ϣ
// counsellor **pCounsellorArray ����ָ ����Ա����ָ���ָ��
// const size_t *pConLen ����ָ ����Ա������ĳ���
// ID **pID ����ָ ������ ID ����ָ���ָ��
// const size_t *pIDLen ����ָ ������ ID ����ĳ���
void AddCounsellorInfo(counsellor **pCounsellorArray, const size_t *pConLen, ID **pID, const size_t *pIDLen);



// �޸ĸ���Ա��Ϣ
// const counsellor *pcounsellor ����ָ�޸ĵ�ǰ����Ա��Ϣ
void ChangeCounsellorInfo(const counsellor *pCounsellor);



// ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const size_t *locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfo(const counsellor *const pCounsellorArray, const size_t len, const size_t *pLocateIndex);



// ͨ�� ID ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const ID *const id ����ָ ��Ҫ�ҵ��ĸ���Ա��IDָ��
// const size_t *locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfoByID(const counsellor *const pCounsellorArray, const size_t len, const ID *const pID, const size_t *pLocateIndex);



// ͨ�� ���� ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const char *const name ����ָ ��Ҫ�ҵ��ĸ���Ա������
// const size_t *pLocateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfoByName(const counsellor *const pCounsellorArray, const size_t len, const char *const name, const size_t *pLocateIndex);



// ��ʾ����Ա��Ϣ
// const counsellor *pcounsellor ����ָ��Ҫ��ʾ�ĸ���Աָ��
void DispCounsellorInfo(const counsellor *const pCounsellor);



// ��ʾ���и���Ա��Ϣ
// const counsellor *pcounsellorArray ����ָ��Ҫ��ʾ�ĸ���Ա����ָ��
// const size_t conLen ����ָ��Ҫ��ʾ�ĸ���Ա����ĳ���
void DispAllCounsellorInfo(const counsellor *const pCounsellorArray, const size_t conLen);



#endif // counsellorINFOMANAGE_H
