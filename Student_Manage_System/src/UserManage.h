#ifndef USERMANAGE_H

#include "common.h"

// ��¼
// ID *pIDArray ����ָ �˺�����
// const size_t idLen ����ָ �˺�����ĳ���
// size_t *pIDIndex ����ָ ��� ��¼��ȷ���˺����˺�������±�
// ��������ֵ bool ָ�Ƿ���ȷ��¼�� ������ȷ��¼���÷���ֵΪ�棬����Ϊ���� pIDIndex ֵ����ȷ
bool Login(ID *pIDArray, const size_t idLen, size_t *pIDIndex);

// ���ID �Ƿ�һ��
// ���� ID *pIDA ָ �˺�A
// ���� ID *pIDB ָ �˺�B
// ���˺�A �� �˺�B ��ȣ� �򷵻�ֵΪ �棬 ����Ϊ��
bool CheckID(ID *pIDA, ID *pIDB);

// �޸�����
// ���� ID *pID Ϊ���޸ĵ��˺�ָ��
void ChangePassWord(ID *pID);

#endif // USERMANAGE_H
