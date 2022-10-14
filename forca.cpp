	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <iostream>
	#include <time.h>
	
	using namespace std;
	
	void menuInicial();
	void limpaTela();
	int  jogar(int numeroJogadores);
	string palavraAleatoria();
	string palavraMascara(string palavra, int tamanhoPalavra);
	void exibeStatus(string palavraMascarada, int tamanhoPalavra, int tentativasRestantes,string letrasArriscadas,string mensagem);
	
	 main(){
	 	
		setlocale(LC_ALL,"Portuguese");
		srand((unsigned)time(NULL));
		 menuInicial();
		 return 0;
		
		}
	
	void menuInicial(){
		int opcao=0;
		while (opcao< 1 || opcao> 3){
			limpaTela();
			cout <<"Bem vindo";
		cout <<"\n 1- Jogar ";
		cout <<"\n 2- Jogar em dupla ";
		cout <<"\n 3- Sobre ";
		cout <<"\n 4- Sair ";
		cout <<"\n Escolha uma opção e tecle Enter ";
		cin >> opcao;
		switch(opcao){
			case 1:
				 if(jogar(1) == 1){
	                    main();
	                }
				break;
				
					case 2:
						if(jogar(2) == 1){
	                    main();
	                }
			
				break;
				
				case 3:
					cout << "Informações do jogo ";
	                limpaTela();
	                cout << "Jogo da forca desenvolvido por Lucas Damasio em 2022 :) \n";
	                cout << "\n1 - Voltar";
	                cout << "\n2 - Sair";
	                cin >> opcao;
	                if(opcao == 1){
	                    main();
	                }
				break;
				case 4:
					cout << "Até mais  ";
					exit(0);
				break;
				
		}
			
		}
	}
	int jogar(int numeroJogadores){
		 string palavra;
	 
	    if(numeroJogadores == 1){
	        palavra=palavraAleatoria();
	 
	    }else{
	 
	        cout << "\nDigite uma palavra:";
	        cin >> palavra;
	 
	    }
	
		int tamanhoPalavra = palavra.size();
		
		string palavraMascarada = palavraMascara(palavra,  tamanhoPalavra);
		
		int tentativas=0 ,max=10, cont=0,opcao;
		char letra;
		string letrasArriscadas;
		bool letraJaUsada=false,acertouLetra=false;
		string mensagem=" Arrisque uma letra";
		string palavraArriscada;
		
		
		
		
		while(palavra!= palavraMascarada  && max- tentativas>0){
			
			limpaTela();
			exibeStatus(palavraMascarada,tamanhoPalavra,max- tentativas,letrasArriscadas,mensagem);
			cout << "\nDigite uma letra ou digite 1 para arriscar a palavra\n";
			cin >> letra;
			if(letra=='1'){
				cout << "\nQual vai ser a palavra arriscada?\n";
				cin >> palavraArriscada;
				if(palavraArriscada==palavra){
					palavraMascarada=(palavra);	
				}
				else{
					tentativas=max;
				}
			}
			 for ( cont=0; cont < tentativas; cont++){
			 	
			 	if(letrasArriscadas[cont]== letra){
			 		mensagem= "Essa letra ja foi digitada";
			 		letraJaUsada=true;
			 		
				 } 	
			 }
			 if(letraJaUsada==false){
			 	
			 	
			 	letrasArriscadas+= tolower(letra);
			
			for( cont=0;cont < tamanhoPalavra;cont++){
				if(palavra[cont]==tolower(letra)){
					palavraMascarada[cont]=palavra[cont];
					mensagem= "Você acertou uma letra";
					acertouLetra=true;
				}
				
			}
			tentativas++;	
			 }
			 
			 if(acertouLetra==false){
			 		mensagem= "Você errou uma letra";
			 	
			 }
			 letraJaUsada=false;
			 acertouLetra=false;
		}	
			if(palavra== palavraMascarada){
			limpaTela();
			cout << "Parabéns, você venceu!!!";
			cout << "Deseja continuar jogando?";
			 cout << "\n1-Sim";
	        cout << "\n2-Nao";
	        cin >> opcao;
	        if(opcao==1){
	        	jogar(numeroJogadores);
	        	
	        	
			}
			else{
				cout << "Ate mais";
				main();
			}
	        
		}
		else
		{
			limpaTela();
			cout << "Mnheee, você perdeu!!!";
			cout<<" \n A palavra era "<< palavra;
			cout << "\nDeseja continuar jogando?";
			 cout << "\n1-Sim";
	        cout << "\n2-Nao";
	        cin >> opcao;
	        if(opcao==1){
	        	jogar(numeroJogadores);
	        	
			}
			if(opcao==2){
				main();
			}
	        
			
		}
	
		
	}
	string palavraAleatoria(){
		
		string palavras[20]={"abacaxi","manga","morango","escola","amizade","jogos","programa","futebol","musica","frase","hamster","pelicano","navalha","xadrez","jaleco","kiwi","ampulheta","bacalhau","embaixador","catarro"};
		 int indiceAleatorio = rand() % 20;
		return palavras[indiceAleatorio];
		
	}
	string palavraMascara(string palavra, int tamanhoPalavra ){
		int cont=0;
		string palavraMascarada;
		while ( cont < tamanhoPalavra){
			palavraMascarada+="_";
			cont++;
		}
		return palavraMascarada;
				
	}
	
	void exibeStatus(string palavraMascarada, int tamanhoPalavra, int tentativasRestantes, string letrasArriscadas,string mensagem){
		cout << mensagem<<"\n";
		cout << "Palavra:" << palavraMascarada << "\tTamanho:"<< tamanhoPalavra;
		cout << "\nTentativas restantes" << tentativasRestantes;
		int cont;
	    cout << "\n Letras arriscadas:";
	    for(cont = 0; cont < letrasArriscadas.size();cont++){
	        cout << letrasArriscadas[cont] << "  ";
	    }
		
	}
	void limpaTela(){
		system("CLS");
	}
