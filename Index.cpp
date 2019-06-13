#include "Index.h"
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <fstream>
#include <map>
#include <bits/stdc++.h>


Index::Index(){

}

Index::~Index()
{
    Ar_Index.clear();
}

void Index::copiar_arquivo(Armazenar_arquivos &nomearquivos){
        for( int x = 0; x <nomearquivos.nomearquivos.size(); x++ ){
        std::string word;
        std::ifstream f;
        std::string name = "./20news-19997//20_newsgroups//" + nomearquivos.nomearquivos[x];
        f.open( name.c_str(), std::ios::in );
        if(f.is_open()){
            while( f >> word ) {
                word=remover(word);
                std::transform(word.begin(), word.end(), word.begin(),::tolower);
                ++sub_map[word];
            }
            f.close();
        }
        else{
                std::cout<< "Arquivo ou Caminho não encontrado";
            }

        for (std::map<std::string, int>::iterator itx = sub_map.begin(); itx != sub_map.end(); ++itx){
         Ar_Index.insert(std::make_pair(itx->first,Chave_interna(nomearquivos.nomearquivos[x],itx->second)));
        }
        sub_map.clear();
}
}
std::string Index::remover(std::string text){

   for(int i=0;i<text.length();i++){
        if (!isalnum(text[i])){
        text.erase(i,1);
   }
}
return text;
}

void Index::adicionar( int posicao,std::string s, std::string fileName){

    std::pair<std::string,int> key = make_pair(fileName, posicao);
     /*if(Ar_Index.find(s) != Ar_Index.end())
        Ar_Index[s]++;
    else
      Ar_Index.insert(std::make_pair(Chave_interna(posicao,s),fileName));*/

}

void Index::encontrar(Armazenar_arquivos &nomearquivos,std::string busca){
        std::cout <<nomearquivos.nomearquivos.size();
        idf=log(Ar_Index.count(busca)/nomearquivos.nomearquivos.size());
        std::cout << idf << " Para a palavra " << busca << ":";
        auto eqr = Ar_Index.equal_range(busca);
        if (eqr.first!=eqr.second){
        std::cout << "A Palavra: "<< busca<< " foi achada no(s) arquivo(s):" << '\n';
        auto st = eqr.first, en = eqr.second;
            for(auto itr = st; itr != en; ++itr){
            std::cout << itr->second.first << ", " << itr->second.second << std::endl;
            }
        }
        else{
        std::cout << "A Palavra: " << busca<< " nao foi encontrada em nenhum arquivo."<< '\n';
        }

 }




Armazenar_arquivos::Armazenar_arquivos(){
    this->nome_arquivos();
}

void Armazenar_arquivos::nome_arquivos(){
 char *check;
 this->nome_diretorios();
 for (int i=0; i<stringvec.size(); i++){
 std::string name = "./20news-19997//20_newsgroups//"+stringvec[i];
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL){
        check=dp->d_name;
        if (strcmp(check,".")!=0 && strcmp(check,"..")!=0){
            nomearquivos.push_back(stringvec[i]+"//"+dp->d_name);
        }
    }
    closedir(dirp);
 }
}

void Armazenar_arquivos::nome_diretorios(){
 char *check;
 std::string name = "./20news-19997//20_newsgroups";
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL){
        check=dp->d_name;
        if (strcmp(check,".")!=0 && strcmp(check,"..")!=0)
        stringvec.push_back(dp->d_name);

    }
    closedir(dirp);
}

Armazenar_arquivos::~Armazenar_arquivos(){
    //dtor
}

 void Armazenar_arquivos::imprimir(){
     std::copy(stringvec.begin(), stringvec.end(),
         std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << stringvec.size();
 }

 void Armazenar_arquivos::chechar_maiscula(std::string &s){
  std::transform(s.begin(), s.end(), s.begin(),::tolower);
 }
