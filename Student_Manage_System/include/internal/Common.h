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
#define NATIVE_PLACE_LEN 20
#define BIRTHDAY_LEN 20
#define MAJOR_LEN 20
#define YEAR_OF_ENROLLMENT_LEN 20




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

typedef enum _enum_status enum_status;
typedef enum _enum_sex enum_sex;
typedef char bool;


enum _enum_sex
{
    Male,
    Female
};

enum _enum_status
{
    Be_Studying_At_School,          //  �ڶ�
    Suspension_of_Schooling,       // ��ѧ
    Leavel_School,                 // ��ѧ
    Serve_in_Army                  // ������
};


// ��ϵͳ�������˵��˺���Ϣ
struct _ID
{
	char id[ID_LEN];
	char password[PASSWORD_LEN];
	char flag;
};


// ��Ŀ��Ϣ
struct _subject
{
    char name[NAME_LEN];
    float mark;
    bool flag;
};


// �༶��Ϣ
struct _class
{
    char name[NAME_LEN];
    bool flag;
};


// ѧ����Ϣ
struct _student
{
    struct _ID id;
    char name[NAME_LEN];
    enum_sex sex;
    char nativePlace[NATIVE_PLACE_LEN];
    char birthday[BIRTHDAY_LEN];
    char major[MAJOR_LEN];
    char YearOfEnrollment[YEAR_OF_ENROLLMENT_LEN];
    char class[CLASS_NAME_LEN];
    enum_status status;
    char address[ADDRESS_LEN];
    char phoneNumber[PHONENUMBER_LEN];
    struct _subject *pSubject;
    size_t subjectNum;
};


// ����Ա��Ϣ
struct _counsellor
{
    struct _ID id;
    char name[NAME_LEN];
    char address[ADDRESS_LEN];
    struct _class *pClass;
    size_t manageClassNum;
};


// ����Ա��Ϣ
struct _admin
{
    struct _ID id;
};



// �ļ�ϵͳ
struct _fileStruct
{
    char adminInfoFile[STRINGBUFFERLEN];
    char studentInfoFile[STRINGBUFFERLEN];
    char counsellorInfoFile[STRINGBUFFERLEN];
    char profile[STRINGBUFFERLEN];
};


// ѧ����Ϣ����ϵͳ�ṹ��
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
