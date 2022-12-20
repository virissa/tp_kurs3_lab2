#include "mylist.h"

template <typename T>
void mcin(T* _x)
{
	while (true)
	{
		cin >> *_x;
		if (std::cin.good())
			break;

		cout << "invalid input" << std::endl;
		cin.clear();
		cin.ignore();
	}
}

aeroflot* myList::operator[](int idx)
{
	if (idx < 0 || idx > size)
	{
		return nullptr;
	}

	aeroflot* ptr = HEAD;

	int count = 0;
	while (count != idx)
	{
		ptr = ptr->getNextPtr();
		count++;
	}

	return ptr;
}

void myList::sort()
{
	if (size == 1)
		return;

	aeroflot* p = HEAD->getNextPtr();
	aeroflot* prev = HEAD;
	int count = 1;
	while (count != size)
	{
		int state = strcmp(p->getName().c_str(), p->getNextPtr()->getName().c_str());
		bool isToSort = (a_to_z_flag == true) ? (state > 0) : (state < 0);
		if (isToSort)
		{
			//swap
			aeroflot* ptr0 = (*this)[count - 1];
			aeroflot* ptr1 = (*this)[count];
			aeroflot* ptr2 = (*this)[count + 1];
			aeroflot* ptr3 = (*this)[count + 2];

			ptr0->setNextPtr(ptr2);
			ptr1->setNextPtr(ptr3);
			ptr2->setNextPtr(ptr1);

			if (LAST == ptr2)
				LAST = ptr1;

			count = 1;
			p = HEAD->getNextPtr();
			prev = HEAD;
		}
		else
		{
			p = p->getNextPtr();
			prev = prev->getNextPtr();
			count++;
		}
	}
}




myList::myList()
{
	cout << "myList constructor called" << endl;
	size = 0;
	HEAD = new aeroflot;
	LAST = HEAD;
	a_to_z_flag = true;
}

void myList::flipFlag()
{
	a_to_z_flag = !a_to_z_flag;
	if (size > 0) sort();
}

void myList::seeFlag()
{
	cout << "\tsorting setting:";
	if (a_to_z_flag)
		cout << "\ta to z" << endl;
	else
		cout << "\tz to a" << endl;
}


void myList::add()
{
	cout << "\tadding new record" << endl;
	aeroflot* add_obj = new aeroflot;
	cin >> *add_obj;
	LAST->setNextPtr(add_obj);
	LAST = add_obj;
	size++;
	sort();
	cout << "\tadded" << endl;
}

void myList::print()
{
	if (size == 0)
		cout << endl << "\tno objects added yet" << endl;
	else
		cout << endl << "\tALL OBJECTS" << endl;
	aeroflot* p = HEAD->getNextPtr();
	while (p != nullptr)
	{
		cout << *p << endl;
		p = p->getNextPtr();
	}
}


void myList::del()
{
	cout << "\tdeleting" << endl;
	if (size == 0)
		throw 0;

	cout << "\tthere are " << size << " records, choose one to delete (index from 1 to " << size << ") : ";

	int idx;
	mcin(&idx);
	if (idx < 0 || idx > size)
		throw - 1;

	aeroflot* prev = (*this)[idx - 1];

	if (idx == size)
	{
		delete LAST;
		LAST = prev;
		LAST->setNextPtr(nullptr);
		size--;
		return;
	}

	aeroflot* curr = (*this)[idx];
	aeroflot* next = (*this)[idx + 1];

	delete curr;
	prev->setNextPtr(next);

	cout << "\tdeleted" << endl;
	size--;
	sort();
}

void myList::edit()
{
	cout << "\tediting" << endl;
	if (size == 0)
		throw 0;

	cout << "\tthere are " << size << " records, choose one to delete (index from 1 to " << size << ") : ";

	int idx;
	mcin(&idx);
	if (idx < 0 || idx > size)
		throw - 1;


	aeroflot* curr = (*this)[idx];
	cout << "\tenter new values for this object" << endl;
	cin >> *curr;

	cout << "\tedited" << endl;
	sort();
}

void myList::findType()
{
	cout << "\tsearch " << endl;
	if (size == 0)
		throw 0;

	string searchValue;

	cout << "\tplane type to search: ";
	cin.clear();
	cin.ignore();
	getline(cin, searchValue);

	aeroflot* p = HEAD->getNextPtr();
	while (p != nullptr)
	{
		if (p->getType() == searchValue)
		{
			cout << "plane number " << p->getNumber() << " flies to " << p->getName() << endl;
		}

		p = p->getNextPtr();
	}
	cout << "\tsearch finished" << endl;
}