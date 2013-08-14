#ifndef _EZWINAPI_FUNCTIONS_H
#define _EZWINAPI_FUNCTIONS_H

	//////////////////////////////////////////////////////////////////////
	//		This header contains functions for making the winAPI easier	//
	//	to deal with.													//
	//																	//
	//	Function Documentation											//
	//																	//
	//	*	HWND makeIDHandle(HWND hwnd, int ctrlID);					//
	//			This function creates a HWND (window handle) when given	//
	//		the control ID of the window desired and a handle to the	//
	//		main window instance.  It creates a vector<HWND> and passes	//
	//		a pointer to that vector to EnumChildWindows().  The		//
	//		callback function (grabHWND()) allows EnumChildWindows() to	//
	//		cycle through every child window of the main window, adding	//
	//		the handle of each window to the vector.					//
	//			Once EnumChildWindows() has exited, the function		//
	//		iterates through each element of the vector, calling		//
	//		GetDlgCtrlID() on each one until it finds one that maches	//
	//		its second parameter.  It then returns that handle.			//
	//			If none of the handles produce an ID that match the		//
	//		given parameter then makeIDHandle() returns NULL.			//
	//																	//
	//	*	shared_ptr<LPSTR> makeStrLPSTR(std::string sourceStr);		//
	//			This function creates a LPSTR (Long Pointer to String)	//
	//		suitable for passing to many winAPI functions, from any		//
	//		C++ string.  It takes the length of the string, calls		//
	//		GlobalAlloc() to create enough memory for the length + 1 in	//
	//		characters (char).  It then copies the string one character	//
	//		at a time into the memory space indicated by the			//
	//		GlobalAlloc() and returns a shared pointer to the first		//
	//		element of that memory.										//
	//			It is important to use this function to assign a		//
	//		variable on it's own line and not in a function parameter	//
	//		list.														//
	//////////////////////////////////////////////////////////////////////

#include <Windows.h>
#include <string>
#include <iterator>
#include <memory>

std::string makeLPSTRStr(LPSTR lpstr);

//A secondary function called by the makeHandleID() function. [EnumChildWindow_Proc]
BOOL CALLBACK grabHWND(HWND childIn, LPARAM vecPtr);

//Converts a Control ID (Int) to the appropriate window handle (HWND)
HWND makeIDHandle(HWND hwnd, int ctrlID);

//Do not forget to free the variable created by this function with GlobalFree!
std::shared_ptr<LPSTR> makeStrLPSTR(std::string sourceStr);

#endif