#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "common.h"


// ��ʼ���ļ�ϵͳ����ȡ�����ļ�
// const fileStruct *pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// ��������ֵ bool ��Ϊ�棬���ʼ���ɹ��������ʼ��ʧ��
bool InitFileSystem(fileStruct *const pFileStruct);



// ��ȡѧ����Ϣ
// const fileStruct *const pFIleStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// student **pStudentArray ����ָ ѧ������ָ���ָ��
// size_t *pLen ����Ϊ ѧ������ĳ���ָ��
// ��������ֵ bool ��Ϊ�棬���ȡ ѧ����Ϣ �ɹ��� �����ȡʧ��
bool ReadStudentFile(const fileStruct *const pFileStruct, student **pStudentArray, size_t *pLen);




// ��ȡ����Ա��Ϣ
// const fileStruct *const pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// conseller **pCounsellorArray ����ָ ����Ա����ָ���ָ��
// size_t *pLen ����ָ ����Ա����ĳ���ָ��
// ��������ֵ bool ��Ϊ�棬���ȡ ����Ա��Ϣ �ɹ��� �����ȡʧ��
bool ReadCounsellorFile(const fileStruct *const pFileStruct, counsellor **pCounsellorArray, size_t *pLen);



// ���� ѧ����Ϣ
// const fileStruct *const pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// const student *const pStudentArray ����ָ ѧ������ָ��
// const size_t len ָ ѧ������ĳ���
// ��������ֵ bool ��Ϊ�棬�򱣴�ѧ����Ϣ�ɹ������򱣴�ʧ��
bool SaveStudentFile(const fileStruct *const pFileStruct, const student *const pStudentArray, const size_t len);




// ���� ����Ա��Ϣ
// const fileStruct *const pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// const conseller *const pCounsellor ����ָ ����Ա����ָ��
// const size_t len ָ ����Ա����ĳ���
// ��������ֵ bool ��Ϊ�棬�򱣴渨��Ա��Ϣ�ɹ������򱣴�ʧ��
bool SaveCounsellorFile(const fileStruct *const pFileStruct, const counsellor *const pCounsellorArray, const size_t len);






#endif // FILESYSTEM_H
