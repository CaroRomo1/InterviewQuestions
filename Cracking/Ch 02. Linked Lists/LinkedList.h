//
//  LinkedList.h
//  LinkedList Tarea 3 (22Sept)
//
//  Created by Carolina Romo on 22/09/14.
//  Copyright (c) 2014 ITESM. All rights reserved.
//


#ifndef LinkedList_Tarea_3__22Sept__LinkedList_h
#define LinkedList_Tarea_3__22Sept__LinkedList_h

#include "Node.h"
using namespace std;

template <class T>
class LinkedList
{
public:
    int length;
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    T deleteFirst();
    T deleteLast();
    int deleteAll();
    T del(int pos);
    T get(int pos);
    T set(T data, int pos);
    bool change(int pos1, int pos2);
    void print();
    
    // TAREA
    void reverse();
    void shift(int c);
    bool operator==(LinkedList<T> l);
    void operator+=(T d);
    void operator+=(LinkedList<T> l);
    LinkedList(LinkedList<T> &l);
    void operator=(LinkedList<T> l);
    node<T> *head;
    
private:
   
    void delAll();
};

template <typename T>
void LinkedList<T>::delAll(){
	node<T> *aux;
	while (head != NULL){
		aux = head;
		head = head->getNext();
		delete aux;
	}
}

template <typename T>
LinkedList<T>::LinkedList(){
	head = NULL;
	length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	this->delAll();
}

template <typename T>
bool LinkedList<T>::isEmpty(){
	return head==NULL;
}

template <typename T>
void LinkedList<T>::addFirst(T data){
	node<T> *aux = new node<T>(data, head);
	head = aux;
	length++;
}

template <typename T>
void LinkedList<T>::addLast(T data){
	if (this->isEmpty()){
		this->addFirst(data);
	}
	else{
		node<T> *aux = head;
		while (aux->getNext() != NULL){
			aux = aux->getNext();
		}
		node<T> *nuevo = new node<T>(data);
		aux->setNext(nuevo);
		length++;
	}
}

template <typename T>
bool LinkedList<T>::add(T data, int pos){
	if (pos < 0 || pos > this->length){
		return false;
	}
	else{
		if (pos == 0){
			this->addFirst(data);
		}
		else if (pos == this->length){
			this->addLast(data);
		}
		else{
			node<T> *aux1 = head;
			node<T> *aux2;
			for (int i=1; i<pos; i++){
				aux1 = aux1->getNext();
			}
			aux2 = aux1->getNext();
			node<T> *nuevo = new node<T>(data, aux2);
			aux1->setNext(nuevo);
		}
		this->length++;
		return true;
	}
}

template <typename T>
T LinkedList<T>::deleteFirst(){
	if (this->isEmpty()){
		return NULL;
	}
	else{
		node<T> *aux = head;
		T infoaux = head->getData();
		head = head->getNext();
		delete aux;
		this->length--;
		return infoaux;
	}
}

template <typename T>
T LinkedList<T>::deleteLast(){
	if (this->length <= 1){
		return this->deleteFirst();
	}
	else{
		node<T> *aux1 = head;
		node<T> *aux2;
		while (aux1->getNext()->getNext() != NULL){
			aux1 = aux1->getNext();
		}
		aux2 = aux1->getNext();
		T infoaux = aux2->getData();
		delete aux2;
		aux1->setNext(NULL);
		this->length--;
		return infoaux;
	}
}

template <typename T>
int LinkedList<T>::deleteAll(){
	this->delAll();
	int total = length;
	length = 0;
	return total;
}

template <typename T>
T LinkedList<T>::del(int pos){
	if (pos < 0 || pos >= this->length){
		return NULL;
	}
	else{
		if (pos == 0){
			return this->deleteFirst();
		}
		else if (pos == this->length-1){
			return this->deleteLast();
		}
		else{
			node<T> *aux1 = head;
			node<T> *aux2;
			for (int i=1; i<pos; i++){
				aux1 = aux1->getNext();
			}
			aux2 = aux1->getNext();
			aux1->setNext(aux2->getNext());
			T infoaux = aux2->getData();
			delete aux2;
			this->length--;
			return infoaux;
		}
	}
}

