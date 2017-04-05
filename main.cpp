#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <ctype.h>

using namespace std;

char  randchar(void);
int side_length(int length);
void printArray();

/*******************************************************************************
*This program takes < * .txt as an argument and returns an enciphered
*message. It parses the message through a row major 2d square matrix array and
*then prints in a column major. The empty cells of the array are filled with
*randchar and produces an enciphered message.
*******************************************************************************/

int main(int  argc, char *argv[], char **env)
{
    int i = 0;
    string str  = "";
    int counter = 0;

    //loop through each char of string to be enciphered.
    while ( ! cin.eof() )
    {
        char s = cin.get();
        str += tolower(s);
    }

//check each character for isalpha and erase non-alpha
for (int i = 0 ; i < str.length() ; ++i)
{
    if (!isalpha(str[i]))
       {
             str.erase(i,1);
             --i;
       }
}

int length  = str.length();
char arrayCounter[(side_length(length))][(side_length(length))];

       //create char matrix and place row major with  input string
       for (int r  = 0; r  < side_length(length); r++)
       {
            for (int c  = 0; c < side_length(length); c++)
            {
              arrayCounter[r][c] = str[counter++];

                   if (arrayCounter[r][c] == 0)
                   {
                       char letChar = tolower(randchar());
                        arrayCounter[r][c] += letChar;// append empty array with randchar
                   }
            }

       }

       cout << endl;

       //print column major enciphered message
       for(int a = 0; a < side_length(length); ++a)
           for(int b = 0; b < side_length(length); ++b)
       cout << arrayCounter[b][a];
       cout << endl;

return 0;

}

int side_length(int length)
{

     // call side_length with the length of the message
     // it should return you an integer which is the
     // correct length of the square array of characters
     // to hold the message, plus any padding characters.
     // int n = sqrt (s.length()) + 1;
     int strlen = sqrt(length) + 1;
     return strlen;

}

//return a random lower-case alphabetic character when calle
char  randchar(void)
{
        int c = ' ';
        //while (c < 'a' || c > 'z')
        while (!isalpha(c))
        {
        c = rand() * 802701 ;
        c %= 26 ;
        c += 'a' ;
        c %= 'z' ;
        }
        return c ;
}



