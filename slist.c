
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

#include "slist.h"

Slist new_list(){
	Slist* s =  (Slist *) malloc(sizeof(Slist));
	s->head = NULL;
	s->tail = NULL;
	s->length = 0;
	return *s;
}
uint32_t length(Slist *list){
	return list->length;
}

int32_t lookup(Slist* list,int32_t data){
	assert(list != NULL);
	int32_t count = -1;
	if(list->head != NULL){
		count = 0;
		Node* tmp = list->head;
		while(tmp!=NULL){
			if(tmp->data == data)
				break;
			count++;
			tmp = tmp->next;
		}
		if(count == list->length){
			count = -1;
		}
	}
	return count;
}

Slist* add_head(Slist *list,int32_t data){
	 assert(list!=NULL);
	// Create Node
	Node * node = (Node *) malloc(sizeof(Node));
	/*
	 // Donot initialize using {} has pointer issues need to check in Stackoverflow
	 // Node snode = {};
	 // Node *node  = &snode;
	*/
	node->data = data;
	node->next = list->head;
	list->head = node;
	if(list->tail == NULL)
		list->tail = node;
	list->length++;
	return list;
}

Slist* add_tail(Slist *list,int32_t data){
	assert(list!=NULL);
	//Create node
	Node* node = (Node *) malloc(sizeof(Node));
	node->data = data;
	list->tail->next = node; //Point last node to the new node
	if(list->head==NULL)
		list->head = node;
	list->tail = node;
	list->length++;
	return list;
}


