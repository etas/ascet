/*
 * EngineCounter.h
 *
 *  Created on: 15.10.2018
 *      Author: BFR9FE
 */

#ifndef SRC_ENGINES_H_
#define SRC_ENGINES_H_

//Initialize the drive module for the two engines
void setupEngines();

void stopEngines();

void setEnginePower();

void resetBalancerData();

void getCounterData();

#endif /* SRC_ENGINES_H_ */
