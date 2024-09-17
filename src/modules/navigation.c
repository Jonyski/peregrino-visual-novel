#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include "navigation.h"

		place_t banheirofb = {
			.name = "Banheiro Feminino",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
			
		};

		place_t banheiromb = {
			.name = "Banheiro Masculino",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
			
		};

		place_t estantes = {
			.name = "Estantes de livros",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
			
		};

	place_t biblioteca = {
		.name = "Biblioteca",
		.subPlaces = {&banheirofb, &banheiromb, &estantes},
		.filePath = NULL,
		.numSubPlaces = 3
	};

		place_t ru = {
			.name = "Bandejão",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
		};
		place_t salaaula = {
			.name = "Sala de Aula",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
		};
		place_t spawn = {
			.name = "Spawnpoint",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
		};
		place_t papelao = {
			.name = "Papelão",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
		};
		place_t banheiroft = {
			.name = "Banheiro Feminino",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
		};
		place_t banheiromt = {
			.name = "Banheiro Masculino",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
		};
		place_t telhado = {
			.name = "Telhado",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0
		};

	place_t titanic = {
		.name = "Titanic",
		.subPlaces = {&ru, &salaaula, &spawn, &papelao, &banheiroft, &banheiromt, &telhado},
		.filePath = NULL,
		.numSubPlaces = 7	 
	};

		place_t anfiteatrocb = {
			.name = "Anfiteatro",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t lab = {
			.name = "Laboratório",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t cantinacb = {
			.name = "Cantina",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t banheiromcb = {
			.name = "Banheiro Masculino",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t banheirofcb = {
			.name = "Banheiro Feminino",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t rp = {
			.name = "Salas de RP",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};

	place_t cb = {
		.name = "CB",
		.subPlaces = {&anfiteatrocb, &lab, &cantinacb, &banheirofcb, &banheiromcb, &rp},
		.filePath = NULL,
		.numSubPlaces = 6	 
	};

		place_t quadra = {
			.name = "Quadra",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t aluguel = {
			.name = "Empréstimo de equipamentos esportivos",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t labirinto = {
			.name = "Labirinto",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t academia = {
			.name = "Academia",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t escalada = {
			.name = "Escalada",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};
		place_t pingpong = {
			.name = "Ping Pong",
			.subPlaces = {NULL},
			.filePath = NULL,
			.numSubPlaces = 0	 
		};

	place_t ginasio = {
		.name = "Ginásio",
		.subPlaces = {&quadra, &aluguel, &labirinto, &academia, &escalada, &pingpong},
		.filePath = NULL,
		.numSubPlaces = 6 
	};

	place_t grama = {
		.name = "Grama",
		.subPlaces = {NULL},
		.filePath = NULL,
		.numSubPlaces = 0	 
	};

	place_t queijo = {
		.name = "Queijo",
		.subPlaces = {NULL},
		.filePath = NULL,
		.numSubPlaces = 0 
	};

	place_t auditorio = {
		.name = "Auditório",
		.subPlaces = {NULL},
		.filePath = NULL,
		.numSubPlaces = 0 
	};

place_t each = {
	.name = "Each",
	.subPlaces = {&biblioteca, &titanic, &cb, &ginasio, &grama, &queijo, &auditorio},
	.filePath = NULL,
	.numSubPlaces = 7
};

void initializePlaces(){
	biblioteca.father = &each;
		banheirofb.father = &biblioteca;
		banheiromb.father = &biblioteca;
		estantes.father = &biblioteca;
	titanic.father = &each;
		ru.father = &titanic;
		salaaula.father = &titanic;
		spawn.father = &titanic;
		papelao.father = &titanic;
		banheiroft.father = &titanic;
		banheiromt.father = &titanic;
		telhado.father = &titanic;
	cb.father = &each;
		anfiteatrocb.father = &cb;
		lab.father = &cb;
		cantinacb.father = &cb;
		banheiromcb.father = &cb;
		banheirofcb.father = &cb;
		rp.father = &cb;
	ginasio.father = &each;
		quadra.father = &ginasio;
		aluguel.father = &ginasio;
		labirinto.father = &ginasio;
		academia.father = &ginasio;
		escalada.father = &ginasio;
		pingpong.father = &ginasio;
	grama.father = &each;
	queijo.father = &each;
	auditorio.father = &each;
}

int navigate(place_t place){
	printf("Você está em %s. Para onde quer ir agora?\n", place.name);
	if(place.numSubPlaces != 0){
		for(int i=0; i<place.numSubPlaces; i++){
			printf("%d) %s\n", i+1, place.subPlaces[i]->name);
		}
		if(place.father != NULL) printf("%d) Ir para outro lugar\n", place.numSubPlaces + 1);
	} else {
		// TODO: read the terminal-place's script
		printf("Morreu\n");
		return 0;
	}
	printf(">");
	int choice;
	scanf("%d", &choice);

	if(choice == place.numSubPlaces + 1 && place.father != NULL){
		navigate(*place.father);
	} else {
		navigate(*place.subPlaces[choice - 1]);
	}

	return 1;

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


