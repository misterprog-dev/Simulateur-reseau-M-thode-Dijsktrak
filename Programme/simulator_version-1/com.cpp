#include "com.h"
#include <iostream>
#include <string.h>

using namespace std;

void invers(char *tab)
{
    int n=strlen(tab);
    int tmp;

    for(int i=0; i<n/2;i++)
    {
        if(i<n-1-i)
        {
            tmp=tab[i];
            tab[i]=tab[n-1-i];
            tab[n-1-i]=tmp;
        }
    }

    tab[n]='\0';
}

char* int_str(int toConvert)
{
    char *m=new char[10];

    int ent=toConvert, rest,compt=0;
    int tmp=toConvert;
    char ens[10]={'0','1','2','3','4','5','6','7','8','9'};
    //cout <<"entrer dans la boucle de int_str"<<endl;
    if (ent==0)
    {
        m[0]='0';
        m[1]='\0';
        return m;
    }
    while(ent!=0)
    {
        //cout <<"division modulo"<<endl;
        ent=tmp/10;
        rest = tmp%10;
        //cout <<"affectation des valeur"<<endl;
        m[compt]=ens[rest];
        compt++;
        //cout <<"ent = " <<ent<<" rest= "<<rest<<endl;
        tmp=ent;
    }
    //cout <<"inversion de tab"<<endl;
    m[compt]='\0';
    invers(m);

    //printf("%s\n", m);
    return m;

}
