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
 *  Description:  RfidSdkTagData.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "AccessOperationCode.h"
#import "RfidSdkDefs.h"

@interface srfidTagData : NSObject
{
    NSMutableString *m_TagId;
    long m_FirstSeenTime;
    long m_LastSeenTime;
    NSMutableString* m_PC;
    short m_PeakRSSI;
    short m_PhaseInfo;
    short m_ChannelIndex;
    short m_TagSeenCount;
    srfidAccessOperationCode *m_OpCode;
    BOOL m_OperationSucceed;
    NSMutableString *m_OperationStatus;
    SRFID_MEMORYBANK m_MemoryBank;
    NSMutableString *m_MemoryBankData;
    NSMutableString *m_PermaLockData;
    int m_ModifiedWordCount;
    NSMutableString *m_g2v2Result;
    NSMutableString *m_g2v2Response;
    BOOL m_BrandIDStatusRfidTagData;
    NSMutableDictionary *multiRfidTagDataDictionary;
    int precentage;
}

- (NSString*)getTagId;
- (void)setTagId:(NSString*)val;
- (BOOL)getBrandIDStatusRfidTagData;
- (void)setBrandIDStatusRfidTagData:(BOOL)brandIdStatus;
- (long)getFirstSeenTime;
- (void)setFirstSeenTime:(long)val;
- (long)getLastSeenTime;
- (void)setLastSeenTime:(long)val;
- (NSString*)getPC;
- (void)setPC:(NSString*)val;
- (short)getPeakRSSI;
- (void)setPeakRSSI:(short)val;
- (short)getChannelIndex;
- (void)setChannelIndex:(short)val;
- (short)getPhaseInfo;
- (void)setPhaseInfo:(short)val;
- (short)getTagSeenCount;
- (void)setTagSeenCount:(short)val;
- (srfidAccessOperationCode*)getOpCode;
- (void)setOpCode:(srfidAccessOperationCode*)val;
- (BOOL)getOperationSucceed;
- (void)setOperationSucceed:(BOOL)val;
- (NSString*)getOperationStatus;
- (void)setOperationStatus:(NSString*)val;
- (SRFID_MEMORYBANK)getMemoryBank;
- (void)setMemoryBank:(SRFID_MEMORYBANK)val;
- (NSString*)getMemoryBankData;
- (void)setMemoryBankData:(NSString*)val;
- (void)setPermaLockData:(NSString*)val;
- (NSString*)getPermaLockData;
- (void)setModifiedWordCount:(int)val;
- (int)getModifiedWordCount;
-(void)setg2v2Result:(NSString*)val;
-(NSString *)getg2v2Result;
-(void)setg2v2Response:(NSString*)val;
-(NSString *)getg2v2Response;

-(NSMutableDictionary *)getTagDictionary;
-(void)setTagDictionary:(NSMutableDictionary *)tagDataDictionary;
-(int)getProximity;
-(void)setProximity:(int)percentageValue;

@end
