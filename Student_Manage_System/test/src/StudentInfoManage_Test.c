#include "../include/UnitTest.h"
#include <stdio.h>
#include <assert.h>

void StudentInfoManage_Test()
{
    DeleteStudentInfo_Test();
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
