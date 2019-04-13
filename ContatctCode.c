#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
#include <windows.h>


// creating a structure which will be using for taking data
typedef struct contatct_details{
	char name[20];
	char ph[10];
} contdetail;


struct security{
	char auth_id[20];
	char user_name[20];
	char user_id[20];
	char password[20];
};


char user[20]= "0";
char username[20]= "0";
int adminacess= 0;

void intro();
void menu();
void creat_new();
void list_cont();
void update_cont();
void del_cont();
void search_cont();


void auth();
void admin();
void show_users();
void create_user();
void delete_user();
void modify_user();


void main(){
	system("cls");
	
	intro();
	
	auth();
}

//intro screen
void intro(){
	SetConsoleTitle("Contatct Program @ Introduction");
	system("color f5");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 438, 239, 490, 290, TRUE);
	printf("=======================================================||\n");
	printf("=======================================================||\n");
	printf("||                                                     ||\n");
	printf("||    University of Engineering & Management Kolkata   ||\n");
	printf("||    Year: First     Semester: 2nd      Section: D2   ||\n");
	printf("||    ----------------------------------------------   ||\n");
	printf("||    Name: Sayor Chatterjee             RollNo.: 40   ||\n");
	printf("||    Name: Somdeep Jana                 RollNo.: 41   ||\n");
	printf("||    Name: Uttam Devnath                RollNo.: 42   ||\n");
	printf("||                                                     ||\n");
	printf("||=======================================================\n");
	printf("||=======================================================\n");
	printf("\n\n Please Enter any Key to Continue......");
	getch();
	
}

//option screen
void menu(){
	SetConsoleTitle("Contatct Program @ Menu");
	system("cls");
	system("color e0");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 445.5, 264, 540, 270, TRUE);
    fflush(stdin);
    printf("                                        Welcome %s", username);
    printf("\n                                        UserId: %s", user);
	printf("\n\n\n         ----- Mobile Contact List Demonstration -----    \n\n");
	//displaying the options
	printf("     1. Create Contatct                  2. All   Contatcts\n");
	printf("     3. Search Contatct                  4. Delete Contatct\n");
	printf("     5. Update Contatct                  6. Exit\n");
	if(adminacess== 1){
		printf("     7. Goto Admin Panel\n");
	}
	printf("     ------------------------------------------------------\n\n");
	printf("     Please Choose a option.......");
	
	//depending upon the options the actions will be taken
	for(;;){
		switch(getch()){
			case '1':
				creat_new();
				break;
			case '2':
				list_cont();
				break;
			case '3':
				search_cont();
				break;
			case '4':
				del_cont();
				break;
			case '5':
				update_cont();
				break;
			case '6':{
				system("cls");
				system("color f0");
				HWND wh = GetConsoleWindow();
    			MoveWindow(wh, 445.5, 264, 470, 210, TRUE);
				printf("\n\n\n\n                Closing Contatcts.......");
				int c, d;
				for (c = 1; c <= 32767; c++){
					for (d = 1; d <= 32767; d++){
					}
				}
				exit(0);
				break;
			}
			case '7':
				if(adminacess==1){
					admin();
				}else{
					goto lable0o0;
				}
			default:
lable0o0:
				system("cls");
				printf("                                        Welcome %s", username);
    			printf("\n                                        UserId: %s", user);
				printf("\n\n\n        ----- Mobile Contact List Demonstration -----    \n\n");
				//displaying the options
				printf("    1. Create Contatct                  2. All   Contatcts\n");
				printf("    3. Search Contatct                  4. Delete Contatct\n");
				printf("    5. Update Contatct                  6. Exit\n");
				if(adminacess== 1){
					printf("    7. Goto Admin Panel\n");
				}
				printf("    ------------------------------------------------------\n\n");
				printf("    Wrong Option, Try again.......");
		}
	}
	
}

