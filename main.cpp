#include <iostream>
#include "Index.cpp"


int WinMain(){
    Armazenar_arquivos nomearquivos;
    //nomearquivos.imprimir(); //testar se os arquivos estão todos sendo lidos
    Index t;
    t.copiar_arquivo(nomearquivos);
    std::string s;
    while( true ) {
        std::cout << "Digite a Palavra que deseja procurar:";
        std::getline( std::cin, s );
        if( !s.length() ) break;
        nomearquivos.chechar_maiscula(s);
        t.encontrar(nomearquivos, s );
    }
}
