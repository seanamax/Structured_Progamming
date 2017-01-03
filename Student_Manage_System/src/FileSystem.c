#include "../include/internal/FileSystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

bool InitFileSystem(fileStruct *const pFileStruct)
{
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

    flag = fscanf(fp, "%d", pLen);
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


        assert(((*pStudentArray)[i].pSubject == NULL && (*pStudentArray)[i].subjectNum != 0) && "Cann't mallocating the memory of student subject!\n");

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

bool ReadCounsellorFile(const fileStruct *const pFileStruct, counsellor **pCounsellorArray, size_t *pLen)
{

    return true;
}
