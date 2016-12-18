#ifndef USERMANAGE_H

#include "common.h"

// 登录
// ID *pIDArray 参数指 账号数组
// const size_t idLen 参数指 账号数组的长度
// size_t *pIDIndex 参数指 获得 登录正确的账号在账号数组的下标
// 函数返回值 bool 指是否正确登录， 若是正确登录，该返回值为真，否则为假且 pIDIndex 值不正确
bool Login(ID *pIDArray, const size_t idLen, size_t *pIDIndex);

// 检查ID 是否一致
// 参数 ID *pIDA 指 账号A
// 参数 ID *pIDB 指 账号B
// 该账号A 和 账号B 相等， 则返回值为 真， 否则为假
bool CheckID(ID *pIDA, ID *pIDB);

// 修改密码
// 参数 ID *pID 为待修改的账号指针
void ChangePassWord(ID *pID);

#endif // USERMANAGE_H
