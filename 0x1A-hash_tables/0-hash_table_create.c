#include "hash_tables.h"

/**
 * hash_table_create - This is a function that will create a hash table
 * @size: size for the table/array to be.
 *
 * Return: a pointer to the table but if an error occurs - NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_tab;
	unsigned long int i = 0;

	if (size <= 0)
		return (NULL);

	hash_tab = malloc(sizeof(hash_table_t));
	if (!hash_tab)
		return (NULL);

	hash_tab->size = size;
	hash_tab->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_tab->array == NULL)
	{
		free(hash_tab);
		return (NULL);
	}

	while (i < size)
		hash_tab->array[i++] = NULL;
	return (hash_tab);
}


