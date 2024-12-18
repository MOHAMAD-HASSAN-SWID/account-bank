#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class blue_print_bank
{

protected:
	enum _mode
	{
		show_all = 1,
		update = 3,
		new_client = 2,
		deleat = 4,
	};

	struct ID_CLINT
	{
		string	_first_name = "";
		string	_last_name = "";
		string  _all_name = "";
		string _phone_number = "";
		string _AccountNumber = "";
		string _PinCode = "";
		string	 email = "";
		float _AccountBalance = 0;
	};
	
	//int client_whos_dlete = -1;

	int find_accont_number(string accont )
	{

		for (int i = 0; i < information_clients.size(); i++)
		{
			if (information_clients[i]._AccountNumber == accont)
				return i;
		}
		return -1;
	}

	void  change_information_clint( ID_CLINT the_client , int mod , int i)
	{
		if (_mode::new_client == mod)
			information_clients.push_back(the_client);
		else
		{
			/*if (_mode::deleat == mod)
				client_whos_dlete = i;*/
			information_clients[i] = the_client;
		}
		
	}

private:

	//int leanth;
	vector <string> data_clients;

	vector <ID_CLINT> information_clients;
	
	vector <string> file_to_data_one_line(string name_file = "Clients.txt")
	{
		vector <string> data_client;

		fstream red_file;
		red_file.open(name_file, ios::in);
		if (red_file.is_open())
		{
			string line;
			while (getline(red_file, line))
			{
				data_client.push_back(line);
			}

			red_file.close();

		}
		return data_client;
	}

	vector <string> data_one_line_to_data_lins(string line, string sapac = "#//#")
	{
		vector <string> data_client;
		int l = 0, r;
		while ((r = line.find(sapac, l)) != line.npos)
		{
			data_client.push_back(line.substr(l, r-l));
			l = r + 4;
		}
		data_client.push_back(line.substr(l, r-l));
		return data_client;


	}

	vector<ID_CLINT> all_data_to_information()
	{
		vector<ID_CLINT> information;
		for (int i = 0; i < data_clients.size(); i++)
		{
			vector <string> data_client = data_one_line_to_data_lins(data_clients[i]);

			information.push_back(data_client_to_information_client(data_client));
		}

		return information;
	}
	
	ID_CLINT data_client_to_information_client(vector<string> data_client)
	{
		ID_CLINT information;
		information._first_name		= data_client[0];
		information._last_name		= data_client[1];
		information.email			= data_client[2];
		information._phone_number	= data_client[3];
		information._AccountNumber  = data_client[4];
		information._PinCode		= data_client[5];
		information._AccountBalance = stof (data_client[6]);
		information._all_name		= information._first_name +" "+information._last_name;

		return information;


	}

	vector<string> information_to_one_line_data(string space = "#//#")
	{
		vector <string> data_client;
		string line;
		for (int i = 0; i < information_clients.size(); i++)
		{
			if (information_clients[i]._AccountNumber!="")
			{
				line =
					information_clients[i]._first_name + space +information_clients[i]._last_name+ space + information_clients[i].email+ space
					+ information_clients[i]._phone_number+ space + information_clients[i]._AccountNumber+ space + information_clients[i]._PinCode+ space
					+ to_string(information_clients[i]._AccountBalance);
				data_client.push_back(line);
			}		   
		}	
		return data_client;
	}	

	void data_client_to_file(string name_file = "Clients.txt")
	{
		vector<string> line = information_to_one_line_data();

		fstream write_to_file;
		write_to_file.open(name_file, ios::out);
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
	blue_print_bank()
	{
		 data_clients = file_to_data_one_line();
		// leanth = data_clients.size();
		 information_clients = all_data_to_information();

	}
	~blue_print_bank()
	{
		char y;
		cout << "if you want save evey think enter y :";
		cin >> y;
		if (y == 'y')
		data_client_to_file();
	}

	vector <ID_CLINT> catch_informatin_all_clints()
	{
		return information_clients;
	}
};

