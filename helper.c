#include "monty.h"
#include <ctype.h>

/**
 * isNumber - Identify if a string is a number
 *
 * @s: String for checking
 * Return: ! if is a number 0 if is not.
 */

int isNumber(char *s)
{
	int i;

	for (i = 0; s[i] != '\n' && s[i]; i++)
	{
		if (isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}
