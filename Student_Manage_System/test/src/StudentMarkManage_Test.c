#include "../include/UnitTest.h"
#include "../../include/internal/StudentMarkManage.h"
#include <assert.h>
void StudentMarkManage_Test()
{
    AddMark_Test();
    ChangeMark_Test();

}


void AddMark_Test()
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


    AddMark(testStudent);
    assert(testStudent[0].pSubject[0].mark == 50.0f && "If unfail,input again.");
    //AddMark(pStudent);
}

void ChangeMark_Test()
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

    ChangeMark(testStudent);

    assert(testStudent[0].pSubject[0].mark == 50.0f && "If unfail,input again.");




    // ChangeMark(pStudentArray[a]);
}
