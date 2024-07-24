#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "navigation.h"
#include "narrator.h"
#include "utils.h"
#include "commands.h"

bool navigationIsOver = false;

int navigateMap(){
	navigationIsOver = false;
	while(!navigationIsOver) {
		printMap();
		showNavigationOptions();
	}
}

int printMap(){
	FILE *file;
	char mapa[1600];

	#ifdef _WIN32
		file = fopen("./assets/EACH-map.txt", "r");
	#else
		file = fopen("./assets/EACH-map.txt", "r");
	#endif

	if(file == NULL){
		perror("Error opening file");
		exit(1);
	}

	while(fgets(mapa, sizeof(mapa), file) != NULL){
		printf("%s", mapa);
	}
	
	fclose(file);
	return 1;
}

void showNavigationOptions(){
	char choice[USR_INPUT_MAX_SIZE];
	slowPrint("Para onde você quer ir, então?\n");
		printf("1)BIBLIOTECA     5)GRAMA\n");
		printf("2)QUEIJO         6)CICLO BÁSICO\n");
		printf("3)AUDITÓRIOS     7)ELEFANTE BRANCO\n");
		printf("4)TITANIC        8)GINÁSIO\n");
	
	invalidInputLabel:
	printf("> ");
	cleanScan(choice);
	while(classifiesAsCommand(choice)) {
		clear();
		processCommand(choice);
		// I know, I know, code repetition is an unforgivable crime or something
		slowPrint("Com isso fora do caminho, para onde você quer ir?\n");
			printf("1)BIBLIOTECA     5)GRAMA\n");
			printf("2)QUEIJO         6)CICLO BÁSICO\n");
			printf("3)AUDITÓRIOS     7)ELEFANTE BRANCO\n");
			printf("4)TITANIC        8)GINÁSIO\n");
			printf("> ");
		cleanScan(choice);
	}

	switch(toupper(*choice)){
		case '1':
			clear();
			biblioteca();
			break;
		case '2':
			clear();
			queijo();
			break;
		case '3':
			clear();
			auditorios();
			break;
		case '4':
			clear();
			titanic();
			break;
		case '5':
			clear();
			grama();
			break;
		case '6':
			clear();
			cb();
			break;
		case '7':
			clear();
			elefantebranco();
			break;
		case '8':
			clear();
			ginasio();
			break;
		default:
			goto invalidInputLabel;
			break;
	}
}


void biblioteca(){
	char choice[USR_INPUT_MAX_SIZE];
	slowPrint("Após caminhar um pouco, você chegou na entrada da Biblioteca!\n");
	slowPrint("Agora, o que fazer?\n");
	biblioLoop(choice);
}	


void queijo(){
	char choice[USR_INPUT_MAX_SIZE];
	slowPrint("Após caminhar um pouco, você chegou no Queijo!\n");
	slowPrint("Agora, o que fazer?\n");
	queijoLoop(choice);
}

void auditorios(){
	char choice[USR_INPUT_MAX_SIZE];
	slowPrint("Após caminhar um pouco, você chegou na entrada de acesso aos auditórios!\n");
	slowPrint("Agora, aonde você quer ir?\n");
	auditoriosLoop(choice);

}

void titanic(){
	char choice[USR_INPUT_MAX_SIZE];
	slowPrint("Após caminhar um pouco, você chegou no titanic!\n");
	slowPrint("Para onde, agora?\n");
	titanicLoop(choice);

}

void grama(){
	char choice[USR_INPUT_MAX_SIZE];
	slowPrint("Após caminhar um pouco, você chegou na grama!\n");
	slowPrint("Agora, o que fazer?\n");
	gramaLoop(choice);

}

int cb(){
	printf("Após caminhar um pouco, você chegou no Ciclo Básico(C2)!\n");
	printf("Para onde, agora?\n");
	return 1;
}

int elefantebranco(){
	printf("Após caminhar um pouco, você chegou no Elefante Branco!\n");
	printf("Para onde, agora?\n");
	return 1;
}

