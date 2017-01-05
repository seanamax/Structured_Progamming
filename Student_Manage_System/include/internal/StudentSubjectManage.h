#ifndef STUDENTSUBJECTMANAGE_H
#define STUDENTSUBJECTMANAGE_H

#include "common.h"


// ɾ������ѧ����Ŀ��Ϣ�� ͨ�� ��� flag ����ɾ��
// student pStudentArray[] ����ָѧ������ָ��
// const size_t Len ����ָ ѧ������ĳ���
void DeleteAllStudentSubjectInfo(student pStudentArray[], const size_t len);



// �������ѧ����Ŀ��Ϣ��ͨ���޸��ѱ��ɾ���Ŀ�Ŀ�������·���ռ�
// student pStudentArray[] ����ָ ѧ������ָ��
// const size_t len ����ָ ѧ��������ĳ���
void AddAllStudentSubjectInfo(student pStudentArray[], const size_t len);



// �޸�����ѧ����Ŀ��Ϣ��ͨ������ÿ��ѧ���Ŀ�Ŀ��Ϣ�������ҵ����ϵĿ�Ŀ��Ϣ�����޸ġ�
// student pStudentArray[] ����ָ ѧ������ָ��
// const size_t len ����ָ ѧ��������ĳ���
void ChangeAllStudentSubjectInfo(student pStudentArray[], const size_t len);




// ɾ������ѧ����Ŀ��Ϣ�� ͨ�� ��� flag ����ɾ��
// const Student *const pStudent ����ָѧ��ָ��
void DeleteSingleStudentSubjectInfo(student *const pStudent);




// ��ӵ���ѧ����Ŀ��Ϣ��ͨ���޸��ѱ��ɾ���Ŀ�Ŀ�������·���ռ�
// const student *const pStudent ����ָ ѧ��ָ��
void AddSingleStudentSubjectInfo(student *const pStudent);



// �޸ĵ���ѧ����Ŀ��Ϣ��ͨ�����Ҹ�ѧ���Ŀ�Ŀ��Ϣ�������ҵ����ϵĿ�Ŀ��Ϣ�����޸ġ�
// student pStudent[] ����ָ ѧ��ָ��
// ��������ֵ bool ��Ϊ�棬 ���޸ĳɹ��������޸�ʧ�ܻ�û���ҵ����ϵĿ�Ŀ
bool ChangeSingleStudentSubjectInfo(student *const pStudent);

#endif // StudentSubjectSUBJECTMANAGE_H
