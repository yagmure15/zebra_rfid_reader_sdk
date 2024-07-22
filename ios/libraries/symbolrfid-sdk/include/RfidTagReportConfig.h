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
 *  Description:  RfidTagReportConfig.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidTagReportConfig : NSObject
{
    BOOL m_IncFirstSeenTime;
    BOOL m_IncLastSeenTime;
    BOOL m_IncPC;
    BOOL m_IncRSSI;
    BOOL m_IncPhase;
    BOOL m_IncChannelIdx;
    BOOL m_IncTagSeenCount;
}

- (BOOL)getIncFirstSeenTime;
- (void)setIncFirstSeenTime:(BOOL)val;
- (BOOL)getIncLastSeenTime;
- (void)setIncLastSeenTime:(BOOL)val;
- (BOOL)getIncPC;
- (void)setIncPC:(BOOL)val;
- (BOOL)getIncRSSI;
- (void)setIncRSSI:(BOOL)val;
- (BOOL)getIncPhase;
- (void)setIncPhase:(BOOL)val;
- (BOOL)getIncChannelIdx;
- (void)setIncChannelIdx:(BOOL)val;
- (BOOL)getIncTagSeenCount;
- (void)setIncTagSeenCount:(BOOL)val;

@end
