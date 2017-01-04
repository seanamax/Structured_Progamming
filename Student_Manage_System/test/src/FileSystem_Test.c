#include "../include/UnitTest.h"
#include "../../include/internal/FileSystem.h"
#include "../../include/internal/StudentInfoManage.h"
#include <assert.h>
#include <string.h>

void FileSystem_Test()
{
    //InitFileSystem_Test();
    ReadStudentFile_Test();
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
