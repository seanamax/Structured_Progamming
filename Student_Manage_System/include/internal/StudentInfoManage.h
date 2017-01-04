#ifndef STUDENTINFOMANEGE_H
#define STUDENTINFOMANAGE_H

#include "common.h"

// ɾ��ѧ����Ϣ�� ͨ�� ��� flag ����ɾ��
// const student *pStudentArray ����ָѧ������ָ��
// const size_t Len ����ָ ѧ������ĳ���
void DeleteStudentInfo(const student *pStudentArray, const size_t len);



// ���ѧ����Ϣ
// student **pStudentArray ����ָ ѧ������ָ���ָ��
// size_t *const pConLen ����ָ ѧ��������ĳ���

void AddStudentInfo(student **pStudentArray, size_t *const pConLen);



// �޸�ѧ����Ϣ
// const student *pStudent ����ָ�޸ĵ�ǰѧ����Ϣ
void ChangeStudentInfo(const student *pStudent);



// ����ѧ����Ϣ
// const student *const pStudentArray ����ָѧ������ָ��
// const size_t len ����ָ ѧ������ĳ���
// size_t *const locateIndex  ���� ָ �ҵ�ѧ���������е��±�
// ��������ֵ bool ֵ ָ�Ƿ���ѧ���������ҵ���ѧ����Ϣ����û���ҵ���locateIndex ֵû������
bool LocateStudentInfo(const student *const pStudentArray, const size_t len, size_t *const pLocateIndex);




// ͨ�� ID ����ѧ����Ϣ
// const student *const pStudentArray ����ָѧ������ָ��
// const size_t len ����ָ ѧ������ĳ���
// const ID *const id ����ָ ��Ҫ�ҵ���ѧ����IDָ��
// size_t *const locateIndex  ���� ָ �ҵ�ѧ���������е��±�
// ��������ֵ bool ֵ ָ�Ƿ���ѧ���������ҵ���ѧ����Ϣ����û���ҵ���locateIndex ֵû������
bool LocateStudentInfoByID(const student *const pStudentArray, const size_t len, const ID *const pID, size_t *const pLocateIndex);




// ͨ�� ���� ����ѧ����Ϣ
// const student *const pStudentArray ����ָѧ������ָ��
// const size_t len ����ָ ѧ������ĳ���
// const char *const name ����ָ ��Ҫ�ҵ���ѧ��������
// size_t *const pLocateIndex  ���� ָ �ҵ�ѧ���������е��±�
// ��������ֵ bool ֵ ָ�Ƿ���ѧ���������ҵ���ѧ����Ϣ����û���ҵ���locateIndex ֵû������
bool LocateStudentInfoByName(const student *const pStudentArray, const size_t len, const char *const name, size_t *const pLocateIndex);




// ��ʾѧ����Ϣ
// const student *pStudent ����ָ��Ҫ��ʾ��ѧ��ָ��
void DispStudentInfo(const student *const pStudent);




// ��ʾ����ѧ����Ϣ
// const student *pStudentArray ����ָ��Ҫ��ʾ��ѧ������ָ��
// const size_t conLen ����ָ��Ҫ��ʾ��ѧ������ĳ���
void DispAllStudentInfo(const student *const pStudentArray, const size_t conLen);


// ɾ�� ѧ��������Ϣ
// student **pStudentArray ����ָ ָ��ѧ������ָ���ָ��
// size_t *pLen  ����ָ ѧ�����鳤�ȵ�ָ��
void DelStudentArray(student **pStudentArray, size_t *pLen);

#endif // STUDENTINFOMANEGE_H
