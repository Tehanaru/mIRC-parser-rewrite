#ifndef STRUCT_WINDOW_CLASSES_H
#define STRUCT_WINDOW_CLASSES_H

	//////////////////////////////////////////////////////////////////////////////
	//		Header file to contain window classes used by the parser interface.	//
	//	Also contains Global Variables (Hopefully just 1, the hInstance)		//
	//																			//
	//	Functions declared here:												//
	//		* BOOL InitApplication(HINSTANCE)									//
	//			- This function intializes the main window instance, setting	//
	//			the main window's parameters and calling the RegisterClassEx	//
	//			function.  It returns whatever RegisterClassEx returns.			//
	//																			//
	//		* BOOL InitInstance(HINSTANCE, INT)									//
	//			- This function initializes the main instance of the program,	//
	//			creates the window, and sends the paint command to the winproc	//
	//			function.  Returns true if the window was successfully created	//
	//			false if no handle to the main window exists.					//
	//////////////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <memory>



BOOL InitApplication(HINSTANCE hiParser, std::shared_ptr<LPSTR> className);

BOOL InitInstance(HINSTANCE hiParser, int nCmdShow, std::shared_ptr<LPSTR> className);

#endif