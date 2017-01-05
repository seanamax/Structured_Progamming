#include "../include/SMS.h"
#include "../include/internal/CounsellorInfoManage.h"
#include "../include/internal/StudentInfoManage.h"
#include "../include/internal/StudentMarkManage.h"
#include "../include/internal/StudentSubjectManage.h"
#include "../include/internal/UserManage.h"
#include "../include/internal/FileSystem.h"
#include "../include/internal/BasicFunc.h"
#include <assert.h>
#include <stdio.h>
#include <windows.h>

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
        SaveSMS(pSMS);
        break;
    }

    case '2': {
        RunSMSByCounsellor(pSMS);
        SaveSMS(pSMS);
        break;
    }

    case '3': {
        RunSMSByAdmin(pSMS);
        SaveSMS(pSMS);
        break;
    }

    case '4': {
        SaveSMS(pSMS);
        break;
    }

    default:
        assert(0);
        break;
    }
}

void SaveSMS(SMS *pSMS)
{
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

}

void RunSMSByAdmin(SMS *pSMS)
{
    bool loginFlag;
    char inputFlag;
    size_t choice;


    loginFlag = LoginByAdmin(&pSMS->Admin);
    while(loginFlag) {

        system("cls");
        PrintSplitLine();
        puts("\t\t--- Admin Mode ---");
        puts("[1]. Student information manage.");
        puts("[2]. Student mark manage.");
        puts("[3]. Student subject manage.");
        puts("[4]. Counsellor information manage.");
        puts("[5]. Change the password.");
        puts("[6]. Exit.");
        PrintSplitLine();

        choice = 0;
        while(choice == 0 || choice > 6) {
            inputFlag = scanf("%u", &choice);

            if(!inputFlag) {
                getchar();
            }
        }

        switch(choice) {

        case 1:
            StudentInfoManageModule(pSMS);

            break;



        case 2:
            StudentMarkManageModule(pSMS);

            break;



        case 3:
            StudentSubjectModule(pSMS);

            break;



        case 4:
            CounsellorInfoManageModule(pSMS);

            break;



        case 5:
            ChangePassword(&pSMS->Admin.id);

            break;


        case 6:
            loginFlag = false;

            break;



        default:
            break;
        }
    }

}


void RunSMSByCounsellor(SMS *pSMS)
{
    bool loginFlag;
    char inputFlag;
    size_t choice;
    size_t index;


    loginFlag = LoginByCounsellor(pSMS->pCounsellor, pSMS->counsellorLen, &index);
    while(loginFlag) {

        system("cls");
        PrintSplitLine();
        puts("\t\t--- Counsellor Mode ---");
        puts("[1]. Student mark manage.");
        puts("[2]. Show the information.");
        puts("[3]. Change the information.");
        puts("[4]. Change password.");
        puts("[5]. Exit.");
        PrintSplitLine();

        choice = 0;
        while(choice == 0 || choice > 5) {
            inputFlag = scanf("%u", &choice);

            if(!inputFlag) {
                getchar();
            }
        }

        switch(choice) {

        case 1:
            StudentMarkManageModule(pSMS);

            break;



        case 2:
            DispCounsellorInfo(pSMS->pCounsellor + index);
            getchar();
            getchar();

            break;



        case 3:
            ChangeCounsellorInfo(pSMS->pCounsellor + index);

            break;



        case 4:
            ChangePassword(&pSMS->pCounsellor[index].id);

            break;



        case 5:
            loginFlag = false;

            break;



        default:
            break;
        }
    }
}


