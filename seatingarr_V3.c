#include<stdio.h>
#include "plane_utils.h"
	
void print_seat_layout(int flight_index){
	
	int local_flight_index = 0;
	struct plane local_plane;
	
	char s[73];
	
	FILE *planeptr = fopen( "planes.txt", "r");
	while(fread(&local_plane, sizeof(struct plane), 1, planeptr)){
		
		if (local_flight_index == flight_index){
			for (int g=0; g<72; g++){
				s[g] = local_plane.seats_avail[g];
			}
		}
		local_flight_index++;
	}
	fclose(planeptr);

	
	
	for(int i=0;i<238;i=i+1){
		printf("_");
	}
	printf("\n\n");
	for(int i=0;i<115;i=i+1){
		printf(" ");
	}
	printf("FIRST CLASS\n\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   __________________                                  |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   %c01              |                                  |\n",s[0]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                    |             __________________   |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                    |             |              %c04   |\n",s[3]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                    |             |                    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   __________________             |                    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   %c02              |             |                    |\n",s[1]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                    |             __________________   |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                    |             |              %c05   |\n",s[4]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                    |             |                    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   __________________             |                    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   %c03              |             |                    |\n",s[2]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                    |             __________________   |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                    |                                  |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                    |                                  |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   __________________                                  |\n\n");
	for(int i=0;i<115;i=i+1){
		printf(" ");
	}
	printf("BUSINESS\n\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |   \\_____...|   |..._____/  |   |..._____/   |    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |_________%c06|   |%c07________|   |_________%c08|    |\n",s[5],s[6],s[7]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |   \\_____...|   |..._____/  |   |..._____/   |    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |_________%c09|   |%c10________|   |_________%c11|    |\n",s[8],s[9],s[10]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |   \\_____...|   |..._____/  |   |..._____/   |    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |_________%c12|   |%c13________|   |_________%c14|    |\n",s[11],s[12],s[13]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |   \\_____...|   |..._____/  |   |..._____/   |    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |_________%c15|   |%c16________|   |_________%c17|    |\n",s[14],s[15],s[16]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |   \\_____...|   |..._____/  |   |..._____/   |    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |_________%c18|   |%c19________|   |_________%c20|    |\n",s[17],s[18],s[19]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |   \\_____...|   |..._____/  |   |..._____/   |    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |_________%c21|   |%c22________|   |_________%c23|    |\n",s[20],s[21],s[22]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |   \\_____...|   |..._____/  |   |..._____/   |    |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|    |_________%c24|   |%c25________|   |_________%c26|    |\n\n",s[23],s[24],s[25]);
	for(int i=0;i<115;i=i+1){
		printf(" ");
	}
	printf("ECONOMY\n\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   _____%c27 %c28_____ %c29  %c30  %c31 _____%c32 %c33_____   |\n",s[26],s[27],s[28],s[29],s[30],s[31],s[32]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                   _____ _____ _____                   |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   _____%c34 %c35_____ %c36  %c37  %c38 _____%c39 %c40_____   |\n",s[33],s[34],s[35],s[36],s[37],s[38],s[39]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                   _____ _____ _____                   |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   _____%c41 %c42_____ %c43  %c44  %c45 _____%c46 %c47_____   |\n",s[40],s[41],s[42],s[43],s[44],s[45],s[46]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                   _____ _____ _____                   |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   _____%c48 %c49_____ %c50  %c51  %c52 _____%c53 %c54_____   |\n",s[47],s[48],s[49],s[50],s[51],s[52],s[53]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                   _____ _____ _____                   |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   _____%c55 %c56_____ %c57  %c58  %c59 _____%c60 %c61_____   |\n",s[54],s[55],s[56],s[57],s[58],s[59],s[60]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                   _____ _____ _____                   |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|   _____%c62 %c63_____ %c64  %c65  %c66 _____%c67 %c68_____   |\n",s[61],s[62],s[63],s[64],s[65],s[66],s[67]);
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
	printf("|                   _____ _____ _____                   |\n");
	for(int i=0;i<90;i=i+1){
		printf(" ");
	}
        printf("|   _____%c69 %c70_____               _____%c71 %c72_____   |\n\n",s[68],s[69],s[70],s[71]);
	for(int i=0;i<238;i=i+1){
		printf("_");
	}
	
	return;
}
	
