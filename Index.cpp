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
        for( int x = 0; x <= nomearquivos.nomearquivos.size(); x++ ){
        std::ifstream f;
        std::string name = "./20news-19997//20_newsgroups//" + nomearquivos.nomearquivos[x];
        f.open( name.c_str(), std::ios::in );
        if(f.is_open()){
            while( !f.eof() ) {
                f >> s;
                std::transform(s.begin(), s.end(), s.begin(),::tolower);
                std::string ert=remover(s);
                adicionar( x+1,ert, nomearquivos.nomearquivos[x]);
                s.clear();
            }
            f.close();
        }
            /*else{
                std::cout<< "Arquivo ou Caminho não encontrado";
            }*/

    }
}
std::string Index::remover(std::string text)
{

   for(int i=0;i<text.length();i++){
        if (!isalnum(text[i])){
        text.erase(i,1);
   }
}
return text;
}

void Index::adicionar(int posicao,std::string s, std::string fileName){

     std::pair<std::string,int> key = make_pair(fileName, posicao);
     Ar_Index.insert(std::make_pair(Chave_interna(posicao,s),fileName));

}

void Index::encontrar(Armazenar_arquivos &nomearquivos,std::string busca){
    int check=0, check_print=0;
    for(int i =0; i<nomearquivos.stringvec.size(); i++ ){
        it =Ar_Index.find(Chave_interna(i+1,busca));
        if (it!= Ar_Index.end()){
            check++;}
        if (check==1 && check_print == 0){
        std::cout << "A Palavra: "<< busca<< " foi achada no(s) arquivo(s):" << '\n';
            check_print++;
         }
        if(check!=0)
        std::cout << it->second << '\n';
    }
    if (check==0){
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
