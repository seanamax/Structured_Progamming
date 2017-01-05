#ifndef USERMANAGE_H
#define USERMANAGE_H

#include "common.h"

// ��ѧ����ݵ�¼��֤
// const student pStudentArray[] ����ָ ѧ������
// const size_t len ����ָ ѧ������ĳ���
// size_t *const pIndex ����ָ��֤�ɹ�����ø�ѧ����ѧ�������е��±�
// ��������ֵ bool �ͣ�������ֵΪ�棬���ʾ��֤�ɹ�������ʧ�ܣ�pIndex ֵ������
bool LoginByStudent(const student pStudentArray[], const size_t len, size_t *const pIndex);


// �Ը���Ա��ݵ�¼��֤
// const counsellor pCounsellorArray[] ����ָ ����Ա����
// const size_t len ����ָ ����Ա����ĳ���
// size_t *const pIndex ����ָ��֤�ɹ�����øø���Ա�ڸ���Ա�����е��±�
// ��������ֵ bool �ͣ� ������ֵΪ�棬���ʾ��֤�ɹ�������ʧ�ܣ�pIndex ֵ������
bool LoginByCounsellor(const counsellor pCounsellorArray[], const size_t len, size_t *const pIndex);

// �Թ���Ա��ݵ�¼��֤
// const admin *const pAdmin ����ָ ����Աָ��
// ��������ֵ bool �ͣ� ������ֵΪ�棬 ���ʾ��֤�ɹ��� ����ʧ��
bool LoginByAdmin(const admin *const pAdmin);



// ���ID �Ƿ�һ��
// ���� const ID *const pIDA ָ �˺�A
// ���� const ID *const pIDB ָ �˺�B
// ���˺�A �� �˺�B ��ȣ� �򷵻�ֵΪ �棬 ����Ϊ��
bool CheckID(const ID *const pIDA, const ID *const pIDB);


// �޸�����
// ���� ID *const pID Ϊ���޸ĵ��˺�ָ��
void ChangePassword(ID *const pID);



#endif // USERMANAGE_H
