#include <iostream>
using namespace std;

template <typename T>
class nodo
{
	T data;
	nodo<T> *siguiente;
    
    public:
	nodo(){this->data=NULL,this->siguiente=NULL;}
	nodo(T data_){this->data=data_,this->siguiente=NULL;}
	void setsiguiente(nodo<T> *sig){siguiente=sig;}
	void setdata(T data){this->data=data;}
	nodo<T>* getsiguiente(){return siguiente;}
	T getdata(){return data;}	
};
	
template <class T>
class pila
{
	private:
		nodo<T>* head;
		int size;
	public:
		pila(){this->head=NULL,size=0;}
		bool size_(){return size==0;}
		int getsize(){return size;}
		
		void agregar(T data){
			nodo<T>* aux =  new nodo<T>(data);
		    if(size_())
		    {
		        head = aux;
		    }
		
		    else
		    {
		        nodo<T>* ptr = head;
		        while(ptr->getsiguiente() != NULL)
		            ptr = ptr->getsiguiente();
		        ptr->setsiguiente(aux);
		    }
		    size++;
		}
		
		T pop_pila(){
			if(size_()) 
		        cout << "Pila vacia\n";
		    else if(size == 1)
		    {
		        T data = head->getdata();
		        delete head;
		        size--;
		        return data;
		    }
		    else
		    {
		        nodo<T>* aux = head;
		        while(aux->getsiguiente()->getsiguiente() != NULL)
		            aux = aux->getsiguiente();
		        nodo<T>* eliminado = aux->getsiguiente();
		        T data = eliminado->getdata();
		        aux->setsiguiente(NULL);
		        delete eliminado;
		        size--;
		        return data;
		    }
		}
		
		void mostrar_pila(){
			nodo<T>* aux = head;
		    while(aux !=NULL)
		    {
		      	cout<<" "<< aux->getdata()<<endl;
		      	aux = aux->getsiguiente();
		    }
		}
		
		~pila(){
			for(int i =0 ; i<size ; i++)
		    {
		        nodo<T>* eliminado = head;
		        head = head->getsiguiente();
		        delete eliminado;
		    }
		}
			
};

template<class T>
class cola{
	private:
		nodo<T>* head;
		int size;
	public:
		cola(){this->head=NULL,size=0;}
		bool size_(){return size==0;}
		int getsize(){return size;}
		
		void agregar_cola(T data)
		{
			nodo<T>* aux =  new nodo<T>(data);
		    if(size_())
		        head = aux;
		
		    else
		    {
		        nodo<T>* ptr = head;
		        while(ptr->getsiguiente() != NULL)
		            ptr = ptr->getsiguiente();
		        ptr->setsiguiente(aux);
		    }
		    size++;
		}
		
		T pop_cola()
		{
			if(size_()) 
		        cout << "cola vacia\n";
		    else
		    {
		        nodo<T>* eliminado = head;
		        head = head->getsiguiente();
		        T data = eliminado->getdata();
		        delete eliminado;
		        size--;
		        return data;
    		}	
		}
		
		void mostrar_cola()
		{
			nodo<T>* aux = head;
		    while(aux !=NULL)
		    {
		      	cout<<" "<< aux->getdata()<<endl;
		      	aux = aux->getsiguiente();
		    }
		}
		~cola(){
			for(int i =0 ; i<size ; i++)
		    {
		        nodo<T>* eliminado = head;
		        head = head->getsiguiente();
		        delete eliminado;
		    }
		}
		
		
};

int main()
{	
	pila<int>pila1;
	pila1.agregar(8);
	pila1.agregar(28);
	pila1.agregar(19);
	pila1.agregar(5);
	pila1.pop_pila();
	pila1.mostrar_pila();
	
	
	cola<int>cola1;
	cola1.agregar_cola(13);
	cola1.agregar_cola(7);
	cola1.agregar_cola(6);
	cola1.agregar_cola(1);
	cola1.pop_cola();
	cola1.mostrar_cola();
	
}
