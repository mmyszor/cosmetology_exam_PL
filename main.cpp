#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include <iostream>
#include <cstdlib>
#include <tchar.h>
#include <windows.h>
#include "pytania.h"
#include "odpowiedzi.h"

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
#define id_kat1 501
#define id_kat2 502
#define id_kat3 503
#define id_kat4 504
#define id_kat5 505
#define IDEND 23
#define pyt 100
#define odp 101
#define ans 102


int liczba;
HWND b1_kat1;
HWND b2_kat2;
HWND b3_kat3;
HWND b4_kat4;
HWND b5_kat5;
HWND pytanie;
HWND odpowiedz;
HWND show_ans;
int x=0;
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_QUESTION);
    wincl.hIconSm = LoadIcon (NULL, IDI_QUESTION);
    wincl.hCursor = LoadCursor (NULL, IDC_HELP);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Kocham Kobitke <3"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1000,                 /* The programs width */
           800,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
    b1_kat1 = CreateWindowEx( 0, "BUTTON", "Ogolne", WS_CHILD | WS_VISIBLE,25, 50, 150, 30, hwnd, (HMENU) id_kat1, NULL, NULL );
    b2_kat2 = CreateWindowEx( 0, "BUTTON", "PMU", WS_CHILD | WS_VISIBLE,25, 100, 150, 30, hwnd, (HMENU) id_kat2, NULL, NULL );
    b3_kat3 = CreateWindowEx( 0, "BUTTON", "Anty Aging", WS_CHILD | WS_VISIBLE,25, 150, 150, 30, hwnd, (HMENU) id_kat3, NULL, NULL );
    pytanie = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |SS_CENTER, 200, 70, 700, 200, hwnd, (HMENU) pyt, NULL, NULL );
    odpowiedz = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |SS_RIGHTJUST, 200, 320, 700, 400, hwnd, (HMENU) odp, NULL, NULL );
    show_ans = CreateWindowEx( 0, "BUTTON", "Pokaz odpowiedz", WS_CHILD | WS_VISIBLE,25, 300, 150, 30, hwnd, (HMENU) ans, NULL, NULL );
    HWND hStatic1 = CreateWindowEx( 0, "STATIC", "Odpowiedz", WS_CHILD | WS_VISIBLE |SS_CENTER, 200, 300, 700, 20, hwnd, (HMENU) pyt, NULL, NULL );
    HWND hStatic2 = CreateWindowEx( 0, "STATIC", "Pytanie", WS_CHILD | WS_VISIBLE |SS_CENTER, 200, 50, 700, 20, hwnd, (HMENU) pyt, NULL, NULL );
    HWND hStatic3 = CreateWindowEx( 0, "STATIC", "Created by Michal Myszor", WS_CHILD | WS_VISIBLE |SS_CENTER, 775, 735, 200, 20, hwnd, (HMENU) pyt, NULL, NULL );


    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_COMMAND:
            switch( wParam )
            {
            case id_kat1:
                {
                x=2;
                liczba =( std::rand() % 84 ) + 1;
                SetWindowText(pytanie, "");
                SetWindowText(odpowiedz, "");
                SetWindowText(pytanie, ogl[liczba]);
                break;
                }
            case id_kat2:
                {
                x=0;
                liczba =( std::rand() % 34 ) + 1;
                SetWindowText(pytanie, "");
                SetWindowText(odpowiedz, "");
                SetWindowText(pytanie, pmu[liczba]);
                break;
                }
            case id_kat3:
                {
                x=1;
                liczba =( std::rand() % 34 ) + 1;
                SetWindowText(pytanie, "");
                SetWindowText(odpowiedz, "");
                SetWindowText(pytanie, aa[liczba]);
                break;
                }

            case ans:
                {
                if (x==0)
                {
                 SetWindowText(odpowiedz, odpo_pmu[liczba]);
                }
                else if (x==1)
                {
                 SetWindowText(odpowiedz, odpo_aa[liczba]);
                }
                else if (x==2)
                {
                 SetWindowText(odpowiedz, odpo_og[liczba]);
                }
                break;
                }


                default:
                break;
                }
break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

