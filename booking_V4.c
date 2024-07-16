#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "plane_utils.h"



//This function creates a flight with the given information.
int create_flight(int from, int to, int day, int month, int year, int ttime){
	
	all_flights[0].flight_id = ttime + year*10000 + month*100000000 + day*10000000000 + to*1000000000000 + from*10000000000000;
	all_flights[0].from = from;
	all_flights[0].to = to;
	for (int i=0; i < (FirstC + BusinessC + EconomyC); i++)
		all_flights[0].seats_avail[i] = 'A';
	
	all_flights[0].number_of_seats_avail.total_available = EconomyC + BusinessC + FirstC;
	all_flights[0].number_of_seats_avail.first_available = FirstC;
	all_flights[0].number_of_seats_avail.busi_available = BusinessC;
	all_flights[0].number_of_seats_avail.econ_available = EconomyC;
	
	
	//total_flights++;
	
	FILE *planeptr = fopen ("planes.txt", "a+");
	fwrite (&all_flights[0], sizeof(struct plane), 1, planeptr);
	
	
	fclose (planeptr);
}



//This function returns 1 for DEL, 2 for BOM, 3 for CHE(MAA), 4 for BLR, 5 for KOL(CCU), -1 otherwise.
int airport_no(char a[]){
	if (strcmp(a, "DEL")==0) return 1;
	else if (strcmp(a, "BOM")==0) return 2;
	else if (strcmp(a, "MAA")==0) return 3;
	else if (strcmp(a, "BLR")==0) return 4;
	else if (strcmp(a, "CCU")==0) return 5;
	else return -1;
}

//This function returns 1 for E, 2 for B, 3 for F, -1 otherwise.
int class_no(char a[]){
	if (strcmp(a, "E")==0) return 3;
	else if (strcmp(a, "B")==0) return 2;
	else if (strcmp(a, "F")==0) return 1;
	else return -1;
}



//This function prints the seats available classwise, and returns total available seats.
int number_available_seats(int flight_index){
	
	struct plane local_plane;
	int local_record_id = 0;
	
	FILE *planeptr = fopen( "planes.txt", "r");
	
	while(fread(&local_plane, sizeof(struct plane), 1, planeptr)){
		
		if (local_record_id == flight_index){
			
			fclose(planeptr);
			
			printf("\nSeats Available in First Class    : %d\n", local_plane.number_of_seats_avail.first_available);
			printf("Seats Available in Business Class : %d\n", local_plane.number_of_seats_avail.busi_available);
			printf("Seats Available in Economy        : %d\n", local_plane.number_of_seats_avail.econ_available);
			printf("======================================\n");
			printf("Total Seats Available             : %d\n", local_plane.number_of_seats_avail.total_available);
		}
	
	local_record_id++;
	}
	return local_plane.number_of_seats_avail.total_available;
}

//This function books a seat in the seat number in the specified class, for a given flight index.
void book_seat(int seat_no, int class_num, int record_id){
	
	struct plane local_plane;
	
	int local_record_id = 0;
	
	FILE *planeptr = fopen( "planes.txt", "r");
	
	FILE *temp = fopen("temp_planes.txt", "a+");

	while(fread(&local_plane, sizeof(struct plane), 1, planeptr)){
		
		if (local_record_id == record_id){
			
			local_plane.seats_avail[seat_no-1] = 'O';
			
			local_plane.number_of_seats_avail.total_available--;
			
			if (class_num == 1) local_plane.number_of_seats_avail.first_available--;
			else if (class_num == 2) local_plane.number_of_seats_avail.busi_available--;
			else if (class_num == 3) local_plane.number_of_seats_avail.econ_available--;
			
		}
		fwrite(&local_plane, sizeof(struct plane), 1, temp);
		
		local_record_id++;
	}
	fclose(planeptr);
	fclose(temp);
	
	remove("planes.txt");
	
	rename("temp_planes.txt", "planes.txt");

}


//This function prints the timings of flights scheduled.
void print_timings(int origin, int dest, int a[]){
		if((origin == 1 && dest == 2) || (origin == 2 && dest == 3) || (origin == 3 && dest == 4) || (origin == 4 && dest == 5) || (origin == 5 && dest ==3)){
			a[0] = 900;
			a[1] = 1500;
			a[2] = 1700;
		}
		else if((origin == 1 && dest == 3) || (origin == 2 && dest == 4) || (origin == 3 && dest == 1) || (origin == 4 && dest == 2) || (origin == 5 && dest ==4)){
			a[0] = 800;
			a[1] = 1600;
			a[2] = 2100;
		}
		else if((origin == 1 && dest == 4) || (origin == 2 && dest == 5) || (origin == 3 && dest == 5) || (origin == 4 && dest == 1) || (origin == 5 && dest ==2)){
			a[0] = 700;
			a[1] = 1230;
			a[2] = 2000;
		}
		else if((origin == 1 && dest == 5) || (origin == 2 && dest == 1) || (origin == 3 && dest == 2) || (origin == 4 && dest == 3) || (origin == 5 && dest ==1)){
			a[0] = 1000;
			a[1] = 1700;
			a[2] = 2300;
		}
		printf("\n%04d     %04d     %04d\n", a[0], a[1], a[2]);
		return;
}

