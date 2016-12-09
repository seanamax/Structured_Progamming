#ifndef COMMON_H

#define NAME_lEN 20
#define PASSWORD_LEN 20
#define PHONENUMBER_LEN 20
#define ADDRESS_LEN 20
#define SUBJECT_NAME_LEN 20
#define ID_LEN 20
#define CLASS_NAME_LEN 20


typedef struct _subject subject;
typedef struct _student student;
typedef struct _conseller conseller;

struct _subject
{
    char name[NAME_LEN];
    float mark;
    struct _subject *pNext;
};


struct _student
{
    char name[NAME_LEN];
    char id[ID_LEN];
    char class[CLASS_NAME_LEN];
    char address[ADDRESS_LEN];
    char phoneNumber[PHONENUMBER_LEN];
    char password[PASSWORD_LEN];
    subject *pSubject;
};

struct _conseller
{
    char name[NAME_LEN];
    char id[ID_LEN];
    char address[ADDRESS_LEN];
    char **manageClass;
    size_t manageClassNum;
};



#endif // COMMON_H
