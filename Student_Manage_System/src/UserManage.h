#ifndef USERMANAGE_H
#define USERMANAGE_H

#include "common.h"

// ��¼
// const ID *const pIDArray ����ָ �˺�����
// const size_t idLen ����ָ �˺�����ĳ���
// size_t *pIDIndex ����ָ ��� ��¼��ȷ���˺����˺�������±�
// ��������ֵ bool ָ�Ƿ���ȷ��¼�� ������ȷ��¼���÷���ֵΪ�棬����Ϊ���� pIDIndex ֵ����ȷ
bool Login(const ID *const pIDArray, const size_t idLen, size_t *pIDIndex);


// ���ID �Ƿ�һ��
// ���� const ID *const pIDA ָ �˺�A
// ���� const ID *const pIDB ָ �˺�B
// ���˺�A �� �˺�B ��ȣ� �򷵻�ֵΪ �棬 ����Ϊ��
bool CheckID(const ID *const pIDA, const ID *const pIDB);


// �޸�����
// ���� ID *pID Ϊ���޸ĵ��˺�ָ��
void ChangePassWord(const ID *pID);



#endif // USERMANAGE_H