//This function returns 1 if at the time entered a flight is scheduled, 0 if not.
int check_timings(int in_time, int a[]){
	return (in_time == a[0] || in_time == a[1] || in_time == a[2]);
}

//This function returns 1 if the seat is bookable, -1 if the seat number doesn't exist, -2 if the chosen seat is already booked.
int checking_seating(int seat_no, int enno_class, int flight_index){
	
	int local_flight_index = 0;
	struct plane local_plane;
	
	FILE *planeptr = fopen( "planes.txt", "r");

	while(fread(&local_plane, sizeof(struct plane), 1, planeptr)){
	
		if (local_flight_index == flight_index){
			
			fclose(planeptr);
			
			if(enno_class == 1){
				if((seat_no < 1) || (seat_no > FirstC)) return(-1);
				else if ((enno_class == 1) && (local_plane.seats_avail[seat_no-1] == 'O')) return (-2);
				else if ((enno_class == 1) && (local_plane.seats_avail[seat_no-1] == 'A')) return 1;
			}
			else if(enno_class == 2){
				if((seat_no < (FirstC + 1 )) || (seat_no > (FirstC + BusinessC))) return(-1);
				else if ((enno_class == 2) && (local_plane.seats_avail[seat_no-1] == 'O')) return (-2);
				else if ((enno_class == 2) && (local_plane.seats_avail[seat_no-1] == 'A')) return 1;
			}
			else if(enno_class == 3){
				if((seat_no < (FirstC + BusinessC + 1)) || (seat_no > (FirstC + BusinessC + EconomyC))) return(-1);
				else if ((enno_class == 3) && (local_plane.seats_avail[seat_no-1] == 'O')) return (-2);
				else if ((enno_class == 3) && (local_plane.seats_avail[seat_no-1] == 'A')) return 1;
			}
		}
		local_flight_index++;
	}
}


int check_flight(long long int flightid){ //This function returns -1 if a flight isn't already in the file, returns 1 if it is.

	
	struct plane local_plane;
	
	FILE *planeptr = fopen( "planes.txt", "r");

	while(fread(&local_plane, sizeof(struct plane), 1, planeptr)){
		
		//printf("Flight ID passed %lld Flight ID from record %lld \n",flightid, local_plane.flight_id);
		
		if (local_plane.flight_id == flightid){
			fclose(planeptr);
			return 1;
		}
		
	}
	fclose(planeptr);
	
	return -1;
}


int index_of_flight(long long int flightid){ //This function returns the index of the flight with given ID in the array.
	
	int record_index = 0;
	struct plane local_plane;
	
	FILE *planeptr = fopen( "planes.txt", "r");

	while(fread(&local_plane, sizeof(struct plane), 1, planeptr)){
		
		//printf("Flight ID passed %lld Flight ID from record %lld \n",flightid, local_plane.flight_id);
		
		if (local_plane.flight_id == flightid){
			fclose(planeptr);
			return record_index;
		}
		record_index++;
	}
	fclose(planeptr);
	
	return -1;
}




