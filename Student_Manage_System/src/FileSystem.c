#include "../include/internal/FileSystem.h"
#include "../include/internal/BasicFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


// ��ʼ���ļ�ϵͳ����ȡ�����ļ�
// const fileStruct *pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// ��������ֵ bool ��Ϊ�棬���ʼ���ɹ��������ʼ��ʧ��
bool InitFileSystem(fileStruct *const pFileStruct)
{
    assert(pFileStruct && "pFileStruct is null pointer, Please check it out in InitFileSystem !");
    assert(pFileStruct->profile && "profile is null");

    FILE *pProfile, *pAdminInfoFile, *pStudentInfoFile, *pCounsellorInfoFile;

    pProfile = fopen(pFileStruct->profile, "r");

    if(!pProfile) {
        return false;
    }

    fscanf(pProfile, "%s", pFileStruct->adminInfoFile);
    fscanf(pProfile, "%s", pFileStruct->studentInfoFile);
    fscanf(pProfile, "%s", pFileStruct->counsellorInfoFile);


    pFileStruct->adminInfoFile[STRINGBUFFERLEN-1] = '\0';
    pFileStruct->studentInfoFile[STRINGBUFFERLEN-1] = '\0';
    pFileStruct->counsellorInfoFile[STRINGBUFFERLEN-1] = '\0';

    pAdminInfoFile = fopen(pFileStruct->adminInfoFile, "r");
    pStudentInfoFile = fopen(pFileStruct->studentInfoFile, "r");
    pCounsellorInfoFile = fopen(pFileStruct->counsellorInfoFile, "r");

    if(!(pAdminInfoFile && pStudentInfoFile && pCounsellorInfoFile)) {
        return false;
    }


    assert(pAdminInfoFile && "Cann't open the file of user-manage, please check it out!");
    assert(pStudentInfoFile && "Cann't open the file of student information, please check it out!");
    assert(pCounsellorInfoFile && "Cann't open the file of counsellor information, please check it out!");

    fclose(pProfile);
    fclose(pAdminInfoFile);
    fclose(pStudentInfoFile);
    fclose(pCounsellorInfoFile);

    return true;
}




// ��ȡѧ����Ϣ
// const fileStruct *const pFIleStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// student **pStudentArray ����ָ ѧ������ָ���ָ��
// size_t *pLen ����Ϊ ѧ������ĳ���ָ��
// ��������ֵ bool ��Ϊ�棬���ȡ ѧ����Ϣ �ɹ��� �����ȡʧ��
bool ReadStudentFile(const fileStruct *const pFileStruct, student **pStudentArray, size_t *pLen)
{

    FILE *fp;
    *pLen = 0;
    int flag = 0;
    size_t i, j;

    fp = fopen(pFileStruct->studentInfoFile, "r");

    assert(fp && "Cann't open the information of student file, please check it out!\n");

    if(!fp) {
        return false;
    }

    flag = fscanf(fp, "%u", pLen);
    if(flag != 1) {
        *pLen = 0;
        return false;
    }

    *pStudentArray = (student *)malloc(sizeof(student) * *pLen);
    assert(pStudentArray && "Cann't mallocation the memory of student array!\n");

    if(!*pStudentArray) {
        *pLen = 0;
        return false;
    }

    for(i=0; i < *pLen; ++ i) {
        (*pStudentArray)[i].id.flag = true;
        fscanf(fp, "%s %s", (*pStudentArray)[i].id.id, (*pStudentArray)[i].id.password);
        fscanf(fp, "%s %s", (*pStudentArray)[i].name, (*pStudentArray)[i].class);
        fscanf(fp, "%s %s", (*pStudentArray)[i].address, (*pStudentArray)[i].phoneNumber);
        fscanf(fp, "%d", &(*pStudentArray)[i].subjectNum);

        (*pStudentArray)[i].pSubject = (subject *)malloc(sizeof(subject) * (*pStudentArray)[i].subjectNum);


        assert(!((*pStudentArray)[i].pSubject == NULL && (*pStudentArray)[i].subjectNum != 0) && "Cann't mallocating the memory of student subject!\n");

        if((*pStudentArray)[i].pSubject == NULL && (*pStudentArray)[i].subjectNum != 0) {

            return false;
        }

        for(j=0; j < (*pStudentArray)[i].subjectNum; ++j) {
            fscanf(fp, "%s", (*pStudentArray)[i].pSubject[j].name);
            fscanf(fp, "%f", &(*pStudentArray)[i].pSubject[j].mark);
            (*pStudentArray)[i].pSubject[j].flag = true;
        }
    }

    fclose(fp);

    return true;
}




