#include "../include/UnitTest.h"
#include "../../include/internal/CounsellorInfoManage.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

void CounsellorInfoManage_test()
{
    //DeleteCounsellorInfo_test();
    //AddCounsellorInfo_test();

}


void DeleteCounsellorInfo_test()
{
    counsellor Counsellor;
    Counsellor.id.flag = true;
    char testID[] = "test_id";
    strcpy(Counsellor.id.id, testID);
    DeleteCounsellorInfo(&Counsellor , 1);
    assert(!Counsellor.id.flag && "Cann't delete counsellor!");
}

void AddCounsellorInfo_test()
{
    counsellor *testCounsellor;
    size_t len;

    testCounsellor = (counsellor *)malloc(sizeof(counsellor));
    testCounsellor[0].id.flag = true;
    strcpy(testCounsellor[0].id.id, "test_id");
    strcpy(testCounsellor[0].id.password, "test_password");
    //strcpy(testCounsellor[0].manageClassNum, "test_class");
    strcpy(testCounsellor[0].name, "test_name");

    strcpy(testCounsellor[0].address, "test_address");
    testCounsellor[0].manageClassNum = 0;

    len = 1;

    AddCounsellorInfo(&testCounsellor, &len);

    DispAllCounsellorInfo(testCounsellor, len);

}
