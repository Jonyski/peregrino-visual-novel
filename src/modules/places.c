#include "places.h"
#include "narrator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printamapa(){

	FILE *file;
	char mapa[1600];

	file = fopen("EACH-map.txt", "r");

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

void opcoes(){

	char choose[1];

	slowPrint("Para onde você quer ir, então?\n");
		printf("A)BIBLIOTECA     E)GRAMA\n");
		printf("B)QUEIJO         F)CICLO BÁSICO\n");
		printf("C)AUDITÓRIOS     G)ELEFANTE BRANCO\n");
		printf("D)TITANIC        H)GINÁSIO\n");
		printf("Sua escolha: ");
		scanf("%c", &choose[0]);
		system("clear");

	switch(*choose){

		case 'A':
			biblioteca();
			break;
		case 'a':
			biblioteca();
			break;
		case 'B':
			queijo();
			break;
		case 'b':
			queijo();
			break;
		case 'C':
			auditorios();
			break;
		case 'c':
			auditorios();
			break;
		case 'D':
			titanic();
			break;
		case 'd':
			titanic();
			break;
		case 'E':
			grama();
			break;
		case 'e':
			grama();
			break;
		case 'F':
			cb();
			break;
		case 'f':
			cb();
			break;
		case 'G':
			elefantebranco();
			break;
		case 'g':
			elefantebranco();
			break;
		case 'H':
			ginasio();
			break;
		case 'h':
			ginasio();
			break;
	}


}

