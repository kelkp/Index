#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Index.cpp"
#include "doctest.h"


TEST_SUITE ("Armazenar_arquivos"){
    TEST_CASE("checar maiuscula"){
        std::vector <std::string> vetor {"A","B","C","D"};
        for(int i = 0 ;i < 4; i++){
            chechar_maiscula(vetor[i]);
        }
        CHECK(t.vetor[0] == "a");
        CHECK(t.vetor[1] == "b");
        CHECK(t.vetor[2] == "c");
        CHECK(t.vetor[3] == "d");
        }
    TEST_CASE("nome_diretorios"){
        std::vector <std::string> diretorios;
        std::string aux;
        diretorios.push_back("alt.atheism");
        diretorios.push_back("comp.graphics");
        diretorios.push_back("comp.os.ms-windows.misc");
        diretorios.push_back("comp.sys.ibm.pc.hardware");
        diretorios.push_back("comp.sys.mac.hardware");
        diretorios.push_back("comp.windows.x");
        diretorios.push_back("misc.forsale");
        diretorios.push_back("rec.autos");
        diretorios.push_back("rec.motorcycles");
        diretorios.push_back("rec.sport.baseball");
        diretorios.push_back("rec.sport.hockey");
        diretorios.push_back("sci.crypt");
        diretorios.push_back("sci.electronics");
        diretorios.push_back("sci.med");
        diretorios.push_back("sci.space");
        diretorios.push_back("soc.religion.christian");
        diretorios.push_back("talk.politics.guns");
        diretorios.push_back("talk.politics.mideast");
        diretorios.push_back("talk.politics.misc");
        diretorios.push_back("talk.religion.misc");
        while(!NULL){
            for(int i = 0; i<diretorios.size(); i++){
                if (diretorios[i] == dp->d_name){
                    aux = diretorios[i];
                }}}
        CHECK(aux == dp->d_name);
    }
}

TEST_SUITE("Index"){
    TESTE_CASE("copiar_arquivo"){
        Index t;
        Armazenar_arquivos t1;
        t1.nomearquivos[0] = {"arquivo1.txt"};
        t.copiar_arquivo(t1.nomearquivos);
        CHECK(t1.stringvec[0] == "a");
        CHECK(t1.stringvec[1] == "b");
        CHECK(t1.stringvec[2] == "c");
        CHECK(t1.stringvec[3] == "d");
    }
    TEST_CASE("remover"){
        std::string s = "ab'{}cde";
        s = remover(s);
        CHECK(s=="abcde");
    }

    TEST_CASE("adicionar"){
        Index t;
        std::string arquivo_teste = "arquivo_teste1.txt";
        std::string s; = "abcde";
        t.adicionar(0,s, nome_arquivo);
        CHECK(stringvec->second == arquivo_teste);
        CHECK(stringvec->first == s);
}
   /* TEST_CASE("encontrar"){
        Armazenar_arquivos t;
        t.nomearquivo.stringvec[0] = "a";
        t.nomearquivo.stringvec[1] = "b";
        t.nomearquivo.stringvec[2] = "c";
        t.nomearquivo.stringvec[3] = "teste";
        std::string busca = "teste";
        encontrar(t.nomearquivo, busca);*/








    }



}
