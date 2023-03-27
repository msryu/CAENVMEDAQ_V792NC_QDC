/******************************************************************************
* 
* CAEN SpA - Front End Division
* Via Vetraia, 11 - 55049 - Viareggio ITALY
* +390594388398 - www.caen.it
*
***************************************************************************//**
* \note TERMS OF USE:
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License as published by the Free Software
* Foundation. This program is distributed in the hope that it will be useful, 
* but WITHOUT ANY WARRANTY; without even the implied warranty of 
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. The user relies on the 
* software, documentation and results solely at his own risk.
******************************************************************************/

#ifndef _CONSOLE_H
#define _CONSOLE_H

#ifdef linux
    #include <sys/time.h> /* struct timeval, select() */
    #include <termios.h> /* tcgetattr(), tcsetattr() */
    #include <stdlib.h> /* atexit(), exit() */
    #include <unistd.h> /* read() */
    #include <stdio.h> /* printf() */
    #include <string.h> /* memcpy() */
    #include <ctype.h>    /* toupper() */

/*****************************************************************************/
/*  GETCH  */
/*****************************************************************************/
int getch(void);

/*****************************************************************************/
/*  KBHIT  */
/*****************************************************************************/
int kbhit();


#else  // Windows

    #include <time.h>
    #include <sys/timeb.h>
    #include <conio.h>
    #include <process.h>

	#define getch _getch
	#define kbhit _kbhit
	
#endif

//****************************************************************************
// Function prototypes
//****************************************************************************
void ClearScreen();
long get_time();

#endif