//
//  deque.h
//  morze
//
//  Created by Эльдар Дамиров on 17.01.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#ifndef deque_h
#define deque_h

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//#define debugMode

enum { NONE, LOW, MEDIUM, FULL };

/*
 NONE - no secure features at all;
 LOW - canaries checker;
 MEDIUM - elements sum, canaries checker;
 FULL - hash, elements sum, class sum, canaries checker;
*/


//// ------------------------------------------------------------------------------------------------
const int poisonInt = 12345678;
const double poisonDouble = NAN;
const float poisonFloat = NAN;
const char poisonChar = '~';
//// ------------------------------------------------------------------------------------------------



template <typename typeOfData> class Deque
    {
    public:
        std::mutex lock;
        
    
//        Deque ( size_t bufferSizeTemp, int securityLevelTemp )
        Deque ( size_t bufferSizeTemp )
            {
            
            bufferSize = bufferSizeTemp;
            
            bufferEnd = buffer + ( bufferSize - 1 );
            
//            securityLevel = securityLevelTemp;
            
            init();
            
            }
            
        ~Deque()
            {
            
            #ifdef debugMode
            
            printf ( "%s", errorList.c_str() );
            
            #endif
            
            }
            
            
        //////////////////////////////////////////
        //////////////////////////////////////////
        //////////////////////////////////////////
        
        void test()
            {
            for ( int i = 0; i < bufferSize; i++ )
                {
                std::cout << buffer [ i ] << "\n";
                }
                
            std::cout << beginDataPointer << "    " << endDataPointer << "\n";
            }
        
        //////////////////////////////////////////
        //////////////////////////////////////////
        //////////////////////////////////////////
            
        bool push_back ( typeOfData valueToPush )
            {
            lock.lock();
            
            if ( endDataPointer != beginDataPointer )
                {
                *endDataPointer = valueToPush;

                
                if ( ( endDataPointer + 1 ) > bufferEnd )
                    {
                    if ( buffer != beginDataPointer )
                        {
                        endDataPointer = buffer;
                        }
                    else
                        {
                        lock.unlock();
                        
                        return false;
                        }
                    }
                else
                    {
                    if ( ( endDataPointer + 1 ) != beginDataPointer )
                        {
                        endDataPointer++;
                        }
                    else
                        {
                        lock.unlock();
                        
                        return false;
                        }
                    }
                    
                lock.unlock();
                
                return true;
                }
            else
                {
                lock.unlock();
                
                return false;
                }
                
            }
            
        bool push_front ( typeOfData valueToPush )
            {
            lock.lock();
            
            if ( beginDataPointer != endDataPointer )
                {
                *beginDataPointer = valueToPush;
                
                if ( ( beginDataPointer - 1 ) < buffer )
                    {
                    if ( bufferEnd != endDataPointer ) 
                        {
                        beginDataPointer = bufferEnd;
                        }
                    else
                        {
                        lock.unlock();
                        
                        return false;
                        }
                    }
                else
                    {
                    if ( ( beginDataPointer - 1 ) != endDataPointer )
                        {
                        beginDataPointer--;
                        }
                    else
                        {
                        lock.unlock();
                        
                        return false;
                        }
                    }
                    
                lock.unlock();
                    
                return true;
                }
            else 
                {
                lock.unlock();
                
                return false;
                }
                
            }
            
            
            
        bool pop_back()
            {
            lock.lock();
            
            #ifdef debugMode
            
            *endDataPointer = poisonValue;
            
            #endif

            if ( ( endDataPointer - 1 ) != beginDataPointer )
                {
                if ( ( endDataPointer - 1 ) < buffer )
                    {
                    if ( bufferEnd != beginDataPointer )
                        {
                        endDataPointer = bufferEnd;
                        }
                    else
                        {
                        lock.unlock();
                        
                        return false;
                        }
                    }
                else
                    {
                    endDataPointer--;
                    }
                    
                lock.unlock();
                    
                return true;
                }
            else
                {
                lock.unlock();
                
                return false;
                }
            }
            
        bool pop_front()
            {
            
            lock.try_lock();
            
            #ifdef debugMode
            
            *beginDataPointer = poisonValue;
            
            #endif
            
            
            if ( ( beginDataPointer + 1 ) != endDataPointer )
                {
                if ( ( beginDataPointer + 1 ) > bufferEnd )
                    {
                    if ( endDataPointer != buffer )
                        {
                        beginDataPointer = buffer;
                        }
                    else
                        {
                        lock.unlock();
                        
                        return false;
                        }
                    }
                else
                    {
                    beginDataPointer++;
                    }
                    
//                if ( lock.try_lock() == true )
                    {
                    lock.unlock();
                    }
                    
                return true;
                }
            else
                {
                lock.unlock();
                
                return false;
                }
                
            }
            
            
        typeOfData* front()
            {
//            return *beginDataPointer;
//            typeOfData* elementToReturn = beginDataPointer;
            
            if ( ( beginDataPointer + 1 ) != endDataPointer )
                {
                if ( ( beginDataPointer + 1 ) > bufferEnd )
                    {
                    if ( buffer != endDataPointer )
                        {
                        return buffer; 
                        }
                    }
                    
                return ( beginDataPointer + 1 );
                }

            return &poisonValue;
            }
            
            
        typeOfData* back()
            {
            
            if ( ( endDataPointer - 1 ) != beginDataPointer )
                {
                if ( ( endDataPointer - 1 ) < buffer )
                    {
                    if ( buffer != beginDataPointer )
                        {
                        return buffer; 
                        }
                    }
                    
                return ( endDataPointer - 1 );
                }
                
            return &poisonValue;
            }
            
        size_t size()
            {
            return bufferSize;
            }
            
        bool empty()
            {
            if ( ( beginDataPointer < endDataPointer ) && ( ( endDataPointer - beginDataPointer ) == 1 ) )
                {
                return true;
                }
            else
                {
                return false;
                }
            }
        
    
    
    private:
    
        size_t bufferSize = 0;
        //// ------------------------------------------------------------------------------------------------
        typeOfData* buffer = new typeOfData [ 512 ] {};
        typeOfData* bufferEnd = nullptr;
        typeOfData* beginDataPointer = nullptr;
        typeOfData* endDataPointer = nullptr;
    
        
        
        //// ------------------------------------------------------------------------------------------------
        int securityLevel = NONE;
        typeOfData poisonValue = NULL;
        std::string errorList = "";
        //// ------------------------------------------------------------------------------------------------
//        std::mutex lock;
        //// ------------------------------------------------------------------------------------------------
        
        //// ------------------------------------------------------------------------------------------------
        
    
    
        void init()
            {
            beginDataPointer = &buffer [ ( ( bufferSize - 1 ) / 2 ) ];
            endDataPointer = &buffer [ ( ( bufferSize - 1 ) / 2 ) + 1 ]; 
            
            #ifdef debugMode
            setPoisonValue();
            
            for ( int currentIndex = 0; currentIndex < bufferSize; currentIndex++ )
                {
                buffer [ currentIndex ] = poisonValue;  
                }
            #endif
            
            }


        int setPoisonValue()
                {
                if ( typeid ( typeOfData ).name() == typeid ( int ).name() )
                    {
                    poisonValue = poisonInt;
                    }
                else if ( typeid ( typeOfData ).name() == typeid ( double ).name() )
                    {
                    poisonValue = poisonDouble;
                    }
                else if ( typeid ( typeOfData ).name() == typeid ( float ).name() )
                    {
                    poisonValue = poisonFloat;
                    }
                else if ( typeid ( typeOfData ).name() == typeid ( char ).name() )
                    {
                    poisonValue = poisonChar;
                    }
                else
                    {
                    errorList = errorList + "This typename is not supported!\n";
                    return 1;
                    }
                    
                return 0;
                }
    
    
    };



#endif /* deque_h */
