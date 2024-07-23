/******************************************************************************
 *
 *       Copyright Zebra Technologies, Inc. 2017
 *
 *       The copyright notice above does not evidence any
 *       actual or intended publication of such source code.
 *       The code contains Zebra Technologies
 *       Confidential Proprietary Information.
 *
 *
 *  Description:  RfidTemperatureEvent.h
 *
 *  Notes:
 *
 ******************************************************************************/


#ifndef RfidTemperatureEvent_h
#define RfidTemperatureEvent_h

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidTemperatureEvent : NSObject
{
    NSMutableString *m_EventCause;
    int m_STM32Temp;
    int m_RadioPATemp;
}

- (NSString*)getEventCause;
- (void)setEventCause:(NSString*)val;
- (int)getSTM32Temp;
- (void)setSTM32Temp:(int)val;
- (int)getRadioPATemp;
- (void)setRadioPATemp:(int)val;

@end

#endif /* RfidTemperatureEvent_h */
