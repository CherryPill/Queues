#ifndef QUEUEFUNCS_H
#define QUEUEFUNCS_H
void showQueues(node**, int);
void _CERT_showQueue(node**, int ID);
void _CERT_enQueue(node**, int,int);
void _CERT_deQueue(node**, int,int);
void _CERT_clearQueue(node**,int);
void _CERT_specFunc(node**, int, int);
void _CERT_saveFile(node **queueArr, int qID, int num);
void saveFile(node **queueArr, int qnt);
void _CERT_setPointers(node **queueArr, int qID);
#endif