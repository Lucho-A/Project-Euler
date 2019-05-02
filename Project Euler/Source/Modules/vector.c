/*
 * vector.c
 *
 *  Created on: 24/04/2018
 *      Author: lucho
 */

#include "libEuler.h"

struct Node{
		llu value;
        struct Node *prev;
        struct Node *next;
};

struct Vector{
        struct Node *aux;
        struct Node *root;
        struct Node *last;
        int size;
};

void vGoTo(Vector *v, int pos){
	vFirst(v);
	for(int i=0;v->aux!=NULL;i++){
		if(i==pos) return;
		vNext(v);
	}
}

Node * vNext(Vector *v){
	if(v->aux!=NULL) v->aux=v->aux->next;
	return v->aux;
}

void vFirst(Vector *v){
	v->aux=v->root;
}

llu vGetValue(Vector *v){
	if(v->aux==NULL) return -1;
	return v->aux->value;
}

Vector * vGetAux(Vector *v){
	return v->aux;
}

void vSetAux(Vector *v, Vector * value){
	v->aux=value;
	return;
}

llu vGetSize(Vector *v){
	if(v->aux==NULL) return -1;
	return v->size;
}

void vInit(Vector **v){
        *v=malloc(sizeof(Vector));
        (*v)->root=NULL;
        (*v)->aux=(*v)->root;
        (*v)->last=NULL;
        (*v)->size=0;
}

void vDelete(Vector *v, int pos){
        if(pos < -2 || pos > v->size || v->root==NULL) return;
        // Current pos
        if(pos==-2){
        	if(v->aux==v->root) pos=0;
        	if(v->aux==v->last) pos=-1;
        }
        // Last
        if(pos==-1 || pos== v->size){
                v->last->next=NULL;
                v->last=v->last->prev;
                v->size--;
                if(v->size == 0) v->root=NULL;
                return;
        }
        // First
        if(pos==0){
            v->root=v->root->next;
            v->aux=v->root;
            v->root->prev=NULL;
            v->size--;
            if(v->size == 0) v->root=NULL;
            return;
        }
        // Current
        if(pos!=-2)vGoTo(v,pos);
        v->aux->prev->next=v->aux->next;
        v->aux->next->prev=v->aux->prev;
        v->size--;
        if(v->size == 0) v->root=NULL;
        return;
}

void vUpdate(Vector *v, int value, int pos){
		if(pos==-1){
			v->aux->value=value;
			return;
		}
        if(pos < -1 || pos > v->size) return;
        vFirst(v);
        for(int i = 0;i != pos;i++) vNext(v);
        v->aux->value=value;
        return;
}

void vAdd(Vector *v, int value, int pos){
        if(pos < -1 || pos > v->size) return;
        if(v->root==NULL && pos<=0){
                Node *aux=malloc(sizeof(Node));
                aux->value=value;
                aux->prev=NULL;
                aux->next=v->root;
                if(v->size==0) v->last=aux;
                v->root=aux;
                v->size++;
                v->aux=v->root;
                return;
        }
        if(pos==-1 || pos== v->size + 1){
                Node *aux=malloc(sizeof(Node));
                aux->value=value;
                aux->prev=v->last;
                aux->next=NULL;
                v->last->next=aux;
                v->last=aux;
                v->size++;
                v->aux=v->root;
                return;
        }else{
                v->aux=v->root;
                for(int i = 0;i != pos;i++) v->aux=v->aux->next;
                Node *aux=malloc(sizeof(Node));
                aux->value=value;
                aux->prev=v->aux->prev;
                aux->next=v->aux;
                if(pos!=0) v->aux->prev->next=aux;
                v->aux->prev=aux;
                if(pos==0) v->root=aux;
                v->size++;
                v->aux=v->root;
                return;
        }
 }

void vShow(Vector *v){
	vFirst(v);
	if(v->aux!=NULL){
		while(v->aux!=NULL){
			printf("Element: %llu\n", vGetValue(v));
			vNext(v);
		}
	}
	return;
}