void switchtitanic(char *choose){

	printf("A)BANDECO           B)SALAS DE AULA\n");
	printf("C)MESAS DE PAPELÃO  D)ASSENTOS DA ENTRADA\n");
	printf("E)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	switch (*choose){

		case 'A':
			slowPrint("Você anda em direção ao Bandeco...\n");
			slowPrint("Mas, ele está fechado (trancado pelo outro lado).\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
		case 'a':
			slowPrint("Você anda em direção ao Bandeco...\n");
			slowPrint("Mas, ele está fechado (trancado pelo outro lado).\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
		case 'B':
			slowPrint("Você sobe as escadas e vaga pelas salas de aula...\n");
			slowPrint("Mas, não está rolando nenhuma aula do seu curso no momento.\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
		case 'b':
			slowPrint("Você sobe as escadas e vaga pelas salas de aula...\n");
			slowPrint("Mas, não está rolando nenhuma aula do seu curso no momento.\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
		case 'C':
			slowPrint("Você procura uma mesa de papelão e senta numa cadeira...\n");
			slowPrint("Mas, suas costas começam a doer e você decide levantar.\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
		case 'c':
			slowPrint("Você procura uma mesa de papelão e senta numa cadeira...\n");
			slowPrint("Mas, suas costas começam a doer e você decide levantar.\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
		case 'D':
			slowPrint("Na entrada da frente do Titanic, você fica nos assentos\n");
			slowPrint("Mas, você fica entediado e você decide levantar.\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
		case 'd':
			slowPrint("Na entrada da frente do Titanic, você fica nos assentos\n");
			slowPrint("Mas, você fica entediado e você decide levantar.\n");
			system("clear");
			slowPrint("E agora?\n");
			switchtitanic(choose);
		case 'E':
			system("clear");
			printamapa();
			opcoes();
			break;
		case 'e':
			system("clear");
			printamapa();
			opcoes();
			break;
			
	}
}

int biblioteca(){

	char choose[1];

	slowPrint("Após caminhar um pouco, você chegou na entrada da Biblioteca!\n");
	slowPrint("Agora, o que fazer?\n");

	printf("A)BANHEIRO DA BIBLIOTECA     B)ENTRAR NA BIBLIOTECA\n");
	printf("C)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	if(strcmp(choose, "A") == 0 || strcmp(choose, "a") == 0){
		slowPrint("Você caminha até o banheiro da Biblioteca!\n");
	} else if (strcmp(choose, "B") == 0 || strcmp(choose, "b") == 0){
		slowPrint("Você adentra na Biblioteca!\n");
	} else if(strcmp(choose, "C") == 0 || strcmp(choose, "c") == 0){
		system("clear");
		printamapa();
		opcoes();
	}

	return 1;
}	


int queijo(){

	char choose[1];

	slowPrint("Após caminhar um pouco, você chegou no Queijo!\n");
	slowPrint("Agora, o que fazer?\n");

	printf("A)SENTAR E REFLETIR SOBRE A VIDA    B)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	if(strcmp(choose, "A") == 0 || strcmp(choose, "a") == 0){
		slowPrint("Você senta no Queijo e começa a transcender espiritualmente...\n");
	} else if (strcmp(choose, "B") == 0 || strcmp(choose, "b") == 0){
		system("clear");
		printamapa();
		opcoes();
	}

	return 1;
	
}

int auditorios(){

	char choose[1];

	slowPrint("Após caminhar um pouco, você chegou na entrada de acesso aos auditórios!\n");
	slowPrint("Agora, aonde você quer ir?\n");

	printf("A)LANCHONETE     B)AUDITÓRIO 1\n");
	printf("C)AUDITÓRIO 2	 D)BANHEIROS \n");
	printf("                 E)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	switch (*choose){

		case 'A':
			slowPrint("Você chega na lanchonete e começa a olhar os preços...\n");
			slowPrint("Mas, percebe que os preços estão longe da realidade do brasileiro médio.\n");
			slowPrint("E morre.\n");
			break;

		case 'a':
			slowPrint("Você chega na lanchonete e começa a olhar os preços...\n");
			slowPrint("Mas, percebe que os preços estão longe da realidade do brasileiro médio.\n");
			slowPrint("E morre.\n");
			break;

		case 'B':
			slowPrint("Você anda até o primeiro auditório...\n");
			slowPrint("Mas não tem nada rolando lá.\n");
			slowPrint("Então, você volta para o lado de fora do acesso aos auditórios.\n");
			system("clear");
			printamapa();
			opcoes();
			break;
		case 'b':
			slowPrint("Você anda até o primeiro auditório...\n");
			slowPrint("Mas não tem nada rolando lá.\n");
			slowPrint("Então, você volta para o lado de fora do acesso aos auditórios.\n");
			system("clear");
			printamapa();
			opcoes();
			break;
		case 'C':
			slowPrint("Você anda até o segundo auditório...\n");
			slowPrint("Mas não tem nada rolando lá.\n");
			slowPrint("Então, você volta para o lado de fora do acesso aos auditórios.\n");
			system("clear");
			printamapa();
			opcoes();
			break;
		case 'c':
			slowPrint("Você anda até o segundo auditório...\n");
			slowPrint("Mas não tem nada rolando lá.\n");
			slowPrint("Então, você volta para o lado de fora do acesso aos auditórios.\n");
			system("clear");
			printamapa();
			opcoes();
			break;
		case 'D':
			slowPrint("Você anda até os banheiros...\n");
			slowPrint("E tira água do joelho.\n");
			slowPrint("Então, você volta para o lado de fora do acesso aos auditórios.\n");
			system("clear");
			printamapa();
			opcoes();
			break;
		case 'd':
			slowPrint("Você anda até os banheiros...\n");
			slowPrint("E tira água do joelho.\n");
			slowPrint("Então, você volta para o lado de fora do acesso aos auditórios.\n");
			system("clear");
			printamapa();
			opcoes();
			break;
		case 'E':
			system("clear");
			printamapa();
			opcoes();
			break;
		case 'e':
			system("clear");
			printamapa();
			opcoes();
			break;
	}



	return 1;
}

int titanic(){

	char choose[1];

	slowPrint("Após caminhar um pouco, você chegou no titanic!\n");
	slowPrint("Para onde, agora?\n");
	switchtitanic(choose);

	return 1;
}

int grama(){

	char choose[1];

	slowPrint("Após caminhar um pouco, você chegou na grama!\n");
	slowPrint("Agora, o que fazer?\n");

	printf("A)PEGAR UMA CADEIRA E SENTAR   B)IR PARA OUTRO LUGAR\n");
	printf("Sua escolha: ");
	scanf("%c", &choose[0]);

	if(strcmp(choose, "A") == 0 || strcmp(choose, "a") == 0){
		slowPrint("Você pega uma cadeira, senta na grama e começa a relaxar...\n");
	} else if (strcmp(choose, "B") == 0 || strcmp(choose, "b") == 0){
		system("clear");
		printamapa();
		opcoes();
	}

	return 1;
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