int ginasio(){
	printf("Após caminhar um pouco, você chegou no Ginásio!\n");
	printf("Para onde, agora?\n");
	return 1;
}


void biblioLoop(char *choice){
	printf("1)BANHEIRO DA BIBLIOTECA     2)ENTRAR NA BIBLIOTECA\n");
	printf("3)IR PARA OUTRO LUGAR\n");
	printf("> ");
	
	cleanScan(choice);
	while(classifiesAsCommand(choice)) {
		clear();
		processCommand(choice);
		// I know, I know, code repetition is an unforgivable crime or something
		slowPrint("Mas agora, o que quer fazer na biblioteca?\n");
			printf("1)BANHEIRO DA BIBLIOTECA     2)ENTRAR NA BIBLIOTECA\n");
			printf("3)IR PARA OUTRO LUGAR\n");
			printf("> ");
		cleanScan(choice);
	}
	clear();

	switch (toupper(*choice)){
		case '1':
			slowPrint("Você caminha até o banheiro da Biblioteca!\n");
			slowPrint("Depois de fazer suas necessidades, você volta para a entrada da Biblioteca.\n");
			slowPrint("Para onde, agora?\n");
			biblioLoop(choice);
			break;
		case '2':
			slowPrint("Você adentra na Biblioteca!\n");
			slowPrint("Mas, percebe que ela não está funcionando agora.\n");
			slowPrint("Para onde, então?\n");
			biblioLoop(choice);
			break;
		case '3':
			system("clear");
			printMap();
			showNavigationOptions();
			break;
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			biblioLoop(choice);
			break;			
	}
}

void titanicLoop(char *choice){
	printf("1)BANDECO           2)SALAS DE AULA\n");
	printf("3)MESAS DE PAPELÃO  4)ASSENTOS DA ENTRADA\n");
	printf("5)IR PARA OUTRO LUGAR\n");
	printf("> ");
	
	cleanScan(choice);
	while(classifiesAsCommand(choice)) {
		clear();
		processCommand(choice);
		// I know, I know, code repetition is an unforgivable crime or something
		slowPrint("E agora, para que parte do Titanic quer ir?\n");
			printf("1)BANDECO           2)SALAS DE AULA\n");
			printf("3)MESAS DE PAPELÃO  4)ASSENTOS DA ENTRADA\n");
			printf("5)IR PARA OUTRO LUGAR\n");
			printf("> ");
		cleanScan(choice);
	}
	clear();

	switch (toupper(*choice)){
		case '1':
			slowPrint("Você anda em direção ao Bandeco...\n");
			slowPrint("Mas, ele está fechado (trancado pelo outro lado).\n");
			system("clear");
			slowPrint("E agora?\n");
			titanicLoop(choice);
			break;
		case '2':
			slowPrint("Você sobe as escadas e vaga pelas salas de aula...\n");
			slowPrint("Mas, não está rolando nenhuma aula do seu curso no momento.\n");
			system("clear");
			slowPrint("E agora?\n");
			titanicLoop(choice);
			break;
		case '3':
			slowPrint("Você procura uma mesa de papelão e senta numa cadeira...\n");
			slowPrint("Mas, suas costas começam a doer e você decide levantar.\n");
			system("clear");
			slowPrint("E agora?\n");
			titanicLoop(choice);
			break;
		case '4':
			slowPrint("Na entrada da frente do Titanic, você fica nos assentos\n");
			slowPrint("Mas, você fica entediado e você decide levantar.\n");
			system("clear");
			slowPrint("E agora?\n");
			titanicLoop(choice);
			break;
		case '5':
			system("clear");
			printMap();
			showNavigationOptions();
			break;
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			titanicLoop(choice);
			break;
	}
}

