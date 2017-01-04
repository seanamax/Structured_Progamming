#ifndef STUDENTINFOMANEGE_H
#define STUDENTINFOMANAGE_H

#include "common.h"

// 删除学生信息， 通过 标记 flag 惰性删除
// const student *pStudentArray 参数指学生数组指针
// const size_t Len 参数指 学生数组的长度
void DeleteStudentInfo(const student *pStudentArray, const size_t len);



// 添加学生信息
// student **pStudentArray 参数指 学生数组指针的指针
// size_t *const pConLen 参数指 学生是数组的长度

void AddStudentInfo(student **pStudentArray, size_t *const pConLen);



// 修改学生信息
// const student *pStudent 参数指修改当前学生信息
void ChangeStudentInfo(const student *pStudent);



// 查找学生信息
// const student *const pStudentArray 参数指学生数组指针
// const size_t len 参数指 学生数组的长度
// size_t *const locateIndex  参数 指 找到学生在数组中的下标
// 函数返回值 bool 值 指是否在学生数组中找到该学生信息，若没有找到，locateIndex 值没有意义
bool LocateStudentInfo(const student *const pStudentArray, const size_t len, size_t *const pLocateIndex);




// 通过 ID 查找学生信息
// const student *const pStudentArray 参数指学生数组指针
// const size_t len 参数指 学生数组的长度
// const ID *const id 参数指 需要找到的学生的ID指针
// size_t *const locateIndex  参数 指 找到学生在数组中的下标
// 函数返回值 bool 值 指是否在学生数组中找到该学生信息，若没有找到，locateIndex 值没有意义
bool LocateStudentInfoByID(const student *const pStudentArray, const size_t len, const ID *const pID, size_t *const pLocateIndex);




// 通过 姓名 查找学生信息
// const student *const pStudentArray 参数指学生数组指针
// const size_t len 参数指 学生数组的长度
// const char *const name 参数指 需要找到的学生的姓名
// size_t *const pLocateIndex  参数 指 找到学生在数组中的下标
// 函数返回值 bool 值 指是否在学生数组中找到该学生信息，若没有找到，locateIndex 值没有意义
bool LocateStudentInfoByName(const student *const pStudentArray, const size_t len, const char *const name, size_t *const pLocateIndex);




// 显示学生信息
// const student *pStudent 参数指需要显示的学生指针
void DispStudentInfo(const student *const pStudent);




// 显示所有学生信息
// const student *pStudentArray 参数指需要显示的学生数组指针
// const size_t conLen 参数指需要显示的学生数组的长度
void DispAllStudentInfo(const student *const pStudentArray, const size_t conLen);


// 删除 学生数组信息
// student **pStudentArray 参数指 指向学生数组指针的指针
// size_t *pLen  参数指 学生数组长度的指针
void DelStudentArray(student **pStudentArray, size_t *pLen);

#endif // STUDENTINFOMANEGE_H
