#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "plane_utils.h"

int month_no(char month[]){
	int n;
	if (month[0] == 'J' && month[1] == 'a' && month[2] == 'n')
		n = 1;
	else if (month[0] == 'F' && month[1] == 'e' && month[2] == 'b')
		n = 2;
	else if (month[0] == 'M' && month[1] == 'a' && month[2] == 'r')
		n = 3;
	else if (month[0] == 'A' && month[1] == 'p' && month[2] == 'r')
		n = 4;
	else if (month[0] == 'M' && month[1] == 'a' && month[2] == 'y')
		n = 5;
	else if (month[0] == 'J' && month[1] == 'u' && month[2] == 'n')
		n = 6;
	else if (month[0] == 'J' && month[1] == 'u' && month[2] == 'l')
		n = 7;
	else if (month[0] == 'A' && month[1] == 'u' && month[2] == 'g')
		n = 8;
	else if (month[0] == 'S' && month[1] == 'e' && month[2] == 'p')
		n = 9;
	else if (month[0] == 'O' && month[1] == 'c' && month[2] == 't')
		n = 10;
	else if (month[0] == 'N' && month[1] == 'o' && month[2] == 'v')
		n = 11;
	else if (month[0] == 'D' && month[1] == 'e' && month[2] == 'c')
		n = 12;
	return n;
}
int diff_in_date(int rdate,int rmonth,int ryear){
    time_t t = time(NULL);
    int date1;
    int a,b;
    int c,d,e,f,year1;
    char month[3];
    struct tm *current_time = localtime(&t);
    char *tttime = asctime(current_time);
    month[0] = *(tttime+4);
    month[1] = *(tttime+5);
    month[2] = *(tttime+6);
    a = (*(tttime+8)-48);
    b = (*(tttime+9)-48);
    date1 = 10*a + b;
    int month1 = month_no(month);
    c = (*(tttime+20)-48);
    d = (*(tttime+21)-48);
    e = (*(tttime+22)-48);
    f = (*(tttime+23)-48);
    year1 = 1000*c + 100*d + 10*e + f;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days = 0;
    while (date1 != rdate || month1 != rmonth|| year1 != ryear) {
        total_days++;
        date1++;
        if (date1 > days_in_month[month1 - 1]) {
            date1 = 1;
            month1++;
        }
	if (month1 > 12) {
            month1 = 1;
            year1++;
        }
    }
    return total_days;
}
float dynamic_price(float price,int rdate,int rmonth,int ryear){
	int a;
	a = diff_in_date(rdate,rmonth,ryear);
	if(a<=5)
		price = price*(1.25);
	else if(a>5 && a<=20)
		price = price*(1.20);
	else if(a>20 && a<=30)
		price = price*(1.10);
	return(price);
}

float class_price(float base_price, int class){
	float price;
	if(class == 2)
		price = 4*base_price; 
	else if(class == 1)
		price = 6*base_price;
	else if(class == 3)
		price = base_price;
	return price;
}


//This function returns 0 if it's not a leap year, 1 if it is.
int IsLeapYear(int year){
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}


//This function returns 0 if the entered date is invalid, 1 if it is.
int isValidDate(int date,int month,int year)
{
    //check range of year,month and day
    if (year > 9999 || year < 2023)
        return 0;
    if (month < 1 || month > 12)
        return 0;
    if (date < 1 || date > 31)
        return 0;
    if (month == 2)
    {
        if (IsLeapYear(year))
            return (date <= 29);
        else
            return (date <= 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (date <= 30);
    return 1;
}

int timings(int origin, int dest, int a){
	if((origin == 1 && dest == 2) || (origin == 2 && dest == 3) || (origin == 3 && dest == 4) || (origin == 4 && dest == 5), (origin == 5 && dest ==3)){
		if(a == 900 || a==1500 || a == 1700)
			return(1);
		else
			return(-1);
	}
        if((origin == 1 && dest == 3) || (origin == 2 && dest == 4) || (origin == 3 && dest == 1) || (origin == 4 && dest == 2), (origin == 5 && dest ==4)){
                if(a == 800 || a==1600 || a == 2100)
                        return(1);
                else
                        return(-1);
                        }
	if((origin == 1 && dest == 4) || (origin == 2 && dest == 5) || (origin == 3 && dest == 5) || (origin == 4 && dest == 1), (origin == 5 && dest ==2)){
                if(a == 700 || a==1230 || a == 2000)
                        return(1);
                else
                        return(-1);
                        }
        if((origin == 1 && dest == 5) || (origin == 2 && dest == 1) || (origin == 3 && dest == 2) || (origin == 4 && dest == 3), (origin == 5 && dest ==1)){
                if(a == 1000 || a==17000 || a == 2300)
                        return(1);
                else
                        return(-1);
                        }
}



float distance_price(int from,int to){
	float price;
	if ((from == 1 && to == 2)||(from == 2 && to == 1)) price= 7000;
	else if ((from == 1 && to == 3) || (from==3 && to ==1)) price = 9000;
	else if ((from == 1 && to == 4) || (from==4 && to ==1)) price = 9500;
	else if ((from == 1 && to == 5) || (from==5 && to ==1)) price = 10000;
	else if ((from == 2 && to == 3) || (from==3 && to ==2)) price = 4500;
	else if ((from == 2 && to == 4) || (from==4 && to ==2)) price = 5000;
	else if ((from == 2 && to == 5) || (from==5 && to ==2)) price = 11000;
	else if ((from == 3 && to == 4) || (from==4 && to ==3)) price = 3000;
	else if ((from == 3 && to == 5) || (from==5 && to ==3)) price = 11000;
	else if ((from == 4 && to == 5) || (from==5 && to ==4)) price = 11200;
	return price;
}

int baggage(int weight, int class){
	int base_weight;
	if (class == 1) base_weight = 20;
	else if (class == 2) base_weight = 10;
	else if (class == 3) base_weight = 5;
	
    if (weight <= base_weight) return 0;
    else return (600*(weight-base_weight));
}	

float final_price(int rdate,int rmonth,int ryear,int weight,int origin,int dest,int class){
	float price = 0;
	//printf("\nInside Final Price:  date: %d ,month: %d ,year: %d, weight: %d, from: %d, to: %d, class: %d\n", rdate, rmonth, ryear, weight, origin, dest, class);
	price = distance_price(origin,dest);
	price = dynamic_price(price,rdate,rmonth,ryear);
	price = price + baggage(weight,class);
	price = class_price(price,class);
	//printf("\n Inside Price: %f", price);
	return price;
}

/*
int main(){
	float price = final_price(12,05,2023,5,4,1,4,1);
	printf("%f",price);
	return 0;
}
*/




