#ifndef CONSELLERINFOMANAGE_H

#include "common.h"

// ɾ������Ա��Ϣ�� ͨ�� ��� flag ����ɾ��
// const conseller *pConsellerArray ����ָ����Ա����ָ��
// const size_t Len ����ָ ����Ա����ĳ���
void DeleteConsellerInfo(const conseller *pConsellerArray, const size_t len);



// ��Ӹ���Ա��Ϣ
// conseller **pConsellerArray ����ָ ����Ա����ָ���ָ��
// const size_t *pConLen ����ָ ����Ա������ĳ���
// ID **pID ����ָ ������ ID ����ָ���ָ��
// const size_t *pIDLen ����ָ ������ ID ����ĳ���
void AddConsellerInfo(conseller **pConsellerArray, const size_t *pConLen, ID **pID, const size_t *pIDLen);



// �޸ĸ���Ա��Ϣ
// const conseller *pConseller ����ָ�޸ĵ�ǰ����Ա��Ϣ
void ChangeConsellerInfo(const conseller *pConseller);



// ���Ҹ���Ա��Ϣ
// const conseller *const pConsellerArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const size_t *locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateConsellerInfo(const conseller *const pConsellerArray, const size_t len, const size_t *pLocateIndex);



// ͨ�� ID ���Ҹ���Ա��Ϣ
// const conseller *const pConsellerArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const ID *const id ����ָ ��Ҫ�ҵ��ĸ���Ա��IDָ��
// const size_t *locateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateConsellerInfoByID(const conseller *const pConsellerArray, const size_t len, const ID *const pID, const size_t *pLocateIndex);



// ͨ�� ���� ���Ҹ���Ա��Ϣ
// const conseller *const pConsellerArray ����ָ����Ա����ָ��
// const size_t len ����ָ ����Ա����ĳ���
// const char *const name ����ָ ��Ҫ�ҵ��ĸ���Ա������
// const size_t *pLocateIndex  ���� ָ �ҵ�����Ա�������е��±�
// ��������ֵ bool ֵ ָ�Ƿ��ڸ���Ա�������ҵ��ø���Ա��Ϣ����û���ҵ���locateIndex ֵû������
bool LocateConsellerInfoByName(const conseller *const pConsellerArray, const size_t len, const char *const name, const size_t *pLocateIndex);



// ��ʾ����Ա��Ϣ
// const conseller *pConseller ����ָ��Ҫ��ʾ�ĸ���Աָ��
void DispConsellerInfo(const conseller *const pConseller);



// ��ʾ���и���Ա��Ϣ
// const conseller *pConsellerArray ����ָ��Ҫ��ʾ�ĸ���Ա����ָ��
// const size_t conLen ����ָ��Ҫ��ʾ�ĸ���Ա����ĳ���
void DispAllConsellerInfo(const conseller *const pConsellerArray, const size_t conLen);

#endif // CONSELLERINFOMANAGE_H
