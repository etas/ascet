uint16 sanitycalc;

/* Basic check to see if processor is able to perform simple operations */
/* Sum the inputs - maximum 510 */
sanitycalc = (uint16)APP_Sanity1 + APP_Sanity2;
/* multiply by 4 - maximum 2040 */
sanitycalc = sanitycalc * 4;
/* Use double bitmask, and right shift to get return */
return((uint8)(sanitycalc & 0x00FC) | (uint8)((sanitycalc & 0x0300) >> 8));