template <typename T>
T LinkedList<T>::get(int pos){
	if (pos < 0 || pos >= this->length){
		return NULL;
	}
	else{
		node<T> *aux = head;
		for (int i=1; i<=pos; i++){
			aux = aux->getNext();
		}
		T infoaux = aux->getData();
		return infoaux;
	}
}

template <typename T>
T LinkedList<T>::set(T data, int pos){
	if (pos < 0 || pos >= this->length){
		return NULL;
	}
	else{
		node<T> *aux = head;
		for (int i=1; i<=pos; i++){
			aux = aux->getNext();
		}
		T infoaux = aux->getData();
		aux->setData(data);
		return infoaux;
	}
}

template <typename T>
bool LinkedList<T>::change(int pos1, int pos2){
	if (pos1 < 0 || pos2 < 0 || pos1 >= this->length || pos2 >= this->length){
		return false;
	}
	else{
		node<T> *aux1 = head;
		node<T> *aux2;
		int posMen = (pos1 < pos2 ? pos1 : pos2);
		int posMay = (pos1 > pos2 ? pos1 : pos2);
		for (int i=1 ; i<= posMen; i++){
			aux1 = aux1->getNext();
		}
		aux2 = aux1;
		for (int i=posMen+1; i<=posMay; i++){
			aux2 = aux2->getNext();
		}
		T infoaux = aux1->getData();
		aux1->setData(aux2->getData());
		aux2->setData(infoaux);
		return true;
	}
}

template <typename T>
void LinkedList<T>::print(){
	node<T> *aux = head;
	while (aux != NULL){
		cout << aux->getData()<< "-->";
		aux = aux->getNext();
	}
	cout << endl;
}

// TAREA TAREA TAREA

template <typename T>
void LinkedList<T>::reverse(){
	if(head == NULL || head->getNext() == NULL){
        return;
    }
	node <T> *aux1,*aux2,*aux3;
    aux1=head;
    aux2=aux1->getNext();
    head->setNext(NULL);
    while(aux2!=NULL){
        aux3=aux2->getNext();
        aux2->setNext(aux1);
        aux1=aux2;
        aux2=aux3;
    }
    head=aux1;
}

template <typename T>
void LinkedList<T>::shift(int c){
    if (c == 0){
        return;
    }
    c = (c % this->length + this->length ) % this->length;
    node<T> *aux1,*aux2, *aux3;
    aux1=head;
    aux2=aux1;
    for(int i=0; i<c; i++){
        aux2= aux2->getNext();
    }
    head=aux2;
    aux3=aux2;
    while(aux3->getNext()!=NULL){
        aux3=aux3->getNext();
    }
    aux3->setNext(aux1);
    for (int i = 0; i< c-1; i++){
        aux1 = aux1->getNext();
    }
    aux1->setNext(NULL);
}


template <typename T>
bool LinkedList<T>::operator==(LinkedList<T> l){
	int aux = l.length / 2 , aux2 = this->length;    
    if (aux2 != aux){
        return false;
    }
    for (int i = 0; i < length; ++i){
		if(this->get(i) != l.get(i)){
			return false;
		}
	}
	return true;
}

template <typename T>
void LinkedList<T>::operator+=(T d){
    this->addLast(d);
}

template <typename T>
void LinkedList<T>::operator+=(LinkedList<T> l){
    node<T> *aux = l.head;
    aux = l.head;
    while (aux != NULL){
        T aux1 = aux->getData();
        this->addLast(aux1);
        aux = aux->getNext();
    }
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &l){
    head = NULL;
    node<T> *aux;
    aux=l.head;
    this->length=l.length;
    for (int i = 0; i < l.length; i++) {
        this->addLast(l.get(i));
    }
}

template <typename T>
void LinkedList<T>::operator=(LinkedList<T> l){
    this->delAll();
    node<T> *aux;
    T d;
    aux=l.head;
    while(aux!=NULL){
        d=aux->getData();
        this->addLast(d);
        aux=aux->getNext();
    }
}





#endif
