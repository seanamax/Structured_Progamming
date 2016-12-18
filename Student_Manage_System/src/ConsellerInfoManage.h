#ifndef CONSELLERINFOMANAGE_H

#include "common.h"

// 删除辅导员信息， 通过 标记 flag 惰性删除
// const conseller *pConsellerArray 参数指辅导员数组指针
// const size_t Len 参数指 辅导员数组的长度
void DeleteConsellerInfo(const conseller *pConsellerArray, const size_t len);



// 添加辅导员信息
// conseller **pConsellerArray 参数指 辅导员数组指针的指针
// const size_t *pConLen 参数指 辅导员是数组的长度
// ID **pID 参数指 所有人 ID 数组指针的指针
// const size_t *pIDLen 参数指 所有人 ID 数组的长度
void AddConsellerInfo(conseller **pConsellerArray, const size_t *pConLen, ID **pID, const size_t *pIDLen);



// 修改辅导员信息
// const conseller *pConseller 参数指修改当前辅导员信息
void ChangeConsellerInfo(const conseller *pConseller);



// 查找辅导员信息
// const conseller *const pConsellerArray 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
// const size_t *locateIndex  参数 指 找到辅导员在数组中的下标
// 函数返回值 bool 值 指是否在辅导员数组中找到该辅导员信息，若没有找到，locateIndex 值没有意义
bool LocateConsellerInfo(const conseller *const pConsellerArray, const size_t len, const size_t *pLocateIndex);



// 通过 ID 查找辅导员信息
// const conseller *const pConsellerArray 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
// const ID *const id 参数指 需要找到的辅导员的ID指针
// const size_t *locateIndex  参数 指 找到辅导员在数组中的下标
// 函数返回值 bool 值 指是否在辅导员数组中找到该辅导员信息，若没有找到，locateIndex 值没有意义
bool LocateConsellerInfoByID(const conseller *const pConsellerArray, const size_t len, const ID *const pID, const size_t *pLocateIndex);



// 通过 姓名 查找辅导员信息
// const conseller *const pConsellerArray 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
// const char *const name 参数指 需要找到的辅导员的姓名
// const size_t *pLocateIndex  参数 指 找到辅导员在数组中的下标
// 函数返回值 bool 值 指是否在辅导员数组中找到该辅导员信息，若没有找到，locateIndex 值没有意义
bool LocateConsellerInfoByName(const conseller *const pConsellerArray, const size_t len, const char *const name, const size_t *pLocateIndex);



// 显示辅导员信息
// const conseller *pConseller 参数指需要显示的辅导员指针
void DispConsellerInfo(const conseller *const pConseller);



// 显示所有辅导员信息
// const conseller *pConsellerArray 参数指需要显示的辅导员数组指针
// const size_t conLen 参数指需要显示的辅导员数组的长度
void DispAllConsellerInfo(const conseller *const pConsellerArray, const size_t conLen);

#endif // CONSELLERINFOMANAGE_H
