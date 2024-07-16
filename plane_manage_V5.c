#include <stdio.h>
#include <string.h>
#include "plane_utils.h"

 //here phonenumber is users phonenumber
int sorting(char phoneno[20] ,struct board b){ 
	static int i =0;
	if(strcmp(phoneno,b.phnno)==0){
		//create another structure globally for sorting an custumers bookings and name that as struct board details[100]
		details[i] = b;
		i = i+1;
	}
	//in main we will loop it until the file is over
	return i;	
}  //here i is the length of details array if we always keep track of i so that we know length of details array

//here we have to pass details[i] structure and loop it in main and j is iterator of for loop
void print_details(struct board b,int j){  
	printf("-------------------------------------------------------------------------------------------------------\n");
	printf(" %d | %12s | %s | %s | %d | %02d/%02d/%04d | %s%02d | %8.2f |\n",j,b.name,b.from,b.to,b.ttime,b.date,b.month,b.year,b.class,b.seat_no,b.price);
	
}

void cancel_seat(int seat_no, int class_num, int record_id){
	
	struct plane local_plane;
	
	int local_record_id = 0;
	
	FILE *planeptr = fopen( "planes.txt", "r");
	
	FILE *temp = fopen("temp_planes.txt", "a+");

	while(fread(&local_plane, sizeof(struct plane), 1, planeptr)){
		
		if (local_record_id == record_id){
			
			local_plane.seats_avail[seat_no-1] = 'A';
			
			local_plane.number_of_seats_avail.total_available++;
			
			if (class_num == 1) local_plane.number_of_seats_avail.first_available++;
			else if (class_num == 2) local_plane.number_of_seats_avail.busi_available++;
			else if (class_num == 3) local_plane.number_of_seats_avail.econ_available++;
			
		}
		fwrite(&local_plane, sizeof(struct plane), 1, temp);
		
		local_record_id++;
	}
	fclose(planeptr);
	fclose(temp);
	
	remove("planes.txt");
	
	rename("temp_planes.txt", "planes.txt");

}

//it returns 1 if he needs to append his ticket else it returns 0
int asking_user(){  
	printf("\n\nTo Cancel A Ticket Press 1\nTo Print A Boarding Pass Press 2\nTo Return to Home Press 0\n");
	int n;
	printf(">");
	scanf("%d",&n);
	while (n != 1 && n != 2 && n!= 0){
		printf(">");
		scanf("%d",&n);
	}
	if (n==1){
		return 1;
	}
	else if (n==2){
		return 2;
	}
	else if (n==0){
		return 0;
	}
}

//here n is the boarding pass serial number he needs to delete and i is the length of details array
int delete_pass(int n,int i){  
	int j;
	for(j=n;j<i-1;++j){
		details[j] = details[j+1];
	}
	return i-1;    //here we need to return new array length of details struct array
}

//here we will pass the structure that is to be deleted and j is the length of the array you pass info. to me
int delete_element(struct board b,int len2,struct board e[]){  
	int i,k;
	for(i=0;i<len2;++i){
		if((b.flightid == e[i].flightid) && (strcmp(b.name,e[i].name)==0) && (b.seat_no == e[i].seat_no)){
			break;
		}
	}
	for(k=i;k<len2;++k){
		e[k] = e[k+1];
	}
	return len2-1;
}

void manage_bookings(){
	struct board e[100];
	int len2 = read_boarding_array(e);
	int k,len;

	for(k=0;k<len2;++k){
		len = sorting(phonnum,e[k]);
	}
	for(k=0;k<len;++k){
		print_details(details[k],k+1);
	}
	
	while(1){
		int q = asking_user();
		if(q==1){
			int del;
			printf("Which Seat Do You Want To Cancel? (Enter the Serial Number)\n");
			printf(">");
			scanf("%d",&del);
			
			cancel_seat(details[del-1].seat_no, class_no(details[del-1].class), index_of_flight( details[del-1].flightid));
			delete_boarding_pass(details[del-1]);
			
			len2 = delete_element(details[del-1],len2,e);
			len = delete_pass(del-1,len);
		}
		if(q==2){
			int del2;
			printf("Which Boarding Pass Do You Want To Print? (Enter the Serial Number)\n");
			printf(">");
			scanf("%d",&del2);
			boarding_pass(details[del2-1].name, details[del2-1].from, details[del2-1].to, details[del2-1].date, details[del2-1].month, details[del2-1].year,details[del2-1].class , details[del2-1].seat_no, details[del2-1].ttime);
		}
		if(q==0){
			break;
		}
		
	}
	for(k=0;k<len;++k){
		print_details(details[k],k+1);
	}
	return;
}