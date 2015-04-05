/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Encrypter;

import java.util.Scanner;

/**
 *
 * @author Charles
 */
public class Driver {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner messageInput = new Scanner(System.in);
        Encrypter encrypt = new Encrypter();
        Decrypter decrypt = new Decrypter();
        String message;
        
        System.out.print("Enter a message to be encrypted: ");
        message = messageInput.nextLine();
        System.out.println("=================================================");
        message = encrypt.Caesar(message);
        System.out.println("Encoded Caesar: " + message);
        
        message = decrypt.Caesar(message);
        System.out.println("Decoded Caesar: " + message);
        
        message = encrypt.Augustus(message);
        System.out.println("Encoded Augustus: " + message);
        
        message = decrypt.Augustus(message);
        System.out.println("Decoded Augustus: " + message);

    }
    
}
