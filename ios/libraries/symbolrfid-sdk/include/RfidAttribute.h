//
//  RfidAttribute.h
//  RFIDDemoApp
//
//  Created by Neeraj Seshadri on 04/09/15.
//  Copyright (c) 2015 Motorola Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface srfidAttribute : NSObject
{
    NSMutableString *m_AttrType;
    int m_AttrNum;
    NSMutableString *m_AttrVal;
    int m_Offset;
    int m_PropertyVal;
    int m_Length;
}

- (int)getAttrNum;
- (void)setAttrNum:(int)val;
- (NSString*)getAttrVal;
- (void)setAttrVal:(NSString*)val;
- (int)getOffset;
- (void)setOffset:(int)val;
- (NSString*)getAttrType;
- (void)setAttrType:(NSString*)val;
- (int)getPropertyVal;
- (void)setPropertyVal:(int)val;
- (int)getLength;
- (void)setLength:(int)val;

@end
