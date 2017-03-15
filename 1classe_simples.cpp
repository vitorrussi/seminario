#include <iostream>
// g++ -o 1classe_simples 1classe_simples.cpp
using namespace std;

class Veiculo {	
	private:
		int rodas;
		int passageiros;
		int crlv;

	public:
		Veiculo(long int crlv) {
			this->crlv = crlv;
		}

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
		void mover() {
			cout << "Me movimento como um veiculo" << endl;
		}
};


int main () {
	Veiculo v(123456789);
	int pass;
	v.set_rodas(4);
	cout << "Digite o numero de passageiros: ";
	cin >> pass;
	v.set_passageiros(pass);

	v.imprime_crlv();
	v.imprime_passageiros();
	v.imprime_rodas();


	return 1;
}