
package ATM;

public class driver{
    
    public static void main (String[] args)
    {
        int accountIndex = 0;
        ATM atm = new ATM();
        Account[] bankAccounts = new Account[1];
        bankAccounts[0] = new Account("000114", 114, 200.00f, "John", "Smith");
        /*System.out.println(bankAccounts[0].getAccountNum() + " " + bankAccounts[0].getPin()
        + " " + bankAccounts[0].getFirstName() + bankAccounts[0].getLastName() + " "
        + bankAccounts[0].balance);*/
        atm.logIn(bankAccounts);
        while(ATM.loggedIn)
        {
        atm.accountInteraction(bankAccounts[accountIndex]);
        }
       
    }
}