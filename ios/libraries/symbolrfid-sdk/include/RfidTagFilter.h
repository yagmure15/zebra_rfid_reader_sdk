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
 *  Description:  RfidTagFilter.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidTagFilter : NSObject
{
    SRFID_MEMORYBANK m_Filter_MaskBank;
    short m_Filter_MaskStartPos;
    NSMutableString *m_Filter_Data;
    NSMutableString *m_Filter_Mask;
    short m_Filter_MatchLength;
    BOOL m_Filter_DoMatch;
}

- (SRFID_MEMORYBANK)getFilterMaskBank;
- (void)setFilterMaskBank:(SRFID_MEMORYBANK)val;
- (short)getFilterMaskStartPos;
- (void)setFilterMaskStartPos:(short)val;
- (NSString*)getFilterData;
- (void)setFilterData:(NSString*)val;
- (NSString*)getFilterMask;
- (void)setFilterMask:(NSString*)val;
- (short)getFilterMatchLength;
- (void)setFilterMatchLength:(short)val;
- (BOOL)getFilterDoMatch;
- (void)setFilterDoMatch:(BOOL)val;

@end
