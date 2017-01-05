#include "../include/UnitTest.h"
#include "../../include/internal/CounsellorInfoManage.h"
#include "../../include/internal/StudentInfoManage.h"
#include "../../include/internal/FileSystem.h"
#include "../../include/internal/StudentMarkManage.h"
#include "../../include/internal/UserManage.h"
#include "../../include/SMS.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SMS_Test()
{
    //InitSMS_Test();
    //RunSMS_Test();
    //RunSMSByAdmin_Test();
    //RunSMSByCounsellor_Test();
    //RunSMSByStudent_Test();
    //StudentInfoManageModule_Test();
    //StudentMarkManageModule_Test();
    //StudentSubjectModule_Test();
    CounsellorInfoManageModule_Test();
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


void RunSMSByAdmin_Test()
{
    SMS sms;
    char profilePath[] = "../../data/profile.txt";
    strcpy(sms.FileStruct.profile, profilePath);

    assert(InitSMS(&sms) && "Cann't initilize the SMS");

    RunSMSByAdmin(&sms);
}


void RunSMSByCounsellor_Test()
{
    SMS sms;
    char profilePath[] = "../../data/profile.txt";
    strcpy(sms.FileStruct.profile, profilePath);

    assert(InitSMS(&sms) && "Cann't initilize the SMS");

    RunSMSByCounsellor(&sms);
}


void RunSMSByStudent_Test()
{
    SMS sms;
    char profilePath[] = "../../data/profile.txt";
    strcpy(sms.FileStruct.profile, profilePath);

    assert(InitSMS(&sms) && "Cann't initilize the SMS");

    RunSMSByStudent(&sms);
}

void StudentInfoManageModule_Test()
{
    SMS sms;
    char profilePath[] = "../../data/profile.txt";
    strcpy(sms.FileStruct.profile, profilePath);

    assert(InitSMS(&sms) && "Cann't initilize the SMS");

    StudentInfoManageModule(&sms);
}


void StudentMarkManageModule_Test()
{
    SMS sms;
    char profilePath[] = "../../data/profile.txt";
    strcpy(sms.FileStruct.profile, profilePath);

    assert(InitSMS(&sms) && "Cann't initilize the SMS");

    StudentMarkManageModule(&sms);
}


void StudentSubjectModule_Test()
{

    SMS sms;
    char profilePath[] = "../../data/profile.txt";
    strcpy(sms.FileStruct.profile, profilePath);

    assert(InitSMS(&sms) && "Cann't initilize the SMS");

    StudentSubjectModule(&sms);
}

void CounsellorInfoManageModule_Test()
{
    SMS sms;
    char profilePath[] = "../../data/profile.txt";
    strcpy(sms.FileStruct.profile, profilePath);

    assert(InitSMS(&sms) && "Cann't initilize the SMS");
    CounsellorInfoManageModule(&sms);

}