//for creating new contatct
void creat_new(){
lable0:
	SetConsoleTitle("Contatct Program @ Create New Contatct");
	system("cls");
	system("color b0");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 448, 234, 470, 300, TRUE);
    fflush(stdin);
	FILE *data;
	contdetail enter, cheack;
	data=fopen(user,"ab+");
	printf("\n\n           ----- Creating New Contatct -----          \n\n");
	if(data==NULL){
		printf("Cannot Open The file Please try again after exit.......");
		exit(1);
	}
	printf("   Enter Name    : ");
    gets(enter.name);
    fflush(stdin);
    while(fread(&cheack, sizeof(cheack), 1, data)==1){
		if(strcmp(cheack.name, enter.name)==0){
			printf("   PhoneNo.      : %s\n\n", cheack.ph);
			printf("   Contatct Already Present...........");
			printf("\n\n                ----------------------\n");
			goto lable0o1;
		}
	}
    printf("   Enter PhoneNo.: ");
    gets(enter.ph);
    fflush(stdin);
    fwrite(&enter,sizeof(enter),1,data);
    printf("\n               -----Contatct Saved -----              \n\n");
lable0o1:
    fclose(data);
	printf("\nPress enter to Creat Another Contatct or any Other Key to goBack.....");
	if(getch()=='\r'){
		goto lable0;
	}else {
		menu();	
	}
    getch();
    menu();
}

//for printing the contatct list
void list_cont(){
	SetConsoleTitle("Contatct Program @ All Contatcts");
	system("cls");
	system("color 30");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 478, 194, 430, 380, TRUE);
    fflush(stdin);
	FILE *data;
	contdetail list;
	data=fopen(user,"rb");
	if(data==NULL){
		printf("Cannot Open The file Please try again after exit.......");
		exit(2);
	}
	printf("\n\n       ----- Listing all Contatcts -----\n\n");
	printf("   No.	| Number	| Name		\n");
	printf(" -------+---------------+------------------------\n");
	int no= 1;
	while(fread(&list,sizeof(list),1,data)==1){
		printf("   %d	| %s	| %s	\n", no, list.ph, list.name);
		printf(" -------+---------------+------------------------\n");

    	no++;
	}
	printf("\n            ----- Complete -----\n\n");
	fclose(data);
	printf("\nEnter any key to Goback......");
    getch();
    menu();
}

//for updating the existing contatct
void update_cont(){
lable1:
	SetConsoleTitle("Contatct Program @ Update Contatct");
	system("cls");
	system("color f0");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 448, 184, 470, 400, TRUE);
    fflush(stdin);
	contdetail cont;
	char username[20], option;
	int update_stat= 0;
	FILE *data, *temp;
	data= fopen(user, "rb+");
	temp= fopen("temp", "wb+");
	if(auth== NULL && temp== NULL){
		printf("\n\nError Openning The security press any key to close and try again.......");
		getch();
		exit(3);
	}
	printf("\n\n            ----- Updating Contatct -----\n\n");
	
	printf("    Enter Name: ");
	gets(username);
	fflush(stdin);
	while(fread(&cont, sizeof(cont), 1, data)==1){
		if(strcmp(cont.name, username)!= 0){
			fwrite(&cont, sizeof(cont), 1, temp);
		}
		if(strcmp(cont.name, username)== 0){
			printf("\n               ----- Previous Data -----\n\n");
			printf("  Name    : %s\n", cont.name);
			printf("  Number  : %s", cont.ph);
			printf("\n\n                ----------------------\n");
lable1o1:
			printf("  Update This Contatct[Y/N]: ");
			option= getch();
			if(option== 'y' || option== 'Y'){
				printf("\n\n  Enter Name   : ");
				gets(cont.name);
				fflush(stdin);
				printf("  Enter Number : ");
				gets(cont.ph);
				fflush(stdin);
				fwrite(&cont, sizeof(cont), 1, temp);
				update_stat= 1;
			}else if(option== 'n' || option== 'N'){
				fclose(data);
				fclose(temp);
				goto lable1o2;	
			}else{
				printf("\nWrong entry try again.......\n");
				goto lable1o1;
			}
		}
	}
	fclose(data);
	fclose(temp);
	if(update_stat== 1){
		remove(user);
		rename("temp", user);
		printf("\n\n           ----- Contatct Updated -----");
	}else{
		printf("\n\n           ----- Contatct Not Found -----");
lable1o2:
		remove("temp");
	}
	printf("\n\nPress Enter to Try Again or any Other Key to goBack.....");
	if(getch()=='\r'){
		goto lable1;
	}else {
		menu();	
	}	
}

