#include<iostream>
using namespace std;

typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
    
}Nodo;

	Nodo *principioPila = NULL;
	Nodo *primeroCola = NULL;
	Nodo *ultimoCola = NULL;
	Nodo *lista = NULL;


	int introducirDatos()
	{
	    int x;
	    cout<<("Numero: ");
	    cin>>x;
	    return x;
	}
	void meterPila()
	{
	    Nodo *nuevo;
	    int numero = introducirDatos();
	
	    while(numero!=0)
	    {
	        Nodo *nuevo = new Nodo;
	        nuevo->dato=numero;
	        nuevo->siguiente=principioPila;
	        principioPila=nuevo;
	        numero=introducirDatos();
	    }
	}
	
	
	void llenarCola()
	{
	    Nodo *nuevo;
	    int numero=introducirDatos();
	
	    while(numero!=0)
	    {
	        Nodo *nuevo = new Nodo;
	        nuevo->dato=numero;
	
	        if(ultimoCola==NULL)
	        {
	            nuevo->siguiente=NULL;
	            primeroCola=nuevo;
	            ultimoCola=nuevo;
	        }
	        else
	        {
	            nuevo->siguiente=NULL;
	            ultimoCola->siguiente=nuevo;
	            ultimoCola=nuevo;
	        }       
	        numero=introducirDatos();
	    }
	}
	
	
	
	
	
	void ListaEnlazadaOrdenada()
	{
	    Nodo *pila,*cola,*pivote,*auxiliar,*anterior;
	    int valor;
	
	    pila=principioPila;
	    while(pila!=NULL)
	    {   
	        valor=pila->dato;
	        Nodo *pivote = new Nodo;;
	        pivote->dato=valor;
	        if(lista==NULL)
	        {
	            pivote->siguiente=lista;
	            lista=pivote;
	        }
	        else
	        {
	            auxiliar=lista;
	            if(pivote->dato < auxiliar->dato)
	            {
	                pivote->siguiente=auxiliar;
	                lista=pivote;
	            }
	            else
	            {
	                while(auxiliar!=NULL && pivote->dato > auxiliar->dato)
	                {
	                    anterior=auxiliar;
	                    auxiliar=auxiliar->siguiente;
	                }
	                if(auxiliar!=NULL)
	                {
	                    anterior->siguiente=pivote;
	                    pivote->siguiente=auxiliar;
	                }
	                else
	                {
	                    anterior->siguiente=pivote;
	                    pivote->siguiente=NULL;
	                }
	            }
	        }
	        pila=pila->siguiente;
	    }
	
	    
	    
	    cola=primeroCola;
	    while(cola!=NULL)
	    {
	        valor=cola->dato;
	        Nodo *pivote = new Nodo;
	        pivote->dato=valor;
	        if(lista==NULL)
	        {
	            pivote->siguiente=lista;
	            lista=pivote;
	        }
	        else
	        {
	            auxiliar=lista;
	            if(pivote->dato < auxiliar->dato)
	            {
	                pivote->siguiente=auxiliar;
	                lista=pivote;
	            }
	            else
	            {
	                while(auxiliar!=NULL && pivote->dato > auxiliar->dato)
	                {
	                    anterior=auxiliar;
	                    auxiliar=auxiliar->siguiente;
	                }
	                if(auxiliar!=NULL)
	                {
	                    anterior->siguiente=pivote;
	                    pivote->siguiente=auxiliar;
	                }
	                else
	                {
	                    anterior->siguiente=pivote;
	                    pivote->siguiente=NULL;
	                }
	            }
	        }
	        cola=cola->siguiente;
	    }   
	}
	
	
	void visualizarDatos()
	{   
	    while(lista!=NULL)
	    {
	        cout<<lista->dato<<" ";
	        lista=lista->siguiente;
	    }       
	}

int main()
{
    cout<<"Datos para la pila"<<endl;
    meterPila();
    cout<<"Datos para la cola"<<endl;
    llenarCola();
    ListaEnlazadaOrdenada();
    cout<<"Lista enlazada ordenada"<<endl;
    visualizarDatos();
    cout<<endl;
    return 0;
}
//https://es.calameo.com/read/00099798206b0eb7a2eb2

