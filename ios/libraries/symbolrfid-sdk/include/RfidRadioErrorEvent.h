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
 *  Description:  RfidRadioErrorEvent.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidRadioErrorEvent : NSObject
{
    NSMutableString *m_Cause;
    int m_ErrorNumber;
}

- (NSString*)getCause;
- (void)setCause:(NSString*)val;
- (int)getErrorNumber;
- (void)setErrorNumber:(int)val;

@end
