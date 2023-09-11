#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * new_dog - creates new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: a dog object
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int i, a1, a2;
	dog_t *ne-dog;
	char *b, *c;

	a1 = 0;
	for (i = 0; name[i] != '\0'; i++)
		a1++;
	a2 = 0;
	for (i = 0; owner[i] != '\0'; i++)
		a2++;
	ne-dog = malloc(sizeof(dog_t));
	if (ne-dog == NULL)
		return (NULL);
	b = malloc((a1 + 1) * sizeof(char));
	if (b == NULL)
	{
		free(ne-dog);
		return (NULL);
	}
	for (i = 0; i < a1; i++)
		b[i] = name[i];
	b[i] = '\0';
	ne-dog->name = b;
	ne-dog->age = age;
	c = malloc((a2 + 1) * sizeof(char));
	if (c == NULL)
	{
		free(b);
		free(ne-dog);
		return (NULL);
	}
	for (i = 0; i < a2; i++)
		c[i] = owner[i];
	c[i] = '\0';
	ne-dog->owner = c;
	return (ne-dog);
}
