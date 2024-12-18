#pragma once
#include <iostream>
#include "map_of_client.h"
using namespace std;
namespace users_ui
{
	int _start;

	map_of_users _print;


	string accont_user;

	string power;

	void hider(string word)
	{
		cout << "\t\t\t====================================\n"
			<< "\t\t\t\t  " << word << "\n"
			<< "\t\t\t====================================\n";
	}

	string give_power_to_user()
	{
		string permi;
		char y;
		cout << "do you want give this user all pwoer y/n ? ";
		cin >> y;
		if (y == 'y')
			permi = "111111111111";
		else
		{
			{cout << "acces to show all accont clints y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to  new accont clints y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to updeate accont clints y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to show delet accont clints y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to search accont clint y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to transform clints y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to show all usres y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to add new accont usres y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to update accont users y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to delet accont users y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }

			{cout << "acces to search accont users y/n?";
			cin >> y;
			if (y == 'y')
				permi += "1";
			else
				permi += "0"; }
			
		}
		return permi;
	}

	void check_your_accont(int i)
	{
		cout << "____________________________________________________\n";
		cout << "first name : " << _print.user_info[i].name
			<< "\npincode : " << _print.user_info[i].password
			<< "\nyour balance : " << _print.user_info[i].powers
			<< "\n__________________________________________________\n";

	}

	void write_your_change(string accont_number)
	{
		cout << "enter your first name : ";
		cin >> _print.auto_full.name;

		cout << "enter your  password : ";
		cin >> _print.auto_full.password;

		/*cout << "enter your powers : ";
		cin >> _print.auto_full.powers;*/

		_print.auto_full.powers= give_power_to_user();
	}

	void change_accont_user(bool ans, string masige)
	{
		system("cls");
		hider("change user");
		string write_accont;
		cout << "enter accont number : ";
		cin >> write_accont;
		int i = _print.find_accont_user(write_accont);
		/*if (_print.user_info[i].name == accont_user)
		{
			cout << "you cant delet this user ...";
			system("pause>0");
			return;
		}*/

		bool f = (i == -1);
		while (ans == f && write_accont != "exit")
		{
			cout << masige << "\n\t\nrepet write count if you want exit write exit : ";
			cin >> write_accont;
			i = _print.find_accont_user(write_accont);
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
			if (y != 'y' && y != 'Y')
				return;
		}
		if (_start != 4)
			write_your_change(write_accont);

		_print.update_informtion_for_user_or_creat_new_user(_start, i);

		system("pause>0");
	}

	void search_user()
	{
		system("cls");
		hider("search accont number ");
		string accont;
		cout << "enter accont number ... ";
		cin >> accont;
		int i = _print.find_accont_user(accont);
		if (i != -1)
			check_your_accont(i);
		else
		{
			cout << "you dont find this accont....";
		}
		system("pause>0");
	}

	void select_all_user()
	{
		system("cls");
		hider("show_all_users");
		cout << "\t\t\t\t number of accont (" << _print.user_info.size()<< ")";
		cout << "\n  _________________________________________________________________________________________\n";
		cout << left << setw(10) << "  user name" << "|"
			<< left << setw(7) << "pasword" << "|"
			<< left << setw(12) << "powers" << "|";
		cout << "\n  _________________________________________________________________________________________\n\n  ";
		for (int i = 0; i != _print.user_info.size(); i++)
		{
			cout << left << setw(10) << _print.user_info[i].name << "|"
				<< left << setw(7) << _print.user_info[i].password << "|"
				<< left << setw(12) << _print.user_info[i].powers << "|";
			cout << "\n  ";
		}
		system("pause>0");
	}

	void test_case()
	{
		if (_start == 1 && power[6] == '1')
			select_all_user();
		else if (_start == 2 && power[7] == '1')
			change_accont_user(0, "this accont found aready..");
		else if (_start == 3 && power[8] == '1' )
			change_accont_user(1, "this accont not found..");
		else if (_start == 4 && power[9] == '1')
			change_accont_user(1, "this accont not found..");
		else if (_start == 5 && power[10] == '1')
			search_user();
		else if (_start <= 5)
		{
			system("cls");
			cout << "you dont have this acces.....";
			system("pause>0");
		}
	}

	void main_users()
	{
		system("cls");
		hider("main_users");
		cout << "\n-------------------------------------------\n";

		cout << "   [1] show all users   \n";
		cout << "   [2] new user \n";
		cout << "   [3] update user  \n";
		cout << "   [4] delet user  \n";
		cout << "   [5] search user \n";
		cout << "   [6] exit  \n";

		cout << "\n-------------------------------------------\n";

		cout << "enter your number.... ";
		cin >> _start;
		test_case();
	}

	int login()
	{

		
		int i;
		string pass_user;
		int m=3;
		do
		{
			do
			{
				system("cls");
				hider("login");
				cout << "enter name user :";
				cin >> accont_user;
				i = _print.find_accont_user(accont_user);
				i = _print.find_accont_user(accont_user);
				if (i != -1)
					break;
				cout << "dont find this user...";
				system("pause>0");
			} while (1);

			cout << "enter password : ";
			cin >> pass_user;
			if (pass_user == _print.user_info[i].password)
				break;
			cout << "error .." << m <<"\n";
			system("pause>0");
		} while (m--);
		if (m <= 0)
			return 0;
		power = _print.user_info[i].powers;
		cout << "connerct seccefuly .....";
		return 1;
		system("pause>0");
	}
}
