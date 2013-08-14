	//////////////////////////////////////////////////////////////////////////////////////////////
	//		This is the source file for the mIRC log parsing program. This file contains		//
	//	the main loop for the application, and includes every header in the project.			//
	//	Each header include is commented with a description of what functions and structures	//
	//	can be found in that file and its associated source.									//
	//////////////////////////////////////////////////////////////////////////////////////////////
#define UNICODE

			//Library Includes
#include <Windows.h>		//Required for Windows API
#include <memory>			//Required for smart pointers
#include <stdexcept>		//Required for exception handling.

			//Project Header Includes
#include "winProc.h"
#include "STRUCT_Window_Classes.h"
#include "ezWinAPI_Functions.h"



int WINAPI WinMain(HINSTANCE parserInstance, HINSTANCE prevInstance, LPSTR lpCmndLine, int nCmndShow)
{
	std::shared_ptr<LPSTR> wnClassName;
	wnClassName = makeStrLPSTR("Main Window Class");

	if(!InitApplication(parserInstance, wnClassName))
	{
		MessageBoxA(NULL, "Window Registration Failed!", "ERROR", MB_ICONERROR | MB_OK);
		return 1;
	}

	if(!InitInstance(parserInstance, nCmndShow, wnClassName))
	{
		MessageBoxA(NULL, "Window Creation Failed!", "ERROR", MB_ICONERROR | MB_OK);
		return 1;
	}


	HWND hMainWnd;			//main window variable
    MSG Msg;				//main message variable

	


    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
	

}