void book_a_flight(){


	//Airports in service.
	printf("\nR.A.C.H.N.A provides services to the following airports currently:\n");
	printf("Delhi(DEL) Bombay(BOM) Madras(MAA) Bangalore(BLR) Calcutta(CUU)\n");
	
	//Departure Input.
	char from_char[5];
	printf("\nEnter the Desired Departure Airport Code");
	printf("\nDeparture : ");
	scanf("%s", from_char);
	from = airport_no(from_char);
	while (from<0){
		printf("Please Enter a Valid Departure Airport Code\n");
		printf("Departure : ");
		scanf("%s", from_char);
		from = airport_no(from_char);
	}
	
	//Destination Input.
	char to_char[5];
	printf("\nEnter the Desired Destination Airport Code");
	printf("\nDestination : ");
	scanf("%s", to_char);
	to = airport_no(to_char);
	while (to<0){
		printf("Please Enter a Destination Valid Airport Code\n");
		printf("Destination : ");
		scanf("%s", to_char);
		to = airport_no(to_char);
	}
	
	//Input Date and validity
	int date,year,month;
	printf("\nEnter the Date in the Format dd/mm/yyyy : ");
	scanf("%d/%d/%d",&date,&month,&year);
	while(isValidDate(date,month,year) == 0){   //Checking the validity of the date.
		printf("Please Enter a Valid Date in the Format dd/mm/yyyy : ");
		scanf("%d/%d/%d",&date,&month,&year);
	}
	
	//Print the timings for the flight.
	printf("\nFlights from %3s to %3s on %d/%d/%d are scheduled at the following times : ", from_char, to_char, date, month, year);
	print_timings(from,to,timings_list);
	
	//Take the timing input.
	printf("\nEnter the Timing of Departure : ");
	scanf("%d" ,&ttime);
	while(check_timings(ttime, timings_list) == 0){
		printf("Please Enter a Valid Timing of Departure : ");
		scanf("%d" ,&ttime);
	}
	
	//Make the flight ID.
	flightid = ttime + year*10000 + month*100000000 + date*10000000000 + to*1000000000000 + from*10000000000000;
	
	//If the flight doesn't exist, create it.
	if (check_flight(flightid) < 0){
		create_flight(from, to, date, month, year, ttime);
	}
	
	//Find the flight in the array.
	flight_index = index_of_flight(flightid);
	
	//Print the current layout.
	print_seat_layout(flight_index);
	
	available = number_available_seats(flight_index);
	
	//Number of tickets
	printf("\nNumber of Tickets Required : ");
	scanf("%d", &num_of_tickets);
		while(num_of_tickets<1 || num_of_tickets > available){
			if (num_of_tickets<1 || num_of_tickets > (EconomyC+BusinessC+FirstC)) printf("Please Enter a Valid Number of Tickets");
			else if (available == 0){
				num_of_tickets = 0;
				break;
			}
			else if (num_of_tickets>available) printf("%d seats are currently unavailable", num_of_tickets);
			printf("\nNumber of Tickets : ");
			scanf("%d", &num_of_tickets);
		}
	
		
	//Which Seats?
	char class[2];
	for (int i=1; i<=num_of_tickets; i++){
		printf("\nEnter the Class for Passenger %d : ", i);
		scanf("%s", class);
		class_num = class_no(class); 
		while(class_num<0){
			printf("Enter a Valid Class for Passenger %d : ", i);
			scanf("%s", class);
			class_num = class_no(class);
		}
		
		printf("\nEnter Seat Number for Passenger %d : ", i);
		scanf("%d", &seat_no);
		
		//printf("\n SeatNo: %d  ClassNo: %d  FlightIndex: %d  \n", seat_no, class_num, flight_index);
		//printf("\nSeat Status : %d\n", checking_seating(seat_no, class_num, flight_index));
		
		while(checking_seating(seat_no, class_num, flight_index)<0){
			if (checking_seating(seat_no, class_num, flight_index) == -1) printf("Please Enter a Valid Seat Number\n");
			else if (checking_seating(seat_no, class_num, flight_index) == -2) printf("Seat %s%d has already been booked\n", class, seat_no);
			printf("Enter Seat Number for Passenger %d : ", i);
			scanf("%d", &seat_no);
		}
		
		if (checking_seating(seat_no, class_num, flight_index)){
			if (booking_function(date, month, year, i)) printf("Seat %s%02d Booked\n", class, seat_no);
			else{ 
				printf("Seat %s%02d NOT Booked\n", class, seat_no);
				i--;
			}
		}
	}
	return;
}



//int main(){
	
	//book_a_flight();
	
	/*
	create_flight(1, 2, 31, 1, 2004, 1930);
	create_flight(1, 3, 12, 5, 2005, 1820);
	create_flight(3, 1, 14, 4, 2004, 800);
	create_flight(4, 2, 16, 7, 2004, 1200);
	
	
	long long int flightid = 800 + 2004*10000 + 4*100000000 + 14*10000000000 + 1*1000000000000 + 3*10000000000000;
	
	int x = index_of_flight(flightid);
	
	book_seat(4, 1, 2);
	book_seat(5, 1, 2);
	book_seat(17, 2, 2);
	book_seat(19, 2, 2);
	book_seat(54, 3, 2);
	book_seat(56, 3, 2);
	
	number_available_seats(2);
	
	int y = checking_seating(27, 2, 2);
	
	printf("record id : %d \n", x);
	printf("value of y: %d \n", y);
	*/
//}