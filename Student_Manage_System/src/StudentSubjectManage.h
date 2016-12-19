#ifndef STUDENTSUBJECTMANAGE_H
#define STUDENTSUBJECTMANAGE_H

#include "common.h"


// ɾ������ѧ����Ŀ��Ϣ�� ͨ�� ��� flag ����ɾ��
// const Student *const pStudentArray ����ָѧ������ָ��
// const size_t Len ����ָ ѧ������ĳ���
void DeleteAllStudentSubjectInfo(const student *const pStudentArray, const size_t len);



// �������ѧ����Ŀ��Ϣ��ͨ���޸��ѱ��ɾ���Ŀ�Ŀ�������·���ռ�
// const student *const pStudentArray ����ָ ѧ������ָ��
// const size_t len ����ָ ѧ��������ĳ���
void AddAllStudentSubjectInfo(const student *const pStudentArray, const size_t len);



// �޸�����ѧ����Ŀ��Ϣ��ͨ������ÿ��ѧ���Ŀ�Ŀ��Ϣ�������ҵ����ϵĿ�Ŀ��Ϣ�����޸ġ�
// const student *const pStudentArray ����ָ ѧ������ָ��
// const size_t len ����ָ ѧ��������ĳ���
void ChangeAllStudentSubjectInfo(const student *const pStudentArray, const size_t len);




// ɾ������ѧ����Ŀ��Ϣ�� ͨ�� ��� flag ����ɾ��
// const Student *const pStudent ����ָѧ��ָ��
void DeleteSingleStudentSubjectInfo(const student *const pStudent);




// ��ӵ���ѧ����Ŀ��Ϣ��ͨ���޸��ѱ��ɾ���Ŀ�Ŀ�������·���ռ�
// const student *const pStudent ����ָ ѧ��ָ��
void AddSingleStudentSubjectInfo(const student *const pStudent);



// �޸ĵ���ѧ����Ŀ��Ϣ��ͨ�����Ҹ�ѧ���Ŀ�Ŀ��Ϣ�������ҵ����ϵĿ�Ŀ��Ϣ�����޸ġ�
// const student *const pStudent ����ָ ѧ��ָ��
// ��������ֵ bool ��Ϊ�棬 ���޸ĳɹ��������޸�ʧ�ܻ�û���ҵ����ϵĿ�Ŀ
bool ChangeSingleStudentSubjectInfo(const student *const pStudentArray);

#endif // StudentSubjectSUBJECTMANAGE_H
