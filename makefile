wpi:
	gcc -o main main.c gpio-wpi.c -l wiringPi
libc:
	gcc -o main main.c gpio-libc.c
