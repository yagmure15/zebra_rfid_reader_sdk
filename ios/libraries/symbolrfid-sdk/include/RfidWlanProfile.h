//
//  RfidWlanProfile.h
//  symbolrfid-sdk
//
//  Created by Dhanushka Adrian on 2023-06-21.
//  Copyright © 2023 Motorola Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface srfidWlanProfile : NSObject
{
    NSString *wlanState;
    NSString *wlanSsid;
    NSString *wlanPassword;
    NSString *wlanConfig;
  
}

- (NSString*)getWlanState;
- (void)setWlanState:(NSString*)val;

- (NSString*)getWlanSsid;
- (void)setWlanSsid:(NSString*)val;

- (NSString*)getWlanPassword;
- (void)setWlanPassword:(NSString*)val;
   
- (NSString*)getWlanConfig;
- (void)setWlanConfig:(NSString*)val;



@end

NS_ASSUME_NONNULL_END
