#include <vector>
#include <iostream>
#include <string>
// g++ -o 7estruturas 7estruturas.cpp
using namespace std;

class Prog2 {
	public:   
		Prog2() {
			tam = 0;
		}
		bool vazia() {
			return tam == 0;
		}
		unsigned int tamanho() {
			return tam;
		}
		virtual int retira() = 0;
		void imprime() {
			if(tam == 0) {
				cout << "A " << nome_da_classe << " esta vazia!" << endl;
				return;
			}
			cout << "Impressao = ";
			for(Elem *aux = topo; aux != 0; aux = aux->prox) {
				cout << aux->dado << " ";
			}
			cout << endl;
		}
		int ver_topo() {
			if (tam == 0) {
				cout << "A " << nome_da_classe << " vazia!" << endl;
				return 0;
			}
			return topo->dado;
		}
	protected:
		int tam;
		class Elem{
			public:
				int dado;
				Elem *prox;
				Elem *ant;
				Elem(int dado) {
					this->dado = dado;
				}
		};
		Elem *topo;
		Elem *base;
		string nome_da_classe;
};

class Pilha : public Prog2 {

	public:
		Pilha() {
			topo = 0;
			nome_da_classe = "Pilha";
		}

		void insere(int dado) {
			if (!tam) {				
				topo = new Elem(dado);
				topo->prox = 0;
			} else {
				Elem *elem = new Elem(dado);
				elem->prox = topo;
				topo = elem;
			}
			tam++;
		}
		int retira() {
			if (tam == 0) {
				cout << "A "<< nome_da_classe << " esta vazia!" << endl;
				return 0;
			}
			int aux = topo->dado;
			Elem *aux2 = topo;
			topo = topo->prox;				
			delete(aux2);
			tam--;
			return aux;			
		}

};

class Fila : public Prog2 {
	public:
		Fila() {
			base = 0;
			nome_da_classe = "Fila";
		}
		Fila(string nome) {
			nome_da_classe = nome;
		}
		void insere(int dado) {
			if (!tam) {				
				base = new Elem(dado);
				base->prox = 0;
				base->ant = 0;
				topo = base;
			} else {
				Elem *elem = new Elem(dado);
				elem->prox = topo;
				topo->ant = elem;
				elem->ant = 0;
				topo = elem;
			}
			tam++;
		}
		int retira() {
				if (tam == 0) {
					cout << "A "<< nome_da_classe << " esta vazia!" << endl;
					return 0;
				}
				int aux = base->dado;
				Elem *aux2 = base;
				base = base->ant;
				base->prox = 0;				
				delete(aux2);
				tam--;
				return aux;			
			}
};

class Lista : public Fila {
	public:
		Lista() : Fila("Lista") {}

		void insere(int dado, int pos) {
			if (!tam || pos >= tam) {				
				Fila::insere(dado);
				return;
			}
			if(pos == 0) {
				Elem *elem = new Elem(dado);
				base->prox = elem;
				elem->ant = base;
				elem->prox = 0;
				base = elem;
			} else {
				Elem *aux = base;
				for(int i = 0; i < pos; i++) aux = aux->ant;
				Elem *elem = new Elem(dado);
				elem->prox = aux->prox;
				elem->ant = aux;
				aux->prox->ant = elem;
				aux->prox = elem;
			}
			tam++;
		}
		int retira(int pos) {
			if (tam == 0) {
				cout << "A "<< nome_da_classe << " esta vazia!" << endl;
				return 0;
			}
			if (pos == 0 || pos > tam) {
				int valor = Fila::retira();
				return valor;
			}
			Elem *aux = base;
			for(int i = 0; i < pos; i++) aux = aux->ant;

			int valor = aux->dado;
			aux->prox->ant = aux->ant;
			aux->ant->prox = aux->prox;
			aux->ant = 0;
			aux->prox = 0;			
			delete(aux);
			tam--;
			return valor;			
		}
};

int main()
{

	Fila p;
	p.imprime();
	p.ver_topo();
	/*p.retira();
	p.insere(2);
	p.insere(3);
	p.insere(4);
	p.insere(5);
	p.insere(6);
	p.insere(7);
	p.insere(3);
	p.imprime();
	p.retira();
	p.retira();
	p.imprime();*/

	

	return 0;
}
