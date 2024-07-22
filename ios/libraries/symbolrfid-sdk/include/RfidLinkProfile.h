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
 *  Description:  RfidLinkProfile.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidLinkProfile : NSObject
{
    int m_RFModeIndex;
    SRFID_DIVIDERATIO m_DivideRatio;
    int m_BDR;
    SRFID_MODULATION m_Modulation;
    SRFID_FORWARDLINKMODULATION m_FLModulation;
    int m_PIE;
    int m_MinTari;
    int m_MaxTari;
    int m_StepTari;
    SRFID_SPECTRALMASKINDICATOR m_SpectralMaskIndicator;
    BOOL m_EPCHAGTCConformance;
}

- (int)getRFModeIndex;
- (void)setRFModeIndex:(int)val;
- (SRFID_DIVIDERATIO)getDivideRatio;
- (void)setDivideRatio:(SRFID_DIVIDERATIO)val;
- (int)getBDR;
- (void)setBDR:(int)val;
- (SRFID_MODULATION)getModulation;
- (void)setModulation:(SRFID_MODULATION)val;
- (SRFID_FORWARDLINKMODULATION)getFLModulation;
- (void)setFLModulation:(SRFID_FORWARDLINKMODULATION)val;
- (int)getPIE;
- (void)setPIE:(int)val;
- (int)getMinTari;
- (void)setMinTari:(int)val;
- (int)getMaxTari;
- (void)setMaxTari:(int)val;
- (int)getStepTari;
- (void)setStepTari:(int)val;
- (SRFID_SPECTRALMASKINDICATOR)getSpectralMaskIndicator;
- (void)setSpectralMaskIndicator:(SRFID_SPECTRALMASKINDICATOR)val;
- (BOOL)getEPCHAGTCConformance;
- (void)setEPCHAGTCConformance:(BOOL)val;
- (NSString*)getDivideRatioString;
- (NSString*)getModulationString;
- (NSString*)getForwardLinkModulationString;
- (NSString*)getSpectralMaskIndicatorString;


@end

