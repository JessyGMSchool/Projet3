/*
# Programme rpi-gpio.c fait par Jessy Grimard-Maheu
#     __                    _____     _                 _     _____     _           
#  __|  |___ ___ ___ _ _   |   __|___|_|_____ ___ ___ _| |___|     |___| |_ ___ _ _ 
# |  |  | -_|_ -|_ -| | |  |  |  |  _| |     | .'|  _| . |___| | | | .'|   | -_| | |
# |_____|___|___|___|_  |  |_____|_| |_|_|_|_|__,|_| |___|   |_|_|_|__,|_|_|___|___|
#  
*/


#include <stdio.h>	// Pour printf()
#include <stdlib.h>	// ._.
#include <string.h>	// Pour strcmp
#include <wiringPi.h> 	// WiringPi librairie

#define NORMAL  "\x1B[0m"
#define ROUGE "\x1B[31m"
#define VERT "\x1B[32m"
#define BLEU "\x1B[36m"

int main(int argc, char*argv[])
{
    int ledPin = atoi(argv[1]);
    int i = 0;
    
    wiringPiSetupGpio();
    pinMode(ledPin, OUTPUT);

    printf(BLEU "Programme pour changer les etats des gpio :D\n");
    printf(NORMAL);

	if(ledPin >= 2 && ledPin <= 27)
	{
		printf("Pin : %d\n",ledPin);
		printf("Etat : ");
		
       	if((strcmp(argv[2],"ON")) == 0)
		{
			printf(VERT "ON\n");
			digitalWrite(ledPin, HIGH); // DEL ON
		}
		else if((strcmp(argv[2],"OFF")) == 0)
		{
			printf(ROUGE "OFF\n");
			digitalWrite(ledPin, LOW); // DEL OFF
		}
		else
		{
		printf(ROUGE "ERREUR\n");
		printf(ROUGE "Entrer 'ON' ou 'OFF'\n");
		}
		return 0;
	}
	else
	{
		printf(ROUGE "Entrer une sortie gpio entre 2 et 27\n");
	}
    return 0;
}

