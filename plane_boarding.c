#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "plane_utils.h"

/*
FILE *boardptr;

struct board all_boards[1];

*/

void create_boarding_pass(char name[],char phoneno[],int from, int to, int date, int month, int year, int ttime, int class, int seat_no, float price){
	
	strcpy(all_boards[0].name, name);
	strcpy(all_boards[0].phnno, phoneno);
	
	if (from == 1) strcpy(all_boards[0].from, "DEL");
	else if (from == 2) strcpy(all_boards[0].from, "BOM");
	else if (from == 3) strcpy(all_boards[0].from, "MAA");
	else if (from == 4) strcpy(all_boards[0].from,"BLR");
	else if (from == 5) strcpy(all_boards[0].from, "CUU");
	
	if (to == 1) strcpy(all_boards[0].from, "DEL");
	else if (to == 2) strcpy(all_boards[0].to, "BOM");
	else if (to == 3) strcpy(all_boards[0].to, "MAA");
	else if (to == 4) strcpy(all_boards[0].to, "BLR");
	else if (to == 5) strcpy(all_boards[0].to, "CUU");
	
	
	all_boards[0].date = date;
	all_boards[0].month = month;
	all_boards[0].year = year;
	all_boards[0].ttime = ttime;
	
	if (class == 1) strcpy(all_boards[0].class, "F");
	else if (class == 2) strcpy(all_boards[0].class, "B");
	else if (class == 3) strcpy(all_boards[0].class, "E");
	
	all_boards[0].seat_no = seat_no;
	all_boards[0].price = price;
	all_boards[0].flightid = ttime + year*10000 + month*100000000 + date*10000000000 + to*1000000000000 + from*10000000000000;
	
	
	FILE *boardptr = fopen ("boarding_passes.txt", "a+");
	fwrite (&all_boards[0], sizeof(struct board), 1, boardptr);
	
	fclose (boardptr);
	return;
}

int read_boarding_array(struct board arr[]){
	
	int array_index = 0;
	struct board local_board;
	
	FILE *boardptr = fopen( "boarding_passes.txt", "r");

	while(fread(&local_board, sizeof(struct board), 1, boardptr)){
		
		arr[array_index] = local_board;
		
		array_index++;
	}
	fclose(boardptr);
	
	return array_index;
}

int delete_boarding_pass(struct board e){
	
	struct board local_board;
	
	int local_record_id = 0;
	
	FILE *boardptr = fopen( "boarding_passes.txt", "r");
	
	FILE *temp = fopen("temp_boards.txt", "a+");

	while(fread(&local_board, sizeof(struct board), 1, boardptr)){
		
		if ((local_board.flightid == e.flightid) && (strcmp(local_board.name,e.name)==0) && (local_board.seat_no == e.seat_no))
		{} //empty statement
		else{
			
			fwrite(&local_board, sizeof(struct board), 1, temp);
			
			local_record_id++;
		}
	}
	fclose(boardptr);
	
	fclose(temp);
	
	remove("boarding_passes.txt");
	
	rename("temp_boards.txt", "boarding_passes.txt");
	
	return local_record_id;
}

int booking_function(int date, int month, int year, int i){
	
	//Baggage
	char wchoice[2];
	printf("\n Carrying Luggage? [Y/n] : ");
	scanf("%s", wchoice);
	while ((strcmp(wchoice,"Y") != 0) && (strcmp(wchoice,"n") != 0)){
		printf("Please Choose a Valid Choice 'Y' or 'n' : \n");
		printf(">");
		scanf("%s", wchoice);
	}
	
	int weight;
	if (strcmp(wchoice,"n") == 0) weight=0;
	else{
		printf("\nEnter the Weight of Your Luggage");
		printf("\nIn KGs : ");
		scanf("%d", &weight);
		while(weight<0 || weight>99){
			if (weight<0) printf("Please Enter a Valid Luggage Weight\n");
			else if (weight>99) printf("Hire a Cargo Jet Instead\n");
			printf("\nIn KGs : ");
			scanf("%d", &weight);
		}
	}
	
	char temp_name[15];
	printf("\nEnter the Name of Passenger %d : ", i);
	scanf("%s", temp_name);
	
	char choice[2];
	float temp_price = final_price(date,month,year,weight,from,to,class_num);
	printf("\nThe Price of this ticket is Rs.%.2f\n", temp_price);
	printf("Book Ticket? [Y/n] : ");
	scanf("%s", choice);
	while ((strcmp(choice,"Y") != 0) && (strcmp(choice,"n") != 0)){
		printf("Please Enter a Valid Choice 'Y' or 'n'\n");
		printf("Book Ticket? [Y/n] : ");
		scanf("%s", choice);
	}
	
	if (strcmp(choice,"n") == 0) return 0;
	else if (strcmp(choice,"Y") == 0){
		book_seat(seat_no, class_num, flight_index);
		create_boarding_pass(temp_name,phonnum,from,to, date,month,year,ttime,class_num,seat_no,temp_price);
		return 1;
	}
}