void RunSMSByStudent(SMS *pSMS)
{
    bool loginFlag;
    char inputFlag;
    size_t choice;
    size_t index;


    loginFlag = LoginByCounsellor(pSMS->pCounsellor, pSMS->counsellorLen, &index);
    while(loginFlag) {

        system("cls");
        PrintSplitLine();
        puts("\t\t--- Student Mode ---");
        puts("[1]. Show the information.");
        puts("[2]. Change the information.");
        puts("[3]. Change the password.");
        puts("[4]. Exit.");
        PrintSplitLine();

        choice = 0;
        while(choice == 0 || choice > 4) {
            inputFlag = scanf("%u", &choice);

            if(!inputFlag) {
                getchar();
            }
        }


        switch(choice) {

        case 1:
            DispStudentInfo(pSMS->pStudent + index);
            getchar();
            getchar();
            break;



        case 2:
            ChangeStudentInfo(pSMS->pStudent + index);

            break;



        case 3:
            ChangePassword(&pSMS->pStudent[index].id);

            break;



        case 4:
            loginFlag = true;

            break;



        default:
            break;
        }
    }

}


void StudentInfoManageModule(SMS *pSMS)
{
    char inputFlag;
    bool locateFlag;
    size_t choice;
    size_t index;

    choice = 0;
    while(choice != 5) {

        //system("cls");
        PrintSplitLine();
        puts("\t\t-- Student Information Manage ---");
        puts("[1]. Delete student information.");
        puts("[2]. Locate student information.");
        puts("[3]. Change student information.");
        puts("[4]. Add student information.");
        puts("[5]. Exit.");
        PrintSplitLine();

        choice = 0;
        while(choice == 0 || choice > 4) {
            inputFlag = scanf("%u", &choice);

            if(!inputFlag) {
                getchar();
            }
        }

        switch(choice) {

        case 1:
            DeleteStudentInfo(pSMS->pStudent, pSMS->studentLen);

            break;



        case 2:
            locateFlag = LocateStudentInfo(pSMS->pStudent, pSMS->studentLen, &index);
            if(locateFlag) {
                puts("Show the information of student that you want to locate.");
                DispStudentInfo(pSMS->pStudent + index);
                getchar();
            }

            else {
                puts("Cann't find the student, please check it out!");
            }

            break;


        case 3:
            locateFlag = LocateStudentInfo(pSMS->pStudent, pSMS->studentLen, &index);
            if(locateFlag) {
                puts("Show the information of student that you want to locate.");
                ChangeStudentInfo(pSMS->pStudent + index);
            }

            else {
                puts("Cann't find the student, please check it out!");
            }

            break;


        case 4:
            AddStudentInfo(&pSMS->pStudent, &pSMS->studentLen);

            break;



        case 5:
            choice = 5;

            break;


        default:
            break;

        }
    }
}


void StudentMarkManageModule(SMS *pSMS)
{
    char inputFlag;
    bool locateFlag;
    size_t index;
    size_t choice;

    choice = 0;
    while(choice != 3) {

        PrintSplitLine();
        puts("\t\t--- Student Mark Manage ---");
        puts("[1]. Add mark to student.");
        puts("[2]. Change mark to student.");
        puts("[3]. Exit.");
        PrintSplitLine();

        choice = 0;
        while(choice == 0 || choice > 3) {
            inputFlag = scanf("%u", &choice);

            if(!inputFlag) {
                getchar();
            }
        }


        switch(choice) {

        case 1:
            locateFlag = LocateStudentInfo(pSMS->pStudent, pSMS->studentLen, &index);
            if(locateFlag) {
                puts("Show the information of student that you want to locate.");
                AddMark(pSMS->pStudent + index);
            }

            else {
                puts("Cann't find the student, please check it out!");
            }

            break;




        case 2:
            locateFlag = LocateStudentInfo(pSMS->pStudent, pSMS->studentLen, &index);
            if(locateFlag) {
                puts("Show the information of student that you want to locate.");
                ChangeMark(pSMS->pStudent + index);
            }

            else {
                puts("Cann't find the student, please check it out!");
            }

            break;



        case 3:
            choice = 3;

            break;




        default:
            break;
        }
    }
}


