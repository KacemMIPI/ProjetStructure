#include "hachage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


HashCell* create_hashcell(Key* key){
	HashCell* h = malloc(sizeof(HashCell));
	h->key = key;
	h->val = 0;
	
	return h;
}

void delete_hashcell(HashCell* c){
	free(c);

}

int hash_function(Key* key, int size){
	return ((key->n)*(key->val))%size;
}

int find_position(HashTable* t, Key* key){
	hash_function(key, t->size);
	for(int i=0; i<t->size; i++){
		if(t->tab[i]->key->n == key->n && t->tab[i]->key->val == key->val){
			return i;
		}
	}
	
	return hash_function(key, t->size);
}
		

HashTable* create_hashtable(CellKey* keys, int size){
	HashTable * h = malloc(sizeof(HashTable));
	assert(h);
	h->tab = malloc(sizeof(HashCell*)*size);
	h->size = size;
	
	for(int i=0; i<size; i++){
		h->tab[find_position(h, keys->data)] = create_hashcell(keys->data);
		keys = keys->next;
	}
	
	return h;
}

}
	
void delete_hashtable(HashTable* t){
	for(int i=0 ; i < t->size; i++){
		free(t->tab[i]->key);
		free(t->tab[i]);
	}
	free(t->tab);
	free(t);
}
