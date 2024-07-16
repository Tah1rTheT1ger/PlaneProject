#include<stdio.h>
#include<string.h>
#include "plane_utils.h"

int boarding_pass(char n[30],char from[4],char to[4],int date,int month,int year,char class[1],int seat,int boarding_time){
	for(int i=0;i<78;i=i+1){           //to start from new line(outside b.p)
		printf(" ");
	}                              
        for(int i=0;i<81;i=i+1){         //net length of boarding pass=81.(inside)
		printf("_");           
	}
	printf("\n");
	for(int i=0;i<78;i=i+1){          //to start from new line( outside b.p)
		printf(" ");           
	}
        printf("|      __|__                                                |                   |\n");//(inside boarding pass)
	for(int i=0;i<78;i=i+1){            //to start from new line(outside b.p)
		printf(" ");
	} 
        printf("|*---o--(_)--o---*       R.A.C.H.N.A        BOARDING PASS   |    BOARDING PASS  |\n");//(inside)
	for(int i=0;i<78;i=i+1){         //to start from new line(outside b.p)
		printf(" ");
	}        
        printf("|");
	for(int i=0;i<59;i=i+1){          //inside.
		printf("_");
	}
	printf("|");
	for(int i=0;i<19;i=i+1){          //inside
		printf("_");
	}
	printf("|\n");
	for(int i=0;i<78;i=i+1){          //to start from new line(outside b.p)
		printf(" ");
	}
        printf("|   Reservation And Check-in Handling Network of Airlines   |    R.A.C.H.N.A    |\n");//inside
	for(int i=0;i<78;i=i+1){               //to start from new line(outside b.p)
		printf(" ");
	}          
        printf("|");
	for(int i=0;i<59;i=i+1){            //inside
		printf(" ");                      
	}
	if(strlen(n)<=14){                    
	        printf("|NAME:%s",n);
	        for(int i=0;i<(14-strlen(n));i=i+1){       //inside
	        printf(" ");
	        }
	        printf("|\n");
	        for(int i=0;i<78;i=i+1){            //to start from new line(outside b.p)
		        printf(" ");
	        }          
                printf("| NAME:%s",n);
	        for(int i=0;i<(53-strlen(n));i=i+1){     //inside
		        printf(" ");
	        }
		printf("|                   |\n");          //inside
	}
	else if(strlen(n)>14){
	    printf("|NAME:");
	    for(int i=0;i<14;i=i+1){         //inside
		    printf("%c",n[i]);
	    }
	    printf("|\n");
 	    for(int i=0;i<78;i=i+1){                 //to start from new line(outside b.p)
		    printf(" ");
	    }          
            printf("| NAME:%s",n);
	    for(int i=0;i<(53-strlen(n));i=i+1){   //inside
		    printf(" ");
	    }
	    printf("|     ");//inside
	    for(int i=14;i<=(strlen(n));i=i+1){       //inside
		    printf("%c",n[i]);
	    }
	    for(int i=0;i<(14-(strlen(n)-14));i=i+1){         //inside
		printf(" ");
	    }
	    printf("|\n");
	}
	for(int i=0;i<78;i=i+1){    //to start from new line (outside b.p)
		printf(" ");
	}        
        printf("|");
	for(int i=0;i<59;i=i+1){    //inside
		printf(" ");
	}
	printf("|FROM:%s           |\n",from);        //inside
	for(int i=0;i<78;i=i+1){              //to start from new line(otside b.p)
		printf(" ");
	}        
        printf("| FROM:%s                         TO:%s                   |TO:%s             |\n",from,to,to);        //inside
	for(int i=0;i<78;i=i+1){               //to start from new line (outside b.p)
		printf(" ");
	}        
        printf("|                                                           |                   |\n"); //inside
	for(int i=0;i<78;i=i+1){          //to start from new line(outside b.p)
		printf(" ");
	}        
        printf("| FLIGHT:AIR JAGGU                                          |CLASS:%s",class);  //inside
	for(int i=0;i<(13-strlen(class));i=i+1){  //inside
		printf(" ");
	}
	printf("|\n");
	for(int i=0;i<78;i=i+1){         //to start from a new line(outside b.p)
		printf(" ");
	}                
        printf("|                                                           |                   |\n");   //inside
	for(int i=0;i<78;i=i+1){    //to start a new line(outside b.p)
	        printf(" ");
	}        
        printf("| DATE:%02d/%02d/%04d                                           |SEAT:%s%02d           |\n",date,month,year,class,seat);
	for(int i=0;i<78;i=i+1){         //to start a new line(outside b.p)
	        printf(" ");
	} 
        printf("|                                                           |                   |\n");  //inside
	for(int i=0;i<78;i=i+1){          //to start a new line(outside b.p)
	        printf(" ");
	} 
        printf("| CLASS:%s",class);
	for(int i=0;i<27-strlen(class);i=i+1){
		printf(" ");
	}
	printf("SEAT:%s%02d                 |DATE:%02d/%02d/%04d    |\n",class,seat,date,month,year);    
	for(int i=0;i<78;i=i+1){         //to start a new line(outside b.p)
	        printf(" ");
	} 
        printf("|                                                           |                   |\n");
	for(int i=0;i<78;i=i+1){      //to start a new line(outside b.p)
	        printf(" ");
	} 
        printf("|                      BOARDING TIME:%02d:%02d                  |BOARDING TIME:%02d:%02d|\n",(boarding_time/100),(boarding_time%100),(boarding_time/100),(boarding_time%100));
	for(int i=0;i<78;i=i+1){    //to start a new line (outside b.p)
	        printf(" ");
	} 
	printf("|___________________________________________________________|___________________|\n");   //inside
}

/*
int main(){
	char n[30],from[4],to[4],class[12];
	int date,month,year,boardt,seat;
	scanf("%s %s %s %02d %02d %04d %s %02d %04d",n,from,to,&date,&month,&year,class,&seat,&boardt);
	boarding_pass(n,from,to,date,month,year,class,seat,boardt);
}
*/
        
        
        
	
	       
	

		

        
	
        


