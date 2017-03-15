#include <iostream>
// g++ -o 6classe_abstrata 6classe_abstrata.cpp
using namespace std;

class Veiculo {	
	private:
		int rodas;

	protected:
		int crlv;

	public:
		int passageiros;

		void set_rodas(int rodas) {
			this->rodas = rodas;
		}
		void set_passageiros(int passageiros) {
			this->passageiros = passageiros;
		}

		void imprime_rodas() {
			cout << "Numero de rodas = " << rodas << endl;
		}
		void imprime_passageiros() {
			cout << "Numero de passageiros = " << passageiros << endl;
		}
		void imprime_crlv() {
			cout << "Numero do crlv = " << crlv << endl;
		}
		virtual void mover() = 0;
};

class Moto : public Veiculo {
	private:
		int cilindradas;
	public:
		// Moto(long int crlv) : Veiculo (crlv){}

		void set_cilindradas(int cilindradas) {
			this->cilindradas = cilindradas;
		}
		void imprime_cilindradas() {
			cout << "Numero de cilindradas = " << cilindradas << endl;
		}
		// void mover() {
		// 	cout << "Sou pilotado" << endl;
		// }
		void set_crlv(long int crlv) {
			this->crlv = crlv;
		}
	};

class Automovel : public Veiculo {
	private:
		int cap_carga;

	public:
		void set_cap_carga(int cap_carga) {
			this->cap_carga = cap_carga;
		}

		void imprime_cap_carga() {
			cout << "Capacidade de carga = " << cap_carga  << " kg" << endl;
		}

		void mover() {
			cout << "Me movimento como um automovel" << endl;
		}

};

class Picape : public Automovel {
	private:
		int tracao;
	public:
		void set_tracao(int tracao) {
			this->tracao = tracao;
		}
		void imprime_tracao() {
			cout << "Numero de rodas com tracao = " << tracao << endl;
		}
		void mover() {
			cout << "Me movimento como uma picape" << endl;
		}

};

int main () {
	Picape picape;
	//Moto moto;
	int pass;
	cout << "Digite o numero de passageiros: ";
	cin >> pass;

	picape.passageiros = pass;  // FUNCAO DO VEICULO
	picape.set_cap_carga(350); 	// FUNCAO DO AUTOMOVEL
	picape.set_tracao(2); 		// FUNCAO DA PICAPE

	picape.mover();				// FUNCAO DA PICAPE
	picape.Automovel::mover();	// FUNCAO DO AUTOMOVEL


	return 1;
}