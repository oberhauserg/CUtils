
#include "CircularQueue.h"
#include <stdio.h>


void CircularQueue_initParams(cq_parameter * params, void * queue, cq_parameter type, cq_parameter queueSize)
{

    params[CQ_SIZE_PARAM]    = queueSize;
    params[CQ_LENGTH_PARAM]  = 0;
    params[CQ_START_PARAM]   = 0;
    params[CQ_END_PARAM]     = 0;
    params[CQ_TYPE_PARAM]    = type;


    params[CQ_ADDRESS_PARAM] = (cq_parameter)queue;

}

void CircularQueue_Push(cq_parameter * params, void* value)
{

    cq_parameter * end;
    cq_parameter * length;

    uint8_t * array;

    if(!CircularQueue_isFull(params))
    {
        // The queue is not full
        end = &params[CQ_END_PARAM];
        length = &params[CQ_LENGTH_PARAM];

        switch(((cq_parameter *)params)[CQ_TYPE_PARAM])
        {

            case CQ_TYPE_UINT8_T:
            
                ((uint8_t*)params[CQ_ADDRESS_PARAM])[*end] = *(uint8_t*)value;

            break;
            case CQ_TYPE_UINT16_T:

                ((uint16_t*)params[CQ_ADDRESS_PARAM])[*end] = *(uint16_t*)value;

            break;
            case CQ_TYPE_UINT32_T:

                ((uint32_t*)params[CQ_ADDRESS_PARAM])[*end] = *(uint32_t*)value;

            break;
            case CQ_TYPE_FLOAT:
                
                ((float*)params[CQ_ADDRESS_PARAM])[*end] = *(float*)value;

            break;                

        }

        if((cq_parameter)end == params[CQ_SIZE_PARAM])
        {
            *end = 0;
        }
        else
        {
            (*end)++;
        }

        length++;

    }


}

void CircularQueue_Pop(cq_parameter * params, void * value)
{
    cq_parameter * start;
    cq_parameter * length;

    uint8_t * array;
    uint64_t address;


    if(!CircularQueue_isEmpty(params))
    {
        // The queue is not empty
        start = &params[CQ_START_PARAM];
        length = &params[CQ_LENGTH_PARAM];

        switch(((cq_parameter *)params)[CQ_TYPE_PARAM])
        {

            case CQ_TYPE_UINT8_T:

            
                address = (uint64_t)&(((uint8_t*)params[CQ_ADDRESS_PARAM])[*start]);

                value = (void*)address;

            break;
            case CQ_TYPE_UINT16_T:

                value = &(((uint16_t*)params[CQ_ADDRESS_PARAM])[*start]);

            break;
            case CQ_TYPE_UINT32_T:

                value = &(((uint32_t*)params[CQ_ADDRESS_PARAM])[*start]);

            break;
            case CQ_TYPE_FLOAT:
                
                value = &(((float*)params[CQ_ADDRESS_PARAM])[*start]);

            break;                

        }

        if((cq_parameter)start == params[CQ_SIZE_PARAM])
        {
            *start = 0;
        }
        else
        {
            (*start)++;
        }

        length++;

    }
}


bool CircularQueue_isFull(cq_parameter * params)
{
    return params[CQ_START_PARAM] == params[CQ_END_PARAM] && params[CQ_LENGTH_PARAM] > 0;
}

bool CircularQueue_isEmpty(cq_parameter * params)
{
    return params[CQ_START_PARAM] == params[CQ_END_PARAM] && params[CQ_LENGTH_PARAM] == 0;
}

float CircularQueue_getAverage(cq_parameter * params)
{

}

void main()
{

    cq_parameter testQueue[CQ_NUM_PARAMS];
    uint8_t array[10];

    uint8_t value[5] = {5, 6, 7, 8, 9};

    CircularQueue_initParams(testQueue, array, CQ_TYPE_UINT8_T, 10);
    
    printf("Adding %d to queue\n",value[0]);
    CircularQueue_Push(testQueue, &value[0]);

    printf("Adding %d to queue\n",value[1]);
    CircularQueue_Push(testQueue, &value[1]);

    printf("Adding %d to queue\n",value[2]);
    CircularQueue_Push(testQueue, &value[2]);

    printf("Adding %d to queue\n",value[3]);
    CircularQueue_Push(testQueue, &value[3]);

    printf("Adding %d to queue\n",value[4]);
    CircularQueue_Push(testQueue, &value[4]);

    uint8_t * pop_value;

    CircularQueue_Pop(testQueue, pop_value);
    printf("Popped from queue: %d\n", *pop_value);

    CircularQueue_Pop(testQueue, pop_value);
    printf("Popped from queue: %d\n", *pop_value);

    CircularQueue_Pop(testQueue, pop_value);
    printf("Popped from queue: %d\n", *pop_value);

    CircularQueue_Pop(testQueue, pop_value);
    printf("Popped from queue: %d\n", *pop_value);

    CircularQueue_Pop(testQueue, pop_value);
    printf("Popped from queue: %d\n", *pop_value);            



    printf("haha yes");

}