//for deleting a contatct
void del_cont(){
lable2:
	SetConsoleTitle("Contatct Program @ Delete Contatct");
	system("cls");
	system("color c0");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 448, 184, 470, 400, TRUE);
    fflush(stdin);
	char name[20], option;
	contdetail cont;// in cont structure the date from the binary file "cotatct_data" will be stored
	FILE *data, *temp;
	int del_stat= 0;
	printf("\n\n             ----- Deleting Contatct -----            \n\n");
	
	data= fopen(user,"rb+");//opening the "cotatct_data" binary file
	if(data==NULL){
		printf("Cannot Open The file Please try again after exit.......");
		exit(4);
	}else {
		temp= fopen("temp", "wb+");// opening a temporary named "temp" file
		if(temp== NULL){
			printf("Cannot Open The file Please try again after exit.......");
			exit(5);
		}else {
			printf("Enter the Name to Delet: ");
			gets(name);// taking the desired person name
			fflush(stdin);
			while(fread(&cont,sizeof(cont),1,data)==1){// reading the data from the file and storing it into the cont structure
				if(strcmp(cont.name,name)!=0){// checking which data name are not maching with the desire name
					fwrite(&cont,sizeof(cont),1,temp);// transfaring the data which is not maching with the desire name into another file "temp"
				}
				if(strcmp(cont.name,name)==0){
					printf("\n                  ----- User Data -----                 \n\n");
					printf("Name	: %s\n", cont.name);
					printf("PhoneNo.: %s\n", cont.ph);
					printf("\n             ----------------------------\n\n");
lable2o1:
					printf("Delete this Contatct[Y/N]: ");
					option= getch();
					if(option== 'y' || option== 'Y'){
						goto lable2o2;
					}else if(option== 'n' || option== 'N'){
						fclose(data);
						fclose(temp);
						goto lable2o3;
					}else{
						printf("\nWrong entry try again.......\n");
						goto lable2o1;
					}
lable2o2:
					del_stat=1;// this will indicate whether any change is made or not
				}
			}
			fclose(data);
			fclose(temp);
			if(del_stat== 1){
				remove(user);
				rename("temp", user);// changing the "temp.txt" file into primary file named "cotatct_data"
				printf("\n\n           ----- Successfully Deleted -----           \n\n");
				printf("\nPress enter to Delete Another Contatct or any Other Key to goBack.....");
				if(getch()=='\r'){
					goto lable2;
				}else {
					menu();	
				}
			}else {
				printf("\nNo Contatct Found With the Name........\n");
lable2o3:
				remove("temp");// this will delete the temp file and make no change to the primary data file
				printf("\nPress Enter to Try Again or any Other Key to goBack.....");
				if(getch()=='\r'){
					goto lable2;
				}else {
					menu();	
				}
			}
		}
	}
}

