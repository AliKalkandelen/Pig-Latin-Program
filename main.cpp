#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <dos.h>

using namespace std;

bool isvowel(char);


int main()
{

int x,y;
string choice;
string str;
   cout << "Hello!. Welcome to the Pig Latin Program!\n\n";
   Sleep(2000);


   do{

    cout <<"If you want to translate TO Pig Latin, please type topig" <<endl <<"If you want to translate FROM Pig Latin, please type frompig\n\n";
   getline(cin,choice);
   if(choice == "topig"){

    cout << "What's your topig string?\n";
    getline(cin,str);
    break;


   }else if(choice == "frompig"){

   cout << "What's your frompig string?\n";
    getline(cin,str);
    break;


   }else{
    cout << "Invalid Response: Please either type topig or frompig.\n\n";
    Sleep(2000);
   }
}while (choice != "topig" || choice != "frompig");




}
