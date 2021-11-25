/*
# Programme rpi-gpio.c fait par Jessy Grimard-Maheu
#     __                    _____     _                 _     _____     _           
#  __|  |___ ___ ___ _ _   |   __|___|_|_____ ___ ___ _| |___|     |___| |_ ___ _ _ 
# |  |  | -_|_ -|_ -| | |  |  |  |  _| |     | .'|  _| . |___| | | | .'|   | -_| | |
# |_____|___|___|___|_  |  |_____|_| |_|_|_|_|__,|_| |___|   |_|_|_|__,|_|_|___|___|
#  
*/

#include "gpio.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define NORMAL  "\x1B[0m"
#define ROUGE "\x1B[31m"
#define VERT "\x1B[32m"
#define BLEU "\x1B[36m"

int gpio(int argc, char*argv[])
{
    int ledPin = atoi(argv[1]);
    int fd = open("/sys/class/gpio/export", O_WRONLY);
    char temp[50];  
    
    printf(BLEU "Programme pour changer les etats des gpio :D\n");
    printf(NORMAL);

	if(ledPin >= 0 && ledPin <= 27)
	{
		printf("Pin : %d\n",ledPin);
		printf("Etat : ");
		
       	if((strcmp(argv[2],"ON")) == 0)
		{
			printf(VERT "ON\n");
			write(fd, argv[1], 2);
			close(fd);
			
			sprintf(temp, "/sys/class/gpio/gpio%d/direction", ledPin);
			fd = open(temp, O_WRONLY);
			write(fd, "out", 3);
			close(fd);
			
			sprintf(temp, "/sys/class/gpio/gpio%d/value", ledPin);
			fd = open(temp, O_WRONLY);
			write(fd, "1", 1);
			close(fd);
			
			
			fd = open("/sys/class/gpio/unexport", O_WRONLY);
			write(fd, argv[1], 2);
			close(fd);

    			return 0;
		}
		else if((strcmp(argv[2],"OFF")) == 0)
		{
			printf(ROUGE "OFF\n");
			write(fd, argv[1], 2);
			close(fd);
			
			sprintf(temp, "/sys/class/gpio/gpio%d/direction", ledPin);
			fd = open(temp, O_WRONLY);
			write(fd, "out", 3);
			close(fd);
			
			sprintf(temp, "/sys/class/gpio/gpio%d/value", ledPin);
			fd = open(temp, O_WRONLY);
			write(fd, "0", 1);
			close(fd);
			
			fd = open("/sys/class/gpio/unexport", O_WRONLY);
			write(fd, argv[1], 2);
			close(fd);

    			return 0;
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
	printf(NORMAL);
	return 0;
}
