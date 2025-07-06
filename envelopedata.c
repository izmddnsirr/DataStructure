#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

struct EnvelopeData
{
    char epacketName[20];
    double pricePerPacket;
    int quantitySold;
    double totalSales;
};

typedef struct EnvelopeData evData;

struct EnvelopeNode
{
    evData data;
    struct EnvelopeNode *next;
};

typedef struct EnvelopeNode evNode;

// int main(){
//     evNoe
// };
