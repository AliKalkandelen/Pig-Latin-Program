#include <string>
#include <iostream>
#include <string.h>
#include <vector>
#include <cctype>
#include <locale>

using namespace std;


string input;
string word;
string topiglatin(string); /**< translates to pig latin */
string frompiglatin(string); /**< translates from pig latin */
string makeProper(string); /**< Capitalizes only first letter */
bool isVowel(char); /**<checks if const char is vowel*/
bool isallconstt(const std::string &str); /**<checks if word is all constants*/



int main(int argc, char *argv[])
{
    enum {TOPIG, FROMPIG} mode;

    if( argc == 1 )
    {
        mode = TOPIG;
    }else if(argc != 2)
    {
        cout<<"Error Message(Wrong argument)"<<endl;
        return 1;
    }
    else
    {
        string userArg(argv[1]);

        if(userArg == "topig")
        {
            mode = TOPIG;
        }
        else if(userArg == "frompig")
        {
            mode = FROMPIG;
        }
        else
        {
            cout<<"Error Message(Argument needs topig or frompig)"<<endl;
            return 1;
        }
    }

        cout<<"Input String"<<endl;
        getline(cin, input);
        input = input + " ";

    if (mode == TOPIG)

    {

       for(int i = 0; (unsigned)i<input.length(); i++)
       {
           if(isalpha(input[i]))
           {
            word.push_back(input[i]);
           }
           else
           {
                 if(!word.empty())
                {
                    string z = topiglatin(word);
                    cout<<z;
                    word.clear();
                    cout<<input[i];
                }
                else
                {
                    cout<<input[i];
                }
           }
       }


    }
    else if(mode == FROMPIG)
    {
       for(int i = 0; (unsigned)i<input.length(); i++)
       {
           if(isalpha(input[i]))
           {
            word.push_back(input[i]);
           }
           else
           {
                 if(!word.empty())
                {
                    string z = frompiglatin(word);
                    cout<<z;
                    word.clear();
                    cout<<input[i];
                }
                else
                {
                    cout<<input[i];
                }
           }
       }
    }
    else
    {
        cout<<"Error Message(Argument Matching Failed)"<<endl;
        return 1;
    }

}



bool isVowel(char ch)
{
	    switch(ch){
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;

	    }
}

bool isallconstt(const std::string &str)
{
    return str.find_first_not_of("bcdfghjklmnpqrstvwxyz") == std::string::npos;
}

bool hasEnding (std::string const &fullString, std::string const &ending)
{
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

string makeProper(string word)
{
    int i = 0;
    while(word[i])
    {
       word[i] = tolower(word[i]);
       i++;
    }

word[0] = toupper(word[0]);
return word;
}

string topiglatin(string word)
{
  if(isVowel(word[0]))
  {
      word = word + "way";

  }
  else if(!isVowel(word[0]))
  {

    do
    {
        if(isallconstt(word))
        {
            word = word + "way";
            return word;
        }
        else
        {

         word = word.substr(1,word.length()) + word[0];
        }

    }while(!isVowel(word[0]));

    word = word + "ay";
  }
  else
    cout<<"Error Message: isVowel error in("<<word<<")";

word = makeProper(word);
return word;
}

string frompiglatin(string word)
{
word = makeProper(word);
string ending = "way";
int h = hasEnding(word,ending);
int g = hasEnding(word,ending.substr(1,2));

  if(h == 1)
  {
    word = word.substr(0,word.length()-3);
  }
  else if(g == 1)
  {

        if(isallconstt(word.substr(0,word.length()-2)))
        {
            word = word.substr(0,word.length()-2);
            return word;
        }
        else
        {
            word = word.substr(0,word.length()-2);
            word = word[word.length()-1] + word.substr(0,word.length()-1);
        }

  }
  else
  {

      return word;
  }



word = makeProper(word);
return word;
}
