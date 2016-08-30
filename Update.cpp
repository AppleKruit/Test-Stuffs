// Date of Creation: February 25th, 2015

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
	void Plain (string letter, int change, string phrase)		//Plaintext
	{
		for (int i = 0; i < letter.length(); i++)
		{
        	char x = letter.at(i);
			cout << x;
		}
	}
	void Cipher (string letter, int change, string phrase)		//Plaintext converted into ciphertext
	{
	 	for (int i = 0; i < letter.length(); i++)
    	{	
			unsigned char x = (unsigned char)(((letter.at(i)) + change));//Input + how much user wants to shift letters
			unsigned char y = x - change;						//Just the input
			if ((y <= 122 and x > 122) or (y <= 90 and x > 90))	//If change that happens will result in the character being larger than 'z' or 'Z'
			{
				x = x - 26;
			}
			else if ((y < 65) or (y>122) or (y < 97 and y > 90))//So only the letters get shifted (not symbols or numbers)
			{
				x = y;
			}
			cout << x;											//Output character after adjustments
		}
	}
	void Encrypt (string letter, int change, string phrase)		//If user chooses to encrypt, this is run
	{
		cout << "Plaintext: ";
		Plain (letter, change, phrase);
		cout << endl << endl<< "Ciphertext: ";
		Cipher (letter, change, phrase);
		cout << endl << endl;
	}
	void Decrypt (string letter, int change, string phrase)		//If user chooses to decrypt, this is run
	{
		cout << "Ciphertext: " ;
		Plain (letter, change, phrase);
		cout << endl << endl<< "Plaintext: ";
		Cipher (letter, change, phrase);
		cout << endl << endl;
	}
		
int main()
	{
		string phrase, option1, letter, exit1, option, changeSTR = "0";
   		int change, exit1a, optiona;
   		int statea, stateb = 0;
        while (stateb != 1)	
        {			
            while (statea != 1)
            {						
                  cout << "1. ROT-N \n2. Exit \n \n";					//Checks weather the user wants to exit the program or not
		          cin >> exit1;
		          cin.clear();
		          if (exit1 == "END")
		          {
			           return(0);
			           stateb = 1;
			           statea = 1;
		          }
		          istringstream dd(exit1);								//Convert string to int (for error checking purposes)
                  statea = 1;							
		          dd >> exit1a;
  	              if (exit1a == 2)										//Exits program
		          {
                       return(0);
                       statea = 1;
                       stateb = 0;
		          }
		          else if (exit1a != 2 and exit1a != 1)					//If incorrect input is given
		          {
			           system ("CLS");
	                   cout << "ERROR: Please enter 1 or 2" << endl << endl;
			           statea = 0;	
                       stateb = 0;										//Go back to selection screen
                  }
             }  
             cout << endl <<  endl << "Welcome to the ROT-N Encryption / Decryption \n \n \n";
             while (statea != 2)
             {
                   cout << "By how much you want to shift the letters (Whole numbers 1 - 26): " << endl << endl;
    	           cin >> changeSTR;	
		           if (changeSTR == "END")
		           {
			            return(0);
                   }														//Choose by how much you want to shift the number by
	               cin.ignore(); cin.clear();						
    	           istringstream ss(changeSTR);													
		           ss >> change;
                   statea = 2;									
		           if (change < 1 or change > 26)							//Error check
                   {
				      system ("CLS");
                      cout << endl << "ERROR: Please enter a number from 1 - 26 ... \n \n \n";
				      statea = 0;
			       }
             }
            while (statea != 3)
            {
    	          cout << endl << endl << "Do you wish to: \n1. Encrypt \n2. Decrypt \nPlease Choose: \n \n";   //Asks weather user wants to encrypt or decrypt
    	          cin >> option;
    	          statea = 3;
   	              if (option == "END")
	              {
                       return (0);											//Go to beginning of program
		          }
		          istringstream ff(option);								//Convert string to int (for error checking purposes)
		          ff >> optiona;
		          cin.ignore();	cin.clear();							//Options for text output depending on user decision
			      if (optiona == 1)
			      {		
				      option1 = "Encrypt";
		          }
			      else if (optiona == 2)
			      {
		              option1 = "Decrypt";
                  }
			      else 												//Error check for string input
			      {	
				       system("CLS");
				       cout << "ERROR: Please enter 1 or 2";
				       statea = 0;
	              }
            }
            while (statea != 4)
            {
                  cout << endl<< "Enter text to " << option1 << ": " << endl << endl;
                  getline(cin,phrase);									//Get the word the user wants to encrypt/decrypt
                  cin.ignore(10000, '\n');
    	          cout << endl << endl;
    	          if (optiona == 1)										//If user inputs '1', run Encrypt function
    	          {
    		          Encrypt(phrase, change, letter);
	              }
    	          else if (optiona == 2)									//If user inputs '2', run Decrypt function
    	          {
  		              Decrypt(phrase, change, letter);
                  }
                  cout << "Please enter another phrase you wish to " << option1 << ", or type 'RETURN'" << endl;
		          cout << "to return to beginning or 'END' to end the program" << endl << endl;
		          getline(cin,phrase);									//Asks if user wants to exit program or type another word or encrypt/decrypt;
		          cin.ignore(10000, '\n');											
		          cout << endl << endl;
		          if (phrase == "END")
		          {
			          return (0);
                      statea = 4;
                      stateb = 1;											//Go to beginning of program
	              }
		          else if (phrase == "RETURN")
		          {
			          system("CLS");
			          statea = 0;
                  }
		          else
		          {
	                  statea = 0;											//Go to getting user input for a encypted/decypted word
                  }
            }
    }
	}
