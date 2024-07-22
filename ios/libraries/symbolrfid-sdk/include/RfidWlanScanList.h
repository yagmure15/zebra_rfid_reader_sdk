//
//  RfidWlanScanList.h
//  symbolrfid-sdk
//
//  Created by Madesan Venkatraman on 20/06/23.
//  Copyright © 2023 Motorola Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface srfidWlanScanList : NSObject
{

    NSString *wlanSsid;
    NSString *wlanKey;
    NSString *wlanLevel;
    NSString *wlanMac;
  
}

- (NSString*)getWlanMac;
- (void)setWlanMac:(NSString*)val;

- (NSString*)getWlanSsid;
- (void)setWlanSsid:(NSString*)val;

- (NSString*)getWlanKey;
- (void)setWlanKey:(NSString*)val;
   
- (NSString*)getWlanLevel;
- (void)setWlanLevel:(NSString*)val;



@end

NS_ASSUME_NONNULL_END
