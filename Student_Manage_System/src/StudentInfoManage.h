#ifndef STUDENTINFOMANEGE_H
#define STUDENTINFOMANAGE_H

#include "common.h"

// ɾ��ѧ����Ϣ�� ͨ�� ��� flag ����ɾ��
// const student *pStudentArray ����ָѧ������ָ��
// const size_t Len ����ָ ѧ������ĳ���
void DeleteStudentInfo(const student *pStudentArray, const size_t len);




// ���ѧ����Ϣ
// student **pStudentArray ����ָ ѧ������ָ���ָ��
// const size_t *pConLen ����ָ ѧ��������ĳ���
// ID **pID ����ָ ������ ID ����ָ���ָ��
// const size_t *pIDLen ����ָ ������ ID ����ĳ���
void AddStudentInfo(student **pStudentArray, const size_t *pConLen, ID **pID, const size_t *pIDLen);



// �޸�ѧ����Ϣ
// const student *pStudent ����ָ�޸ĵ�ǰѧ����Ϣ
void ChangeStudentInfo(const student *pStudent);



// ����ѧ����Ϣ
// const student *const pStudentArray ����ָѧ������ָ��
// const size_t len ����ָ ѧ������ĳ���
// const size_t *locateIndex  ���� ָ �ҵ�ѧ���������е��±�
// ��������ֵ bool ֵ ָ�Ƿ���ѧ���������ҵ���ѧ����Ϣ����û���ҵ���locateIndex ֵû������
bool LocateStudentInfo(const student *const pStudentArray, const size_t len, const size_t *pLocateIndex);




// ͨ�� ID ����ѧ����Ϣ
// const student *const pStudentArray ����ָѧ������ָ��
// const size_t len ����ָ ѧ������ĳ���
// const ID *const id ����ָ ��Ҫ�ҵ���ѧ����IDָ��
// const size_t *locateIndex  ���� ָ �ҵ�ѧ���������е��±�
// ��������ֵ bool ֵ ָ�Ƿ���ѧ���������ҵ���ѧ����Ϣ����û���ҵ���locateIndex ֵû������
bool LocateStudentInfoByID(const student *const pStudentArray, const size_t len, const ID *const pID, const size_t *pLocateIndex);




// ͨ�� ���� ����ѧ����Ϣ
// const student *const pStudentArray ����ָѧ������ָ��
// const size_t len ����ָ ѧ������ĳ���
// const char *const name ����ָ ��Ҫ�ҵ���ѧ��������
// const size_t *pLocateIndex  ���� ָ �ҵ�ѧ���������е��±�
// ��������ֵ bool ֵ ָ�Ƿ���ѧ���������ҵ���ѧ����Ϣ����û���ҵ���locateIndex ֵû������
bool LocateStudentInfoByName(const student *const pStudentArray, const size_t len, const char *const name, const size_t *pLocateIndex);




// ��ʾѧ����Ϣ
// const student *pStudent ����ָ��Ҫ��ʾ��ѧ��ָ��
void DispStudentInfo(const student *const pStudent);




// ��ʾ����ѧ����Ϣ
// const student *pStudentArray ����ָ��Ҫ��ʾ��ѧ������ָ��
// const size_t conLen ����ָ��Ҫ��ʾ��ѧ������ĳ���
void DispAllStudentInfo(const student *const pStudentArray, const size_t conLen);


#endif // STUDENTINFOMANEGE_H
