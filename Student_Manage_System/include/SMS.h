#ifndef SMS_H
#define SMS_H

#include "./internal/common.h"

// 初始化 SMS
bool InitSMS(SMS *pSMS);

// 运行 SMS
void RunSMS(SMS *pSMS);

void RunSMSByCounsellor(SMS *pSMS);
void RunSMSByAdmin(SMS *pSMS);
void RunSMSByStudent(SMS *pSMS);
void SaveSMS(SMS *pSMS);

#endif // SMS_H
