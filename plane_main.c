#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "plane_utils.h"


int main(){
	
	system("cls");
	
	welcome_message();
	
	printf("\n\nEnter 1 to continue! \n");
	int next_check;
	printf(">");
	scanf("%d", &next_check);
	while(next_check != 1){
		printf(">");
		scanf("%d", &next_check);
	}
	if (next_check==1) system("cls");
	
	login();
	
	menu();

}