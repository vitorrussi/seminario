#include <iostream>
// https://pt.wikibooks.org/wiki/Programar_em_C%2B%2B/Heran%C3%A7a
// g++ -o 4herancamultipla 4herancamultipla.cpp
 using namespace std;

 class base 
    {
    public:
           base() { cout << "Construindo base" << endl; }
           ~base() { cout << "Destruindo base" << endl; }
    };

 class derivada1 : public base 
    {
    public:
           derivada1() { cout << "Construindo derivada1" << endl; }
           ~derivada1() { cout << "Destruindo derivada1" << endl; }
    };

 class derivada2: public derivada1 
    {
    public:
           derivada2() { cout << "Construindo derivada2\n"; }
           ~derivada2() { cout << "Destruindo derivada2\n"; }
    };

 int main()
 {
    derivada2 ob; // constrói e destrói o objeto ob
#ifdef WIN32
    system ("pause");
#endif
    return 0;
 }
