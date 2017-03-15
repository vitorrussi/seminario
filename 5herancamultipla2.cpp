#include <iostream>
// https://pt.wikibooks.org/wiki/Programar_em_C%2B%2B/Heran%C3%A7a
// g++ -o 5herancamultipla2 5herancamultipla2.cpp
 using namespace std;

 class base1 
         {
         public:
               base1() { cout << "Construindo base1\n"; }
               ~base1() { cout << "Destruindo base1\n"; }
        };

 class base2 
        {
        public:
               base2() { cout << "Construindo base2\n"; }
               ~base2() { cout << "Destruindo base2\n"; }
        };

 class derivada: public base2,public base1
        {
        public:
               derivada() { cout << "Construindo derivada\n"; }
               ~derivada() { cout << "Destruindo derivada\n"; }
        }; 

 int main()
 {
    derivada ob;// construindo e destruindo o objeto.
#ifdef WIN32
    system ("pause");
#endif
    return 0;
 }