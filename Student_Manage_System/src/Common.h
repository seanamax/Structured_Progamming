#ifndef COMMON_H

#define NAME_LEN 20
#define PASSWORD_LEN 20
#define PHONENUMBER_LEN 20
#define ADDRESS_LEN 20
#define SUBJECT_NAME_LEN 20
#define ID_LEN 20
#define CLASS_NAME_LEN 20


typedef struct _subject subject;
typedef struct _student student;
typedef struct _conseller conseller;
typedef struct _ID ID;
typedef struct _admin admin;
typedef char bool;


struct _ID
{
	char id[ID_LEN];
	char password[PASSWORD_LEN];
	char flag;
}

struct _subject
{
    char name[NAME_LEN];
    float mark;
    bool flag;
};



struct _class
{
    char name[NAME_LEN];
    bool flag;
};



struct _student
{
    struct _ID *id;
    char name[NAME_LEN];
    char class[CLASS_NAME_LEN];
    char address[ADDRESS_LEN];
    char phoneNumber[PHONENUMBER_LEN];
    struct _subject *pSubject;
    size_t subjectNum;
    size_t deleteManageClassNum;
};



struct _conseller
{
    struct _ID *id;
    char name[NAME_LEN];
    char address[ADDRESS_LEN];
    struct _class *pClass;
    size_t manageClassNum;
    size_t deleteManageClassNum;
};

struct _admin
{
    struct *_ID;
};


#endif // COMMON_H
