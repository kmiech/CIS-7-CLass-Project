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

  do
  {
   cout << "Please select from the following options.\n";
    cout << "1) Encrypt a message.\n";
    cout << "2) Decrypt a message.\n";
    cout << "3) Exit the program.\n";
    cout << "Enter choice: ";
    cin >> choice;
    while ((choice < 1) || (choice > 3))
    {
      cout << "\nThat is not a valid option. Please choose again.\n";
      cout << "Enter choice: ";
      cin >> choice;
    }

    if (choice == 1)
    {
     cin.ignore();
     cout << "\nEnter message to be encrypted: ";
     getline(cin, user_msg);
     char_check(user_msg);
     upper_char(user_msg);
       
     cout << "Enter a key word for decryption: ";
     getline(cin, user_key);
     char_check(user_key);
     upper_char(user_key);
   
     new_key = keymaker(user_msg, user_key);
     encrypt_msg = encrypt(user_msg, new_key);
     
     cout << "\nYour key for this message is : " << new_key << endl;
     cout << "Your encrypted message is: " << encrypt(user_msg, keymaker(user_msg, user_key)) << endl << endl;
    }

    else if (choice == 2)
    {
      cout << "\nThe key for this message is: " << new_key << endl;
      cout << "The decrypted msg is: " << decrypt(encrypt_msg, new_key) << endl << endl;
    }

    else
    {
      cout << "Thank you for using this program.\n";
    }

  }while(choice != 3); //sentinel to end do-while loop

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
    int tmp = (msg[i] - key[i] + 26) % 26 ;

    tmp += 'A';
    if(msg[i] == ' ')
      tmp = ' ';
    tmp_decrypt.push_back(tmp);
  }
  return tmp_decrypt;
}

string keymaker(string msg, string key)
{
	int tmp = msg.length();

	for (int i = 0; i < msg.length() ; i++)
	{
		if (tmp == i)
			i = 0;
		if (key.length() == msg.length())
    {
			break;
    }
    if(key.length() < msg.length())
    {
      key.push_back(key[i]);
    }
     if (key.length() > msg.length())
      key.pop_back();
	}
	return key;
}


void char_check (string &line)
{  
  int i = 0;
  while (i < line.length())
   { for (int i = 0; i < line.length(); i++)  
      { 
        if ( ! ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') || (line[i] == ' ')))
        {    
          i = 0;
          cout << "Characters only please. Enter message: ";
           getline(cin, line);
         }  
      }
      i++;
   }
    cout << endl;
}

void upper_char (string &line)
{
  for (int i = 0; i < line.length(); i++)
   line[i] = toupper(line[i]);
}