//for searching contatct
void search_cont(){
lable3:
	SetConsoleTitle("Contatct Program @ Search Contatct");
	system("cls");
	system("color 60");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 448, 256.5, 470, 255, TRUE);
    fflush(stdin);
	contdetail cont;
	FILE *data;
	char name[20];
	int search_stat= 0;
	data= fopen(user,"rb+");
	printf("\n\n            ----- Searching Contatct -----            \n\n");
	
	if(data==NULL){
		printf("Cannot Open The file Please try again after exit.......");
		exit(3);
	}
	printf("Enter the Name to Search: ");
	gets(name);
	fflush(stdin);
	while(fread(&cont, sizeof(cont), 1, data)==1){
		if(strcmp(cont.name, name)==0){
			printf("PhoneNo.                : %s", cont.ph);
			search_stat= 1;
		}
	}
	fclose(data);
	if(search_stat== 1){
		printf("\n\n          ----- Successfully Searched -----           \n\n");
		printf("Press enter to Search Another Contatct or any Other Key to goBack.....");
		if(getch()=='\r'){
			goto lable3;	
		}else {
			menu();
		}
	
	}else {
		printf("\n\nNo Contatct Found With the Name........\n");
		printf("\nPress Enter to Try Again or any Other Key to goBack.....");
		if(getch()=='\r'){
			goto lable3;
		}else {
			menu();	
		}
	}
}

//for authacation purpos
void auth(){
lable3o1:
	system("cls");
	SetConsoleTitle("Contatct Program @ Authentication");
	system("color 02");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 445.5, 264, 457, 240, TRUE);
    fflush(stdin);
	FILE *auth;
	auth= fopen("security", "rb+");
	if(auth== NULL){
		printf("\n\nError Openning The security press any key to close and try again.......");
		getch();
		exit(4);
	}
	char user_name[20], user_password[20];
	int user_find= 0;
	struct security auth_data;
	printf("\n\n\n\n\n   Please Enter The User ID: ");
	gets(user_name);
	fflush(stdin);
	while(fread(&auth_data, sizeof(auth_data), 1, auth)==1 ){
		if(strcmp(auth_data.user_id, user_name)== 0){
			printf("   Enter Password: ");
			gets(user_password);
			fflush(stdin);
			char id[10]= {'a', 'd', 'm', 'i', 'n', '\0'};
			if(strcmp(auth_data.password, user_password)== 0){
				if(strcmp(auth_data.user_id, id)== 0){
					fclose(auth);
					adminacess= 1;
					admin();
				}else{
					strcpy(user, auth_data.user_id);
					strcpy(username, auth_data.user_name);
					fclose(auth);
					menu();
				}
			}
			if(strcmp(auth_data.user_id, user_password)!= 0){
				printf("\n\nEntered Password is wrong, Press any key to try again......");
				getch();
				fclose(auth);
				goto lable3o1;
			}
			user_find= 1;
		}
	}
	if(user_find== 0){
		printf("\nUser Not found, press any key to try again........");
		fclose(auth);
		getch();
		goto lable3o1;
	}
}

//for the admin panel
void admin(){
lable4o1:
	system("cls");
	SetConsoleTitle("Contatct Program @ Admin");
	system("color 04");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 445.5, 264, 500, 240, TRUE);
    fflush(stdin);
	struct security users[10];
	FILE *auth;
	auth= fopen("security", "r+");
	if(auth== NULL){
		printf("\n\nError Openning The security press any key to close and try again.......");
		getch();
		exit(4);
	}
	printf("\n\n                 ----- Admin Panel -----\n\n");
	printf(" 1. Create User                        2. Show All Users\n");
	printf(" 3. Delete User                        4. Exit\n");
	printf(" 5. Modify User\n");
	printf("\nChoose a option..........");
lable4o2:
	switch(getch()){
		case '1':
			fclose(auth);
			create_user();
			break;
		case '2':
			fclose(auth);
			show_users();
			break;
		case '3':
			fclose(auth);
			delete_user();
			break;
		case '4':
			system("cls");
			system("color f0");
			HWND wh = GetConsoleWindow();
    		MoveWindow(wh, 445.5, 264, 470, 210, TRUE);
			printf("\n\n\n\n                Closing Contatcts.......");
			int c, d;
			for (c = 1; c <= 32767; c++){
				for (d = 1; d <= 32767; d++){
				}
			}
			fclose(auth);
			exit(5);
			break;
		case '5':
			fclose(auth);
			modify_user();
			break;
		default:
			system("cls");
			printf("\n\n                 ----- Admin Panel -----\n\n");
			printf(" 1. Create User                        2. Show All Users\n");
			printf(" 3. Delete User                        4. Exit\n");
			printf(" 5. Modify User\n");
			printf("\nWrong option, Try again..........");
			goto lable4o2;
	}
	
}


void create_user(){
	system("cls");
	SetConsoleTitle("Contatct Program @ Create User");
	system("color 06");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 445.5, 264, 500, 300, TRUE);
    fflush(stdin);
	int i=0;
	struct security creatuser;
	struct security users;
	FILE *auth;
	auth= fopen("security", "ab+");
	if(auth== NULL){
		printf("\n\nError Openning The security press any key to close and try again.......");
		getch();
		exit(4);
	}
	printf("\n\n               ----- Creating New User -----\n\n");
	while(fread(&users, sizeof(users), 1, auth)== 1){
		i++;
	}
	fclose(auth);
	if(i== 10){
		printf("user database full, Enter any key to goback......");
		getch();
		fclose(auth);
		admin();
	}
	printf("Enter UserID: ");
	gets(creatuser.user_id);
	fflush(stdin);
	auth= fopen("security", "ab+");
	while(fread(&users, sizeof(users), 1, auth)== 1){
		if(strcmp(users.user_id, creatuser.user_id)== 0){
			printf("\nUser Already present, press any key to goback.......");
			getch();
			fclose(auth);
			admin();
		}
	}
	fclose(auth);
	printf("Enter Password: ");
	gets(creatuser.password);
	fflush(stdin);
	printf("Enter User Name: ");
	gets(creatuser.user_name);
	fflush(stdin);
	char authid[20]= {'s', 'o', 'm', 'd', 'e', 'e', 'p', '2', '0', '1', '3', '\0'};
	strcpy(creatuser.auth_id, authid);
	auth= fopen("security", "ab+");
	fwrite(&creatuser, sizeof(creatuser), 1, auth);
	fclose(auth);
	printf("\n\n                ----- User Created -----");
	printf("\n\nPress any key to goback........");
	getch();
	admin();
}


void show_users(){
lable5o1:
	system("cls");
	system("color 02");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 445.5, 264, 560, 350, TRUE);
    fflush(stdin);
	struct security users[10];
	FILE *auth;
	auth= fopen("security", "rb");
	if(auth== NULL){
		printf("\n\nError Openning The security press any key to close and try again.......");
		getch();
		exit(4);
	}
	int i= 0, user_no= 0;
	char user_op= '0';
	printf("\n\n                 ----- Displaying All Users -----\n\n");
	printf("   No.	| UserID		| Password	| Name\n");
	printf(" -------+-----------------------+---------------+---------------\n");
	while(fread(&users[i], sizeof(users[i]), 1, auth)== 1){
		if(i>0){
	printf("   %d	| %s		| %s		| %s\n", i, users[i].user_id, users[i].password, users[i].user_name);
		printf(" -------+-----------------------+---------------+---------------\n");
		}
		i++;
	}
	printf("\n                     ----- Complete -----\n");
	printf("\nEnter The Number to open or 'b' to goback.......");
lable5o2:
	user_op= getch();
	if(user_op== '1'){user_no= 1;}else if(user_op== '2'){user_no= 2;}else if(user_op== '3'){user_no= 3;}else if(user_op== '4'){user_no= 4;}else if(user_op== '5'){user_no= 5;}else if(user_op== '6'){user_no= 6;}else if(user_op== '7'){user_no= 7;}else if(user_op== '8'){user_no= 8;}else if(user_op== '9'){user_no= 9;}else{user_no= 11;}
	if(user_op== '1' || user_op== '2' || user_op== '3' || user_op== '4' || user_op== '5' || user_op== '6' || user_op== '7' || user_op== '8' || user_op== '9'){
		if(strlen(users[user_no].user_id)>1){
			strcpy(user, users[user_no].user_id);
			strcpy(username, users[user_no].user_name);
			fclose(auth);
			menu();
		}else{
			goto lable5o3;
		}
	}else if(user_op== 'b'){
		fclose(auth);
		admin();
	}else{
lable5o3:
		printf("\nWrong Option, try Again........");
		goto lable5o2;
	}
}


