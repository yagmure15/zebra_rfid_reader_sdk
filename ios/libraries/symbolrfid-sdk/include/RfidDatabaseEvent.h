/******************************************************************************
 *
 *       Copyright Zebra Technologies, Inc. 2017
 *
 *       The copyright notice above does not evidence any
 *       actual or intended publication of such source code.
 *       The code contains Zebra Technologies
 *       Confidential Proprietary Information.
 *
 *
 *  Description:  RfidDatabaseEvent.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidDatabaseEvent : NSObject
{
    NSMutableString *m_DatabaseEvent;
    int m_EntriesUsed;
    int m_EntriesRemaining;
}

- (NSString*)getCause;
- (void)setCause:(NSString*)val;
- (int)getEntriesUsed;
- (void)setEntriesUsed:(int)val;
- (int)getEntriesRemaining;
- (void)setEntriesRemaining:(int)val;

@end
