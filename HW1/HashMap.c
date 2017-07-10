//
//  HashTable.c
//  HW1
//
//  Created by Roicxy Alonso Gonzalez on 7/7/17.
//  Copyright © 2017 AlonsoRoicxy. All rights reserved.
//

#include "HashMap.h"
#include <stdlib.h>


//*****************************************************************************
boolean Hash_New(HashMap * myHash)
{
    if(myHash && !myHash->table)
    {
        myHash->table = calloc(DEFAULT_TABLE_SIZE, sizeof(void *) * DEFAULT_TABLE_SIZE);
        
        if(myHash->table)
        {
            myHash->tableSize = DEFAULT_TABLE_SIZE;
            myHash->currentSize = 0;
            
            return TRUE;
        }
    }
    
    return FALSE;
}
//******************************************************************************
boolean Hash_Insert(HashMap * myHash, void * item)
{
    if(myHash && myHash->table && (( (myHash->currentSize * 1.0)- 1) / (myHash->tableSize * 1.0)) < 1 && item)
    {
    
        size_t hashCode = Hash_HashingCode(myHash, item);
       
        if(myHash->table[hashCode])
        {
            Item * temp = myHash->table[hashCode];
            
            while(temp->next)
            {
                temp = temp->next;
            }
            Item * newItem = calloc(1,sizeof(Item *));
            newItem->item = item;
            newItem->next = NULL;
            temp->next = newItem;
            myHash->currentSize++;
           
            return TRUE;
        }
        else if(!myHash->table[hashCode])
        {
            Item * newItem = calloc(1,sizeof(Item *));
            
            newItem->item = item;
            newItem->next = NULL;
            myHash->table[hashCode] = newItem;
            myHash->currentSize++;
            
            return TRUE;
        }
    }
    else if(myHash && myHash->table && ((myHash->currentSize - 1) / myHash->tableSize) >= 1 && item)
    {
        if(Hash_Rehash(myHash))
            return Hash_Insert(myHash, item);
    }
    
    return FALSE;
}
//******************************************************************************
void * Hash_Get_Item(HashMap * myHash, void * item)
{
    if(myHash && myHash->table && Hash_Contains(myHash, item))
    {
        size_t hashCode = Hash_HashingCode(myHash, item);
        
        if(myHash->table[hashCode])
        {
            Item * head = myHash->table[hashCode];
            
            while(head && !Hash_Comparables(head->item, item))
                head = head->next;
            
            if(head)
                return head->item;
        }
    }
        
    return NULL;
}
//******************************************************************************
void * Hash_Get_Item_With_Index(HashMap * myHash, size_t * index)
{
    if(myHash && myHash->table && index && myHash->table[*index])
    {
        return myHash->table[*index];
    }
    
    return NULL;
}
//******************************************************************************
boolean Hash_Comparables(void * item1, void * item2)
{
    if(item1 && item2)
    {
        size_t * addr1 = *(&item1) + (sizeof(item1) + sizeof(size_t));
        size_t valAddr1 = *addr1;
        
        size_t * addr2 = *(&item2) + (sizeof(item2) + sizeof(size_t));
        size_t valAddr2 = *addr2;
        
        if(valAddr1 == valAddr2)
            return TRUE;
    }    
    
    return FALSE;
}
//******************************************************************************
boolean Hash_Remove(HashMap * myHash, void * item)
{
    if(myHash && myHash->table && item)
    {
        size_t hashCode = Hash_HashingCode(myHash, item);
        
        if(myHash->table[hashCode] && Hash_Contains(myHash, item))
        {
            Item * temp = myHash->table[hashCode];
            Item * lastItem = temp;
            
            while(temp && (Hash_Get_HashCode(temp->item) != Hash_Get_HashCode(item)))
            {
                lastItem = temp;
                temp = temp->next;
            }
            
            if(temp == myHash->table[hashCode])
            {
                lastItem = temp;
                
                myHash->table[hashCode] = temp->next;
                
                if(lastItem)
                    free(lastItem);
                
                myHash->currentSize--;
                
                return TRUE;
            }
            
            temp = lastItem->next;
            lastItem->next = lastItem->next->next;
            
            if(temp)
                free(temp);
            
            myHash->currentSize--;
            
            return TRUE;
        }
    }
    return FALSE;
}
//******************************************************************************
boolean Hash_Rehash(HashMap * myHash)
{
    if(myHash && myHash->table)
    {
        size_t oldTableSize = myHash->tableSize;

        size_t newTableSize = Hash_nextPrime(oldTableSize * 2);
        
        HashMap * newHash = malloc(sizeof(HashMap));
        
        newHash->table = calloc(newTableSize,sizeof(void*) * newTableSize);
        
        newHash->currentSize = 0;
        newHash->tableSize = newTableSize;
        
        size_t item = 0;
        
        while(myHash->currentSize > 0)
        {
            if(item >= oldTableSize)
                item = 0;
            
            Item * newItem = Hash_Get_Item_With_Index(myHash, &item);
            if(newItem && newItem->item)
            {
                Hash_Insert(newHash, newItem->item);
                Hash_Remove(myHash, newItem->item);
            }
            
            item++;
                
        }
        
        free(myHash->table);
        
        myHash->table = newHash->table;
        myHash->currentSize = newHash->currentSize;
        myHash->tableSize = newHash->tableSize;
        free(newHash);
        
        return TRUE;
    }
    
    return FALSE;
}
//******************************************************************************
boolean Hash_Contains(HashMap * myHash, void * item)
{
    if(myHash && myHash->table && item)
    {
        size_t hashCode = Hash_HashingCode(myHash, item);
        
        Item * temp = myHash->table[hashCode];
        
        if(temp)
        {           
            while(temp && (Hash_Get_HashCode(temp->item) != Hash_Get_HashCode(item)))
            {
                temp = temp->next;
            }
            
            if(temp && Hash_Get_HashCode(temp->item) == Hash_Get_HashCode(item))
            {
                return TRUE;
            }
        }
    }
    
    return FALSE;
}
//*****************************************************************************
size_t Hash_Get_HashCode(void * item)
{
    if(item)
    {
        size_t * hashCodeAddress = *(&item) + (sizeof(item) + sizeof(size_t));
        
        return *hashCodeAddress;
    }
    return 0;
}
//***************************************************************************
size_t Hash_HashingCode(HashMap * myHash, void * item)
{
    if(item)
    {
        size_t tempHash = Hash_Get_HashCode(item);
        size_t hash = ((tempHash % myHash->tableSize));
        return hash;
    }
    
    
    return 0;
}
//***************************************************************************
boolean Hash_MakeEmpty(HashMap * myHash)
{
    if(myHash && myHash->table)
    {
        free(myHash->table);
        return TRUE;
    }
    
    return FALSE;
}
//***************************************************************************
size_t Hash_nextPrime(size_t n)
{
    if(n)
    {
        int div = 2;
        
        size_t newPrime = n;
        
        boolean isPrime = FALSE;
        
        while(!(isPrime = Hash_isPrime(newPrime)))
        {
                newPrime++;
            
        }
        
        if(isPrime)
            return newPrime;
    }
    
    return 0;
}
//***************************************************************************
boolean Hash_isPrime(size_t n)
{
    if(n)
    {
        //int div = 2;
        
        if (n % 2 == 0)
        {
            return FALSE;
        }
        else if(n % 3 == 0)
        {
            return FALSE;
        }
        else if(n % 5 == 0)
        {
            return FALSE;
        }
        else if(n % 7 == 0)
        {
            return FALSE;
        }
        else if(n % 11 == 0)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    
    return FALSE;
}
//while(prim && num <= number)
//{
//    if(getPrimeNumber(number, num) != 0)
//    {
//        prim = true;
//        if (getNextPrimeNumber(counter) != 0)
//        {
//            num = getNextPrimeNumber(counter);
//        }
//        counter++;
//    }
//    else
//    {
//        prim = false;
//    }
//    
//}

//if(prim)
//{
//    return number;
//}
//else
//{
//    return 0;
//}
//
//}
//private static int getPrimeNumber(int number, int div)
//{
//    if (number % div == 0 && number != div )
//    {
//        return 0;
//    }
//    else
//    {
//        return number;
//    }
//}
//
//private static int getNextPrimeNumber(int num)
//{
//    
//    if (num % 2 == 0)
//    {
//        return 0;
//    }
//    else
//    {
//        return num;
//    }
//}

