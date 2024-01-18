#include "monty.h"
#include <ctype.h>

/**
 * is_numeric - Checks if a string represents a numeric value.
 * @str: The string to be checked.
 * Return: 1 if the string is numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
	if (!str || *str == '\0' || (*str == '-' && *(str + 1) == '\0'))
		return (0);

	while (*str)
	{
		if (!isdigit(*str) && *str != '-')
			return (0);
		str++;
	}

	return (1);
}
