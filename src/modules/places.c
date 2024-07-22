#include "places.h"
#include "narrator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int printMap(){
	FILE *file;
	char mapa[1600];
	file = fopen("/home/user/peregrino-visual-novel/assets/EACH-map.txt", "r");
	if(file == NULL){
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	while(fgets(mapa, sizeof(mapa), file) != NULL){
		printf("%s", mapa);
	}
	
	fclose(file);
	return 1;
}

void showNavigationOptions(){
	char choose[1];
	slowPrint("Para onde você quer ir, então?\n");
		printf("A)BIBLIOTECA     E)GRAMA\n");
		printf("B)QUEIJO         F)CICLO BÁSICO\n");
		printf("C)AUDITÓRIOS     G)ELEFANTE BRANCO\n");
		printf("D)TITANIC        H)GINÁSIO\n");
		printf("Sua escolha: ");
		scanf("%c", &choose[0]);
		system("clear");

	switch(toupper(*choose)){
		case 'A':
			biblioteca();
			break;
		case 'B':
			queijo();
			break;
		case 'C':
			auditorios();
			break;
		case 'D':
			titanic();
			break;
		case 'E':
			grama();
			break;
		case 'F':
			cb();
			break;
		case 'G':
			elefantebranco();
			break;
		case 'H':
			ginasio();
			break;
	}
}

//FUNCTIONS WITH THE SWITCHES OF THE EACH ONE OF THE PLACES (IMPORTANT TO THE RECURSION & LOOPING)

void switchbiblio(char *choose){
	printf("A)BANHEIRO DA BIBLIOTECA     B)ENTRAR NA BIBLIOTECA\n");
	printf("C)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	switch (toupper(*choose)){
		case 'A':
			slowPrint("Você caminha até o banheiro da Biblioteca!\n");
			slowPrint("Depois de fazer suas necessidades, você volta para a entrada da Biblioteca.\n");
			slowPrint("Para onde, agora?\n");
			switchbiblio(choose);
			break;
		case 'B':
			slowPrint("Você adentra na Biblioteca!\n");
			slowPrint("Mas, percebe que ela não está funcionando agora.\n");
			slowPrint("Para onde, então?\n");
			switchbiblio(choose);
			break;
		case 'C':
			system("clear");
			printMap();
			showNavigationOptions();
			break;
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			switchbiblio(choose);
			break;			
	}
}

void switchtitanic(char *choose){
	printf("A)BANDECO           B)SALAS DE AULA\n");
	printf("C)MESAS DE PAPELÃO  D)ASSENTOS DA ENTRADA\n");
	printf("E)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	switch (toupper(*choose)){
		case 'A':
			slowPrint("Você anda em direção ao Bandeco...\n");
			slowPrint("Mas, ele está fechado (trancado pelo outro lado).\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
			break;
		case 'B':
			slowPrint("Você sobe as escadas e vaga pelas salas de aula...\n");
			slowPrint("Mas, não está rolando nenhuma aula do seu curso no momento.\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
			break;
		case 'C':
			slowPrint("Você procura uma mesa de papelão e senta numa cadeira...\n");
			slowPrint("Mas, suas costas começam a doer e você decide levantar.\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
			break;
		case 'D':
			slowPrint("Na entrada da frente do Titanic, você fica nos assentos\n");
			slowPrint("Mas, você fica entediado e você decide levantar.\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
			break;
		case 'E':
			system("clear");
			printMap();
			showNavigationOptions();
			break;
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			switchtitanic(choose);
			break;
	}
}

void switchqueijo(char *choose){
	printf("A)SENTAR E REFLETIR SOBRE A VIDA    B)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	switch(toupper(*choose)){
		case 'A':
			slowPrint("Você senta no Queijo e começa a transcender espiritualmente...\n");
			slowPrint("Após isso, o que você vai fazer?\n");
			switchqueijo(choose);
			break;
		case 'B':
			system("clear");
			printMap();
			showNavigationOptions();
			break;
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			switchqueijo(choose);
			break;
	}
}

void switchauditorios(char *choose){
	printf("A)LANCHONETE     B)AUDITÓRIO 1\n");
	printf("C)AUDITÓRIO 2	 D)BANHEIROS \n");
	printf("E)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	switch (toupper(*choose)){
		case 'A':
			slowPrint("Você chega na lanchonete e começa a olhar os preços...\n");
			slowPrint("Mas, percebe que os preços estão longe da realidade do brasileiro médio.\n");
			slowPrint("E morre.\n");
			slowPrint("Para onde, agora?\n");
			switchauditorios(choose);
			break;
		case 'B':
			slowPrint("Você anda até o primeiro auditório...\n");
			slowPrint("Mas não tem nada rolando lá.\n");
			slowPrint("Então, você volta para o lado de fora.\n");
			slowPrint("Para onde, agora?\n");
			switchauditorios(choose);
			break;
		case 'C':
			slowPrint("Você anda até o segundo auditório...\n");
			slowPrint("Mas não tem nada rolando lá.\n");
			slowPrint("Então, você volta para o lado de fora.\n");
			slowPrint("Para onde, agora?\n");
			switchauditorios(choose);
			break;
		case 'D':
			slowPrint("Você anda até os banheiros...\n");
			slowPrint("E tira água do joelho.\n");
			slowPrint("Então, você volta para o lado de fora.\n");
			slowPrint("Para onde, agora?\n");
			switchauditorios(choose);
			break;
		case 'E':
			system("clear");
			printMap();
			showNavigationOptions();
			break;
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			switchauditorios(choose);
			break;
	}
}

void switchgrama(char *choose){
	printf("A)PEGAR UMA CADEIRA E SENTAR   B)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	switch(toupper(*choose)){
		case 'A':
			slowPrint("Você pega uma cadeira, senta na grama e começa a relaxar...\n");
			slowPrint("Depois de um tempo, você levanta e guarda a cadeira.\n");
			slowPrint("O que vais fazer agora?\n");
			switchgrama(choose);
			break;
		case 'B':
			system("clear");
			printMap();
			showNavigationOptions();
		default:
			system("clear");
			slowPrint("Opção inválida. Escolha novamente.\n");
			switchgrama(choose);
			break;
	}
}

//FUNCTIONS THAT REPRESENT THE PLACES

void biblioteca(){
	char choose[1];
	slowPrint("Após caminhar um pouco, você chegou na entrada da Biblioteca!\n");
	slowPrint("Agora, o que fazer?\n");
	switchbiblio(choose);
}	


void queijo(){
	char choose[1];
	slowPrint("Após caminhar um pouco, você chegou no Queijo!\n");
	slowPrint("Agora, o que fazer?\n");
	switchqueijo(choose);
}

void auditorios(){
	char choose[1];
	slowPrint("Após caminhar um pouco, você chegou na entrada de acesso aos auditórios!\n");
	slowPrint("Agora, aonde você quer ir?\n");
	switchauditorios(choose);

}

void titanic(){
	char choose[1];
	slowPrint("Após caminhar um pouco, você chegou no titanic!\n");
	slowPrint("Para onde, agora?\n");
	switchtitanic(choose);

}

void grama(){
	char choose[1];
	slowPrint("Após caminhar um pouco, você chegou na grama!\n");
	slowPrint("Agora, o que fazer?\n");
	switchgrama(choose);

}

int cb(){
	printf("Após caminhar um pouco, você chegou no Ciclo Básico(CB)!\n");
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