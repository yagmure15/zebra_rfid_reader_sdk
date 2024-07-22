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
 *  Description:  RfidReaderCapabilitiesInfo.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidReaderCapabilitiesInfo : NSObject
{
    NSString *m_SerialNumber;
    NSString *m_Model;
    NSString *m_Manufacturer;
    NSString *m_ManufacturingDate;
    NSString *m_ScannerName;
    NSString *m_AsciiVersion;
    int m_SelectFilterNum;
    int m_MinPower;
    int m_MaxPower;
    int m_PowerStep;
    NSString *m_AirProtocolVersion;
    NSString *m_BDAddress;
    int m_MaxAccessSequence;
}

- (NSString*)getSerialNumber;
- (void)setReaderSerialNumber:(NSString*)val;
- (NSString*)getModel;
- (void)setModel:(NSString*)val;
- (NSString*)getManufacturer;
- (void)setManufacturer:(NSString*)val;
- (NSString*)getManufacturingDate;
- (void)setManufacturingDate:(NSString*)val;
- (NSString*)getScannerName;
- (void)setScannerName:(NSString*)val;
- (NSString*)getAsciiVersion;
- (void)setAsciiVersion:(NSString*)val;
- (NSString*)getAirProtocolVersion;
- (void)setAirProtocolVersion:(NSString*)val;
- (NSString*)getBDAddress;
- (void)setBDAddress:(NSString*)val;
- (int)getSelectFilterNum;
- (void)setSelectFilterNum:(int)val;
- (int)getMinPower;
- (void)setMinPower:(int)val;
- (int)getMaxPower;
- (void)setMaxPower:(int)val;
- (int)getPowerStep;
- (void)setPowerStep:(int)val;
- (int)getMaxAccessSequence;
- (void)setMaxAccessSequence:(int)val;

@end

