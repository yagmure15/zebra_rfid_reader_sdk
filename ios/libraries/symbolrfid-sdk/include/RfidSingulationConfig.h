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
 *  Description:  RfidSingulationConfig.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidSingulationConfig : NSObject
{
    SRFID_SLFLAG m_SLFlag;
    SRFID_SESSION m_Session;
    SRFID_INVENTORYSTATE m_State;
    int m_TagPopulation;
}

- (SRFID_SLFLAG)getSLFlag;
- (void)setSlFlag:(SRFID_SLFLAG)val;
- (SRFID_SESSION)getSession;
- (void)setSession:(SRFID_SESSION)val;
- (SRFID_INVENTORYSTATE)getInventoryState;
- (void)setInventoryState:(SRFID_INVENTORYSTATE)val;
- (int)getTagPopulation;
- (void)setTagPopulation:(int)val;

@end

