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
 *  Description:  RfidRegulatoryConfig.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"


@interface srfidRegulatoryConfig : NSObject
{
    NSMutableString *m_RegionCode;
    NSMutableArray *m_EnabledChannelsList;
    SRFID_HOPPINGCONFIG m_HoppingConfig;
}

- (NSString*)getRegionCode;
- (void)setRegionCode:(NSString*)val;
- (NSArray*)getEnabledChannelsList;
- (void)setEnabledChannelsList:(NSArray*)val;
- (void)addEnabledChannel:(int)channelId;
- (SRFID_HOPPINGCONFIG)getHoppingConfig;
- (void)setHoppingConfig:(SRFID_HOPPINGCONFIG)val;

@end

