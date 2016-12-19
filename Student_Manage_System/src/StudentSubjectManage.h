#ifndef STUDENTSUBJECTMANAGE_H
#define STUDENTSUBJECTMANAGE_H

#include "common.h"


// 删除所有学生科目信息， 通过 标记 flag 惰性删除
// const Student *const pStudentArray 参数指学生数组指针
// const size_t Len 参数指 学生数组的长度
void DeleteAllStudentSubjectInfo(const student *const pStudentArray, const size_t len);



// 添加所有学生科目信息，通过修改已标记删除的科目或者重新分配空间
// const student *const pStudentArray 参数指 学生数组指针
// const size_t len 参数指 学生是数组的长度
void AddAllStudentSubjectInfo(const student *const pStudentArray, const size_t len);



// 修改所有学生科目信息，通过查找每个学生的科目信息，如若找到符合的科目信息，则修改。
// const student *const pStudentArray 参数指 学生数组指针
// const size_t len 参数指 学生是数组的长度
void ChangeAllStudentSubjectInfo(const student *const pStudentArray, const size_t len);




// 删除单个学生科目信息， 通过 标记 flag 惰性删除
// const Student *const pStudent 参数指学生指针
void DeleteSingleStudentSubjectInfo(const student *const pStudent);




// 添加单个学生科目信息，通过修改已标记删除的科目或者重新分配空间
// const student *const pStudent 参数指 学生指针
void AddSingleStudentSubjectInfo(const student *const pStudent);



// 修改单个学生科目信息，通过查找该学生的科目信息，如若找到符合的科目信息，则修改。
// const student *const pStudent 参数指 学生指针
// 函数返回值 bool 若为真， 则修改成功，否则修改失败或没有找到符合的科目
bool ChangeSingleStudentSubjectInfo(const student *const pStudentArray);

#endif // StudentSubjectSUBJECTMANAGE_H
