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
 *  Description:  RfidAntennaConfiguration.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidAntennaConfiguration : NSObject
{
    short m_Power;
    short m_LinkProfileIdx;
    int m_Tari;
    BOOL m_DoSelect;
}

- (short)getPower;
- (void)setPower:(short)val;
- (short)getLinkProfileIdx;
- (void)setLinkProfileIdx:(short)val;
- (int)getTari;
- (void)setTari:(int)val;
- (BOOL)getDoSelect;
- (void)setDoSelect:(BOOL)val;

@end

