//
//  main.cpp
//  morze
//
//  Created by Эльдар Дамиров on 17.01.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <thread>

#include "deque.h"

enum { silence, dot, dash }; 




class morzeEncryptor
    {
    public:
        morzeEncryptor ( std::string voiceTemp ) : messages ( 1024 )
            {
            voice = voiceTemp;
            
            init();
            
            }
          
            
        ~morzeEncryptor()
            {
            
            }
        
    
    
    private:
        std::string voice = "";
        char* commandForDot = "";
        char* commandForDash = "";
        
        bool isFinish = false;
        
        int spaceBetweenSignals = 500000; // in milliseconds;
        
        Deque <int> messages;
        
        void init()
            {
            std::string temp  = "say -v " + voice + " 'beep'"; 
            commandForDot = &temp [ 0 ];
            
            temp = "say -v " + voice + " 'beeeeeep'";
            commandForDash = &temp [ 0 ];
            
            controller ( std::ref ( isFinish ) );
            }
        
        
        
        void controller ( Deque <int>& messages, bool& isFinish )
            {
            char currentChar = ' ';
            
            
            while ( currentChar != '/' )
                {
                currentChar = getchar();
                
                encryptChar ( currentChar );
                
                }
                
            isFinish = true;
            }
            
            
        void speaker ( Deque <int>& messages, bool& isFinish )
            {
            while ( isFinish != true )
                {
                if ( messages.size() > 0 )
                    {
                    
                    }
                }
            }
        
        
// chip eight;
        
        int encryptChar ( char currentCharTemp )
            {
            char currentChar = ' ';
            
            if ( currentCharTemp > 'a' )
                {
                currentChar = currentCharTemp - ( 'a' - 'A' );
                }
            else    
                {
                currentChar = currentCharTemp;
                }
            
            
            switch ( currentChar )
            {
            case 'A':
                {
                messages.push_back ( dot );
                messages.push_back (  silence  );
                messages.push_back (  dash  );
                
                break;
                }
            case 'B':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case 'C':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                    
                break;
                }
            case 'D':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                    
                break;
                }
            case 'E':
                {
                messages.push_back ( dot );
                
                break;
                }
            case 'F':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case 'G':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                break;
                }
            case 'H':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case 'I':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case 'J':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'K':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'L':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case 'M':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'N':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case 'O':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'P':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case 'Q':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'R':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case 'S':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case 'T':
                {
                messages.push_back ( dash );
                
                break;
                }
            case 'U':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'V':
                {
                messages.push_back ( dot );
                messages.push_back ( silence ); 
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'W':
                {
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'X':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'Y':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                
                break;
                }
            case 'Z':
                {
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dash );
                messages.push_back ( silence );
                messages.push_back ( dot );
                messages.push_back ( silence );
                messages.push_back ( dot );
                
                break;
                }
            case ' ':
                {
                messages.push_back ( silence );
                messages.push_back ( silence );
                messages.push_back ( silence );
                messages.push_back ( silence );
                
                break;
                }

            default:
                {
                break;
                }
                
            }

            
            
            return 0;
            }
        
        
        
        void playSymbol ( int symbol )
            {
            
            if ( symbol == dot )
                {
                system ( commandForDot );
                }
            
            if ( symbol == dash )
                {
                system ( commandForDash );
                }
                
            if ( symbol == silence )
                {
                usleep ( spaceBetweenSignals );
                } 
            
            }
            
            
            
        
        
        
    
    
    };



int main(int argc, const char * argv[]) 
    {
//    system ( "say -v Bells 'beeep'" );

//    char* command = "say -v Bells 'beep'";
    std::string voice = "Bells";
    std::string temp  = "say -v " +  voice + " 'beep'"; 
//            commandForDot = "say -v " + *voice + " 'beep'";
            char* commandForDot = &temp [ 0 ];
    
    system ( commandForDot );


    
    return 0;
    }
