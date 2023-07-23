// Sends a WM_SYSCOMMAND message with parameter SC_MONITORPOWER 2.
// This turns off the screen, which enables modern standby.
// 
// Thanks to: https://learn.microsoft.com/en-us/answers/questions/809840/how-to-programatically-trigger-modern-standby-(des
// Documentation: https://learn.microsoft.com/en-gb/windows/win32/menurc/wm-syscommand

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    // Register the window class.

    const wchar_t CLASS_NAME[] = L"Message Handling Window";

    WNDCLASS wc = { };

    // No custom message handling required, so we just pass the default window procedure here.
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create window to get a valid handle for SendMessage.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Message Handling Window",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInst,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    // Send WM_SYSCOMMAND to power off the monitor.
    // 
    // Note: Using HWND_BROADCAST, all top-level windows will receive the message.
    // This leads to the monitor being turned off multiple times. To circumvent this,
    // we have created a dummy window which will receive our message.

    SendMessage(hwnd, WM_SYSCOMMAND, SC_MONITORPOWER, 2);

    // Destroy the window.

    DestroyWindow(hwnd);

    return 0;
}
