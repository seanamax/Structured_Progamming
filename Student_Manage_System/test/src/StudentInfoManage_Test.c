#include "../include/UnitTest.h"
#include <stdio.h>
#include <assert.h>

void StudentInfoManage_Test()
{
    //DeleteStudentInfo_Test();
    //AddStudentInfo_Test();

    ChangeStudentInfo_Test();
}

void DeleteStudentInfo_Test()
{
    student Student;
    Student.id.flag = true;
    char testID[] = "test_id";

    strcpy(Student.id.id, testID);
    DeleteStudentInfo(&Student, 1);

    assert(!Student.id.flag && "Cann't delete stduent!");
}


void AddStudentInfo_Test()
{

    student *testStudent, *testStudentFlag;
    size_t len;

    testStudentFlag = testStudent = (student *)malloc(sizeof(student));
    testStudent[0].id.flag = true;
    strcpy(testStudent[0].id.id, "test_id");
    strcpy(testStudent[0].id.password, "test_password");
    strcpy(testStudent[0].class, "test_class");
    strcpy(testStudent[0].name, "test_name");
    strcpy(testStudent[0].phoneNumber, "test_phoneNumber");
    strcpy(testStudent[0].address, "test_address");
    testStudent[0].subjectNum = 0;

    len = 1;

    AddStudentInfo(&testStudent, &len);

    DispAllStudentInfo(testStudent, len);

}


void ChangeStudentInfo_Test()
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
    testStudent[0].subjectNum = 0;

    ChangeStudentInfo(testStudent);

    DispStudentInfo(testStudent);
}
