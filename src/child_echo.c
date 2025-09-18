#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    DWORD myPid = GetCurrentProcessId();
    DWORD parentPid = 0;

    if (argc >= 2) {
        parentPid = atoi(argv[1]);
    }

    char buffer[100];
    sprintf(buffer, "Child PID = %u, Parent PID (passed) = %u\r\n", 
            (unsigned)myPid, (unsigned)parentPid);

    DWORD written;
    WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), buffer, strlen(buffer), &written, NULL);

    Sleep(50000);

    return 0;
}
