#ifndef _BT_KERNEL_H_
#define _BT_KERNEL_H_

#include <bt_types.h>
#include <process/bt_threads.h>

typedef void (*BT_FN_TASK_ENTRY)(void *pParam);

BT_ERROR 	BT_kStartScheduler	(void);
void 		BT_kStopScheduler	(void);
void 	   *BT_kTaskCreate		(BT_FN_TASK_ENTRY pfnStartRoutine, const BT_i8 *szpName, BT_THREAD_CONFIG *pConfig, BT_ERROR *pError);
void		BT_kTaskDelete 		(void *pTaskHandle);

BT_TICK		BT_kTickCount		(void);
void		BT_kTaskDelay		(BT_TICK ulTicks);
void		BT_kTaskDelayUntil 	(BT_TICK *pulPreviousWakeTime, BT_TICK ulTimeIncrement);
void 		BT_kTaskYield		(void);
void 	   *BT_kGetThreadTag	(void *pThreadID);
void		BT_kSetThreadTag	(void *pThreadID, void *pTagData);

void 	   *BT_kMutexCreate		(void);
void 	   *BT_kRecursiveMutexCreate(void);
void	    BT_kMutexDestroy	(void *pMutex);
BT_BOOL		BT_kMutexPend		(void *pMutex, BT_u32 ulTimeout);
BT_BOOL		BT_kMutexRelease	(void *pMutex);
BT_BOOL		BT_kMutexPendRecursive		(void *pMutex, BT_u32 ulTimeout);
BT_BOOL		BT_kMutexReleaseRecursive	(void *pMutex);
BT_BOOL		BT_kMutexReleaseFromISR		(void *pMutex, BT_BOOL *pbHigherPriorityTaskWoken);

void 	   *BT_kQueueCreate				(BT_u32 ulElements, BT_u32 ulElementWidth);
void 		BT_kQueueDestroy			(void *pQueue);
BT_ERROR 	BT_kQueueSend				(void *pQueue, const void* pMessage, BT_TICK oTimeoutTicks);
BT_ERROR 	BT_kQueueSendFromISR		(void *pQueue, const void* pMessage, BT_BOOL *pbHigherPriorityTaskWoken);
BT_ERROR 	BT_kQueueSendToFront		(void *pQueue, const void* pMessage, BT_TICK oTimeoutTicks);
BT_ERROR 	BT_kQueueSendToBack			(void *pQueue, const void* pMessage, BT_TICK oTimeoutTicks);
BT_ERROR 	BT_kQueueReceive			(void *pQueue, void* pMessage, BT_TICK oTimeoutTicks);
BT_ERROR 	BT_kQueueReceiveFromISR		(void *pQueue, void* pMessage, BT_BOOL *pbHigherPriorityTaskWoken);
BT_u32		BT_kQueueMessagesWaiting	(void *pQueue);


void 		BT_kEnterCritical	();
void 		BT_kExitCritical	();

#endif
