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
 *  Description:  RfidStopTriggerConfig.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidStopTriggerConfig : NSObject
{
    BOOL m_StopOnHandheldTrigger;
    SRFID_TRIGGERTYPE m_TriggerType;
    BOOL m_StopOnTagCount;
    unsigned int m_StopTagCount;
    BOOL m_StopOnTimeout;
    unsigned int m_StopTimeout;
    BOOL m_StopOnInventoryCount;
    unsigned int m_StopInventoryCount;
    BOOL m_StopOnAccessCount;
    unsigned int m_StopAccessCount;
}

- (BOOL)getStopOnHandheldTrigger;
- (void)setStopOnHandheldTrigger:(BOOL)val;
- (SRFID_TRIGGERTYPE)getTriggerType;
- (void)setTriggerType:(SRFID_TRIGGERTYPE)val;
- (BOOL)getStopOnTagCount;
- (void)setStopOnTagCount:(BOOL)val;
- (unsigned int)getStopTagCount;
- (void)setStopTagCount:(unsigned int)val;
- (BOOL)getStopOnTimeout;
- (void)setStopOnTimeout:(BOOL)val;
- (unsigned int)getStopTimeout;
- (void)setStopTimout:(unsigned int)val;
- (BOOL)getStopOnInventoryCount;
- (void)setStopOnInventoryCount:(BOOL)val;
- (unsigned int)getStopInventoryCount;
- (void)setStopInventoryCount:(unsigned int)val;
- (BOOL)getStopOnAccessCount;
- (void)setStopOnAccessCount:(BOOL)val;
- (unsigned int)getStopAccessCount;
- (void)setStopAccessCount:(unsigned int)val;

@end
