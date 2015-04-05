package calculator;

/**
 * The main class that oversees the usage of the menu and calculator
 * classes.
 * @author Charles
 */
public class driver{
    
    public static void main(String[] args)
    {
        Calculator calc = new Calculator();
        Menu menu = new Menu();
        
        menu.print();
        menu.setSelection();
        
        if (menu.getSelection() != 7)
            calc.setValues();
        
        switch(menu.getSelection())
        {
            case 1: calc.Add(); break;
            case 2: calc.Sub(); break;
            case 3: calc.Mul(); break;
            case 4: calc.Div(); break;
            case 5: calc.Pow(); break;
            case 6: calc.Mod(); break;
            case 7: System.out.println("Exiting. Thank you for using this program");
                    System.exit(0);
        }
        
        calc.Results();
              
    }
}