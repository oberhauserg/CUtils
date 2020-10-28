#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_

#include <stdint.h>
#include <stdbool.h>

//typedef unsigned short uint16_t;

typedef int cq_parameter;

#define CQ_SIZE_PARAM       0
#define CQ_LENGTH_PARAM     1
#define CQ_START_PARAM      2
#define CQ_END_PARAM        3
#define CQ_TYPE_PARAM       4
#define CQ_ADDRESS_PARAM    5

#define CQ_NUM_PARAMS 6

#define CQ_TYPE_UINT8_T     0
#define CQ_TYPE_UINT16_T    1
#define CQ_TYPE_UINT32_T    2
#define CQ_TYPE_FLOAT       3


void CircularQueue_initParams(cq_parameter * params, void * queue, cq_parameter type, cq_parameter queueSize);

void CircularQueue_PushVoid(cq_parameter * params, void * value);
void CircularQueue_PopVoid(cq_parameter * params, void * value);

bool CircularQueue_isFull(cq_parameter * params);
bool CircularQueue_isEmpty(cq_parameter * params);

float CircularQueue_getAverage(cq_parameter * params);

#endif //CIRCULARQUEUE_H_