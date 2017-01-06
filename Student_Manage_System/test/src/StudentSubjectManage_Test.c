#include "../include/UnitTest.h"
#include "../../include/internal/StudentSubjectManage.h"
#include <assert.h>


void StudentSubjectManage_Test()
{
    DeleteAllStudentSubjectInfo_Test();
    AddAllStudentSubjectInfo_Test();
    ChangeAllStudentSubjectInfo_Test();
    DeleteSingleStudentSubjectInfo_Test();
    AddSingleStudentSubjectInfo_Test();
    ChangeSingleStudentSubjectInfo_Test();


}

void DeleteAllStudentSubjectInfo_Test()
{
    student *testStudent;

    testStudent = (student *)malloc(sizeof(student));
    testStudent[0].id.flag = true;
    strcpy(testStudent[0].id.id, "test_id");
    strcpy(testStudent[0].id.password, "test_password");
    strcpy(testStudent[0].class, "test_class");
    strcpy(testStudent[0].name, "test_name");
    strcpy(testStudent[0].phoneNumber, "test_phoneNumber");
    strcpy(testStudent[0].address, "test_address");

    testStudent[0].subjectNum = 1;
    testStudent[0].pSubject = (subject *)malloc(sizeof(subject));
    strcpy(testStudent[0].pSubject[0].name, "test_subject_name");
    testStudent[0].pSubject[0].mark = 0.0f;


    DeleteAllStudentSubjectInfo(testStudent,1);
    assert(testStudent[0].pSubject[0].flag == false && "If fail,input again.");
}

void AddAllStudentSubjectInfo_Test()
{
    student *testStudent;

    testStudent = (student *)malloc(sizeof(student));
    testStudent[0].id.flag = true;
    strcpy(testStudent[0].id.id, "test_id");
    strcpy(testStudent[0].id.password, "test_password");
    strcpy(testStudent[0].class, "test_class");
    strcpy(testStudent[0].name, "test_name");
    strcpy(testStudent[0].phoneNumber, "test_phoneNumber");
    strcpy(testStudent[0].address, "test_address");

    testStudent[0].subjectNum = 1;
    testStudent[0].pSubject = (subject *)malloc(sizeof(subject));
    strcpy(testStudent[0].pSubject[0].name, "test_subject_name");
    testStudent[0].pSubject[0].flag = true;
    testStudent[0].pSubject[0].mark = 0.0f;

    AddAllStudentSubjectInfo(testStudent, 1);

    assert(!(strcmp(testStudent[0].pSubject[1].name, "wu")) && "If fail,input again.");
}

void ChangeAllStudentSubjectInfo_Test()
{
    student *testStudent;

    testStudent = (student *)malloc(sizeof(student));
    testStudent[0].id.flag = true;
    strcpy(testStudent[0].id.id, "test_id");
    strcpy(testStudent[0].id.password, "test_password");
    strcpy(testStudent[0].class, "test_class");
    strcpy(testStudent[0].name, "test_name");
    strcpy(testStudent[0].phoneNumber, "test_phoneNumber");
    strcpy(testStudent[0].address, "test_address");

    testStudent[0].subjectNum = 1;
    testStudent[0].pSubject = (subject *)malloc(sizeof(subject));
    strcpy(testStudent[0].pSubject[0].name, "test_subject_name");
    testStudent[0].pSubject[0].mark = 0.0f;

    ChangeAllStudentSubjectInfo(testStudent, 1);
    DispStudentInfo(testStudent);
    assert(!strcmp(testStudent[0].pSubject[0].name, "clang") && "If fail,input again.");
}

void DeleteSingleStudentSubjectInfo_Test()
{
    student *testStudent;

    testStudent = (student *)malloc(sizeof(student));
    testStudent[0].id.flag = true;
    strcpy(testStudent[0].id.id, "test_id");
    strcpy(testStudent[0].id.password, "test_password");
    strcpy(testStudent[0].class, "test_class");
    strcpy(testStudent[0].name, "test_name");
    strcpy(testStudent[0].phoneNumber, "test_phoneNumber");
    strcpy(testStudent[0].address, "test_address");

    testStudent[0].subjectNum = 1;
    testStudent[0].pSubject = (subject *)malloc(sizeof(subject));
    strcpy(testStudent[0].pSubject[0].name, "test_subject_name");
    testStudent[0].pSubject[0].mark = 0.0f;

    DeleteSingleStudentSubjectInfo(testStudent);
    assert(testStudent[0].pSubject[0].flag == false && "If fail,input again.");
}

void AddSingleStudentSubjectInfo_Test()
{
    student *testStudent;

    testStudent = (student *)malloc(sizeof(student));
    testStudent[0].id.flag = true;
    strcpy(testStudent[0].id.id, "test_id");
    strcpy(testStudent[0].id.password, "test_password");
    strcpy(testStudent[0].class, "test_class");
    strcpy(testStudent[0].name, "test_name");
    strcpy(testStudent[0].phoneNumber, "test_phoneNumber");
    strcpy(testStudent[0].address, "test_address");

    testStudent[0].subjectNum = 1;
    testStudent[0].pSubject = (subject *)malloc(sizeof(subject));
    strcpy(testStudent[0].pSubject[0].name, "test_subject_name");
    testStudent[0].pSubject[0].flag = true;
    testStudent[0].pSubject[0].mark = 0.0f;

    AddSingleStudentSubjectInfo(testStudent);
    DispStudentInfo(testStudent);
}

void ChangeSingleStudentSubjectInfo_Test()
{
    student *testStudent;

    testStudent = (student *)malloc(sizeof(student));
    testStudent[0].id.flag = true;
    strcpy(testStudent[0].id.id, "test_id");
    strcpy(testStudent[0].id.password, "test_password");
    strcpy(testStudent[0].class, "test_class");
    strcpy(testStudent[0].name, "test_name");
    strcpy(testStudent[0].phoneNumber, "test_phoneNumber");
    strcpy(testStudent[0].address, "test_address");

    testStudent[0].subjectNum = 1;
    testStudent[0].pSubject = (subject *)malloc(sizeof(subject));
    strcpy(testStudent[0].pSubject[0].name, "test_subject_name");
    testStudent[0].pSubject[0].flag = true;
    testStudent[0].pSubject[0].mark = 0.0f;

    ChangeSingleStudentSubjectInfo(testStudent);
    DispStudentInfo(testStudent);
}
