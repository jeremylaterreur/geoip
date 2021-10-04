#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAXCHAR 1000
#define CONVERT 256

int main(int argc, char *argv[]){

    FILE *fp;
    char Ligne[MAXCHAR];
    char *Sortie;

    fp = fopen("geoip.csv","r");


    while (feof(fp) != true)
    {
        fgets(Ligne, MAXCHAR, fp);
        //printf("Ligne: %s", Ligne);

        Sortie = strtok(Ligne, ",");

	int i=0;
	char debutintervalle[99];
	char finintervalle[99];
	char pays[99];
	memset(pays,0,99);
	memset(debutintervalle,0,99);
	memset(finintervalle,0,99);
	int debutip=0;
	int finip=0;
	char lepays[99];

		const char * separators = ".";
		long int ip0=0;
		long int ip1=0;
		long int ip2=0;
		long int ip3=0;
		long int ip=0;
			
		sscanf(argv[1],"%ld.%ld.%ld.%ld",&ip0,&ip1,&ip2,&ip3);			
		ip0=ip0*CONVERT*CONVERT*CONVERT;				
		ip1=ip1*CONVERT*CONVERT;
		ip2=ip2*CONVERT;
		ip=ip0+ip1+ip2+ip3;
		//printf("%ld\n",ip);

        while(Sortie != NULL)
        { int a=1;
			if (i==0) 
			 { while (Sortie[a] != '"')
			  {
				 debutintervalle[a-1]=Sortie[a];
				 a++;
			  }
			 debutip = atoi(debutintervalle);
			 }
			 
			 if (i==1) 
			 {
				 while (Sortie[a] != '"')
			  {
				 finintervalle[a-1]=Sortie[a];
				 a++;
			  }
			 finip = atoi(finintervalle);
			 }
			 if (i==2)
			 while (Sortie[a] != '"')
			 {
				 pays[a-1]=Sortie[a];
				 a++;
			 }
			strcpy(lepays,pays);
            //printf("Sortie: %s\n", Sortie);
            Sortie = strtok(NULL, ",");
			i++;
        } 
		if (debutip <= ip && ip <= finip)
		{
		printf (" L'ip saisie est %ld \n",ip);
		printf (" L'ip du pays %s. \n",lepays);
		i=0;
		}
    }

    return 0;

}