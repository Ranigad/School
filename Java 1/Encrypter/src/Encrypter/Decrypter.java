/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Encrypter;

/**
 *
 * @author Charles
 */
public class Decrypter {
    
    Decrypter(){}
    
    String Caesar(String message){
        String encryptedMessage = moveToUnusedCharacters(message);
        int shift = -3;
        
        for(int i = 65; i < 91; i++)
        {
            encryptedMessage = encryptedMessage.replace((char)i, (char)(((i + 32 - 'a' + 26 - shift) % 26) + 'a'));
        }
        for(int i = 0; i < 26; i++)
        {
             encryptedMessage = encryptedMessage.replace((char)i, (char)(((i + 65 - 'A' + 26 - shift) % 26) + 'A'));
        }
        
        return encryptedMessage;
    }
    
    String Augustus(String message){
        
        String encryptedMessage = moveToUnusedCharacters(message);
        
        
        for(int i = 66; i < 91; i++)
        {
            encryptedMessage = encryptedMessage.replace((char)i, (char)(i - 1 + 32));
        }
        
        encryptedMessage = encryptedMessage.replace("AA","z");
        encryptedMessage = encryptedMessage.replace((char)0, 'A');
        encryptedMessage = encryptedMessage.replace("AA", "Z");
        
        
        for(int i = 1; i < 26; i++)
        {
            encryptedMessage = encryptedMessage.replace((char)i, (char)(i - 1 + 65));
        }
        
        return encryptedMessage;
    }
    
    String moveToUnusedCharacters(String message)
    {
        String shiftedMessage = message;
        for(int i = 65; i < 91; i++)
        {
            shiftedMessage = shiftedMessage.replace((char) i, (char) (i - 65));
        }
        for(int i = 97; i < 123; i++)
        {
            shiftedMessage = shiftedMessage.replace((char) i, (char)(i - 32));
        }
        return shiftedMessage;
    }
}


