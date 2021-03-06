#ifndef COUNSELLORINFOMANAGE_H
#define COUNSELLORINFOMANAGE_H

#include "common.h"

// 删除辅导员信息， 通过 标记 flag 惰性删除
// counsellor pcounsellorArray[] 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
void DeleteCounsellorInfo(counsellor pCounsellorArray[], const size_t len);



// 添加辅导员信息
// counsellor **pCounsellorArray 参数指 辅导员数组指针的指针
// size_t *const pConLen 参数指 辅导员是数组的长度
void AddCounsellorInfo(counsellor **pCounsellorArray, size_t *const pConLen);



// 修改辅导员信息
// counsellor *const pcounsellor 参数指修改当前辅导员信息
void ChangeCounsellorInfo(counsellor *const pCounsellor);



// 查找辅导员信息
// const counsellor *const pCounsellorArray 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
// size_t *const locateIndex  参数 指 找到辅导员在数组中的下标
// 函数返回值 bool 值 指是否在辅导员数组中找到该辅导员信息，若没有找到，locateIndex 值没有意义
bool LocateCounsellorInfo(const counsellor *const pCounsellorArray, const size_t len, size_t *const pLocateIndex);



// 通过 ID 查找辅导员信息
// const counsellor *const pCounsellorArray 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
// const ID *const id 参数指 需要找到的辅导员的ID指针
// size_t *const locateIndex  参数 指 找到辅导员在数组中的下标
// 函数返回值 bool 值 指是否在辅导员数组中找到该辅导员信息，若没有找到，locateIndex 值没有意义
bool LocateCounsellorInfoByID(const counsellor *const pCounsellorArray, const size_t len, const ID *const pID, size_t *const pLocateIndex);



// 通过 姓名 查找辅导员信息
// const counsellor *const pCounsellorArray 参数指辅导员数组指针
// const size_t len 参数指 辅导员数组的长度
// const char *const name 参数指 需要找到的辅导员的姓名
// size_t *const pLocateIndex  参数 指 找到辅导员在数组中的下标
// 函数返回值 bool 值 指是否在辅导员数组中找到该辅导员信息，若没有找到，locateIndex 值没有意义
bool LocateCounsellorInfoByName(const counsellor *const pCounsellorArray, const size_t len, const char *const name, size_t *const pLocateIndex);



// 显示辅导员信息
// const counsellor *pcounsellor 参数指需要显示的辅导员指针
void DispCounsellorInfo(const counsellor *const pCounsellor);



// 显示所有辅导员信息
// const counsellor *pcounsellorArray 参数指需要显示的辅导员数组指针
// const size_t conLen 参数指需要显示的辅导员数组的长度
void DispAllCounsellorInfo(const counsellor *const pCounsellorArray, const size_t conLen);



// 删除 辅导员数组信息
// counsellor **pCounsellorArray 参数指 指向辅导员数组指针的指针
// size_t *pLen 参数指 辅导员数组长度的指针
void FreeCounsellorArray(counsellor **pCounsellorArray, size_t *pLen);



#endif // counsellorINFOMANAGE_H
