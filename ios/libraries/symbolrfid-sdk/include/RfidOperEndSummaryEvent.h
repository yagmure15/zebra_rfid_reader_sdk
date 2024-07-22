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
 *  Description:  RfidOperEndSummaryEvent.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"


@interface srfidOperEndSummaryEvent : NSObject
{
    long m_TotalTimeUs;
    int m_TotalTags;
    int m_TotalRounds;
}

- (long)getTotalTimeUs;
- (void)setTotalTimeUs:(long)val;
- (int)getTotalTags;
- (void)setTotalTags:(int)val;
- (int)getTotalRounds;
- (void)setTotalRounds:(int)val;

@end
