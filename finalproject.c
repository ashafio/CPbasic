#include <stdio.h>

float initialdeposit,totalDeposit=0,addDeposit;
int cardnumber,dob,pin;
int temp,i,n;
int option,storeOption,bankOption,cartOption;
int productCode;
float payable=0,netPayable;

int main()
{

    printf("Enter initial deposit : ");
    scanf("%f",&initialdeposit);
    printf("Initial Deposit: %f",initialdeposit);

    temp = initialdeposit;
    initialdeposit = totalDeposit;
    totalDeposit = temp;

    printf("\nTotal Deposit: %f",totalDeposit);

    mainMenu();

   getch();
   return 0;
}

void mainMenu()
{
    printf("\n*** Main Menu ***\n Select an option from given options below.\n");
    printf(" 1 --> Visit Online Store.\n 2 --> Bank\n 3 --> Help\n 4 --> Terminate\n");
    printf("Enter your chosen option number: ");
    scanf("%d",&option);
    printf("Chosen : %d\n",option);


    if(option==1)
    {

        onlinestore();

    }

    else if(option==2)
    {
        bank();
    }
    else if(option==3)
    {
        help();
    }

    else if(option==4)
    {
        terminate();
    }
    else
    {
        printf("Invalid input.try again\n");
        mainMenu();
    }
}

void onlinestore()
{
        printf("*** Welcome to Online Store ***\n");
        printf("Products's name         price       Product Code\n");
        printf("GoPro 10 Camera         580 CAD     2001\n");
        printf("Samsung Galaxy A52      550 CAD     3001\n");
        printf("MacBook Air Pro         1200 CAD    4001\n");
        printf("HP NoteBook             1000 CAD    5001\n");

        cart();

        /*
        printf("How many products do you need?\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
        printf("1.Want to add more products to the cart?\n2.Checkout\n");
        printf("Enter choice: ");
        scanf("%d",&cartOption);
        if(cartOption==1)
        {
            cart();
        }
        else if(cartOption==2)
        {
            checkout();
        }
        } */

}

void cart()
{
        printf("Enter Product Code to add to the Cart: ");
        scanf("%d",&productCode);

        if(productCode==2001)
    {
        payable=payable+580;
        printf("Payable: %.2f\n",payable);

    }
    else if(productCode==3001)
    {
        payable=payable+550;
        printf("Payable: %.2f\n",payable);
    }
    else if(productCode==4001)
    {
        payable=payable+1200;
        printf("Payable: %.2f\n",payable);
    }
    else if(productCode==5001)
    {
        payable=payable+1000;
        printf("Payable: %.2f\n",payable);
    }
    else
    {
        printf("Invalid Input\n");
        printf("Payable: %.2f\n",payable);
        cart();
    }


        printf("1.Want to add more products to the cart?\n2.Checkout\n");
        printf("Enter choice: ");
        scanf("%d",&cartOption);
        if(cartOption==1)
        {
            cart();
        }
        else if(cartOption==2)
        {
            checkout();
        }

}

void checkout()
{
    printf("Payable: %.4f\n",payable);
    netPayable = payable+(payable*0.13);

    printf("Net Payable(+13 %% tax):%.4f\n",netPayable);

    printf("Card Number: ");
    scanf("%d",&cardnumber);
    printf("\n pin: ");
    scanf("%d",&pin);

    if(totalDeposit>=netPayable)
    {
        totalDeposit = totalDeposit-netPayable;
        printf("CAD %.2f has been deducted from your account.\n Your products are on the way.\n Thank you for shopping with us.\n",netPayable);
    }
    else if(totalDeposit<netPayable)
    {
        printf("Sorry ): Insufficient Balance.\n Please, deposit some money first.\n");
    }

    mainMenu();


}


void bank()
{
        printf("1. Check Balance.\n");
        printf("2. Deposit More.\n");
        printf("3. Main Menu\n");

        printf("Enter your choice:");
        scanf("%d",&bankOption);

        if(bankOption==1)
        {
            printf("Your Total Bank Balance is: %.2f \n",totalDeposit);
            bank();

        }
        else if(bankOption==2)
        {
            printf("Want to deposit more? Just fill up the form below.\n");
            printf("Card Number: ");
            scanf("%d",&cardnumber);

            printf("\n Date of Birth: ");
            scanf("%d",&dob);

            printf("\n Ammount: ");
            scanf("%f",&addDeposit);

            printf("\n pin: ");
            scanf("%d",&pin);

            printf("\n Success!!! You just added CAD %.2f to your Bank Balance.Thank You.\n",addDeposit);

            totalDeposit = totalDeposit+addDeposit;
            bank();


        }
        else if(bankOption==3)
        {
            printf("\n");
            mainMenu();
        }

        else
        {
            printf("Sorry :( Invalid Input.\n");
            bank();
        }

}


void help()
{
    printf("Do you need help?\nRead our user manual below.\n ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");

}

void terminate()
{
    exit(0);
}
