/*
 ******************************************************************************
 *       Filename:    List.h
 *    Description:    Header file
 *       
 *        Version:    1.0
 *        Created:    2018-07-20
 *         Author:    chencheng
 *
 *        History:    initial draft
 ******************************************************************************
 */

#ifndef __LIST_H
#define __LIST_H


/** @class: List
*
*   @brief: link list class
*
*/
template <class DataType>
class List
{
private:
    DataType *   data;
    int          currentLength;
    int          maxSize;

public:
    List(int size);
    ~List();

    int getMaxSize();
    int getCurrentLength();
};



/* @func :    List
 *
 * @param:    construction function
 * 
 * @param:    initSize    initial size
 */
template <class DataType>
List<DataType>::List(int initSize)
{
    data = new DataType [initSize];

    maxSize       = initSize;
    currentLength = 0;
}


template <class DataType>
List<DataType>::~List()
{
    delete [] data;

    maxSize       = 0;
    currentLength = 0;
}


template <class DataType>
int List<DataType>::getCurrentLength()
{
    return currentLength;
}


template <class DataType>
int List<DataType>::getMaxSize()
{
    return maxSize;
}


#endif /* __LIST_H */