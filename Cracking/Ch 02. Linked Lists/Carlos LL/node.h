template <class T>
class node 
{
private:
	node<T> *next;
	T data;

public:
	node(T data);
	node(T data, node<T> *next);
	T getData();
	node<T>* getNext();
	void setData(T data);
	void setNext(node<T> *next);
};

template <typename T>
node<T>::node(T data)
{
	this->data = data;
	this->next = null;
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
	return data;
}

template <typename T>
node<T>* node<T>::getNext()
{
	return next;
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

