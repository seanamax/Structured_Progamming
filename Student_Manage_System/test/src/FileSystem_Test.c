#include "../include/UnitTest.h"
#include "../../include/internal/FileSystem.h"
#include "../../include/internal/StudentInfoManage.h"
#include "../../include/internal/CounsellorInfoManage.h"
#include <assert.h>
#include <string.h>

void FileSystem_Test()
{
    //InitFileSystem_Test();
    //ReadStudentFile_Test();
    //ReadCounsellorFile_Test();
    //ReadAdminFile_Test();
    //SaveStudentFile_Test();
    //SaveCounsellorFile_Test();
    //SaveAdminFile_Test();
}


void InitFileSystem_Test()
{
    fileStruct fStruct = { "", "", "", "../../data/profile.txt"};
    bool flag = InitFileSystem(&fStruct);

    assert(!strcmp("../../data/Admin.txt", fStruct.adminInfoFile));
    assert(!strcmp("../../data/Student.txt", fStruct.studentInfoFile));
    assert(!strcmp("../../data/Counsellor.txt", fStruct.counsellorInfoFile));
    assert(flag);

}




void ReadStudentFile_Test()
{
    fileStruct fStruct = { "", "", "", "../../data/profile.txt"};
    student *pStudentArray = NULL;
    size_t pLen = 0;
    bool flag;

    flag = InitFileSystem(&fStruct);

    assert(flag && "Cann't open the profile!");

    flag = ReadStudentFile(&fStruct, &pStudentArray, &pLen);

    assert(flag && "Cann't open the Student.txt");

    DispAllStudentInfo(pStudentArray, pLen);
}




void ReadCounsellorFile_Test()
{
    fileStruct fStruct = { "", "", "", "../../data/profile.txt"};
    counsellor *pCounsellorArray;
    size_t pLen = 0;
    bool flag;

    flag = InitFileSystem(&fStruct);

    assert(flag && "Cann't open the profile!");

    flag = ReadCounsellorFile(&fStruct, &pCounsellorArray, &pLen);

    assert(flag && "Cann't open the Counsellor.txt!");

    DispAllCounsellorInfo(pCounsellorArray, pLen);
}




void ReadAdminFile_Test()
{
    fileStruct fStruct = { "", "", "", "../../data/profile.txt"};
    admin Admin;

    bool flag;

    flag = InitFileSystem(&fStruct);

    assert(flag && "Cann't open the profile!");

    flag = ReadAdminFile(&fStruct, &Admin);

    assert(flag && "Cann't open the Admin.txt!");

    printf("%s\n%s\n", Admin.id.id, Admin.id.password);
}




void SaveStudentFile_Test()
{
    fileStruct fStruct = { "", "", "", "../../data/profile.txt"};
    fileStruct fStruct2;

    student *pStudentArray = NULL;
    size_t pLen = 0;
    bool flag;

    flag = InitFileSystem(&fStruct);

    assert(flag && "Cann't open the profile!");

    flag = ReadStudentFile(&fStruct, &pStudentArray, &pLen);

    assert(flag && "Cann't open the Student.txt");

    DispAllStudentInfo(pStudentArray, pLen);

    fStruct2 = fStruct;
    strcpy(fStruct2.studentInfoFile, "../../data/Student2.txt");


    // ≤‚ ‘∂Ë–‘…æ≥˝—ß…˙
    //pStudentArray[0].id.flag = false;

    // ≤‚ ‘∂Ë–‘…æ≥˝ø∆ƒø
    //pStudentArray[1].pSubject[0].flag = false;

    SaveStudentFile(&fStruct2, pStudentArray, pLen);
}




void SaveCounsellorFile_Test()
{
    fileStruct fStruct = { "", "", "", "../../data/profile.txt"};
    fileStruct fStruct2;

    counsellor *pCounsellorArray = NULL;
    size_t pLen = 0;
    bool flag;

    flag = InitFileSystem(&fStruct);

    assert(flag && "Cann't open the profile!");

    flag = ReadCounsellorFile(&fStruct, &pCounsellorArray, &pLen);

    assert(flag && "Cann't open the Counsellor.txt");

    DispAllCounsellorInfo(pCounsellorArray, pLen);

    fStruct2 = fStruct;
    strcpy(fStruct2.counsellorInfoFile, "../../data/Counsellor2.txt");


    // ≤‚ ‘∂Ë–‘…æ≥˝∏®µº‘±
    //pCounsellorArray[0].id.flag = false;


    // ≤‚ ‘∂Ë–‘…æ≥˝∞‡º∂
    //pCounsellorArray[1].pClass[0].flag = false;

    SaveCounsellorFile(&fStruct2, pCounsellorArray, pLen);

}



void SaveAdminFile_Test()
{
    fileStruct fStruct = { "", "", "", "../../data/profile.txt"};
    fileStruct fStruct2;

    admin Admin;

    bool flag;

    flag = InitFileSystem(&fStruct);

    assert(flag && "Cann't open the profile!");

    fStruct2 = fStruct;
    strcpy(fStruct2.adminInfoFile, "../../data/Admin2.txt");

    flag = ReadAdminFile(&fStruct, &Admin);

    assert(flag && "Cann't open the Admin.txt!");

    flag = SaveAdminFile(&fStruct2, &Admin);

    assert(flag && "Cann't open the Admin.txt!");

    printf("%s\n%s\n", Admin.id.id, Admin.id.password);


}




















