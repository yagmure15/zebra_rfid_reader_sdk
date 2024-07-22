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
 *  Description:  AccessOperationCode.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidAccessOperationCode : NSObject
{
    NSString *m_Name;
    SRFID_ACCESSOPERATIONCODE m_Ordinal;
}

- (id)initAccessOperationCode:(NSString*)name aOrdinal:(SRFID_ACCESSOPERATIONCODE)ordinal;

+ (srfidAccessOperationCode*)getAccessOperationCodeValue:(SRFID_ACCESSOPERATIONCODE)value;
+ (srfidAccessOperationCode*)getAccessOperationCodeValueFromString:(NSString*)str;

- (NSString*)getName;
- (SRFID_ACCESSOPERATIONCODE)getOrdinal;

@end
