/*Seth, George, Chris
Vigenere Ciphere Project*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string TABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !#$%&()\'\"*+,-./0123456789:;<=>?@[\\]^_`{|}~";

string keymaker(string, string);
string en_crypt(string, vector<int>, vector<int>);
string de_crypt(string, vector<int>, vector<int>);
vector<int> convert(string, vector<int> &);
void clear(string &, string &, string &, string &, vector<int> &, vector<int> &, vector<int> &);
void clear_decrypt(vector<int> &, vector<int> &);

int main()
{
	char choice[2];
	string user_msg, user_key, encrypt, decrypt, makekey, sec_key, sec_msg;
	vector<int> newmsg, newkey, newencrypt, own_msg, own_key;

	cout << "  .____.                .__.       ____/\\__  .____..__.                   \n";
	cout << "  |    |    ____   ___  |  | __.  /   / /_/  |    |/ _|____ __.__.         \n";
	cout << "  |    |   /  _ \\_/ __\\ |  |/ /   \\__/ /_ \\  |      <_/ __ (  |  |     \n";
	cout << "  |    |__(  (_) )  \\___|    (    / / /__) ) |    |  \\  __/\\___  |      \n";
	cout << "  |_______ \\____/ \\___  }__|_ \\  /_/ /__  /  |____|__ \\__  > ____|     \n";
	cout << "          \\/          \\/     \\/    \\/   \\/           \\/  \\/\\/    \n\n";
	cout << "                            A G.C.K. Program                           \n\n\n";

	do
	{
		cout << "              ___________________________________________  \n";
		cout << "             | Please select from the following options. | \n";
		cout << "             |===========================================| \n";
		cout << "             | 1)-------- Encrypt a message.             | \n";
		cout << "             | 2)-------- Decrypt a message.             | \n";
		cout << "             | 3)-------- Exit the program.              | \n";
		cout << "             |___________________________________________| \n\n";
		cout << "                        ***  Enter choice  ***           ";
		cin >> choice;
		cin.ignore();

		while ((choice[0] < '1') || (choice[0] > '3') || (choice[1] > ' '))
		{
			cout << "              ___________________________________________  \n";
			cout << "             |        That is not a valid option.        | \n";
			cout << "             |           Please choose again.            | \n";
			cout << "             |___________________________________________| \n\n";
			cout << "                        ***  Enter choice  ***           ";
			cin >> choice;
			cin.ignore();
		}

		if (choice[0] == '1')
		{
			if (encrypt.length() > 0)
			{
				clear(encrypt, user_msg, user_key, makekey, newmsg, newkey, newencrypt);
			}
			cout << "              ___________________________________________  \n";
			cout << "             |      Enter message to be encrypted:       | \n";
			cout << "             |___________________________________________| \n\n --> ";
			getline(cin, user_msg);

			cout << "              ___________________________________________  \n";
			cout << "             |      Enter a key word for encryption:     | \n";
			cout << "             |___________________________________________| \n\n --> ";
			getline(cin, user_key);
			if (user_key.length() == 0)
				user_key = "blank";

			makekey = keymaker(user_msg, user_key);
			convert(user_msg, newmsg);
			convert(makekey, newkey);
			encrypt = en_crypt(user_msg, newmsg, newkey);

			cout << "\n  Your key for this message is: \n  --> " << makekey << endl;
			cout << "\n  Your encrypted message is: \n  --> " << encrypt << endl << endl;
		}

		else if (choice[0] == '2')
		{
			convert(encrypt, newencrypt);

			if (user_msg.length() > 0)
			{
				cout << "              ___________________________________________  \n";
				cout << "             |      What would you like to decrypt?      | \n";
				cout << "             |===========================================| \n";
				cout << "             | 1) Decrypt last message.                  | \n";
				cout << "             | 2) Input a message for decryption.        | \n";
				cout << "             |___________________________________________|\n\n";
				cout << "                        ***  Enter choice  ***           ";
				cin >> choice;
				cin.ignore();

				while ((choice[0] < '1') || (choice[0] > '2') || (choice[1] > ' '))
				{
					cout << "              ___________________________________________  \n";
					cout << "             |        That is not a valid option.        | \n";
					cout << "             |           Please choose again.            | \n";
					cout << "             |___________________________________________| \n\n";
					cout << "                        ***  Enter choice  ***           ";
					cin >> choice;
					cin.ignore();
				}

				if (choice[0] == '1')
				{
					cout << "\n  The key for this message is: \n  --> " << makekey << endl;
					cout << "\n  The decrypted msg is: \n  --> " << de_crypt(encrypt, newencrypt, newkey) << endl << endl;
				}

				else
				{
					cout << "              ___________________________________________  \n";
					cout << "             |      Enter message to be decrypted:       | \n";
					cout << "             |___________________________________________| \n\n --> ";
					getline(cin, sec_msg);

					cout << "              ___________________________________________  \n";
					cout << "             |      Enter key word for decryption:       | \n";
					cout << "             |___________________________________________| \n\n --> ";
					getline(cin, sec_key);
					if (sec_key.length() == 0)
						sec_key = ' ';

					convert(sec_msg, own_msg);
					convert(keymaker(sec_msg, sec_key), own_key);

					cout << "\n  Your decrypted message is: \n  --> " << de_crypt(sec_msg, own_msg, own_key) << endl << endl;
					clear_decrypt(own_msg, own_key);
				}
			}

			else
			{
				cout << "              ___________________________________________  \n";
				cout << "             |      Enter message to be decrypted:       | \n";
				cout << "             |___________________________________________| \n\n --> ";
				getline(cin, sec_msg);

				cout << "              ___________________________________________  \n";
				cout << "             |      Enter key word for decryption:       | \n";
				cout << "             |___________________________________________| \n\n --> ";
				getline(cin, sec_key);
				if (sec_key.length() == 0)
					sec_key = ' ';

				convert(sec_msg, own_msg);
				convert(keymaker(sec_msg, sec_key), own_key);

				cout << "\n  Your decrypted message is: \n  --> " << de_crypt(sec_msg, own_msg, own_key) << endl << endl;
				clear_decrypt(own_msg, own_key);
			}
		}

		else
		{
			cout << "              ___________________________________________  \n";
			cout << "             |  ******** THANK YOU FOR USING **********  | \n";
			cout << "             |___________________________________________| \n\n";
			cout << "  .____.                .__.       ____/\\__  .____..__.                   \n";
			cout << "  |    |    ____   ___  |  | __.  /   / /_/  |    |/ _|____ __.__.         \n";
			cout << "  |    |   /  _ \\_/ __\\ |  |/ /   \\__/ /_ \\  |      <_/ __ (  |  |     \n";
			cout << "  |    |__(  (_) )  \\___|    (    / / /__) ) |    |  \\  __/\\___  |      \n";
			cout << "  |_______ \\____/ \\___  }__|_ \\  /_/ /__  /  |____|__ \\__  > ____|     \n";
			cout << "          \\/          \\/     \\/    \\/   \\/           \\/  \\/\\/    \n\n";
			cout << "                            A G.C.K. Program                           \n\n\n";
		}

	} while (choice[0] != '3'); //sentinel to end do-while loop

	clear(encrypt, user_msg, user_key, makekey, newmsg, newkey, newencrypt);

	system("pause");
	return 0;
}

vector<int> convert(string str, vector<int> &vec)
{
	for (int i = 0; i < str.length(); i++)
		for (int t = 0; t < TABLE.length(); t++)
			if (str[i] == TABLE[t])
				vec.push_back(t);
	return vec;
}

string en_crypt(string user_msg, vector<int> newmsg, vector<int> newkey)
{
	int tmp;
	string tmp_encrypt;
	for (int i = 0; i < user_msg.length(); i++)
	{
		tmp = (newmsg[i] + newkey[i] + (user_msg.length() % TABLE.length() + (i % TABLE.length()))) % TABLE.length();
		tmp_encrypt.push_back(TABLE[tmp]);
	}
	return tmp_encrypt;
}

string de_crypt(string encrypt, vector<int> newencrypt, vector<int> newkey)
{
	int tmp;
	string tmp_decrypt;
	for (int i = 0; i < encrypt.length(); i++)
	{
		tmp = (newencrypt[i] - newkey[i] + ((TABLE.length() * TABLE.length()) - (encrypt.length() % TABLE.length() + (i % TABLE.length())))) % TABLE.length();
		tmp_decrypt.push_back(TABLE[tmp]);
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

void clear(string &encrypt, string &user_msg, string &user_key, string &makekey, vector<int> &newmsg, vector<int> &newkey, vector<int> &newencrypt)
{
	encrypt.clear();
	user_msg.clear();
	user_key.clear();
	makekey.clear();
	newmsg.clear();
	newmsg.shrink_to_fit();
	newkey.clear();
	newkey.shrink_to_fit();
	newencrypt.clear();
	newencrypt.shrink_to_fit();
}

void clear_decrypt(vector<int> &own_msg, vector<int> &own_key)
{
	own_msg.clear();
	own_msg.shrink_to_fit();
	own_key.clear();
	own_key.shrink_to_fit();
}