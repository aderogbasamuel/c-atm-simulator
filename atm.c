#include <stdio.h>
#include <string.h>
void checkBalance(float balance);
float deposit(float balance);
float withdraw(float balance);
void pressEnterToContinue();

int main(){

    float balance= 500.0;
    char name[20]="Samuel", enteredName[20];
    int pin= 1004, enteredPin;
    int choice;
    for(int i=1; i<= 5; i++){
        printf("\nLogin attempt %d of 5\n", i);
        printf("-------------------------");
        printf("\nUsername:");
        scanf("%19s", enteredName);

        printf("PIN:");
        scanf("%d",&enteredPin);

        if(strcmp(name,enteredName)==0&&pin== enteredPin){ 
            printf("Welcome %s\n", enteredName); 
            do{
                printf("\n---------ATM MENU--------\n");
                printf("1. Check Balance \n2. Deposit \n3. Withdraw \n4. Exit");
                printf("\n--------------------------\n");
                printf("Choose an option: ");
                scanf("%d", &choice);
                switch(choice){
                    case 1:
                        checkBalance(balance);
                        pressEnterToContinue();
                        break;
                    case 2:
                        balance=deposit(balance);
                        printf("Your new balance is:\t %f \n", balance);
                        pressEnterToContinue();
                        break;
                    case 3:
                        balance= withdraw(balance);
                        printf("Your new balance is:\t %f \n", balance);
                        pressEnterToContinue();
                        break;
                    case 4:
                        printf("Thank you for using the application.\n");
                        pressEnterToContinue();
                        break;
                    default:
                        printf("invalid option. Try again\n");
                        pressEnterToContinue();
                }
                
            }
            while(choice!=4);

            break;
        }
        else{
            printf("Invalid Username or PIN. \n");
        }
    }
    printf("\nToo many failed attempts. Account Locke. \n");
    return 0;
}

void checkBalance(float balance){
    printf("Your avalable balance is:\t %f \n", balance);
}

float deposit(float balance){
    float depositamt;
    printf("How much do you want to deposit? ");
    scanf("%f", &depositamt);
    balance+=depositamt;
    printf("Deposit succesful. \n");
    return balance;
}
float withdraw(float balance){
    float withdrawamt;
    printf("How much do you want to withdraw? ");
    scanf("%f", &withdrawamt);
    if(withdrawamt <= 0){
        printf("Invalid Amount.\n");
    }
    else if(withdrawamt>balance){
        printf("Insufficent amount. \n");
    }
    else{
        balance-=withdrawamt;
        printf("Withdrawal succesful. \n");
    }
    return balance;
};
void pressEnterToContinue(){
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}