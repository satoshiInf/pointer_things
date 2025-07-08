

#include <iostream>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int get_word(char *buffer , int buffer_size , FILE *fp)
{
    
    int len; //len = the length of file
    int ch;  // ch = each charactor in loop
    
    // ch is substituted by fp-charactor,and then if ch is not equal to EOF(-1)
    //and ch is not any charactors or numbers
    
    // this is to deal with blank charactor to skip.
    while((ch = getc(fp)) != EOF && !isalnum(ch) )
    {
        // do nothing
    }
    
    // if ch is the end of file, then return -1
    if (ch == EOF)
    {
        return EOF;
    }
    
    len = 0;
    
    do
    {
        // len is the number of characters stored in 'buffer'
        // We must ensure that 'len' does not exceed 'buffer_size'
        // to prevent buffer overflow.

        buffer[len] = ch;
        len++;
        if( len >= buffer_size)
        {
            // error message
            fprintf(stderr,"Word too long.\n");
            exit(-1);
        }
        
    }
    while((ch = getc(fp)) != EOF && isalnum(ch));
    
    buffer[len] = '\0';
    
    
    // for loop to check
    // /0 is not cout
    // with (int) /0 is cout as ACII
    for(int i =0; i != len +1; i++)
    {
        cout << buffer[i] << endl;
    }
    
    for(int i =0; i != len +1; i++)
    {
        cout << (int)buffer[i] << endl;
    }
    
    return len;

}


// input stdin and check whether blank or not.
//if stdin is blank, while-loop have to be done until charactor is input there.
int main()
{
    char buffer[256];
    
    while(get_word(buffer, 256,stdin) != EOF)
    {
        cout << buffer <<  endl;
        printf("you input <<%s>>\n", buffer);
    }

    return 0;
}
