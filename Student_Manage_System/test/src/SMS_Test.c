#include "../include/UnitTest.h"
#include <assert.h>

void SMS_Test()
{
    //InitSMS_Test();
    RunSMS_Test();
}


void InitSMS_Test()
{
    SMS sms;
    char profilePath[] = "../../data/profile.txt";
    strcpy(sms.FileStruct.profile, profilePath);

    assert(InitSMS(&sms) && "Cann't initilize the SMS");

    DispAllCounsellorInfo(sms.pCounsellor, sms.counsellorLen);
    DispAllStudentInfo(sms.pStudent, sms.studentLen);
}


void RunSMS_Test()
{
    SMS sms;
    char profilePath[] = "../../data/profile.txt";
    strcpy(sms.FileStruct.profile, profilePath);

    assert(InitSMS(&sms) && "Cann't initilize the SMS");

    RunSMS(&sms);
}
