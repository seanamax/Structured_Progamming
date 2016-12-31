#ifndef COUNSELLORINFOMANAGE_H
#define COUNSELLORINFOMANAGE_H

#include "common.h"

// ɾ������Ա��Ϣ�� ͨ�� ��� flag ����ɾ��
// counsellor pcounsellorArray[] ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
void DeleteCounsellorInfo(counsellor pCounsellorArray[], const size_t len);



// ��Ӹ���Ա��Ϣ
// counsellor **pCounsellorArray ����ָ ����Ա����ָ���ָ��
// size_t *const pConLen ����ָ ����Ա������ĳ���
void AddCounsellorInfo(counsellor **pCounsellorArray, size_t *const pConLen);



// �޸ĸ���Ա��Ϣ
// counsellor *const pcounsellor ����ָ�޸ĵ�ǰ����Ա��Ϣ
void ChangeCounsellorInfo(counsellor *const pCounsellor);



// ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// size_t *const locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfo(const counsellor *const pCounsellorArray, const size_t len, size_t *const pLocateIndex);



// ͨ�� ID ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const ID *const id ����ָ ��Ҫ�ҵ��ĸ���Ա��IDָ��
// size_t *const locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfoByID(const counsellor *const pCounsellorArray, const size_t len, const ID *const pID, size_t *const pLocateIndex);



// ͨ�� ���� ���Ҹ���Ա��Ϣ
// const counsellor *const pCounsellorArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const char *const name ����ָ ��Ҫ�ҵ��ĸ���Ա������
// size_t *const pLocateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateCounsellorInfoByName(const counsellor *const pCounsellorArray, const size_t len, const char *const name, size_t *const pLocateIndex);



// ��ʾ����Ա��Ϣ
// const counsellor *pcounsellor ����ָ��Ҫ��ʾ�ĸ���Աָ��
void DispCounsellorInfo(const counsellor *const pCounsellor);



// ��ʾ���и���Ա��Ϣ
// const counsellor *pcounsellorArray ����ָ��Ҫ��ʾ�ĸ���Ա����ָ��
// const size_t conLen ����ָ��Ҫ��ʾ�ĸ���Ա����ĳ���
void DispAllCounsellorInfo(const counsellor *const pCounsellorArray, const size_t conLen);


#endif // counsellorINFOMANAGE_H
