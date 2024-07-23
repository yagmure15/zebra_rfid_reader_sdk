//
//  RfidGetWifiStatusInfo.h
//  symbolrfid-sdk
//
//  Created by Dhanushka Adrian on 2023-06-16.
//  Copyright © 2023 Motorola Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface srfidGetWifiStatusInfo : NSObject
{
    NSString *wifiStatus;
    NSString *wifiState;
    NSString *macAddress;
}

- (NSString*)getWifiStatus;
- (void)setWifiStatus:(NSString*)val;

- (NSString*)getWifiState;
- (void)setWifiState:(NSString*)val;

- (NSString*)getMacAddress;
- (void)setMacAddress:(NSString*)val;

@end

NS_ASSUME_NONNULL_END
