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
 *  Description:  RfidStartTriggerConfig.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidStartTriggerConfig : NSObject
{
    BOOL m_StartOnHandheldTrigger;
    SRFID_TRIGGERTYPE m_TriggerType;
    unsigned int m_StartDelay;
    BOOL m_RepeatMonitoring;
}

- (BOOL)getStartOnHandheldTrigger;
- (void)setStartOnHandheldTrigger:(BOOL)val;
- (SRFID_TRIGGERTYPE)getTriggerType;
- (void)setTriggerType:(SRFID_TRIGGERTYPE)val;
- (unsigned int)getStartDelay;
- (void)setStartDelay:(unsigned int)val;
- (BOOL)getRepeatMonitoring;
- (void)setRepeatMonitoring:(BOOL)val;

@end
