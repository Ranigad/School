package ATM;

import java.util.Scanner;

public class ATM{
    
    int failedAttempts;
    Scanner keypad;
    static Boolean loggedIn;
    String transaction;
    
    ATM(){
        keypad = new Scanner(System.in);
        failedAttempts = 0;
        loggedIn = false;
    }
    
    void printMainMenu()
    {                 
          System.out.println("Please choose one of the following: ");
          System.out.println("1. Deposit Cash\n" + "2. Withdraw Cash");
          System.out.println("3. Print Statement\n" + "4. Exit");
          System.out.print("Your Choice: ");
    }
    
    void printExitScreen()
    {
        System.out.println("     Thank you for banking with us!");
        System.out.println("          Please come back soon. \n");
        printSignature();
        System.out.println("\n==========================================");
    }
    
    void printHeader(int previousAction)
    {
        System.out.println("==========================================");
        
        if(previousAction == 1)
                System.out.println("$" + transaction + " has been deposited into your account");
        if(previousAction == 2)
                System.out.println("$" + transaction + " has been withdrawn from your account");
        if(previousAction == 3)
            System.out.println("The bank statement has been created.");
        if(previousAction == 4)
            printExitScreen();
        
        System.out.println("");
    }
    
    void printSignature()
    {
        System.out.println("               CSCI114 Bank                 \n" + 
                           "Member of FDIC, Equal Housing Lender");
    }
   
    void accountInteraction(Account user)
    {
        int menuOption = 0;
        String userInput;
        
        System.out.println("Welcome to the Palomar CSCI114 ATM \n");
        while (loggedIn)
        {
            printMainMenu();
            userInput = keypad.next();
            if(isInteger(userInput))
                menuOption = Integer.parseInt(userInput);
            
            System.out.println("==========================================");
                if (menuOption == 1)
                {
                    //deposit
                    deposit(user);
                }
                else if (menuOption == 2)
                {
                    // withdrawal
                   withdrawal(user);
                }
                else if (menuOption == 3)
                {
                    // Check Balance
                    printStatement(user);
                }
                else if (menuOption == 4)
                {
                    loggedIn = false;
                }
                else
                {
                    System.out.println("Not a valid option.");
                }
                printHeader(menuOption);
        }

    }
    
    void logIn(Account[] users)
    {
        String accNum;
        int pin;
        System.out.print("==============================" + "\n");
                   //"  Login Attempt #" + (failedAttempts + 1) + "\n\n" +
        while(!loggedIn && failedAttempts < 3)
            {   
                System.out.print("Account number: ");
                accNum = keypad.next();

                System.out.print("Pin: ");
                pin = keypad.nextInt();
                if(checkAccounts(users, accNum, pin))
                {
                    loggedIn = true;
                }
                else
                    System.out.println("The account number and pin don't match! \n" + 
                            "Make sure you have the correct account number and pin. \n" +
                            "==============================" + "\n" +
                            (3 - failedAttempts) + " attempt(s) left.");
                    
            }
             if(!loggedIn)
            {
                System.out.println("You have reached your maximum number of attempts. Exiting.");
            }
    }
    
    Boolean checkAccounts(Account[] users, String accountNum, int pin)
    {
        Boolean validInformation = false;
        for (int i = 0; i < users.length; i++)
        {
            if(accountNum.equals(users[i].getAccountNum()) && pin == users[i].getPin())
            {
                validInformation = true;
            }
        }
        if(!validInformation)
        {
            failedAttempts++;
        }
        return validInformation;
    }
    
    void deposit(Account user)
    {
        float deposit;
        Boolean validDeposit = false;
        while (!validDeposit)
            {
            System.out.println("Please enter the amount of deposit in USD:");
            System.out.println("For example: 89.75");
            System.out.print("$");
            
            transaction = (keypad.next());
            while(!isFloat(transaction))
            {
                System.out.print("Invalid Amount! Try again: $");
                transaction = keypad.next();
            }
            deposit = Float.parseFloat(transaction);

            if (deposit < 0.0f)
            {
                System.out.println("Deposit can not be less than $0.00");
            }
            else
            {
                 user.deposit(deposit);
                 validDeposit = true;
            }    
        }
    }
    
    void withdrawal(Account user)
    {
        float withdrawal;
        Boolean validWithdrawal = false;
        while(!validWithdrawal)
        {
            System.out.println("Please enter the amount to withdraw in USD:");
            System.out.println("For example: 89.75");
            System.out.print("$");
            
            transaction = (keypad.next());
            while(!isFloat(transaction))
            {
                System.out.print("Invalid Amount! Try again: $");
                transaction = keypad.next();
            }
            withdrawal = Float.parseFloat(transaction);
            
            System.out.println(transaction + " : " + user.checkBalance());
            if (withdrawal > user.checkBalance())
            {
                System.out.println("Not enough funds available for this transaction!");
            }
            else if (withdrawal < 0)
            {
                System.out.println("Amount can not be less than $0.00!");
            }
            else
            {
                System.out.println("Withdrawal successful.");
                user.withdrawal(withdrawal);
                validWithdrawal = true;
            }
        }
    }
    
    void printStatement(Account user)
    {
        System.out.println("Name: " + user.getLastName() + ", " + user.getFirstName());
        System.out.println("Account Number: " + user.getAccountNum());
        System.out.print("Current Balance: $");
        System.out.format("%.2f\n", user.checkBalance());
        System.out.println("-------------------------------------------");
        printSignature();
    }
    
    Boolean isInteger(String userInput)
    {
        try{
            Integer.parseInt(userInput);
        } catch(NumberFormatException e)
        {
            return false;
        }
        return true;
    }
    
    Boolean isFloat(String userInput)
    {
        try{
            Float.parseFloat(userInput);
        } catch(NumberFormatException e)
        {
            return false;
        }
        return true;
    }
}