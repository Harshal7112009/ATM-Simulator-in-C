#include <stdio.h>

int main() {
    // Variables
    int enteredPin;
    int choice;
    int accountType;           
    int correctPin = 2607;    
    float balance = 50000.0;   
    float amount;

    printf("=== WELCOME TO YOUR BANK ATM ===\n");
    printf("Please enter your 4-digit PIN: ");
    scanf("%d", &enteredPin);

    
    if (enteredPin != correctPin) {
        printf("Incorrect PIN! Access Denied.\n");
        return 0; 
    }

    
    printf("\n--- CHOOSE YOUR ACCOUNT TYPE ---\n");
    printf("1. Savings Account\n");
    printf("2. Current Account\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &accountType);

    
    if (accountType == 1) {
        printf("\n>> Savings Account Selected <<\n");
    } else if (accountType == 2) {
        printf("\n>> Current Account Selected <<\n");
    } else {
        printf("Invalid choice! Session terminated.\n");
        return 0; 
    }

    
    while (1) {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your current balance is: Rs. %.2f\n", balance);
                break; 

            case 2:
                printf("Enter amount to deposit: Rs. ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance = balance + amount; 
                    printf("Successfully deposited! New Balance: Rs. %.2f\n", balance);
                } else {
                    printf("Invalid amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: Rs. ");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("Insufficient balance! You only have Rs. %.2f\n", balance);
                } else if (amount <= 0) {
                    printf("Invalid amount!\n");
                } else {
                    balance = balance - amount;
                    printf("Please collect your cash. Remaining Balance: Rs. %.2f\n", balance);
                }
                break;

            case 4:
                printf("Thank you for using our ATM. Goodbye!\n");
                return 0; 

            default:
                printf("Invalid choice! Please choose between 1 and 4.\n");
        }
    }

    return 0;
}
