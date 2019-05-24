/*Seth, George, Chris
Vigenere Ciphere Project*/
#include <iostream>
#include <string>
#include <locale>
using namespace std;

string encrypt(string, string);
string decrypt(string, string);
string keymaker(string, string);
void char_check(string &);
void upper_char(string &);

int main()
{
	int choice;
	string user_msg, user_key;
	static string new_key;
	static string encrypt_msg;

	cout << "  .____                  __        ____/\\__   ____  __.                   \n";
	cout << "  |    |    ____   ___  |  | __   /   / /_/  |    |/ _|____ __.__.         \n";
	cout << "  |    |   /  _ \\_/ __\\ |  |/ /   \\__/ /_ \\  |      <_/ __ (  |  |     \n";
	cout << "  |    |__(  (_) )  \\___|    (    / / /__) ) |    |  \\  __/\\___  |      \n";
	cout << "  |_______ \\____/ \\___  }__|_ \\  /_/ /__  /  |____|__ \\__  > ____|     \n";
	cout << "          \\/          \\/     \\/    \\/   \\/           \\/  \\/\\/    \n\n";
	cout << "                            A G.C.K. Program                           \n\n\n";


	do
	{

		cout << "\n  ___________________________________________  \n";
		cout << " | Please select from the following options. | \n";
		cout << " |===========================================| \n";
		cout << " | 1)-------- Encrypt a message.             | \n";
		cout << " | 2)-------- Decrypt a message.             | \n";
		cout << " | 3)-------- Exit the program.              | \n";
		cout << " |___________________________________________| \n\n";
		cout << "            ***  Enter choice  ***           ";
		cin >> choice;

		while ((choice < 1) || (choice > 3))
		{
			cout << "  ___________________________________________  \n";
			cout << " |        That is not a valid option.        | \n";
			cout << " |           Please choose again.            | \n";
			cout << " |___________________________________________| \n\n";
			cout << "            ***  Enter choice  ***           ";
			cin >> choice;
		}

		if (choice == 1)
		{
			cin.ignore();
			cout << "  ___________________________________________  \n";
			cout << " |      Enter message to be encrypted:       | \n";
			cout << " |___________________________________________| \n\n --> ";
			getline(cin, user_msg);
			char_check(user_msg);
			upper_char(user_msg);

			cout << "  ___________________________________________  \n";
			cout << " |      Enter a key word for decryption:     | \n";
			cout << " |___________________________________________| \n\n --> ";
			getline(cin, user_key);
			char_check(user_key);
			upper_char(user_key);

			new_key = keymaker(user_msg, user_key);
			encrypt_msg = encrypt(user_msg, new_key);

			cout << "\n  Your key for this message is: \n  --> " << new_key << endl;
			cout << "  Your encrypted message is: \n  --> " << encrypt(user_msg, keymaker(user_msg, user_key)) << endl << endl;
		}

		else if (choice == 2)
		{
			if (user_msg.length() > 0)
			{

				cout << "  ___________________________________________  \n";
				cout << " |      What would you like to decrypt?      | \n";
				cout << " |===========================================| \n";
				cout << " | 1) Decrypt last message.                  | \n";
				cout << " | 2) Input a message for decryption.        | \n";
				cout << " |___________________________________________|\n\n";
				cout << "            ***  Enter choice  ***           ";
				cin >> choice;

				while ((choice < 1) || (choice > 2))
				{
					cout << "  ___________________________________________  \n";
					cout << " |        That is not a valid option.        | \n";
					cout << " |           Please choose again.            | \n";
					cout << " |___________________________________________| \n\n";
					cout << "            ***  Enter choice  ***           ";
					cin >> choice;
				}

				if (choice == 1)
				{
					cout << "\n  The key for this message is: \n  --> " << new_key << endl;
					cout << "  The decrypted msg is: \n  --> " << decrypt(encrypt_msg, new_key) << endl << endl;
				}
				else
				{
					cout << "Print out for 2nd choice.\n";
				}
			}
			else
			{
				cout << "  ___________________________________________  \n";
				cout << " |      Enter message to be decrypt:         | \n";
				cout << " |___________________________________________| \n\n --> ";
			}
		}

		else
		{
			cout << "              ___________________________________________  \n";
			cout << "             |  ******** THANK YOU FOR USING **********  | \n";
			cout << "             |___________________________________________| \n";
			cout << "  .____                  __        ____/\\__   ____  __.                   \n";
			cout << "  |    |    ____   ___  |  | __   /   / /_/  |    |/ _|____ __.__.         \n";
			cout << "  |    |   /  _ \\_/ __\\ |  |/ /   \\__/ /_ \\  |      <_/ __ (  |  |     \n";
			cout << "  |    |__(  (_) )  \\___|    (    / / /__) ) |    |  \\  __/\\___  |      \n";
			cout << "  |_______ \\____/ \\___  }__|_ \\  /_/ /__  /  |____|__ \\__  > ____|     \n";
			cout << "          \\/          \\/     \\/    \\/   \\/           \\/  \\/\\/    \n\n";
			cout << "                            A G.C.K. Program                           \n\n\n";
		}

	} while (choice != 3); //sentinel to end do-while loop

	system("Pause");
	return 0;
}

string encrypt(string msg, string key)
{
	string tmp_encrypt;
	for (int i = 0; i < msg.length(); i++)
	{
		// if (msg[i] >= 'A' && msg[i] <= 'Z')
		int tmp = (msg[i] + key[i]) % 26;
		tmp += 'A';
		if (msg[i] == ' ')
			tmp = ' ';
		tmp_encrypt.push_back(tmp);
	}
	return tmp_encrypt;
}

string decrypt(string msg, string key)
{
	string tmp_decrypt;
	for (int i = 0; i < msg.length(); i++)
	{
		int tmp = (msg[i] - key[i] + 26) % 26;

		tmp += 'A';
		if (msg[i] == ' ')
			tmp = ' ';
		tmp_decrypt.push_back(tmp);
	}
	return tmp_decrypt;
}


string keymaker(string msg, string key)
{
	int tmp = msg.length();

	for (int i = 0; i < msg.length(); i++)
	{
		if (tmp == i)
			i = 0;
		if (key.length() == msg.length())
		{
			break;
		}
		if (key.length() < msg.length())
		{
			key.push_back(key[i]);
		}
		if (key.length() > msg.length())
			key.pop_back();
	}
	return key;
}

void char_check(string &line)
{
	int i = 0;
	while (!((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || (line[i] == ' ')))
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (!((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || (line[i] == ' ')))
			{
				i = 0;
				cout << "  ___________________________________________  \n";
				cout << " |        That is not a valid option.        | \n";
				cout << " |         Characters only please.           | \n";
				cout << " |___________________________________________| \n\n";
				cout << " Enter message: \n  --> ";
				getline(cin, line);
			}
		}
		i++;
	}
	cout << endl;
}

void upper_char(string &line)
{
	for (int i = 0; i < line.length(); i++)
		line[i] = toupper(line[i]);
}