void StudentSubjectModule(SMS *pSMS)
{

    char inputFlag;
    bool locateFlag;
    size_t index;
    size_t choice;

    choice = 0;
    while(choice != 7) {

        PrintSplitLine();
        puts("\t\t--- Student Mark Manage ---");
        puts("[1]. Add same subject to all students.");
        puts("[2]. Delete same subject to all students.");
        puts("[3]. Change same subject to all students.");
        puts("[4]. Delete subject to single student.");
        puts("[5]. Add subject to single student.");
        puts("[6]. Change subject to single student.");
        puts("[7]. Cancel.");
        PrintSplitLine();

        choice = 0;
        while(choice == 0 || choice > 7) {
            inputFlag = scanf("%u", &choice);

            if(!inputFlag) {
                getchar();
            }
        }


        switch(choice) {

        case 1:
            AddAllStudentSubjectInfo(pSMS->pStudent, pSMS->studentLen);

            break;





        case 2:
            DeleteAllStudentSubjectInfo(pSMS->pStudent, pSMS->studentLen);

            break;





        case 3:
            DeleteAllStudentSubjectInfo(pSMS->pStudent, pSMS->studentLen);

            break;





        case 4:
            locateFlag = LocateStudentInfo(pSMS->pStudent, pSMS->studentLen, &index);
            if(locateFlag) {
                puts("Show the information of student that you want to locate.");
                DeleteSingleStudentSubjectInfo(pSMS->pStudent + index);

            }

            else {
                puts("Cann't find the student, please check it out!");
            }

            break;





        case 5:
            locateFlag = LocateStudentInfo(pSMS->pStudent, pSMS->studentLen, &index);
            if(locateFlag) {
                puts("Show the information of student that you want to locate.");
                AddSingleStudentSubjectInfo(pSMS->pStudent + index);

            }

            else {
                puts("Cann't find the student, please check it out!");
            }

            break;





        case 6:
            locateFlag = LocateStudentInfo(pSMS->pStudent, pSMS->studentLen, &index);
            if(locateFlag) {
                puts("Show the information of student that you want to locate.");
                ChangeSingleStudentSubjectInfo(pSMS->pStudent + index);

            }

            else {
                puts("Cann't find the student, please check it out!");
            }

            break;





        case 7:
            choice = 7;

            break;




        default:
            break;
        }
    }
}


void CounsellorInfoManageModule(SMS *pSMS)
{
    char inputFlag;
    bool locateFlag;
    size_t choice;
    size_t index;

    choice = 0;
    while(choice != 5) {

        //system("cls");
        PrintSplitLine();
        puts("\t\t-- Counsellor Information Manage ---");
        puts("[1]. Delete Counsellor information.");
        puts("[2]. Locate Counsellor information.");
        puts("[3]. Change Counsellor information.");
        puts("[4]. Add Counsellor information.");
        puts("[5]. Exit.");
        PrintSplitLine();

        choice = 0;
        while(choice == 0 || choice > 4) {
            inputFlag = scanf("%u", &choice);

            if(!inputFlag) {
                getchar();
            }
        }

        switch(choice) {

        case 1:
            DeleteCounsellorInfo(pSMS->pCounsellor, pSMS->counsellorLen);

            break;



        case 2:
            locateFlag = LocateCounsellorInfo(pSMS->pCounsellor, pSMS->counsellorLen, &index);
            if(locateFlag) {
                puts("Show the information of Counsellor that you want to locate.");
                DispCounsellorInfo(pSMS->pCounsellor + index);
                getchar();
            }

            else {
                puts("Cann't find the Counsellor, please check it out!");
            }

            break;


        case 3:
            locateFlag = LocateCounsellorInfo(pSMS->pCounsellor, pSMS->counsellorLen, &index);
            if(locateFlag) {
                puts("Show the information of Counsellor that you want to locate.");
                ChangeCounsellorInfo(pSMS->pCounsellor + index);
            }

            else {
                puts("Cann't find the Counsellor, please check it out!");
            }

            break;


        case 4:
            AddCounsellorInfo(&pSMS->pCounsellor, &pSMS->counsellorLen);

            break;



        case 5:
            choice = 5;

            break;


        default:
            break;

        }
    }
}
