//
//  RfidMultipleTagsConfig.h
//  symbolrfid-sdk
//
//  Created by Dhanushka Adrian on 2021-09-30.
//  Copyright © 2021 Zebra Technologies Corp. and/or its affiliates. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

NS_ASSUME_NONNULL_BEGIN

/// The multi tag configuration object
@interface srfidMultipleTagsConfig : NSObject
{
    NSMutableDictionary *multipleTagDictionary;
}

- (BOOL)isMultiTagLocatePerforming;

- (BOOL)addItem:(NSString *)epc aRSSIValueLimit:(int)rssiValue;

- (BOOL)deleteItem:(NSString *)epc;

- (void)purgeItem;

- (int)getTagListCount;

- (NSMutableDictionary *)getTagList;

@end



NS_ASSUME_NONNULL_END
