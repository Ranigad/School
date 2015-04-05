package ATM;

public class Account{
    
    String firstName;
    String lastName;
    String accountNum;
    int pin;
    float balance;
    
    
    Account()
    {
        accountNum = "0";
        pin = 0;
        balance = 0.0f;
        firstName = "";
        lastName = "";
    }
    
    Account(String accountNum, int pin, float balance, String firstName, String lastName)
    {
        this.accountNum = accountNum;
        this.pin = pin;
        this.balance = balance;
        this.firstName = firstName;
        this.lastName = lastName;
    }
    
    void deposit(float deposit)
    {
        balance += deposit;
    }
    
    float checkBalance()
    {
        return balance;
    }
    
    void withdrawal(float withdrawal)
    {
        balance -= withdrawal;
    }
    
    String getAccountNum()
    {
        return accountNum;
    }
    
    String getLastName()
    {
        return lastName;
    }
    
    String getFirstName()
    {
        return firstName;
    }
    
    int getPin()
    {
        return pin;
    }
}