#include "../include/internal/Common.h"
#include "../include/SMS.h"
#include "../test/include/UnitTest.h"
#include <string.h>

int main()
{

    SMS *pSMS;
    char profilePath[] = "../../data/profile.txt";

    pSMS = (SMS *)malloc(sizeof(SMS));
    strcpy(pSMS->FileStruct.profile, profilePath);
    InitSMS(pSMS);
    RunSMS(pSMS);

    //freopen("1.txt", "rw+", stdin);
    //UnitTest();
    return 0;
}
