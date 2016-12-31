#ifndef SMS_H
#define SMS_H

#include "CounsellorInfoManage.h"
#include "StudentInfoManage.h"
#include "StudentMarkManage.h"
#include "StudentSubjectManage.h"
#include "UserManage.h"
#include "FileSystem.h"

// 初始化 SMS
bool InitSMS(SMS *pSMS);

// 运行 SMS
void RunSMS(SMS *pSMS);

void RunSMSByCounsellor(SMS *pSMS);
void RunSMSByAdmin(SMS *pSMS);
void RunSMSByStudent(SMS *pSMS);

#endif // SMS_H
