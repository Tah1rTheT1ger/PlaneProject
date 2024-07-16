#define EconomyC 46
#define BusinessC 21
#define FirstC 5

//Global Declarations


//User Structure
struct user{
	char user_id[30];
	char phone_no[30];
};

char user_name[20];
char phonnum[20];

//Plane Sub-Structure
struct no_of_avail{
		int total_available;
		int first_available;
		int busi_available;
		int econ_available;
};


//Defining a plane stucture
struct plane{
	long long int flight_id;
	int from;
	int to;
	char seats_avail[EconomyC + BusinessC + FirstC];
	struct no_of_avail number_of_seats_avail;
	int fare;
};

//An array of plane structures.
struct plane all_flights[100];

//int total_flights = 0; //after booking increment

//File pointer for planes
//FILE *planeptr;

//Booking Related
long long int flightid;
int from;
int to;
int class_num;
int seat_no;
int num_of_tickets;
int ttime;
int flight_index;
int timings_list[3];
int available;

//Boarding Related
struct board{
	char name[20];
	char phnno[20];
	char from[20];
	char to[20];
	int ttime;
	int date;
	int month;
	int year;
	char class[20];
	int seat_no;
	float price;
	long long int flightid;
};

//File pointer for boarding Passes
//FILE *boardptr;
//File Pointer for complaints
//FILE *fcomplaints;

//Address to store all boarding passes in the file.
struct board all_boards[1];
//Array of Boarding Pass structures
struct board details[100];



//From Booking
int create_flight(int from, int to, int day, int month, int year, int ttime);

int airport_no(char* a);

int class_no(char* a);

int number_available_seats(int flight_index);

void book_seat(int seat_no, int class_num, int record_id);

void print_timings(int origin, int dest, int a[]);

int check_timings(int in_time, int a[]);

int checking_seating(int seat_no, int enno_class, int flight_index);

int check_flight(long long int flightid);

int index_of_flight(long long int flightid);

void book_a_flight();

//From Dynamic_Price
int month_no(char month[]);

int diff_in_date(int rdate,int rmonth,int ryear);

float dynamic_price(float price,int rdate,int rmonth,int ryear);

float class_price(float base_price, int class);

int IsLeapYear(int year);

int isValidDate(int date,int month,int year);

int timings(int origin, int dest, int a);

float distance_price(int from,int to);

int baggage(int weight, int class);

float final_price(int rdate,int rmonth,int ryear,int weight,int origin,int dest,int class);

//From Login
void login();

void menu();

//From Seating Arrangement
void print_seat_layout(int flight_index);

//From Boarding
void create_boarding_pass(char name[],char phoneno[],int from, int to, int date, int month, int year, int ttime, int class, int seat_no, float price);

int read_boarding_array(struct board arr[]);

int delete_boarding_pass(struct board e);

int booking_function(int date, int month, int year, int i);

//From Manage
int sorting(char phoneno[20],struct board b);

void print_details(struct board b,int j);

int asking_user();

int delete_pass(int n,int i);

int delete_element(struct board b,int len2,struct board e[]);

void manage_bookings();

void cancel_seat(int seat_no, int class_num, int record_id);
//Complaint
int book_complaint(char username[],char phno[]);
//Welcome Message
void welcome_message();
//Boarding Pass
int boarding_pass(char n[30],char from[4],char to[4],int date,int month,int year,char class[1],int seat,int boarding_time);
//About
void print_about();