#pragma once
#include <iostream>
#include"map_of_client.h"

using namespace std;
namespace transform_ui
{
	int _start_trans;

	int balance;


	void hider(string word)
	{
		cout << "\t\t\t====================================\n"
			<< "\t\t\t\t  " << word << "\n"
			<< "\t\t\t====================================\n";
	}

	void trans_form_menue(map_of_client& _print);

	void check_your_accont(int i, map_of_client &_print)
	{
		cout << "____________________________________________________\n";
		cout << "first name : " << _print.clints_info[i]._first_name
			<< "\nlast name : " << _print.clints_info[i]._last_name
			<< "\nfull name : " << _print.clints_info[i]._all_name
			<< "\nphone number : " << _print.clints_info[i]._phone_number
			<< "\naccont number :" << _print.clints_info[i]._AccountNumber
			<< "\npincode : " << _print.clints_info[i]._PinCode
			<< "\nemail : " << _print.clints_info[i].email
			<< "\nyour balance : " << _print.clints_info[i]._AccountBalance
			<< "\n__________________________________________________\n";

	}

	int  search_balance(map_of_client &_print)
	{
		string accont;
		cout << "enter accontnumber : ";
		cin >> accont;
		int i =_print.find_accont_client(accont);

		while (i == -1 && accont != "exit")
		{
			cout << "re enter accontnumber  or if you exit enter exit : ";
			cin >> accont;
			i = _print.find_accont_client(accont);
		}
		if (accont == "exit")
			return -1;
		
		return i;
	}

	void change_balance(int i , int balance , map_of_client& _print)
	{
		cout << "before depost : " << _print.clints_info[i]._AccountBalance << "\n";
		_print.clints_info[i]._AccountBalance += balance;
		cout << "after depost : " << _print.clints_info[i]._AccountBalance << "\n";

		_print.auto_full = _print.clints_info[i];
		_print.update_informtion_for_client_or_creat_new_client(3, i);
	}

	void depost(map_of_client &_print)
	{
		system("cls");
		int add_balance;
		hider("depost menue");
		int i = search_balance(_print);
		if (i == -1)
			return ;
		check_your_accont(i, _print);
		cout << " enter balance : ";
		cin >> balance;
		change_balance(i , balance, _print);
		system("pause>0");
	}

	void whithraw(map_of_client& _print)
	{
		system("cls");
		hider("whithraw menue");
		int i = search_balance(_print);
		check_your_accont(i, _print);
		cout << " enter balance : ";
		cin >> balance;
		if (balance <= _print.clints_info[i]._AccountBalance)
			change_balance(i, -balance, _print);
		else
			cout << "you dont have this balance ... ";
		system("pause>0");
	}

	void all_balancew(map_of_client& _print)
	{
		system("cls");
		hider("show all balance");
		cout << "\t\t\t\t number of accont (" << _print.clints_info.size() << ")";
		cout << "\n  _________________________________________________________________________________________\n";
		cout << left << setw(10) << "  first name" << "|"
			<< left << setw(11) << "last name" << "|"
			<< left << setw(21) << "full name" << "|"
			<< left << setw(11) << "acontnumber" << "|"
			<< left << setw(12) << "balance" << "|";
		cout << "\n  _________________________________________________________________________________________\n\n  ";
		for (int i = 0; i < _print.clints_info.size(); i++)
		{
			cout << left << setw(10) <<_print.clints_info[i]._first_name << "|"
				<< left << setw(11) << _print.clints_info[i]._last_name << "|"
				<< left << setw(21) << _print.clints_info[i]._all_name << "|"
				<< left << setw(11) << _print.clints_info[i]._AccountNumber << "|"
				<< left << setw(12) << _print.clints_info[i]._AccountBalance<< "|\n  ";

		}
		system("pause>0");
	}

	void show_balance(int i, map_of_client& _print)
	{
		cout << "_________________________\n"
			<< "full name : " << _print.clints_info[i]._all_name
			<< "\naccont number : " << _print.clints_info[i]._AccountNumber
			<< "\nbalnce : " << _print.clints_info[i]._AccountBalance << "\n_________________________\n";
	}

	void tansform_from_clints(map_of_client& _print)
	{
		system("cls");
		hider("trans form clints");
		int index1, index2;
		index1 = search_balance(_print);
		show_balance(index1, _print);

		index2 = search_balance(_print);
		show_balance(index2, _print);
		int b;
		
		cout << "enter your balance that you want transform : ";
		cin >> b;

		while (b > _print.clints_info[index1]._AccountBalance)
		{
			cout << "you dont have this balnce :\nreturn agine...";
			cin >> b;
		}

		_print.clints_info[index1]._AccountBalance -= b;
		_print.clints_info[index2]._AccountBalance += b;
		cout << "\n\tdone...\n";
		show_balance(index1, _print);

		show_balance(index2, _print);

		_print.change_accont_balance(index1);
		_print.change_accont_balance(index2);
		system("pause>0");

	}

	void test_case_trans(map_of_client &_print)
	{
		if (_start_trans == 1)
			depost(_print);
		else if (_start_trans == 2)
			whithraw(_print);
		else if (_start_trans == 3)
			all_balancew(_print);
		else if (_start_trans == 4)
			tansform_from_clints(_print);
	}

	void trans_form_menue(map_of_client &_print)
	{
		system("cls");
		hider("transform menue");
		
		cout << "\n-------------------------------------------\n";
		cout << "   [1] depost   \n";
		cout << "   [2] withdraw  \n";
		cout << "   [3] total balanc  \n";
		cout << "   [4] transform from clints  \n";
		cout << "   [5] main menue  \n";
		cout << "\n-------------------------------------------\n";

		cout << "enter your number.... ";
		cin >> _start_trans;
		test_case_trans(_print);
	}
}