void queijoLoop(char *choice){
	printf("1)SENTAR E REFLETIR SOBRE A VIDA    2)IR PARA OUTRO LUGAR\n");
	printf("> ");
	
	cleanScan(choice);
	while(classifiesAsCommand(choice)) {
		clear();
		processCommand(choice);
		// I know, I know, code repetition is an unforgivable crime or something
		slowPrint("A vida aqui no queijo é muito boa, o que quer fazer?\n");
			printf("1)SENTAR E REFLETIR SOBRE A VIDA    2)IR PARA OUTRO LUGAR\n");
			printf("> ");
		cleanScan(choice);
	}
	clear();

	switch(toupper(*choice)){
		case '1':
			slowPrint("Você senta no Queijo e começa a transcender espiritualmente...\n");
			slowPrint("Após isso, o que você vai fazer?\n");
			queijoLoop(choice);
			break;
		case '2':
			system("clear");
			printMap();
			showNavigationOptions();
			break;
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			queijoLoop(choice);
			break;
	}
}

void auditoriosLoop(char *choice){
	printf("1)LANCHONETE     2)AUDITÓRIO 1\n");
	printf("3)AUDITÓRIO 2	 4)BANHEIROS \n");
	printf("5)IR PARA OUTRO LUGAR\n");
	printf("> ");

	cleanScan(choice);
	while(classifiesAsCommand(choice)) {
		clear();
		processCommand(choice);
		// I know, I know, code repetition is an unforgivable crime or something
		slowPrint("Está bem vazio aqui nos auditórios, quer fazer o que?\n");
			printf("1)LANCHONETE     2)AUDITÓRIO 1\n");
			printf("3)AUDITÓRIO 2	 4)BANHEIROS \n");
			printf("5)IR PARA OUTRO LUGAR\n");
			printf("> ");
		cleanScan(choice);
	}
	clear();

	switch (toupper(*choice)){
		case '1':
			slowPrint("Você chega na lanchonete e começa a olhar os preços...\n");
			slowPrint("Mas, percebe que os preços estão longe da realidade do brasileiro médio.\n");
			slowPrint("E morre.\n");
			slowPrint("Para onde, agora?\n");
			auditoriosLoop(choice);
			break;
		case '2':
			slowPrint("Você anda até o primeiro auditório...\n");
			slowPrint("Mas não tem nada rolando lá.\n");
			slowPrint("Então, você volta para o lado de fora.\n");
			slowPrint("Para onde, agora?\n");
			auditoriosLoop(choice);
			break;
		case '3':
			slowPrint("Você anda até o segundo auditório...\n");
			slowPrint("Mas não tem nada rolando lá.\n");
			slowPrint("Então, você volta para o lado de fora.\n");
			slowPrint("Para onde, agora?\n");
			auditoriosLoop(choice);
			break;
		case '4':
			slowPrint("Você anda até os banheiros...\n");
			slowPrint("E tira água do joelho.\n");
			slowPrint("Então, você volta para o lado de fora.\n");
			slowPrint("Para onde, agora?\n");
			auditoriosLoop(choice);
			break;
		case '5':
			system("clear");
			printMap();
			showNavigationOptions();
			break;
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			auditoriosLoop(choice);
			break;
	}
}

void gramaLoop(char *choice){
	printf("1)PEGAR UMA CADEIRA E SENTAR   2)IR PARA OUTRO LUGAR\n");
	printf("> ");
	
	cleanScan(choice);
	while(classifiesAsCommand(choice)) {
		clear();
		processCommand(choice);
		// I know, I know, code repetition is an unforgivable crime or something
		slowPrint("você chega até a ouvir a grama chamando seu nome, o que quer fazer?\n");
			printf("1)PEGAR UMA CADEIRA E SENTAR   2)IR PARA OUTRO LUGAR\n");
			printf("> ");
		cleanScan(choice);
	}
	clear();

	switch(toupper(*choice)){
		case '1':
			slowPrint("Você pega uma cadeira, senta na grama e começa a relaxar...\n");
			slowPrint("Depois de um tempo, você levanta e guarda a cadeira.\n");
			slowPrint("O que vais fazer agora?\n");
			gramaLoop(choice);
			break;
		case '2':
			system("clear");
			printMap();
			showNavigationOptions();
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			gramaLoop(choice);
			break;
	}
}
