#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "common.h"


// 初始化文件系统，读取配置文件
// const fileStruct *pFileStruct 参数指 文件系统所必有信息的结构体
// 函数返回值 bool 若为真，则初始化成功，否则初始化失败
bool InitFileSystem(fileStruct *const pFileStruct);



// 读取学生信息
// const fileStruct *const pFIleStruct 参数指 文件系统所必有信息的结构体
// student **pStudentArray 参数指 学生数组指针的指针
// size_t *pLen 参数为 学生数组的长度指针
// 函数返回值 bool 若为真，则读取 学生信息 成功， 否则读取失败
bool ReadStudentFile(const fileStruct *const pFileStruct, student **pStudentArray, size_t *pLen);




// 读取辅导员信息
// const fileStruct *const pFileStruct 参数指 文件系统所必有信息的结构体
// conseller **pCounsellorArray 参数指 辅导员数组指针的指针
// size_t *pLen 参数指 辅导员数组的长度指针
// 函数返回值 bool 若为真，则读取 辅导员信息 成功， 否则读取失败
bool ReadCounsellorFile(const fileStruct *const pFileStruct, counsellor **pCounsellorArray, size_t *pLen);



// 保存 学生信息
// const fileStruct *const pFileStruct 参数指 文件系统所必有信息的结构体
// const student *const pStudentArray 参数指 学生数组指针
// const size_t len 指 学生数组的长度
// 函数返回值 bool 若为真，则保存学生信息成功，否则保存失败
bool SaveStudentFile(const fileStruct *const pFileStruct, const student *const pStudentArray, const size_t len);




// 保存 辅导员信息
// const fileStruct *const pFileStruct 参数指 文件系统所必有信息的结构体
// const conseller *const pCounsellor 参数指 辅导员数组指针
// const size_t len 指 辅导员数组的长度
// 函数返回值 bool 若为真，则保存辅导员信息成功，否则保存失败
bool SaveCounsellorFile(const fileStruct *const pFileStruct, const counsellor *const pCounsellorArray, const size_t len);






#endif // FILESYSTEM_H
