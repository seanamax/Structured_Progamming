#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdio.h>

#define NAME_LEN 20
#define PASSWORD_LEN 20
#define PHONENUMBER_LEN 20
#define ADDRESS_LEN 20
#define SUBJECT_NAME_LEN 20
#define ID_LEN 20
#define CLASS_NAME_LEN 20

#define STRINGBUFFERLEN 256

#define true 1
#define false 0


typedef struct _subject subject;
typedef struct _student student;
typedef struct _counsellor counsellor;
typedef struct _ID ID;
typedef struct _admin admin;
typedef struct _class class;
typedef struct _fileStruct fileStruct;
typedef struct _SMS SMS;
typedef char bool;


// 该系统中所有人的账号信息
struct _ID
{
	char id[ID_LEN];
	char password[PASSWORD_LEN];
	char flag;
};


// 科目信息
struct _subject
{
    char name[NAME_LEN];
    float mark;
    bool flag;
};


// 班级信息
struct _class
{
    char name[NAME_LEN];
    bool flag;
};


// 学生信息
struct _student
{
    struct _ID id;
    char name[NAME_LEN];
    char class[CLASS_NAME_LEN];
    char address[ADDRESS_LEN];
    char phoneNumber[PHONENUMBER_LEN];
    struct _subject *pSubject;
    size_t subjectNum;
};


// 辅导员信息
struct _counsellor
{
    struct _ID id;
    char name[NAME_LEN];
    char address[ADDRESS_LEN];
    struct _class *pClass;
    size_t manageClassNum;
};


// 管理员信息
struct _admin
{
    struct _ID id;
};



// 文件系统
struct _fileStruct
{
    char adminInfoFile[STRINGBUFFERLEN];
    char studentInfoFile[STRINGBUFFERLEN];
    char counsellorInfoFile[STRINGBUFFERLEN];
    char profile[STRINGBUFFERLEN];
};


// 学生信息管理系统结构体
struct _SMS
{
    fileStruct FileStruct;

    student *pStudent;
    size_t studentLen;


    admin Admin;

    counsellor *pCounsellor;
    size_t counsellorLen;
};



#endif // COMMON_H
