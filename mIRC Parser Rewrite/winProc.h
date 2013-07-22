#ifndef WINPROC_H
#define WINPROC_H

	//////////////////////////////////////////////////////////////////////////////////
	//		Header file for the main winProc function that will handle the messages	//
	//	sent to the application.													//
	//////////////////////////////////////////////////////////////////////////////////

#include <Windows.h>

LRESULT CALLBACK wndProcMain(HWND mainWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif