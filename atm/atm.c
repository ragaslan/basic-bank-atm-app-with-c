#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct Person{
	char name[30];
	int password;
	float amount;
	int loginState;
	int userPass;
};


typedef struct Person person;



void withdraw(person);
void deposit(person);
void amount(person);
void showScreen(person);



int main(){
	// create the person
	person person1 = {"Ragaslan",123456,1000,0,0};
	// start the app
	showScreen(person1);
	
	
	return 0;
}

void withdraw(person x){
	if(x.loginState == 0){
			printf("\n\tPlease enter your password to withdraw !\t:");
			scanf("%d",&x.userPass);
	}
	if(x.userPass == x.password){
		x.loginState = 1;
		printf("\n\tplease enter the amount of money to be withdrawn:\t");
		float withdrawAmount;
		scanf("%f",&withdrawAmount);
		if(withdrawAmount > 0){
			if(withdrawAmount > x.amount){
				printf("\n\tInsufficient balance! you will back the withdraw menu in 2 second");
				sleep(2);
				system("cls");
				withdraw(x);
			}else{
				x.amount -= withdrawAmount;
				printf("\n\tWithdraw process is successful ! you will back the amount page in 2 second");
				sleep(2);
				system("cls");
				amount(x);
			}
			
		}else{
			printf("\n\twithdraw error ! you will back the withdraw menu in 2 second");
			sleep(2);
			system("cls");
			withdraw(x);
		}

	}else{
		
		printf("\n\tpassword is wrong ! you will back the withdraw menu in 2 second");
		sleep(2);
		system("cls");
		withdraw(x);
	}
	
}

void deposit(person x){
	float depositAmount;
	printf("\n\tPlease enter the amount of money to be deposited\t:");
	scanf("%f",&depositAmount);
	if(depositAmount > 0){
		x.amount += depositAmount;
		printf("\n\tDeposit process is successful ! you will back the amount page in 2 second");
		sleep(2);
		system("cls");
		amount(x);
	}else{
		printf("\n\tdeposit error ! you will back the deposit menu in 2 second");
		sleep(2);
		system("cls");
		deposit(x);
	}
}
void amount(person x){
	int process;
	printf("\n\tYour Amount : %f\n",x.amount);
	printf("\n\t1)quit\n\t2)Back \t:");
	scanf("%d",&process);
	switch(process){
		case 1:
			break;
		case 2:
			system("cls");
			showScreen(x);
			break;
		default:
			system("cls");
			showScreen(x);
			break;
	}
}
void showScreen(person x){
	int process;
	printf("\n\tWelcome %s\n\n",x.name);
	printf("\tPlease choose the process ! \n\t1)Withdraw\n\t2)Deposit\n\t3)Amount\n\t4)Quit \t:");
	scanf("%d",&process);
	switch(process){
		case 1:
			withdraw(x);
			break;
		case 2:
			deposit(x);
			break;
		case 3:
			amount(x);
			break;
		case 4:
			x.loginState = 0;
			x.userPass = 0;
			break;
		default:
			system("cls");
			showScreen(x);
			break;
	}
}

