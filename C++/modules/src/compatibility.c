#include <stdlib.h>

void universalClear(){
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__linux__)
    system("clear");
#else
#error undefined operation system
#endif // defined
}
