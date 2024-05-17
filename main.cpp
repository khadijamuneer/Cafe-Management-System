#include "PROJECT.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

	Welcome();
	for (int i = 0; i < 100; i++)
	{
		User userObj;
		userObj.user();

		int identity;
		cout << "Enter you Identity!" << endl;
		cout << "1. Administrator" << endl;
		cout << "2. Staff" << endl;
		cout << "3. Customer" << endl;
		cin >> identity;
		switch (identity)
		{
		case 1:
			Administrator Obj;
			Obj.option();
			break;
		case 2:
			CafeStaff process;
			process.ProcessOrder();
			break;
		case 3:
			Customer obj;
			obj.Option();
		}
	}
	return 0;
}