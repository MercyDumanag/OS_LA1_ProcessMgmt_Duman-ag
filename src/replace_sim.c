#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Command to simulate exec(): run 'cmd /c dir'
    char cmdLine[] = "cmd /c dir";

    // Create the child process
    if (!CreateProcess(
            NULL,       // application name
            cmdLine,    // command line
            NULL,       // process security attributes
            NULL,       // thread security attributes
            FALSE,      // handles not inherited
            0,          // creation flags
            NULL,       // use parent's environment
            NULL,       // use parent's working directory
            &si,        // startup info
            &pi)) {     // process info
        printf("Failed to create process. Error = %lu\n", GetLastError());
        return 1;
    }

    // Wait for the child to finish
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Get child exit code
    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);

    // Close handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    // Parent exits with the same code as the child
    return (int)exitCode;
}
