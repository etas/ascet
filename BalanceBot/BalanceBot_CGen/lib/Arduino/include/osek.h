/*
 * osek.h
 *
 *  Created on: 10.07.2017
 *      Author: dya9fe
 */

#ifndef OSEK_H_
#define OSEK_H_

#ifndef TASK                                                                                            /* rtk_req 347 */
 #define TASK(x) void x(void)
#endif /* TASK */

void TerminateTask();
void DisableAllInterrupts();
void EnableAllInterrupts() ;

#endif /* OSEK_H_ */
