#ifndef USERMANAGE_H
#define USERMANAGE_H

#include "common.h"

// 以学生身份登录认证
// const student pStudentArray[] 参数指 学生数组
// const size_t len 参数指 学生数组的长度
// size_t *const pIndex 参数指认证成功，获得该学生在学生数组中的下标
// 函数返回值 bool 型，若返回值为真，则表示认证成功，否则失败，pIndex 值无意义
bool LoginByStudent(const student pStudentArray[], const size_t len, size_t *const pIndex);


// 以辅导员身份登录认证
// const counsellor pCounsellorArray[] 参数指 辅导员数组
// const size_t len 参数指 辅导员数组的长度
// size_t *const pIndex 参数指认证成功，获得该辅导员在辅导员数组中的下标
// 函数返回值 bool 型， 若返回值为真，则表示认证成功，否则失败，pIndex 值无意义
bool LoginByCounsellor(const counsellor pCounsellorArray[], const size_t len, size_t *const pIndex);

// 以管理员身份登录认证
// const admin *const pAdmin 参数指 管理员指针
// 函数返回值 bool 型， 若返回值为真， 则表示认证成功， 否则失败
bool LoginByAdmin(const admin *const pAdmin);



// 检查ID 是否一致
// 参数 const ID *const pIDA 指 账号A
// 参数 const ID *const pIDB 指 账号B
// 该账号A 和 账号B 相等， 则返回值为 真， 否则为假
bool CheckID(const ID *const pIDA, const ID *const pIDB);


// 修改密码
// 参数 ID *const pID 为待修改的账号指针
void ChangePassword(ID *const pID);



#endif // USERMANAGE_H
