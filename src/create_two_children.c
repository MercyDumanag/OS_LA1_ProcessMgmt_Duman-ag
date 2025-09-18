#include <windows.h>
#include <stdio.h>

int main() {
    DWORD parentPid = GetCurrentProcessId();
    printf("Parent PID = %u\n", (unsigned)parentPid);

    STARTUPINFO si1, si2;
    PROCESS_INFORMATION pi1, pi2;

    ZeroMemory(&si1, sizeof(si1));
    si1.cb = sizeof(si1);
    ZeroMemory(&pi1, sizeof(pi1));

    ZeroMemory(&si2, sizeof(si2));
    si2.cb = sizeof(si2);
    ZeroMemory(&pi2, sizeof(pi2));

    // --- Prepare command lines with actual parent PID ---
    char cmdLine1[50], cmdLine2[50];
    sprintf(cmdLine1, "child_echo.exe %u", (unsigned)parentPid);
    sprintf(cmdLine2, "child_echo.exe %u", (unsigned)parentPid);

    // Create first child
    if (!CreateProcess(NULL, cmdLine1, NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1)) {
        printf("Failed to create first child. Error = %lu\n", GetLastError());
        return 1;
    }

    // Create second child
    if (!CreateProcess(NULL, cmdLine2, NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2)) {
        printf("Failed to create second child. Error = %lu\n", GetLastError());
        return 1;
    }

    // Wait for both children to finish
    HANDLE children[2] = { pi1.hProcess, pi2.hProcess };
    WaitForMultipleObjects(2, children, TRUE, INFINITE);

    // Get exit codes
    DWORD exitCode1, exitCode2;
    GetExitCodeProcess(pi1.hProcess, &exitCode1);
    GetExitCodeProcess(pi2.hProcess, &exitCode2);

    printf("First child exited with code %u\n", (unsigned)exitCode1);
    printf("Second child exited with code %u\n", (unsigned)exitCode2);

    // Close handles
    CloseHandle(pi1.hProcess);
    CloseHandle(pi1.hThread);
    CloseHandle(pi2.hProcess);
    CloseHandle(pi2.hThread);

    return 0;
}
