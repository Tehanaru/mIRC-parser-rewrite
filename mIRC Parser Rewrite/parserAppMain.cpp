	//////////////////////////////////////////////////////////////////////////////////////////////
	//		This is the source file for the mIRC log parsing program. This file contains		//
	//	the main loop for the application, and includes every header in the project.			//
	//	Each header include is commented with a description of what functions and structures	//
	//	can be found in that file and its associated source.									//
	//////////////////////////////////////////////////////////////////////////////////////////////

			//Library Includes
#include <Windows.h>		//Required for Windows API
#include <memory>			//Required for smart pointers
#include <stdexcept>		//Required for exception handling.

			//Project Header Includes
#include "winProc.h"




int winMain(HINSTANCE parserInstance, HINSTANCE prevInstance, LPSTR lpCmndLine, int nCmndShow)
{

	
	WNDCLASSEX wcBaseWnd;	//Replace this with a custom window class
    HWND hMainWnd;			//main window variable
    MSG Msg;				//main message variable

	//Things that need to happen here before we start the main loop
	
	//Register the window class + Error checking

	//Create the window + error checking


    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
	

}
