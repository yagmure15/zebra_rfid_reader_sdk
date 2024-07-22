/******************************************************************************
 *
 *       Copyright Zebra Technologies, Inc. 2014 - 2015
 *
 *       The copyright notice above does not evidence any
 *       actual or intended publication of such source code.
 *       The code contains Zebra Technologies
 *       Confidential Proprietary Information.
 *
 *
 *  Description:  RfidReportConfig.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>

@interface srfidReportConfig : NSObject
{
    BOOL m_IncFirstSeenTime;
    BOOL m_IncLastSeenTime;
    BOOL m_IncPC;
    BOOL m_IncRSSI;
    BOOL m_IncPhase;
    BOOL m_IncChannelIndex;
    BOOL m_IncTagSeenCount;
    NSMutableDictionary *multipleTagDictionary;
    BOOL isSdkMultipleTagsLocationing;
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
- (BOOL)getIncChannelIndex;
- (void)setIncChannelIndex:(BOOL)val;
- (BOOL)getIncTagSeenCount;
- (void)setIncTagSeenCount:(BOOL)val;
- (NSMutableDictionary*)getTagDictionary;
- (void)setTagDictionary:(NSMutableDictionary *)tagDictionary;
- (BOOL)getSdkStatusMultipleTagsLocationing;
- (void)setSdkStatusMultipleTagsLocationing:(BOOL)multipleTagLocationingStatus;

- (BOOL)addItem:(NSString *)epc aRSSIValueLimit:(int)rssiValue;
- (BOOL)deleteItem:(NSString *)epc;
- (void)purgeItem;
- (int)getTagListCount;
- (NSMutableDictionary *)getTagList;

@end