void modify_user(){
	system("cls");
	SetConsoleTitle("Contatct Program @ Modify User");
	system("color 02");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 445.5, 264, 440, 300, TRUE);
    fflush(stdin);
	struct security modifyuser;
	char userid[20];
	int modify_stat= 0;
	FILE *auth, *temp_auth;
	auth= fopen("security", "rb+");
	temp_auth= fopen("temp_auth", "wb+");
	if(auth== NULL && temp_auth== NULL){
		printf("\n\nError Openning The security press any key to close and try again.......");
		getch();
		exit(4);
	}
	printf("\n\n             ----- Updating User -----\n\n");
	printf("    Enter UserId: ");
	gets(userid);
	fflush(stdin);
	while(fread(&modifyuser, sizeof(modifyuser), 1, auth)==1){
		if(strcmp(modifyuser.user_id, userid)!= 0){
			fwrite(&modifyuser, sizeof(modifyuser), 1, temp_auth);
		}
		if(strcmp(modifyuser.user_id, userid)== 0){
			printf("    Enter Password: ");
			gets(modifyuser.password);
			fflush(stdin);
			printf("   Enter User Name: ");
			gets(modifyuser.user_name);
			fflush(stdin);
			char authid[20]= {'s', 'o', 'm', 'd', 'e', 'e', 'p', '2', '0', '1', '3', '\0'};
			strcpy(modifyuser.auth_id, authid);
			fwrite(&modifyuser, sizeof(modifyuser), 1, temp_auth);
			modify_stat= 1;
		}
	}
	fclose(auth);
	fclose(temp_auth);
	if(modify_stat== 1){
		remove("security");
		rename("temp_auth", "security");
		printf("\n\n            ----- User Updated -----\n\n");
	}else{
		remove("temp_auth");
		printf("\n\n            ----- User Not Found -----\n\n");
	}
	printf("Press any key to Goback.........");
	getch();
	admin();
}


void delete_user(){
	system("cls");
	SetConsoleTitle("Contatct Program @ Delete User");
	system("color 02");
	HWND wh = GetConsoleWindow();
    MoveWindow(wh, 445.5, 264, 440, 300, TRUE);
    fflush(stdin);
	struct security deletuser;
	char userid[20];
	int delete_stat= 0;
	FILE *auth, *temp_auth;
	auth= fopen("security", "rb+");
	temp_auth= fopen("temp_auth", "wb+");
	if(auth== NULL && temp_auth== NULL){
		printf("\n\nError Openning The security press any key to close and try again.......");
		getch();
		exit(4);
	}
	printf("\n\n              ----- Deleting User -----\n\n");
	printf(" Enter UserId: ");
	gets(userid);
	fflush(stdin);
	while(fread(&deletuser, sizeof(deletuser), 1, auth)==1){
		if(strcmp(deletuser.user_id, userid)!= 0){
			fwrite(&deletuser, sizeof(deletuser), 1, temp_auth);
		}
		if(strcmp(deletuser.user_id, userid)== 0){
			delete_stat= 1;
		}
	}
	fclose(auth);
	fclose(temp_auth);
	if(delete_stat== 1){
		remove("security");
		rename("temp_auth", "security");
		printf("\n\n           ----- User Deleted -----\n\n");
	}else{
		remove("temp_auth");
		printf("\n\n           ----- User Not Found -----\n\n");
	}
	printf("Press any key to Goback.........");
	getch();
	admin();
}
