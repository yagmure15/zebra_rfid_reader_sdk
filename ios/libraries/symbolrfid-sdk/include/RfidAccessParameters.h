//
//  RfidAccessParameters.h
//  RFIDDemoApp
//
//  Created by Neeraj Seshadri on 02/02/16.
//  Copyright © 2016 Motorola Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidAccessParameters : NSObject

@property (nonatomic, assign) SRFID_ACCESSOPERATIONCODE accessOperationCode;
@property (nonatomic, assign) SRFID_MEMORYBANK memoryBank;
@property (nonatomic, assign) short offset;
@property (nonatomic, assign) short length;
@property (nonatomic, assign) long password;
@property (nonatomic, assign) BOOL doBlockWrite;
@property (nonatomic, assign) BOOL doLock;
@property (nonatomic, assign) short blockPtr;
@property (nonatomic, assign) short blockRange;
@property (nonatomic, strong) NSString  *blockMask;
@property (nonatomic, strong) NSString  *dataToWrite;
@property (nonatomic, assign) SRFID_ACCESSPERMISSION accessPermissions;


@end
