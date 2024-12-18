#pragma once
#include<iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class blue_brint_users
{
protected:
	struct ID_user 
	{
		string name;
		string password;
		string powers ;
	};

	enum _mod
	{
		show_all = 1,
		update = 3,
		new_user = 2,
		deleat = 4,
	};

	vector <string> data_users;

	vector <ID_user> information_users;

	int find_accont_number(string accont)
	{

		for (int i = 0; i < information_users.size(); i++)
		{
			if (information_users[i].name == accont)
				return i;
		}
		return -1;
	}

	void  change_information_clint(ID_user the_user, int mod, int i )
	{
		if (_mod::new_user == mod)
			information_users.push_back(the_user);
		else
		{
			information_users[i] = the_user;
		}

	}

private:
	vector <string> file_to_data_one_line(string name_file = "users.txt")
	{
		vector <string> data_user;

		fstream red_file;
		red_file.open(name_file, ios::in);
		if (red_file.is_open())
		{
			string line;
			while (getline(red_file, line))
			{
				data_user.push_back(line);
			}

			red_file.close();

		}
		return data_user;
	}

	vector <string> data_one_line_to_data_lins(string line, string sapac = "#//#")
	{
		vector <string> data_user;
		int l = 0, r;
		while ((r = line.find(sapac, l)) != line.npos)
		{
			data_user.push_back(line.substr(l, r - l));
			l = r + 4;
		}
		data_user.push_back(line.substr(l, r - l));
		return data_user;


	}

	vector<ID_user> all_data_to_information()
	{
		vector<ID_user> information;
		for (int i = 0; i < data_users.size(); i++)
		{
			vector <string> data_user = data_one_line_to_data_lins(data_users[i]);

			information.push_back(data_client_to_information_client(data_user));
		}

		return information;
	}

	ID_user data_client_to_information_client(vector<string> data_user)
	{
		ID_user information;
		information.name = data_user[0];
		information.password = data_user[1];
		information.powers =data_user[2];
		return information;
	}

	vector<string> information_to_one_line_data(string space = "#//#")
	{
		vector <string> data_client;
		string line;
		for (int i = 0; i < information_users.size(); i++)
		{
			if (information_users[i].name != "")
			{
				line =
					information_users[i].name + space +  information_users[i].password + space
					+information_users[i].powers;
				data_client.push_back(line);
			}
		}
		return data_client;
	}

	void data_client_to_file(string name_file = "users.txt")
	{
		vector<string> line = information_to_one_line_data();

		fstream write_to_file;
		write_to_file.open("users.txt", ios::out);
		if (write_to_file.is_open())
		{
			for (int i = 0; i < line.size(); i++)
			{
				write_to_file << line[i] << "\n";
			}

			write_to_file.close();
		}
	}

protected:
	blue_brint_users()
	{
		data_users = file_to_data_one_line();
		information_users = all_data_to_information();
	}
	~blue_brint_users()
	{
		//system("cls");
		char y;
		cout << "if you want save evey think for users enter y :";
		cin >> y;
		if (y == 'y')
			data_client_to_file();
	}

	vector <ID_user> catch_informatin_all_users()
	{
		return information_users;
	}

};

