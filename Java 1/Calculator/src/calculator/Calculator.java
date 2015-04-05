
package calculator;

import java.util.Scanner;


/**
 * A calculator that can perform operations on two given operands.
 * @author Charles
 */
public class Calculator {

    private int a;
    private int b;
    private int answer;
    private double decAnswer;
    private char operator;
    
    /**
     * Default constructor.
     */
    Calculator() 
    {
        decAnswer = 0.0;
    }
    
    /**
     * Constructor for provided user inputs.
     * @param firstNum First operand for operations.
     * @param secondNum  Second operand for operations.
     */
    Calculator(int firstNum, int secondNum)
    {
        a = firstNum;
        b = secondNum;
        decAnswer = 0.0;
    }
    
    /**
     * Accessor for the first operand.
     * @return the first operand.
     */
    public int getFirst()
    {
        return a;
    }
    
    /**
     * Accessor for the second operand.
     * @return the second operand.
     */
    public int getSecond()
    {
        return b;
    }
    
    /**
     * Accessor for the operator character.
     * @return the character for te operator used.
     */
    public char getOperator()
    {
        return operator;
    }
    
    /**
     * Accessor for the answer.
     * @return the answer to the calculations.
     */
    public int getAnswer()
    {
        return answer;
    }
    
    /**
     * Has the user enter the two operands for calculations.
     */
    public void setValues()
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter your first number: ");
        while(!s.hasNextInt())
            {
                System.out.print("That was not an integer! Please try again: ");
                s.next();
            }
        a = s.nextInt();
        System.out.print("Enter your second number: ");
        while(!s.hasNextInt())
            {
                System.out.print("That was not an integer! Please try again: ");
                s.next();
            }
        b = s.nextInt();
        s.close();
    }
    
    /**
     * Adds the two operands.
     */
    public void Add() {
        operator = '+';
        answer = a + b;
    }
    
    /**
     * Subtracts the two operands.
     */
    public void Sub()
    {
        operator = '-';
        answer = a - b;
    }
    
    /**
     * Multiplies the two operands.
     */
    public void Mul()
    {
        operator = '*';
        answer = a * b;
    }
    
    /**
     * Divides the two operands.
     */
    public void Div()
    {
        operator = '/'; 
        
        if (b == 0)
        {
            System.out.println("Cannot divide by zero!");
            Scanner s = new Scanner(System.in);
            while (b == 0)
            {
                System.out.print("Enter a valid divisor: ");
                b = s.nextInt();
            }
        }
        
        if (a % b == 0)
           answer = a / b;
        else
           decAnswer = 1.0f * a / b;
        
    }
    
    /**
     * Takes the first operand to the power of the second operand.
     */
    public void Pow()
    {
        operator = '^';
        
        int total = 1;
        for (int i = 0; i < Math.abs(b); i++)
        {
            total *= a;
        }
        if (b < 0)
            decAnswer = 1.0f / total;
        else
            answer = total;
       
    }
    
    /**
     * Finds the remainder given a divided by b.
     */
    public void Mod()
    {
        operator = '%';
        answer = a % b;
    }
    
    /**
     * Prints results of calculation.
     */
    public void Results()
    {
        if (decAnswer == 0.0)
           System.out.println(a + " " + operator + " " + b + " = " + answer);
        else
           System.out.println(a + " " + operator + " " + b + " = " + decAnswer);
    }
}
