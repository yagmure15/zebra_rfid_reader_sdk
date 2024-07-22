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
 *  Description:  RfidAccessCriteria.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidTagFilter.h"

@interface srfidAccessCriteria : NSObject

@property (atomic, retain) srfidTagFilter* tagFilter1;
@property (atomic, retain) srfidTagFilter* tagFilter2;

@end
