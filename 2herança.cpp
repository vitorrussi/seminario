#include <iostream>
// g++ -o 2herança 2herança.cpp
using namespace std;

class Veiculo {	
	private:
		int rodas;

	protected:
		int crlv;

	public:
		int passageiros;

		// Veiculo(long int crlv) { this->crlv = crlv;	}

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

		void mover() {
			cout << "Me movimento como uma moto" << endl;
		}

		// void set_crlv(long int crlv) {
		// 	this->crlv = crlv;
		// }
	};


int main () {
	Moto moto;
	int pass;
	cout << "Digite o numero de passageiros: ";
	cin >> pass;

	moto.passageiros = pass;   // VARIAVEL PUBLICA

	moto.set_rodas(3); // FUNCAO HERDADA DO VEICULO
	moto.set_cilindradas(60); // NOVA FUNCAO

	// moto.rodas = 3;			//PRIVATE
	// moto.crlv = 123456789;	//PROTECTED


	//moto.imprime_crlv();
	moto.imprime_passageiros();
	moto.imprime_rodas();


	return 1;
}