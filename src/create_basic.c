#include <windows.h>
#include <stdio.h>

int main() {
    DWORD parentPid = GetCurrentProcessId();
    printf("Parent PID = %u\n", (unsigned)parentPid);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Command line: run child_echo.exe and pass parent PID
    char cmdLine[100];
    sprintf(cmdLine, ".\\child_echo.exe %u", (unsigned)parentPid);

    // Create the child process
    if (!CreateProcess(
            NULL,        // application name
            cmdLine,     // command line
            NULL,        // process security attributes
            NULL,        // primary thread security attributes
            FALSE,       // handles not inherited
            0,           // creation flags
            NULL,        // use parent's environment
            NULL,        // use parent's working dir
            &si,         // startup info
            &pi)) {      // process info
        printf("Failed to create child process. Error = %lu\n", GetLastError());
        return 1;
    }

    // Wait for child to finish
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Get child exit code
    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);
    printf("Child exited with code %u\n", (unsigned)exitCode);

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
