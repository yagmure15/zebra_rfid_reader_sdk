//
//  RfidBatteryStatusInformation.h
//  symbolrfid-sdk
//
//  Created by Dhanushka Adrian on 2022-11-03.
//  Copyright © 2022 Motorola Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RfidSdkDefs.h"

//NS_ASSUME_NONNULL_BEGIN

/// Responsible for battery status information
@interface srfidRfidBatteryStatusInformation : NSObject
{
    NSMutableString *batteryStatusTittle;
    NSMutableString *batterStatusValue;
}

- (NSString*)getBatteryStatusTittle;
- (void)setBatteryStatusTittle:(NSString*)val;
- (NSString*)getBatterStatusValue;
- (void)setBatteryStatusValue:(NSString*)val;
@end

//NS_ASSUME_NONNULL_END
