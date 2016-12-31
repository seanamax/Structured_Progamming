#include "FileSystem.h"
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
