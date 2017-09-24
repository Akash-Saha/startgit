#include <stdio.h>
#include <stdlib.h>

/* This program contains the solutions to Kernighan and Ritchie Chapter 1*/

/*Write a program to count the number of tabs, newlines and backspaces in an input*/
void one_8()
{
    int c,tab,bs,nl;
    tab=nl=bs=0;
    while((c=getchar())!=EOF)
    {
        if(c=='\t')
            ++tab;
        else if(c=='\b')
            ++bs;
        else if(c=='\n')
            ++nl;

    }

    printf("Tabs=%d,\n Backspaces=%d, \n New lines=%d",tab,bs,nl);

}


/*Write a program to replace all multiple spaces in input with single spaces in output.*/
void one_9()
{//This code has become humongous !!! Not good at all !! Lemme see if I can improve it!!

    #define EVEN 0
    #define ODD 1
    int c,space,c1;
    c1='a';space=1;
    while((c=getchar())!=EOF)
        {
            if(c==' ')
            {
               space=ODD;
               c1=getchar();
               if(c1==' ')
                space=EVEN;
               else
                {
                    putchar(' ');
                    putchar(c1);
                }
            }
            else
            {
              if(space==EVEN)
              {
                  putchar(' ');
                  putchar(c);
                  space=ODD;
              }
              else
              putchar(c);

            }


        }

}
/*Write a program to replace all multiple spaces with single spaces in input.*/
void one_9_2nd()
{//A clearer logic I guess !!
    int c;
    #define IN 1//If inside a word
    #define OUT 0//If outside a word
    int state;
    state=OUT;
    int counter=0;
    while((c=getchar())!=EOF)
    {
        if(c==' '|| c=='\n' || c=='\t')
        {
            state=OUT;
            counter++;
        }
        else if(state==OUT)
        {
            state=IN;
           if(counter>0)
           {
               putchar(' ');
               counter=0;
           }

        }
        if(state==IN)
            putchar(c);


    }

    }








/*Write a program to replace all tabs, backspaces and \ in input with their escape sequences*/
void one_10()
{
    int c;
    while((c=getchar())!=EOF)
    {
        if(c=='\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if(c=='\b')
        {
            putchar('\\');
            putchar('b');
        }
        else if(c=='\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);


    }


}

/*Write a program to print words of an input in separate lines*/
void one_12()
{
    int c;
    #define IN 1//If inside a word
    #define OUT 0//If outside a word
    int state;
    state=OUT;
    int counter=0;
    while((c=getchar())!=EOF)
    {
        if(c==' '|| c=='\n' || c=='\t')
        {
            state=OUT;
            counter++;
        }
        else if(state==OUT)
        {
            state=IN;
           if(counter>0)
           {
               putchar('\n');
               counter=0;
           }

        }
        if(state==IN)
            putchar(c);


    }

    }

/*Write a program to draw a histogram of the lenghts of words in input*/

void one_13()
{

  int c;
    #define IN 1//If inside a word
    #define OUT 0//If outside a word
    int state;
    state=OUT;
    int counter=0;
    int wordnum=0;
    int arr[217];//Maximum possible lenght of a word
    int i=0;

    for(i=0;i<217;i++)
        arr[i]=0;

    while((c=getchar())!=EOF)
    {
        if(c==' '|| c=='\n' || c=='\t')
        {
            state=OUT;
            ++arr[counter-1];
            counter=0;
        }
        else if(state==OUT)
        {
            state=IN;

        }
        if(state==IN)
        {
            counter++;
        }
    }

     printf("Length  Frequency\n");

    for(i=0;i<217;i++)
    {
        if(arr[i]!=0)
        {

            printf("%3d \t %3d \n",(i+1),arr[i]);
        }

    }

}


void one_14()
{
    int c;
    int arr[128];
    int i;

    for(i=0;i<128;i++)
        arr[i]=0;

    while((c=getchar())!=EOF)
    {
        ++arr[c];
    }

    for(i=0;i<128;i++)
    {
        if(arr[i]!=0)
        {
            printf("%c\t%d\n",i,arr[i]);

        }
    }

}




int main()
{

   one_14();
   return 0;
}
