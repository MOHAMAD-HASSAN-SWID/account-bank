#pragma once
#include <iostream>
#include <string>
#include "blue_print_bank.h"
#include<iomanip>
#include "blue_brint_users.h"
using namespace std;

class map_of_client:protected blue_print_bank
{
public:	
	ID_CLINT auto_full;
	ID_CLINT defult_information;

	vector <ID_CLINT> clints_info = catch_informatin_all_clints();
	int length = clints_info.size();

	void update_informtion_for_client_or_creat_new_client( int mod , int i)
	{
			change_information_clint( auto_full  ,mod, i);
			clints_info = catch_informatin_all_clints();
			auto_full = defult_information;
	}

	void change_accont_balance(int i)
	{
		change_information_clint(clints_info[i],3, i);
	}

	int find_accont_client(string accont)
	{
		return find_accont_number(accont);
	}

	map_of_client()
		:blue_print_bank()
	{

	}


};

class map_of_users :protected blue_brint_users
{
public:
	ID_user auto_full;
	ID_user defult_information;

	vector <ID_user> user_info = catch_informatin_all_users();

	void update_informtion_for_user_or_creat_new_user(int mod, int i)
	{
		change_information_clint(auto_full, mod, i);
		user_info = catch_informatin_all_users();
		auto_full = defult_information;
	}

	int find_accont_user(string accont)
	{
		return find_accont_number(accont);
	}

	map_of_users()
		:blue_brint_users()
	{

	}


};
