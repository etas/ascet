/**
 * Copyright ETAS GmbH, Stuttgart, Germany. All rights reserved.
 *
 * Consistency conversion API
 */
#ifndef ESDL_DEFAULTCONVERSION_H
#define ESDL_DEFAULTCONVERSION_H

#define ESDL_ConsistencyConversion_u8(X) (~(X))
#define ESDL_ConsistencyConversion_s8(X) (~(X))
#define ESDL_ConsistencyConversion_u16(X) (~(X))
#define ESDL_ConsistencyConversion_s16(X) (~(X))
#define ESDL_ConsistencyConversion_u32(X) (~(X))
#define ESDL_ConsistencyConversion_s32(X) (~(X))
#define ESDL_ConsistencyConversion_r32(X) ((X))
#define ESDL_ConsistencyConversion_r64(X) ((X))

#endif /* ESDL_DEFAULTCONVERSION_H */