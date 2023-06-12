#include "hash_tables.h"
/**
 *hash_table_get - function that retrieves a value associated with a key
 *
 *@ht: hash table you want to look into
 *@key: the key you are looking for
 *
 *Return: the value associated with the element else NULL
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *node;

	if (!ht || !key)
		return (NULL);
	idx = key_index((unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node)
	{
		if (!strcmp(key, node->key))
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

