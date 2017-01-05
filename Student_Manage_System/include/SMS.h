#ifndef SMS_H
#define SMS_H

#include "./internal/common.h"

// ��ʼ�� SMS
bool InitSMS(SMS *pSMS);

// ���� SMS
void RunSMS(SMS *pSMS);

void RunSMSByCounsellor(SMS *pSMS);
void RunSMSByAdmin(SMS *pSMS);
void RunSMSByStudent(SMS *pSMS);
void SaveSMS(SMS *pSMS);

#endif // SMS_H
