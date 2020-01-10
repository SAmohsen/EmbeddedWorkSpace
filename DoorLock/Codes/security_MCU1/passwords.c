/*
 * passwords.c
 *
 *  Created on: Jan 10, 2020
 *      Author: sayed
 */
#include "passwords.h"

char globalPassword[MAX_PASSWORD_LENGTH] = { '1', '2', '3', '4', '\0' };

static uint8 getstringlength(char *str) {
	uint8 counter = 0;
	while (str[counter] != 0) {
		counter++;
	}
	return counter;
}

void saveNewPassword(char *newpass)
{
	uint8 itr = 0;
	while (newpass[itr] != '\0')
	{
		globalPassword[itr] = newpass[itr];
		itr++;
	}
	globalPassword[itr] = '\0';
}

char* takePassword() {
	static char pass[MAX_PASSWORD_LENGTH];
	char key;
	uint8 i = 0;
	uint8 endpasswordfalg = 0;
	while ((i < MAX_PASSWORD_LENGTH) && (!endpasswordfalg))
	{
		key = Keypad_getPressedKey();
		if (key == ' ')
		{
			pass[i] = '\0';
			endpasswordfalg = 1;
		}
		else
		{
			pass[i] = key;
			LCD_SendU8Data('*');
		}
		i++;
	}
	return pass;
}

void waitWrongPassword() {
	Timer1_InitoneSecond();
	while (tick <= 9)
	{
		PORTB = (PORTB & 0x0F) | ((9 - tick) << 4);
	}
	timer1_stop();
	PORTB &= 0x0F;
	tick = 0;

}
uint8 checkpasswords(char *pass1, char *pass2) {
	uint8 itr = 0;
	uint8 passwordsStatus = MATCHED_PASSWORDS;
	uint8 pass1Length = getstringlength(pass1);
	uint8 pass2Length = getstringlength(pass2);
	if (pass2Length != pass1Length)
	{
		passwordsStatus = WRONG_PASSWORDS;
	}
	else
	{
		while (pass1[itr] != '\0')
		{
			if (pass1[itr] != pass2[itr])
			{
				passwordsStatus = WRONG_PASSWORDS;
				break;
			}
			itr++;
		}
	}
	return passwordsStatus;
}
void setnewPassword()
{
	char *pass1 = takePassword();
	LCD_Clear();
	LCD_goToXY(1, 1);
	LCD_SendString("Renter new Pass");
	LCD_goToXY(3, 1);
	char *pass2 = takePassword();
	uint8 status = checkpasswords(pass1, pass2);
	if (status == MATCHED_PASSWORDS)
	{
		saveNewPassword(pass2);
		DoorStatus = DOOR_IS_LOCKED;

	}
	else if (status == WRONG_PASSWORDS)
	{
		LCD_Clear();
		LCD_SendString("Wrong Password !");
		waitWrongPassword();
	}
	else
	{

	}
	LCD_Clear();
}
