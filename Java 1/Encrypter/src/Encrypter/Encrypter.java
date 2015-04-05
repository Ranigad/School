package Encrypter;



public class Encrypter{
    
    Encrypter(){}
    
    String Caesar(String message){
        String encryptedMessage = moveToUnusedCharacters(message);
        int shift = 3;
        
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
        
        for(int i = 65; i < 90; i++)
        {
            encryptedMessage = encryptedMessage.replace((char)i, (char)(i + 1 + 32));
        }
        
        encryptedMessage = encryptedMessage.replace("Z","aa");
        encryptedMessage = encryptedMessage.replace((char)25, 'Z');
        encryptedMessage = encryptedMessage.replace("Z", "AA");
        
        for(int i = 0; i < 25; i++)
        {
            encryptedMessage = encryptedMessage.replace((char)i, (char)(i + 1 + 65));
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


/* Alternate code for encrypt Augustus

        String encryptedMessage = message;// = moveToUnusedCharacters(message);
        
        encryptedMessage = encryptedMessage.replace('Z', (char) 0);
        for(int i = 90; i >= 65; i--)
        {
            encryptedMessage = encryptedMessage.replace((char)i, (char)(i + 1));
        }
        encryptedMessage = encryptedMessage.replace((char)0, 'A').replace("A", "AA");

        encryptedMessage = encryptedMessage.replace('z', '\0');
        
        for(int i = 122; i >= 97; i--)
        {
            encryptedMessage = encryptedMessage.replace((char)i, (char)(i + 1));
        }
        
        encryptedMessage = encryptedMessage.replace((char)0, 'a').replace("a", "aa");
        
        return encryptedMessage;
*/