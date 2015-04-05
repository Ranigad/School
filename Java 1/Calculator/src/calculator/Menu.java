package calculator;

import java.util.Scanner;

/**
 * A class to display a menu and to allow user selection.
 * @author Charles
 */
public class Menu{
        
    private int selection;
    
    public Menu()
    {
        selection = 0;
    }
    /** 
     * Prints a menu of possible user selections. 
     */
    public void print()
    {
        System.out.println("1 - Add \n"
                            + "2 - Subract \n"
                            + "3 - Multiply \n"
                            + "4 - Divide \n"
                            + "5 - Power \n"
                            + "6 - Modulus \n"
                            + "7 - Exit \n"
                            + "===================");
    }
    
    /**
     * Gets the user's input for menu navigation.
     */
    public void setSelection()
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter your menu selection: ");
        
        while (!validSelection())
        {
            while(!s.hasNextInt())
            {
                System.out.print("Please enter an integer: ");
                s.next();
            }
            
            selection = s.nextInt();
            
            if (!validSelection())
            {
                System.out.print("Not a valid menu selection! Please try again: ");
            }
        }
    }
    
    /**
     * Accessor for the user selection.
     * @return the user menu selection.
     */
    public int getSelection()
    {
        return selection;
    }
    
    /**
     * Checks if the selection entered is within a certain bounds.
     * @return whether the selection is within a certain bounds.
     */
    private boolean validSelection()
    {
        return selection >=1 && selection<=7;
    }
}