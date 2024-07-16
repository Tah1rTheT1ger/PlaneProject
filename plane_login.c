#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plane_utils.h"


void login(){
	
	int i,flag=1;
	char ch;
	FILE *fptr;
	fptr=fopen("user_data.txt","a+");
	printf("Enter Your Username : ");
	scanf("%s",user_name);
	printf("Enter Your Phone Number : ");
	scanf("%s",phonnum);
	struct user *ptr;
	ptr=(struct user*)malloc(100*(sizeof(struct user)));
	for(i=0;i<100;i++){
		fscanf(fptr,"%s",(ptr+i)->user_id);
		if((strcmp((ptr+i)->user_id,user_name))==0){
			flag=1;
			fscanf(fptr,"%s",(ptr+i)->phone_no);
			if((strcmp((ptr+i)->phone_no,phonnum))==0){
				printf("\nWelcome %s!\n\n", user_name);
				flag=0;
				break;
			}	
		}
	}
	if(flag){
		printf("Not a Registered User, Please Sign Up\n");
		printf("Please Enter Your Desired Username : ");
		scanf("%s",user_name);
		printf("Please Enter Your Phone Number : ");
		scanf("%s",phonnum);
	        strcpy((ptr+i)->phone_no,phonnum);
		strcpy((ptr+i)->user_id,user_name);
		fprintf(fptr,"%s ",(ptr+i)->user_id);
		fprintf(fptr,"%s\n",(ptr+i)->phone_no);
		
		printf("\nThanks For Registering, %s!\n", user_name);
		}
	fclose(fptr);
	return ;
}


void menu(){
	int mode;
	printf("Press 1 for Booking\n Press 2 for Manage\n Press 3 for Complaint\n Press 4 for About\n Press 0 for Exit\n");
	scanf("%d",&mode);
	
	while( mode != 0){
		switch(mode){
			case 1:
				system("cls");
				//book
				book_a_flight();
				break;
			case 2:
				system("cls");
				//manage
				manage_bookings();
				break;
			case 3:
				system("cls");
				//complaint
				book_complaint(user_name, phonnum);
				break;
			case 4:
				system("cls");
				//about
				print_about();
				break;
		}
		if ( mode!=1 && mode!=2 && mode!=3 && mode!=4) printf("\nPlease Enter an Integer from 0 to 4\n");
		printf("\n\n\n========================================================================\n\nPress 1 for Booking\n Press 2 for Manage\n Press 3 for Complaint\n Press 4 for About\n Press 0 for Exit\n");
		printf("\n\nSelect a Mode or Exit : ");
		scanf("%d", &mode);
	}
	return;
}