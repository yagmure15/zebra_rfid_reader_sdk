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
 *  Description:  RfidPreFilter.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"


@interface srfidPreFilter : NSObject
{
    SRFID_SELECTTARGET m_Target;
    SRFID_SELECTACTION m_Action;
    SRFID_MEMORYBANK m_MemoryBank;
    int m_MaskStartPos;
    NSMutableString *m_MatchPattern;
    int tagMatchLength;
}

- (SRFID_SELECTTARGET)getTarget;
- (void)setTarget:(SRFID_SELECTTARGET)val;
- (SRFID_SELECTACTION)getAction;
- (void)setAction:(SRFID_SELECTACTION)val;
- (SRFID_MEMORYBANK)getMemoryBank;
- (void)setMemoryBank:(SRFID_MEMORYBANK)val;
- (int)getMaskStartPos;
- (void)setMaskStartPos:(int)val;
- (int)getMatchLength;
- (void)setMatchLength:(int)length;
- (NSString*)getMatchPattern;
- (void)setMatchPattern:(NSString*)val;


@end

