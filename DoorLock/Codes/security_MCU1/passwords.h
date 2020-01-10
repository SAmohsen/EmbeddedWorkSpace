/*
 * passwords.h
 *
 *  Created on: Jan 10, 2020
 *      Author: sayed
 */

#ifndef PASSWORDS_H_
#define PASSWORDS_H_

#include "door.h"
#include "GPT.h"
#include "LCD.h"



#define MAX_PASSWORD_LENGTH 8
#define MATCHED_PASSWORDS 1
#define WRONG_PASSWORDS 0
extern char globalPassword[MAX_PASSWORD_LENGTH];
void saveNewPassword(char *newpass) ;
char* takePassword() ;
void waitWrongPassword() ;
uint8 checkpasswords(char *pass1, char *pass2) ;
void setnewPassword() ;


#endif /* PASSWORDS_H_ */
