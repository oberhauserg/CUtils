
#include "CircularQueue.h"
#include <stdio.h>


uint8_t cq_get_uint8_t(cq_parameter i);
uint16_t cq_get_uint16_t(cq_parameter i);
uint32_t cq_get_uint32_t(cq_parameter i);
float cq_get_float(cq_parameter i);

void CircularQueue_initParams(CircularQueue * params, void * queue, size_t type_size, cq_parameter queueSize)
{

    params->size    = queueSize;
    params->length  = 0;
    params->start   = 0;
    params->end     = 0;
    params->type    = type_size;

    params->array_position = (uint64_t)queue;

}

bool CircularQueue_Push(CircularQueue * params, void* value)
{

    bool insert_success = false;

    if(!CircularQueue_isFull(params))
    {

        for(size_t i = 0; i < params->type; i++)
        {
            *((uint8_t*)params->array_position+params->type*params->end + i) = *(uint8_t*)(value + i);
        }

        params->end++;

        if(params->end == params->size)
        {
            params->end = 0;
        }
    
        params->length++;

        insert_success = true;

    }

    return insert_success;

}

bool CircularQueue_Pop(CircularQueue * params, void ** value)
{

    bool remove_success = false;

    if(!CircularQueue_isEmpty(params))
    {

        *value = (void*)(params->array_position+params->type*params->start);

        params->start++;

        if(params->start == params->size)
        {
            params->start = 0;
        }
        
        params->length--;

        remove_success = true;

    }

    return remove_success;

}


bool CircularQueue_isFull(CircularQueue * params)
{
    return params->start == params->end && params->length > 0;
}

bool CircularQueue_isEmpty(CircularQueue * params)
{
    return params->start == params->end && params->length == 0;
}

// These functions assume unsigned arithmetic types
uint64_t CircularQueue_getSumUInt(CircularQueue * params)
{

    uint64_t sum = 0;

    for(cq_parameter i = 0; i < params->length; i++)
    {
        
    }

}

float CircularQueue_getAverageUInt(CircularQueue * params)
{

}

// These functions assume signed arithmetic types
int64_t CircularQueue_getSumInt(CircularQueue * params);
float CircularQueue_getAverageInt(CircularQueue * params);

// These functions assume floating point types
float CircularQueue_getSumFloat(CircularQueue * params);
float CircularQueue_getAverageFloat(CircularQueue * params);


#define ENABLE_CQ_TESTS
#ifdef ENABLE_CQ_TESTS

#include <math.h>

#define TEST_VALUES_SIZE 16
#define TEST_QUEUE_SIZE 10

#define BOOL_TO_STR(boolean) boolean ? "true" : "false"

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

bool byte_push_expected_values[TEST_VALUES_SIZE] = {true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false};
uint8_t byte_pop_expected_values[TEST_VALUES_SIZE] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 14, 14, 14, 14, 14, 14};

bool cq_byte_test()
{
    CircularQueue byteQueue;
    uint8_t bytes[TEST_QUEUE_SIZE];

    CircularQueue_initParams(&byteQueue, bytes, sizeof(uint8_t), sizeof(bytes)/sizeof(bytes[0]));

    uint8_t byte_test_values[TEST_VALUES_SIZE] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19 , 20};

    for(uint8_t i = 0; i < TEST_VALUES_SIZE; i++)
    {
        bool success = CircularQueue_Push(&byteQueue, &byte_test_values[i]);
        printf("Adding %d to queue. Success: %s Expected %s \n",byte_test_values[i], BOOL_TO_STR(success), BOOL_TO_STR(byte_push_expected_values[i]));

        if(byte_push_expected_values[i] != success)
            return false;
    
    }

    uint8_t * pop_value;

    for(uint8_t i = 0; i < TEST_VALUES_SIZE; i++)
    {
        CircularQueue_Pop(&byteQueue, (void**)&pop_value);
        printf("Popped from queue: %d Expected: %d\n", *pop_value, byte_pop_expected_values[i]);

        if(byte_pop_expected_values[i] != *pop_value)
            return false;

    }

    return true;

}

bool cq_short_test()
{
    CircularQueue byteQueue;
    uint16_t bytes[TEST_QUEUE_SIZE];

    CircularQueue_initParams(&byteQueue, bytes, sizeof(uint16_t), sizeof(bytes)/sizeof(bytes[0]));

    uint16_t byte_test_values[TEST_VALUES_SIZE] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19 , 20};

    for(uint16_t i = 0; i < TEST_VALUES_SIZE; i++)
    {
        bool success = CircularQueue_Push(&byteQueue, &byte_test_values[i]);
        printf("Adding %d to queue. Success: %s Expected %s \n",byte_test_values[i], BOOL_TO_STR(success), BOOL_TO_STR(byte_push_expected_values[i]));

        if(byte_push_expected_values[i] != success)
            return false;
    
    }

    uint16_t * pop_value;

    for(uint16_t i = 0; i < TEST_VALUES_SIZE; i++)
    {
        CircularQueue_Pop(&byteQueue, (void**)&pop_value);
        printf("Popped from queue: %d Expected: %d\n", *pop_value, byte_pop_expected_values[i]);

        if(byte_pop_expected_values[i] != *pop_value)
            return false;

    }

    return true;

}

bool cq_float_test()
{
    CircularQueue byteQueue;
    float bytes[TEST_QUEUE_SIZE];

    CircularQueue_initParams(&byteQueue, bytes, sizeof(float), sizeof(bytes)/sizeof(bytes[0]));

    float byte_test_values[TEST_VALUES_SIZE] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19 , 20};

    for(uint8_t i = 0; i < TEST_VALUES_SIZE; i++)
    {
        bool success = CircularQueue_Push(&byteQueue, &byte_test_values[i]);
        printf("Adding %f to queue. Success: %s Expected %s \n",byte_test_values[i], BOOL_TO_STR(success), BOOL_TO_STR(byte_push_expected_values[i]));

        if(byte_push_expected_values[i] != success)
            return false;
    
    }

    float * pop_value;

    for(uint8_t i = 0; i < TEST_VALUES_SIZE; i++)
    {
        CircularQueue_Pop(&byteQueue, (void**)&pop_value);
        printf("Popped from queue: %f Expected: %d\n", *pop_value, byte_pop_expected_values[i]);

        if(byte_pop_expected_values[i] != *pop_value)
            return false;

    }

    return true;

}

int main()
{

    bool test_passed = true;

    if(!cq_byte_test())
        return 1;

    if(!cq_short_test())
        return 1;

    if(!cq_float_test())
        return 1;


    return 0;

}

#endif