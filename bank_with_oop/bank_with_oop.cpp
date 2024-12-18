
#include <iostream>
#include "map_of_client.h"
#include"ui_bank.h"
//#include"blue_brint_users.h"
using namespace std;

	


int main()
{
	if (users_ui::login())
		while (bank_ui::_start < 8)
			bank_ui::main_menue();
}

