#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

//typedef unsigned short uint16_t;

typedef uint64_t cq_parameter;

#define CQ_SIZE_PARAM       0
#define CQ_LENGTH_PARAM     1
#define CQ_START_PARAM      2
#define CQ_END_PARAM        3
#define CQ_TYPE_PARAM       4
#define CQ_ADDRESS_PARAM    5

#define CQ_NUM_PARAMS 6

#define CQ_TYPE_UINT8_T     1
#define CQ_TYPE_UINT16_T    2
#define CQ_TYPE_UINT32_T    4
#define CQ_TYPE_FLOAT       4

typedef struct cq_params_struct
{
    cq_parameter size;
    cq_parameter length;
    cq_parameter start;
    cq_parameter end;
    size_t type;
    size_t array_position;
} CircularQueue;



void CircularQueue_initParams(CircularQueue * params, void * queue, size_t type_size, cq_parameter queueSize);

bool CircularQueue_Push(CircularQueue * params, void * value);
bool CircularQueue_Pop(CircularQueue * params, void ** value);

bool CircularQueue_isFull(CircularQueue * params);
bool CircularQueue_isEmpty(CircularQueue * params);

float CircularQueue_getAverage(CircularQueue * params);

#endif //CIRCULARQUEUE_H_