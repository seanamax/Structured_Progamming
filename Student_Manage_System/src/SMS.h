#ifndef SMS_H
#define SMS_H

#include "ConsellerInfoManage.h"
#include "StudentInfoManage.h"
#include "StudentMarkManage.h"
#include "StudentSubjectManage.h"
#include "UserManage.h"
#include "FileSystem.h"


typedef struct _SMS SMS;
struct _SMS
{
    fileStruct FileStruct;

    student *pStudent;
    size_t studentLen;

    ID *pID;
    size_t IDLen;

    admin Admin;

    conseller *pConseller;
    size_t consellerLen;
};


bool InitSMS(SMS *pSMS);
void RunSMS(SMS *pSMS);

#endif // SMS_H
