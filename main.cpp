#include <iostream>
#include "mylist.h"

using namespace std;

void menuPrint()
{
	cout << endl << "\tMAIN PROGRAMM MENU" << endl;
	cout << "0\texit programm" << endl;
	cout << "1\tprint objects" << endl;
	cout << "2\tadd object" << endl;
	cout << "3\tedit object" << endl;
	cout << "4\tdelete object" << endl;
	cout << "5\tfind planes by type" << endl;
	cout << "6\tflip sorting flag" << endl;
}

void menu()
{
	myList obj;

	int take = 0;

	while (1)
	{
		menuPrint();
		obj.seeFlag();

		mcin(&take);
		switch (take)
		{
		case 0:
			return;

		case 1:
			obj.print();
			break;

		case 2:
			obj.add();
			break;

		case 3:
			try {
				obj.edit();
			}
			catch (int e)
			{
				if (e == -1)
					cout << "EXEPTION: invalid index" << endl;
				if (e == 0)
					cout << "EXEPTION: no objects added yet" << endl;
			}
			break;

		case 4:
			try {
				obj.del();
			}
			catch (int e)
			{
				if (e == -1)
					cout << "EXEPTION: invalid index" << endl;
				if (e == 0)
					cout << "EXEPTION: no objects added yet" << endl;
			}
			break;

		case 5:
			try {
				obj.findType();
			}
			catch (int e)
			{
				if (e == 0)
					cout << "EXEPTION: no objects added yet" << endl;
			}
			break;
		case 6:
			obj.flipFlag();
			break;

		default:
			cout << "unknown" << endl;
		}
	}


}

int main()
{
	menu();

	return 0;
}