// ��ȡ����Ա��Ϣ
// const fileStruct *const pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// conseller **pCounsellorArray ����ָ ����Ա����ָ���ָ��
// size_t *pLen ����ָ ����Ա����ĳ���ָ��
// ��������ֵ bool ��Ϊ�棬���ȡ ����Ա��Ϣ �ɹ��� �����ȡʧ��
bool ReadCounsellorFile(const fileStruct *const pFileStruct, counsellor **pCounsellorArray, size_t *pLen)
{
    FILE *fp;
    size_t i, j;
    char flag;

    assert(pFileStruct && "The pointer is NULL!");
    assert(pCounsellorArray && "The pointer is NULL!");
    assert(pLen && "The pointer is NULL!");

    fp = fopen(pFileStruct->counsellorInfoFile, "r");

    assert(fp && "Cann't open the counsellorInfoFile, please check it out!");

    if(!fp) {
        return false;
    }

    flag = fscanf(fp, "%d", pLen);
    if(flag != 1) {
        return false;
    }

    *pCounsellorArray = (counsellor *)malloc(*pLen * sizeof(counsellor));

    assert(*pCounsellorArray != NULL &&
           "Cann't mallocating the memory in ReadCounsellorFile function, please check it out!");

    if(*pCounsellorArray == NULL) {
        return false;
    }

    for(i=0; i < *pLen; ++i) {
        fscanf(fp, "%s %s", (*pCounsellorArray)[i].id.id, (*pCounsellorArray)[i].id.password);
        fscanf(fp, "%s %s", (*pCounsellorArray)[i].name, (*pCounsellorArray)[i].address);
        fscanf(fp, "%u", &(*pCounsellorArray)[i].manageClassNum);

        (*pCounsellorArray)[i].id.flag = true;

        (*pCounsellorArray)[i].pClass = (class *)malloc((*pCounsellorArray)[i].manageClassNum * sizeof(class));

        assert(!((*pCounsellorArray)[i].pClass == NULL && (*pCounsellorArray)[i].manageClassNum != 0) &&
               "Cann't mallocating the memory in ReadCounsellorFile function, please check it out!");


        for(j=0; j < (*pCounsellorArray)[i].manageClassNum; ++j) {
            fscanf(fp, "%s", (*pCounsellorArray)[i].pClass[j].name);
            (*pCounsellorArray)[i].pClass[j].flag = true;
        }


    }

    fclose(fp);

    return true;

}





// ��ȡ����Ա��Ϣ
// const fileStruct *const pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// admin *const pAdmin ����ָ ����Ա
// ��������ֵ bool ��Ϊ�棬���ȡ ����Ա��Ϣ �ɹ��� �����ȡʧ��
bool ReadAdminFile(const fileStruct *const pFileStruct, admin *const pAdmin)
{
    FILE *fp;
    char flag;

    assert(pFileStruct && "The pointer is NULL!");
    assert(pAdmin && "The pointer is NULL!");

    fp = fopen(pFileStruct->adminInfoFile, "r");

    assert(fp && "Cann't open the adminInfoFile, please check it out!");

    if(!fp) {
        return false;
    }

    flag = fscanf(fp, "%s %s", pAdmin->id.id, pAdmin->id.password);
    if(flag != 2) {
        return false;
    }

    fclose(fp);
    return true;
}




