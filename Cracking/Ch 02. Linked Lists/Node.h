//
//  Nose.h
//  LinkedList Tarea 3 (22Sept)
//
//  Created by Carolina Romo on 22/09/14.
//  Copyright (c) 2014 ITESM. All rights reserved.
//

#ifndef LinkedList_Tarea_3__22Sept__Nose_h
#define LinkedList_Tarea_3__22Sept__Nose_h

template <class T>
class node
{
public:
    node(T data);
    node(T data, node<T> *next);
    T getData();
    node<T>* getNext();
    void setData(T data);
    void setNext(node<T> *next);
    T data;
    node<T> *next;
	
private:
    
};

template <typename T>
node<T>::node(T data)
{
	this->data = data;
	this->next = NULL;
}

template <typename T>
node<T>::node(T data, node<T> *next)
{
	this->data = data;
	this->next = next;
}

template <typename T>
T node<T>::getData()
{
	return this->data;
}

template <typename T>
node<T>* node<T>::getNext()
{
	return this->next;
}

template <typename T>
void node<T>::setData(T data)
{
	this->data = data;
}

template <typename T>
void node<T>::setNext(node<T> *next)
{
	this->next = next;
}

#endif
