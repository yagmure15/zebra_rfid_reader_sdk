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
 *  Description:  RfidBatteryEvent.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"


@interface srfidBatteryEvent : NSObject
{
    int m_PowerLevel;
    BOOL m_IsCharging;
    NSMutableString *m_EventCause;
}

- (int)getPowerLevel;
- (void)setPowerLevel:(int)val;
- (BOOL)getIsCharging;
- (void)setIsCharging:(BOOL)val;
- (NSString*)getEventCause;
- (void)setEventCause:(NSString*)val;

@end
