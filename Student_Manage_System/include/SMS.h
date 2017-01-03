#ifndef SMS_H
#define SMS_H

#include "CounsellorInfoManage.h"
#include "StudentInfoManage.h"
#include "StudentMarkManage.h"
#include "StudentSubjectManage.h"
#include "UserManage.h"
#include "FileSystem.h"

// ��ʼ�� SMS
bool InitSMS(SMS *pSMS);

// ���� SMS
void RunSMS(SMS *pSMS);

void RunSMSByCounsellor(SMS *pSMS);
void RunSMSByAdmin(SMS *pSMS);
void RunSMSByStudent(SMS *pSMS);

#endif // SMS_H
