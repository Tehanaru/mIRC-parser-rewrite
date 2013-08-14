	//////////////////////////////////////////////////////////////////////////
	//		This source file contains functions to make the winAPI easier	//
	//	to deal with.														//
	//																		//
	//	Function List:														//
	//																		//
	//	*	makeIDHandle()	-	Converts a control ID into a HWND handle.	//
	//	*	makeStrLPSTR()	-	Converts strings to LPSTR.					//
	//////////////////////////////////////////////////////////////////////////

#include <Windows.h>
#include <string>
#include <iterator>
#include <vector>
#include <memory>

using std::string;		using std::iterator;
using std::vector;		using std::shared_ptr;

string makeLPSTRStr(LPSTR lpstr)
{
	return string(lpstr);
}


//Secondary function called by makeHandleID() [EnumChildWindow_Proc]
BOOL CALLBACK grabHWND(HWND childIn, LPARAM vecPtr)
{
	(*(vector<HWND>*)vecPtr).push_back(childIn);
	return TRUE;
}

//Converts a control ID to the handle of the window with that ID.
HWND makeIDHandle(HWND hwnd, int ctrlID)
{
	vector<HWND> handleVec;
	vector<HWND>* vecPtr = &handleVec;
	
	EnumChildWindows(hwnd, grabHWND, (LPARAM)vecPtr);
	
	vector<HWND>::iterator hand_it = handleVec.begin();

	while ( hand_it != handleVec.end() )
	{
		if ( GetDlgCtrlID(*hand_it) == ctrlID )
			return *hand_it;
		hand_it++;
	}

	vector<HWND> handleVecT;
	vector<HWND>* vecPtrT = &handleVecT;

	EnumWindows(grabHWND, (LPARAM)vecPtrT);

	vector<HWND>::iterator ht_it = handleVecT.begin();

	while ( ht_it != handleVecT.end() )
	{
		if ( GetDlgCtrlID(*ht_it) == ctrlID )
			return *ht_it;
		ht_it++;
	}

	return NULL;
}


	//	- strTo_LPSTR - STRING TO LPSTR	
//ALWAYS use to assign variables on their own line as shared_ptr<LPSTR> or other smart pointer type
shared_ptr<LPSTR> makeStrLPSTR(string sourceStr)
{
	int len = sourceStr.size() + 1;
	LPSTR ptrNew = (LPSTR)GlobalAlloc(GPTR, len);



	string::iterator src_it = sourceStr.begin();
	LPSTR tPtr = ptrNew;

	while ( src_it != sourceStr.end() )
	{
		*tPtr = *src_it++; ++tPtr;
	}

	shared_ptr<LPSTR> ptrOut = (shared_ptr<LPSTR>)&ptrNew;

	return ptrOut;
}
