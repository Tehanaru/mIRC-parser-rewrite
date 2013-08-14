// QuickAlgorithems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cin;		using std::cout;
using std::vector;

int _tmain(int argc, _TCHAR* argv[])
{
	
	vector<int> dataList;
	dataList.push_back(804);
	dataList.push_back(605);
	dataList.push_back(308);
	dataList.push_back(304);
	dataList.push_back(216);
	dataList.push_back(902);
	dataList.push_back(803);

	int temp;

//	for (int n = 0; n != 7; ++n)
	//{
		//cout << dataList[n] << " ";
	//}
	//cout << std::endl;

	for(int i=0; i!=6;++i)
	{
		for (int j=i + 1; j!=7;++j)
		{

			if (dataList[i] > dataList[j])
			{
				temp = dataList[i];
				dataList[i] = dataList[j];
				dataList[j] = temp;
				
				//cout << "I: " << i << "  J: " << j;
				//cout << std::endl;

				//for (int m = 0; m!=7; ++m)
				//{
				//	cout << dataList[m] << " ";
				//}
				//cout << std::endl;
			}


		}
	}

	cout << std::endl;

	for (int k = 0; k != 7; ++k)
	{
		cout << dataList[k];
		cout<< std::endl;
	}

	system("PAUSE");
	return 0;
}

