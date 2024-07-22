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
 *  Description:  RfidPowerEvent.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidPowerEvent : NSObject
{
    NSMutableString *m_Cause;
    float m_Voltage;
    float m_Current;
    float m_Power;
}

- (NSString*)getCause;
- (void)setCause:(NSString*)val;
- (float)getVoltage;
- (void)setVoltage:(float)val;
- (float)getCurrent;
- (void)setCurrent:(float)val;
- (float)getPower;
- (void)setPower:(float)val;

@end
