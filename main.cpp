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

int main(int  argc, char *argv[], char **env)
{
    int i = 0;
   // int length = 0;
    string str  = "";

    int counter = 0;




    while ( ! cin.eof() )
    {
        char s = cin.get();
       str += tolower(s);



    }

//    cout << str << endl;

for (int i = 0 ; i < str.length() ; ++i)
{
        if (!isalpha(str[i]))
        {
                str.erase(i,1);
                --i;
        }
}

//cout << str << endl;

int length  = str.length();
char arrayCounter[(side_length(length))][(side_length(length))];

//cout << length << endl;
//cout <<  side_length(length) << endl;

       for (int r  = 0; r  < side_length(length); r++)
       {
            for (int c  = 0; c < side_length(length); c++)
            {

              arrayCounter[r][c] = str[counter++];

                   if (arrayCounter[r][c] == 0)
                   {
                       char letChar = tolower(randchar());
                        arrayCounter[r][c] += letChar;
                   }

               cout << arrayCounter[r][c];

            }
                cout << endl;
       }

       cout << endl;

       for(int a = 0; a < side_length(length); ++a)
        for(int b = 0; b < side_length(length); ++b)
       cout << arrayCounter[b][a];


//cout << i << endl;


return 0;

}



int side_length(int length)
{
     int strlen = sqrt(length) + 1;
     // call side_length with the length of the message
     // it should return you an integer which is the
     // correct length of the square array of characters
     // to hold the message, plus any padding characters.
     // int n = sqrt (s.length()) + 1;
     return strlen;

}

char  randchar(void)
{
         //return a random lower-case alphabetic character when called
        // note: (((rand() * some multiplier) % 26 )+ 'a') will produce such a character

        int c = ' ' ;
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