// ���� ѧ����Ϣ
// const fileStruct *const pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// const student *const pStudentArray ����ָ ѧ������ָ��
// const size_t len ָ ѧ������ĳ���
// ��������ֵ bool ��Ϊ�棬�򱣴�ѧ����Ϣ�ɹ������򱣴�ʧ��
bool SaveStudentFile(const fileStruct *const pFileStruct, const student *const pStudentArray, const size_t len)
{
    assert(pFileStruct && "the pointer is NULL in SaveStudentFile function, please check it out!");
    assert(pStudentArray && "the pointer is NULL in SaveStudentFIle function, please check it out!");

    FILE *fp;
    size_t i, j, inFactLenOfStudentArray, inFactLenOfSubjectArray;

    fp = fopen(pFileStruct->studentInfoFile, "w");
    assert(fp && "Cann't open the studentInfoFile in SaveStudentFile function, please check it out!");

    inFactLenOfStudentArray = 0;
    for(i=0; i < len; ++i) {
        if(pStudentArray[i].id.flag) {
            ++ inFactLenOfStudentArray;
        }
    }

    fprintf(fp, "%u\n\n", inFactLenOfStudentArray);
    for(i=0; i < len; ++i) {
        if(pStudentArray[i].id.flag) {
            fprintf(fp, "%s %s\n", pStudentArray[i].id.id, pStudentArray[i].id.password);
            fprintf(fp, "%s %s\n", pStudentArray[i].name, pStudentArray[i].class);
            fprintf(fp, "%s %s\n", pStudentArray[i].address, pStudentArray[i].phoneNumber);

            inFactLenOfSubjectArray = 0;
            for(j=0; j < pStudentArray[i].subjectNum; ++j) {
                if(pStudentArray[i].pSubject[j].flag) {
                    ++ inFactLenOfSubjectArray;
                }
            }


            fprintf(fp, "%u\n", inFactLenOfSubjectArray);
            for(j=0; j < pStudentArray[i].subjectNum; ++j) {
                if(pStudentArray[i].pSubject[j].flag) {
                    fprintf(fp, "%s %.2f\n", pStudentArray[i].pSubject[j].name, pStudentArray[i].pSubject[j].mark);
                }
            }

            fputc('\n', fp);
        }
    }

    fclose(fp);

    return true;
}




// ���� ����Ա��Ϣ
// const fileStruct *const pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ľṹ��
// const conseller *const pCounsellor ����ָ ����Ա����ָ��
// const size_t len ָ ����Ա����ĳ���
// ��������ֵ bool ��Ϊ�棬�򱣴渨��Ա��Ϣ�ɹ������򱣴�ʧ��
bool SaveCounsellorFile(const fileStruct *const pFileStruct, const counsellor *const pCounsellorArray, const size_t len)
{
    assert(pFileStruct && "the pointer is NULL in SaveCounsellortFile function, please check it out!");
    assert(pCounsellorArray && "the pointer is NULL in SaveCounsellor function, please check it out!");


    FILE *fp;
    size_t i, j, inFactLenOfCounsellorArray, inFactLenOfClassArray;

    fp = fopen(pFileStruct->counsellorInfoFile, "w");
    assert(fp && "Cann't open the counsellorInfoFile in SaveStudentFile function, please check it out!");

    inFactLenOfCounsellorArray = 0;
    for(i=0; i < len; ++i) {
        if(pCounsellorArray[i].id.flag) {
            ++ inFactLenOfCounsellorArray;
        }
    }

    fprintf(fp, "%u\n\n", inFactLenOfCounsellorArray);
    for(i=0; i < len; ++i) {
        if(pCounsellorArray[i].id.flag) {
            fprintf(fp, "%s %s\n", pCounsellorArray[i].id.id, pCounsellorArray[i].id.password);
            fprintf(fp, "%s %s\n", pCounsellorArray[i].name, pCounsellorArray[i].address);

            inFactLenOfClassArray = 0;
            for(j=0; j < pCounsellorArray[i].manageClassNum; ++j) {
                if(pCounsellorArray[i].pClass[j].flag) {
                    ++ inFactLenOfClassArray;
                }
            }

            fprintf(fp, "%u\n", inFactLenOfClassArray);
            for(j=0; j < pCounsellorArray[i].manageClassNum; ++j) {
                if(pCounsellorArray[i].pClass[j].flag) {
                    fprintf(fp, "%s\n", pCounsellorArray[i].pClass[j].name);
                }
            }
            fputc('\n', fp);
        }
    }

    fclose(fp);
    return true;
}




// ���� ����Ա��Ϣ
// const fileStruct *const pFileStruct ����ָ �ļ�ϵͳ��������Ϣ�Ļ�����
// const admin *const pAdmin
// ��������ֵ bool ��Ϊ�棬�򱣴����Ա��Ϣ�ɹ������򱣴�ʧ��
bool SaveAdminFile(const fileStruct *const pFileStruct, const admin *const pAdmin)
{
    FILE *fp;

    assert(pFileStruct && "The pointer is NULL!");
    assert(pAdmin && "The pointer is NULL!");

    fp = fopen(pFileStruct->adminInfoFile, "w");

    assert(fp && "Cann't open the adminInfoFile, please check it out!");

    if(!fp) {
        return false;
    }

    fprintf(fp, "%s\n%s\n", pAdmin->id.id, pAdmin->id.password);

    fclose(fp);
    return true;
}





















































