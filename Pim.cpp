/*
  Name: PIM-Sistema de Criptografia/Descriptografia
  Copyright: UNIP
  Author: Jorge Danilo Gomes da Silva
  Date: 13/11/13 11:35
  Description: Sistema que criptografa e salva em um arquivo txt. E depois
  Descriptografa no mesmo arquivo txt.
  
*/

#include <stdio.h>
#include<conio.h>
#include<iostream>
#include<cstdlib>
#include<ostream>
#include <stdlib.h>

using namespace std;

//Estrutura Login Sistema.
struct login {
     char login[10],senha[6];
     int compara;
};
typedef login entrada; //A estrutura agora passa a ser um tipo de dado (TAD).

//Estrutura de Criptografia
struct criptografia {
       string texto;
     
};
typedef criptografia texto; //A estrutura agora passa a ser um tipo de dado (TAD).
 
//Estrutua de Descriptografia
struct descriptografia {
 string texto;
 int senha;    
};
typedef descriptografia novoTexto; //A estrutura agora passa a ser um tipo de dado (TAD).


//funcao que limpa tela
void LimpaTela(){
   
  system("cls");    
}

//funcao de login de entrada do sistema.

int entradaSistema(void){
system("color 97");    
entrada loginsistema;  // passando a variavel para manipular o registro
cout<<"Digite o login de 6 digitos : ";
cin.getline(loginsistema.login,10);
cout<<endl;
cout<<"Digite a senha de 6 digitos : ";
loginsistema.senha[0] = getch();
cout<< "*";
loginsistema.senha[1] = getch();
cout<< "*";
loginsistema.senha[2] = getch();
cout<< "*";
loginsistema.senha[3] = getch();
cout<< "*";
loginsistema.senha[4] = getch();
cout<< "*";
loginsistema.senha[5] = getch();
cout<< "*";

//comparação da senha letra por letra.
if((loginsistema.senha[0] == '1') && (loginsistema.senha[1] == '2') && (loginsistema.senha[2] == '3') && (loginsistema.senha[3] == '4') 
  && (loginsistema.senha[4] == '5' && (loginsistema.senha[5]== '6'))){
    cout<< "Acesso Permitido.\n";
      LimpaTela();
}
else{
  cout<< "\nAcesso negado!\n voce nao tem permicao para acesso!\n";
    exit(1);
}

//comparacao do login usando a o comando strcmp
loginsistema.compara=strcmp(loginsistema.login,"danilo");

if(loginsistema.compara==0)
{  
   cout<<"Bem vindo!Voce entrou no sistema !";
     LimpaTela();
}
   else
   {  
      cout<<"Tente Novamente!";
        exit(1); 
  }  
}
        
//Função de Criptografia de Texto 

float CriptografaTexto(void){
system("color a5");
texto criptografa;
int i; 
FILE*arquivo;
arquivo=fopen("ArquivoPim.txt","w");  
if(!arquivo) 
{
   cout<<"Erro na Abertura do Arquivo";
    exit(1);
}
cout<<"Entre com o texto a ser criptografado no arquivo:\n"; 
getline(cin,criptografa.texto);
getline(cin,criptografa.texto);
  for (i = 0; criptografa.texto[i];i++) {
   putc (criptografa.texto[i] + 5, arquivo);
}
cout<<"\n\nTexto Criptografado com Sucesso !\a"<<endl; 
fclose(arquivo);
} 

//Função de Descriptografia de Texto

float DescriptografaTexto(void){
system("color  c7");
novoTexto descriptografa;
FILE*arquivo; 
int i;

arquivo=fopen("ArquivoPim.txt","w"); 
if(!arquivo) 
{
  cout<<"Erro na Abertura do Arquivo"; 
    exit(1); 
}

cout<<"Entre com a chave de seguranca para Descriptografar seu texto :\n";  
cin>>descriptografa.senha;
cout<<"Entre com o texto a ser Descriptografado no arquivo:\n";  
getline(cin,descriptografa.texto);
if (descriptografa.senha != 0) { 
  getline(cin,descriptografa.texto);
    for(i=0;descriptografa.texto[i];i++) {
      putc(descriptografa.texto[i]- descriptografa.senha,arquivo);
 } 
}
cout<<"\n\nTexto Descriptografado com sucesso !\a"<<endl;
fclose(arquivo); 
} 

//funcao que exibe as informacoes dos academicos

void informacao(void){
  LimpaTela();   
  system("color B9");
  cout<<"---------------------------------\n";   
  cout<<"Sistema Desenvolvido pelos Academicos:\n\n";
  cout<<"\t:: Jorge Danilo Gomes da Silva\n\n";
  cout<<"\t:: Jefferson\n\n";
  cout<<"\t:: Junior Rabelo\n\n";
  cout<<"\tTrabalho para aprensentacao para obtencao da nota do PIM.\n";     
  cout<<"-----------------------------------------------------------\n";
}

//funcao principal

int main(){
system("color f9");  
int i,opcao;
cout<<"----------------------------------------\n";
cout<<"------------ Trabalho do PIM -----------\n";
cout<<"----------------------------------------\n\n\n";
cout<<"----------------------------------------\n";
cout<<"------- Programa de Criptografia -------\n";
cout<<"----------------------------------------\n\n\n";
entradaSistema();
cout<<"Escolha uma das opcoes abaixo\n\n"; 
cout<<"1: Para criptografia de texto\n";
cout<<"2: Para descriptografia de texto\n";
cout<<"3: Para informacao do sistema\n\n";
cout<<"---------------------------------------\n";
cout<<"\n Opcao: ";
cin>>opcao; 

//Condição caso,caso uma dessas opções forem selecionadas as funcões entrará em uso.
switch(opcao){ 
case 1:    
  CriptografaTexto();  
break; 
case 2:    
  DescriptografaTexto(); 
break; 
case 3:
  informacao();
break;     
default:  
        cout<<"\n";
        cout<<"Opcao invalida,Entre novamente no Sistema por Favor!\a\n";        
        cout<<"\n";              
}

cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"----------------------------------\n";
cout<<"Caso queira Sair Aperte 's' \n\n";   
cout<<"----------------------------------\n";
getch(); 
return 0;
}
