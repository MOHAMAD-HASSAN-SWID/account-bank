#pragma once
#include <iostream>
#include"map_of_client.h"
#include"transform.h"
#include "usres.h"
using namespace std;
namespace bank_ui
{
	int _start;

	map_of_client _print;

	void hider(string word)
	{
		cout << "\t\t\t====================================\n"
			<<"\t\t\t\t  " <<word << "\n"
		<< "\t\t\t====================================\n";
	}

	void main_menue();

	void select_all_client()
	{
		system("cls");
		hider("all of clint");
		cout << "\t\t\t\t number of accont (" << _print.clints_info.size()<< ")";
		cout << "\n  _________________________________________________________________________________________\n";
		cout << left << setw(10) << "  first name" << "|"
			<< left << setw(11) << "last name" << "|"
			<< left << setw(21) << "full name" << "|"
			<< left << setw(11) << "phonenumber" << "|"
			<< left << setw(11) << "acontnumber" << "|"
			<< left << setw(7) << "pincode" << "|"
			<< left << setw(22) << "emil" << "|"
			<< left << setw(12) << "balance" << "|";
		cout << "\n  _________________________________________________________________________________________\n\n  ";
		for (int i = 0; i != _print.clints_info.size(); i++)
		{
			cout <<left << setw(10)<< _print.clints_info[i]._first_name << "|"
				<< left << setw(11) << _print.clints_info[i]._last_name << "|"
				<< left << setw(21) << _print.clints_info[i]._all_name << "|"
				<< left << setw(11) << _print.clints_info[i]._phone_number << "|"
				<< left << setw(11) << _print.clints_info[i]._AccountNumber << "|"
				<< left << setw(7) << _print.clints_info[i]._PinCode << "|"
				<< left << setw(22) << _print.clints_info[i].email << "|"
				<< left << setw(12) << _print.clints_info[i]._AccountBalance << "|";
			cout <<"\n  ";
		}
		system("pause>0");

	}

	void write_your_change(string accont_number)
	{
		cout << "enter your first name : ";
		cin >> _print.auto_full._first_name;

		cout << "enter your last name : ";
		cin >> _print.auto_full._last_name;

		cout << "enter your phone number : ";
		cin >> _print.auto_full._phone_number;

		_print.auto_full._AccountNumber = accont_number;

		cout << "enter your pin code : ";
		cin >> _print.auto_full._PinCode;

		cout << "enter your emile : ";
		cin >> _print.auto_full.email;

		cout << "enter your accont balance : ";
		cin >> _print.auto_full._AccountBalance;

		_print.auto_full._all_name = _print.auto_full._first_name + " " + _print.auto_full._last_name;
	}

	void check_your_accont(int i)
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

	void change_accontnumber(bool ans , string masige)
	{
		system("cls");
		hider("change accont");
		string write_accont;
		cout << "enter accont number : ";
		cin >> write_accont;
		int i = _print.find_accont_client(write_accont);
		bool f = (i == -1);
		while ( ans == f  && write_accont !="exit")
		{
			cout << masige << "\n\t\nrepet write count if you want exit write exit : ";
			cin >> write_accont;
			i = _print.find_accont_client(write_accont);
			f = (i == -1);
		}
		if (write_accont == "exit")
			return;
		
		if (_start == 3 || _start == 4)
		{
			check_your_accont(i);
			char y;
			cout << "do you want continue ? y/n... ";
			cin >> y;
			if (y != 'y' && y!='Y')
				return;
		}

		if (_start != 4)
			write_your_change(write_accont);

		_print.update_informtion_for_client_or_creat_new_client(_start, i);
			
		system("pause>0");
	}

	void search_accont_number()
	{
		system("cls");
		hider("search accont number ");
		string accont;
		cout << "enter accont number ... ";
		cin >> accont;
		int i = _print.find_accont_client(accont);
		if (i!=-1)
		check_your_accont(i);
		else
		{
			cout << "you dont find this accont....";
		}
		system("pause>0");
	}

	void transform()
	{
		transform_ui::_start_trans = 0;
		while (transform_ui::_start_trans <5)
		 transform_ui::trans_form_menue(_print);
	}

	void manage_users()
	{
		users_ui::_start = 0;
		while(users_ui::_start <6)
		users_ui::main_users();
	}

	void end_program()
	{
		system("cls");

		cout << "\n\n\n***********************************\n\n";

		cout << "thank you for use our programar *-^)";

		cout << "\n\n***********************************\n";

		system("pause>0");
	}

	void test_case()
	{
		if (_start == 1 && users_ui::power[0] == '1')
			select_all_client();
		else if (_start == 2 && users_ui::power[1] == '1')
			change_accontnumber(0, "this accont found aready..");
		else if (_start == 3 && users_ui::power[2] == '1')
			change_accontnumber(1, "this accont not found..");
		else if (_start == 4 && users_ui::power[3] == '1')
			change_accontnumber(1, "this accont not found..");
		else if (_start == 5 && users_ui::power[4] == '1')
			search_accont_number();
		else if (_start == 6 && users_ui::power[5] == '1')
			transform();
		else if (_start == 7 )
			manage_users();
		else if (_start <= 6)
		{
			system("cls");
			cout << "you dont have this acces.....";
			system("pause>0");
		}
		else
			end_program();
	}

	void main_menue()
	{
		system("cls");

		hider(" menue bank");

		cout << "\n-------------------------------------------\n";

		cout << "   [1] show all accont   \n";
		cout << "   [2] new accont  \n";
		cout << "   [3] update accont  \n";
		cout << "   [4] delet accont  \n";
		cout << "   [5] search accont number \n";
		cout << "   [6] transform  \n";
		cout << "   [7] manage users  \n";
		cout << "   [8] exit  \n";

		cout << "\n-------------------------------------------\n";

		cout << "enter your number.... ";
		cin >> _start;
		test_case();
	}

}
