#ifndef INDEX_H
#define INDEX_H
#include <map>
#include <vector>


class Armazenar_arquivos;
class Index{
    public:
        Index(); // construtor
        virtual ~Index(); // destrutor
        void copiar_arquivo(Armazenar_arquivos &nomearquivos); // abre os arquivos mapeados e chama a função adicionar para cada palavra
        void adicionar( int posicao,std::string s, std::string fileName ); // adiciona as palavras a map
        void encontrar (Armazenar_arquivos &nomearquivos,std::string busca); // função para encontrar as palavras digitadas na estrutura map
        std::string remover(std::string text); // remove caracteres especiais

    private:
        typedef std::pair<int,std::string> Chave_interna; // definição da chave interna
        std::map<Chave_interna,std::string> Ar_Index; // declaração map
        std::map<Chave_interna,std::string>::iterator it; // iterator
        std::string s; // string para a palavra buscada
};

class Armazenar_arquivos{
    public:
        Armazenar_arquivos();//construtor
        virtual ~Armazenar_arquivos(); // destrutor
        void imprimir(); // função para verificar se todos os arquivos estão sendo lidos
        void chechar_maiscula(std::string &s); // converte a palavra digitada para minuscula

    private:
        std::vector<std::string> stringvec; // vetor de string que recebe o nome dos arquivos na pasta
        friend void Index::copiar_arquivo(Armazenar_arquivos &nomearquivos); // função friend para permitir acesso de função da class Index
        friend void Index::encontrar (Armazenar_arquivos &nomearquivos,std::string busca); // função friend para permitir acesso de função da class Index
};






#endif // INDEX_H
