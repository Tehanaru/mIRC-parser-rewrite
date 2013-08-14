	//////////////////////////////////////////////////////////////
	//	Source file for the window class registration functions	//
	//////////////////////////////////////////////////////////////

#include <Windows.h>
#include <memory>
#include <stdexcept>

#include "winProc.h"
#include "resource.h"
#include "ezWinAPI_Functions.h"


BOOL InitApplication(HINSTANCE hInstance, std::shared_ptr<LPSTR> className)
{
	WNDCLASSEX wcMain;
	

	//Parameters for main window
	wcMain.cbSize			=	sizeof(WNDCLASSEX);
	wcMain.style			=	0;
	wcMain.lpfnWndProc		=	wndProcMain;
	wcMain.cbClsExtra		=	0;
	wcMain.cbWndExtra		=	0;
	wcMain.hInstance		=	hInstance;
	wcMain.hIcon			=	LoadIcon(NULL, MAKEINTRESOURCE(IDI_PARSER));
	wcMain.hCursor			=	LoadCursor(NULL, IDC_ARROW);
	wcMain.hbrBackground	=	(HBRUSH)(COLOR_WINDOW);
	wcMain.lpszMenuName		=	MAKEINTRESOURCE(IDR_MAIN_MENU);
	wcMain.lpszClassName	=	(LPCWSTR)(*className);

	return RegisterClassEx(&wcMain);
}

BOOL InitInstance(HINSTANCE hiParser, int nCmdShow, std::shared_ptr<LPSTR> className)
{
	HWND hwnd;
	std::shared_ptr<LPSTR> wnTitle;
	wnTitle = makeStrLPSTR("mIRC Log Parser");

	hwnd = CreateWindow( 
			(LPCWSTR)(*className),			// name of window class 
			(LPCWSTR)(*wnTitle),			// title-bar string 
			WS_OVERLAPPEDWINDOW,			// top-level window 
			CW_USEDEFAULT,					// default horizontal position 
			CW_USEDEFAULT,					// default vertical position 
			CW_USEDEFAULT,					// default width 
			CW_USEDEFAULT,					// default height 
			(HWND) NULL,					// no owner window 
			(HMENU) NULL,					// use class menu 
			hiParser,						// handle to application instance 
			(LPVOID) NULL);					// no window-creation data 

	if (!hwnd)
		return FALSE;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	return TRUE;
}