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
 *  Description:  RfidRegionInfo.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"


@interface srfidRegionInfo : NSObject
{
    NSMutableString *m_RegionCode;
    NSMutableString *m_RegionName;
}

- (NSString*)getRegionCode;
- (void)setRegionCode:(NSString*)val;
- (NSString*)getRegionName;
- (void)setRegionName:(NSString*)val;

@end

