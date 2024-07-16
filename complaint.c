#include <stdio.h>
#include<string.h>
#include "plane_utils.h"


int book_complaint(char username[],char phno[]){
	char* arr[5];
	char a[100];
	printf("Choose the Option which you feel about to Complaint:\n");
	printf("==============================================================================================================\n\n");
	printf("1. Flight delays or cancellantions           : If flight system causes delays or cancellatons\n\n");
	printf("2. Inaccurate flight information             : If flight management server info is inaccurate\n\n");
	printf("3. Poor communication                        : If the flight updates are not timely you can book this complaint\n\n");
	printf("4. Uncomfortable or unsafe flight conditions : If you feel our flight is unsafe or uncomfartable choose this\n\n");
	printf("5. Poor customer service                     : Passenger may complaint if hospitality is not good\n\n");

	int n;
	printf(">");
	scanf("%d",&n);
	arr[0] = "Flight delays or cancellantions: If flight system causes delayes or cancellatons\n";
	arr[1] = "Inaccurate flight information: If flight management server info is inaccurate\n";
	arr[2] = "Poor communication : If the flight updates are not timely you can book this complaint\n";
	arr[3] = "Uncomfartable or unsafe flight conditions:If you feel our flight is unsafe or uncomfartable choose this\n";
	arr[4] = "Poor customer service:Passenger may complaint if hospitality is not good\n";

	//we have to open a file and print name and phn number and his complaint and if he chooses option 6 then we will scan and print that string in our file.
	FILE *fcomplaints = fopen("complaints.txt","a");
	if(1 <= n <= 5){
		fprintf(fcomplaints,"%s %s %s\n",username,phno,arr[n-1]);
		}

	fclose(fcomplaints);
	printf("Your complaint is successfully booked! Hope this may not repeat again:)");
	return 0;
}


void print_about(){
	printf("\n\n\nAir Ticket Management System Made In C\n\n\n");
	
	
	printf("R.A.C.H.N.A - Reservation And Check-in Handling for Networks of Airlines\n\n\n");
	
	printf("   Brought to you By:\n\n");
	
	printf("==================================================\n");
	printf("|   The Team - 'Andhra Avengers'                 |\n");
	printf("==================================================\n");
	printf("| IMT2022029 - Metlapalli Ragini                 |\n");
	printf("| IMT2022034 - Kondapalli Srivatsa Tarun         |\n");
	printf("| IMT2022052 - Udayagiri Narayana Srimanth       |\n");
	printf("| IMT2022100 - Khadarabad Tahir Mohammed         |\n");
	printf("| IMT2022545 - Tadikonda Venkata Sai Chaitanya   |\n");
	printf("| IMT2022569 - Veerubhotla Savithru Karthi Keyan |\n");
	printf("==================================================\n");
	
	
	
	
	
	
	
	printf("\n\n\nContribututions Made by Each Team Member : \n");
	printf("========================================================================\n");
	printf("plane_main       - Ragini\n");
	printf("plane_login      - Ragini\n");
	printf("booking_V4       - Tahir, Ragini\n");
	printf("plane_boarding   - Narayana, Tahir, Tarun\n");
	printf("dynamic_price_v2 - Savithru, Chaitanya\n");
	printf("plane_manage_V5  - Narayana, Savithru\n");
	printf("complaint        - Chaitanya, Narayana\n");
	printf("welcome_msg_V2   - Tarun\n");
	printf("seatingarr_V3    - Chaitanya, Tarun\n");
	printf("boarding_pass_V3 - Tarun, Savithru\n");
	printf("plane_utils      - Tahir, Narayana, Tarun, Ragini, Chaitanya, Savithru\n");
	
	return;
}