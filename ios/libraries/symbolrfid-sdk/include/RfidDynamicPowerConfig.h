/******************************************************************************
 *
 *       Copyright Zebra Technologies, Inc. 2015
 *
 *       The copyright notice above does not evidence any
 *       actual or intended publication of such source code.
 *       The code contains Zebra Technologies
 *       Confidential Proprietary Information.
 *
 *
 *  Description:  RfidDynamicPowerConfig.h
 *
 *  Notes: Command used to enable/disable the Antenna's dynamic power
 *         optimization feature.
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>

@interface srfidDynamicPowerConfig : NSObject
{
    BOOL m_DynamicPowerOptimizationEnabled;
}

- (BOOL)getDynamicPowerOptimizationEnabled;
- (void)setDynamicPowerOptimizationEnabled:(BOOL)val;

@end
