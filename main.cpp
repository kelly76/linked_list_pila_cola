//https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Estructuras_II

#include <iostream>
using namespace std;

template<typename T>
class list_Iterator;

template<typename T>
class node{
private:
    T data;
    node<T> *next;
public:
    node(){
        data=0;
        next=NULL;
    }
    node(const node<T> &n){
        data=n.data;
        next=n.next;
    }
    T getData(){
        return data;
    }
    void setData(T d){
        data=d;
    }
    node* get_next(){
        return next;
    }
    void set_next(node<T> *n){
        next=n;
    }

};

template<typename T>
class linked_list{
private:
    node<T> *head,*tail;
    int c;
public:
    linked_list(){
        cout<<"Construido"<<endl;
        head=NULL;
        tail=NULL;
        c=0;
    }
    ~linked_list(){
        while(head!=NULL){
            delete head;
            head=head->get_next();
        }
        cout<<"Destruido"<<endl;
    }
    node<T>* crear_nodo(T new_data){
        node<T> *new_node=new node<T>;
        new_node->setData(new_data);
        return new_node;
    }
    void primer_nodo(T new_data){
        c++;
        node<T> *new_node=crear_nodo(new_data);
        head=new_node;
        tail=new_node;
        cout<<"primer_nodo"<<endl;
    }
    void push(T new_data){
        c++;
        node<T> *new_node=crear_nodo(new_data);
        tail->set_next(new_node);
        tail=tail->get_next();
        cout<<"push hecho"<<endl;
    }
    T pop_stack(){
        T x;
        node<T>* aux=tail;
        x=aux->getData();
        delete aux;
        tail=getNodo(c-2);
        c--;
        return x;
    }
    T pop_cola(){
        T x;
        if(tail==head){
            x=head->getData();
            tail=NULL;
            head=NULL;
        }
        node<T>* aux=head;
        head=head->get_next();
        x=aux->getData();
        delete aux;
        c--;
        return x;
    }
    void eliminar_nodo(int pos){
        int i=1;
        node<T>* aux=head;
        node<T>* prev;
        while(i!=pos){
            prev=aux;
            aux=aux->get_next();
            i++;
        }
        prev->set_next(aux->get_next() );
        delete aux;
        c--;
        cout<<"nodo " <<pos<<" eliminado"<<endl;

    }
    node<T>* getNodo(int n){
        int i=0;
        node<T>* aux=head;
        while(i!=n){
            aux=aux->get_next();
            i++;
        }
        return aux;
    }
    int getSize(){
        return c;
    }
    node<T>* get_head(){
    	return head;
	}
    node<T>* get_tail() {
        return tail;
	}
    /*list_Iterator<T>* crearIterator(){
        return new list_Iterator<T>(this);
    }*/
    list_Iterator<T> mostrar(){
        cout<<"Mostrando:"<<endl;
        list_Iterator<T> it;
        for(it=this->get_head() ; it != this->get_tail() ; ++it ){
            cout << *it << " -> ";
        }
        cout<<*it<<endl;
    }
};

template<typename T>
class list_Iterator{
private:
    node<T>* nodoIte;
public:
    list_Iterator(node<T>* nodo=NULL){
        nodoIte=nodo;
    }
	void operator=(node<T>* nodo){
		nodoIte=nodo;
	}
	node<T>* operator++(){
		nodoIte= nodoIte->get_next();
        return nodoIte;
	}
	T operator*(){
		return nodoIte->getData();
	}
	bool operator==(node<T>* nodo){
		return nodoIte== nodo;
	}
	bool operator!=(node<T> *nodo){
		return nodoIte!= nodo;
	}
};

int main()
{
    linked_list<int> pila;
    pila.primer_nodo(3);
    pila.push(4);
    pila.push(5);
    pila.push(6);
    pila.push(7);
    pila.mostrar();
    cout<<"size: "<<pila.getSize()<<endl;
    cout<<"pop_pila: "<<pila.pop_stack()<<endl;
    pila.pop_stack();
    pila.pop_stack();
    pila.pop_stack();
    pila.mostrar();
    cout<<"head: "<<pila.get_head()->getData()<<", tail: "<<pila.get_tail()->getData()<<endl;

    cout<<"-----------------------"<<endl;

    linked_list<int> cola;
    cola.primer_nodo(1);
    cola.push(2);
    cola.push(3);
    cola.push(4);
    cola.push(5);
    cola.mostrar();
    cout<<"pop_cola: "<<cola.pop_cola()<<endl;
    cola.mostrar();
    cout<<"size: "<<cola.getSize()<<endl;

    return 0;
}
