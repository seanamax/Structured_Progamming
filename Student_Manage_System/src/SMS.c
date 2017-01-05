#include "../include/SMS.h"
#include "../include/internal/CounsellorInfoManage.h"
#include "../include/internal/StudentInfoManage.h"
#include "../include/internal/StudentMarkManage.h"
#include "../include/internal/StudentSubjectManage.h"
#include "../include/internal/UserManage.h"
#include "../include/internal/FileSystem.h"
#include <assert.h>
#include <stdio.h>

bool InitSMS(SMS *pSMS)
{

    if(!InitFileSystem(&pSMS->FileStruct)) {
        assert(!"InitFileSystem function is NULL, profile file or others is wrong!");
        return false;
    }

    if(!ReadAdminFile(&pSMS->FileStruct, &pSMS->Admin)) {
        assert(!"Cann't read ADMIN file, please check it out!");
        return false;
    }

    if(!ReadCounsellorFile(&pSMS->FileStruct, &pSMS->pCounsellor, &pSMS->counsellorLen)) {
        assert(!"Cann't read  COUNSELLOR file, please check it out!");
        return false;
    }

    if(!ReadStudentFile(&pSMS->FileStruct, &pSMS->pStudent, &pSMS->studentLen)) {
        assert(!"Cann't read STUDENT file, please check it out!");
        return false;
    }

    return true;
}


void RunSMS(SMS *pSMS)
{
    PrintSplitLine();
    puts("There are 3 mode you have to choose!");
    puts("[1] Student Mode");
    puts("[2] Counsellor Mode");
    puts("[3] Admin Mode");
    puts("[4] Exit");
    PrintSplitLine();

    char ch = '0';
    while(ch != '1' && ch != '2' && ch != '3' && ch != '4') {
        ch = getchar();
    }

    switch(ch) {
    case '1': {
        RunSMSByStudent(pSMS);
        break;
    }

    case '2': {
        RunSMSByCounsellor(pSMS);
        break;
    }

    case '3': {
        RunSMSByAdmin(pSMS);
        break;
    }

    case '4': {
        while(!SaveAdminFile(&pSMS->FileStruct, &pSMS->Admin)) {
            assert("Cann't save ADMIN file, please check it out!");
            puts("Cann't save ADMIN file, please check it out!");
            getchar();
        }

        while(!SaveCounsellorFile(&pSMS->FileStruct, pSMS->pCounsellor, pSMS->counsellorLen)) {
            assert("Cann't save COUNSELLOR file, please check it out!");
            puts("Cann't save COUNSELLOR file, please check it out!");
            getchar();
        }


        while(!SaveStudentFile(&pSMS->FileStruct, pSMS->pStudent, pSMS->studentLen)) {
            assert("Cann't save STUDENT file, please check it out!");
            puts("Cann't save STUDENT file, please check it out!");
            getchar();
        }

        FreeCounsellorArray(&pSMS->pCounsellor, &pSMS->counsellorLen);
        FreeStudentArray(&pSMS->pStudent, &pSMS->studentLen);

        break;
    }

    default:
        assert(0);
        break;
    }
}


void RunSMSByAdmin(SMS *pSMS)
{

}


void RunSMSByCounsellor(SMS *pSMS)
{

}


void RunSMSByStudent(SMS *pSMS)
{

}



