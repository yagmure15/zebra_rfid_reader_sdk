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
 *  Description:  RfidSdkApi.h
 *
 *  Notes:
 *
 ******************************************************************************/
#import "RfidSdkDefs.h"
#import "RfidSdkApiDelegate.h"
#import "RfidReportConfig.h"
#import "RfidAccessConfig.h"
#import "RfidAntennaConfiguration.h"
#import "RfidDynamicPowerConfig.h"
#import "RfidSingulationConfig.h"
#import "RfidTagReportConfig.h"
#import "RfidReaderVersionInfo.h"
#import "RfidReaderCapabilitiesInfo.h"
#import "RfidStartTriggerConfig.h"
#import "RfidStopTriggerConfig.h"
#import "RfidRegulatoryConfig.h"
#import "RfidPreFilter.h"
#import "RfidAttribute.h"
#import "RfidAccessCriteria.h"
#import "RfidAccessParameters.h"
#import "RfidUniqueTagsReport.h"
#import "RfidUntraceableConfig.h"
#import "RfidGetWifiStatusInfo.h"

#ifndef __RFID_SDK_API__
#define __RFID_SDK_API__

@protocol srfidISdkApi <NSObject>

- (NSString*) srfidGetSdkVersion;

- (SRFID_RESULT) srfidSetDelegate:(id<srfidISdkApiDelegate>)delegate;
- (SRFID_RESULT) srfidSubsribeForEvents:(int)sdkEventsMask;
- (SRFID_RESULT) srfidUnsubsribeForEvents:(int)sdkEventsMask;

- (SRFID_RESULT) srfidSetOperationalMode:(int)operationalMode;

- (SRFID_RESULT) srfidGetAvailableReadersList:(NSMutableArray**)availableReadersList;
- (SRFID_RESULT) srfidGetActiveReadersList:(NSMutableArray**)activeReadersList;

- (SRFID_RESULT) srfidEstablishCommunicationSession:(int)readerID;
- (SRFID_RESULT) srfidTerminateCommunicationSession:(int)readerID;
- (SRFID_RESULT) srfidEstablishAsciiConnection:(int)readerID aPassword:(NSString*)password;

- (SRFID_RESULT) srfidEnableAvailableReadersDetection:(BOOL)enable;
- (SRFID_RESULT) srfidEnableAutomaticSessionReestablishment:(BOOL)enable;

- (SRFID_RESULT) srfidStartRapidRead:(int)readerID aReportConfig:(srfidReportConfig*)reportConfig aAccessConfig:(srfidAccessConfig*)accessConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidStopRapidRead:(int)readerID aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidStartInventory:(int)readerID aMemoryBank:(SRFID_MEMORYBANK)memoryBankId aReportConfig:(srfidReportConfig*)reportConfig aAccessConfig:(srfidAccessConfig*)accessConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidStopInventory:(int)readerID aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidPerformBrandCheckInventory:(int)readerID aMemoryBank:(SRFID_MEMORYBANK)memoryBankId aReportConfig:(srfidReportConfig*)reportConfig aAccessConfig:(srfidAccessConfig*)accessConfig aStatusMessage:(NSString**)statusMessage brandId:(NSString*)brandId epcLenth:(int)epcLength;


- (SRFID_RESULT) srfidGetSupportedLinkProfiles:(int)readerID aLinkProfilesList:(NSMutableArray**)linkProfilesList aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidGetAntennaConfiguration:(int)readerID aAntennaConfiguration:(srfidAntennaConfiguration**)antennaConfiguration aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetAntennaConfiguration:(int)readerID aAntennaConfiguration:(srfidAntennaConfiguration*)antennaConfiguration aStatusMessage:(NSString**)statusMessage;

/* dynamic power optimization */
- (SRFID_RESULT) srfidGetDpoConfiguration:(int)readerID aDpoConfiguration:(srfidDynamicPowerConfig**)dpoConfiguration aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetDpoConfiguration:(int)readerID aDpoConfiguration:(srfidDynamicPowerConfig*)dpoConfiguration aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetSingulationConfiguration:(int)readerID aSingulationConfig:(srfidSingulationConfig**)singulationConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetSingulationConfiguration:(int)readerID aSingulationConfig:(srfidSingulationConfig*)singulationConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetTagReportConfiguration:(int)readerID aTagReportConfig:(srfidTagReportConfig**)reportConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetTagReportConfiguration:(int)readerID aTagReportConfig:(srfidTagReportConfig*)reportConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetReaderVersionInfo:(int)readerID aReaderVersionInfo:(srfidReaderVersionInfo**)readerVersionInfo aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetReaderCapabilitiesInfo:(int)readerID aReaderCapabilitiesInfo:(srfidReaderCapabilitiesInfo**)readerCapabilitiesInfo aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetStartTriggerConfiguration:(int)readerID aStartTriggeConfig:(srfidStartTriggerConfig**)triggerConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetStartTriggerConfiguration:(int)readerID aStartTriggeConfig:(srfidStartTriggerConfig*)triggerConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetStopTriggerConfiguration:(int)readerID aStopTriggeConfig:(srfidStopTriggerConfig**)triggerConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetStopTriggerConfiguration:(int)readerID aStopTriggeConfig:(srfidStopTriggerConfig*)triggerConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetSupportedRegions:(int)readerID aSupportedRegions:(NSMutableArray**)supportedRegionsList aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidGetRegionInfo:(int)readerID aRegionCode:(NSString*)regionCode aSupportedChannels:(NSMutableArray**)supportedChannelsList aHoppingConfigurable:(BOOL*)hoppingConfigurable aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetRegulatoryConfig:(int)readerID aRegulatoryConfig:(srfidRegulatoryConfig**)regulatoryConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetRegulatoryConfig:(int)readerID aRegulatoryConfig:(srfidRegulatoryConfig*)regulatoryConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetBeeperConfig:(int)readerID aBeeperConfig:(SRFID_BEEPERCONFIG*)beeperConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetBeeperConfig:(int)readerID aBeeperConfig:(SRFID_BEEPERCONFIG)beeperConfig aStatusMessage:(NSString**)statusMessage;


- (SRFID_RESULT) srfidGetPreFilters:(int)readerID aPreFilters:(NSMutableArray**)filtersList aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetPreFilters:(int)readerID aPreFilters:(NSMutableArray*)filtersList aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidStartTagLocationing:(int)readerID aTagEpcId:(NSString*)epcID aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidStartTagLocationing:(int)readerID aTagEpcId:(NSString*)epcID aTagEpcMask:(NSString*)epcMask aStatusMessage:(NSString**)statusMessage;

//Start multiTags locationing
- (SRFID_RESULT) srfidStartMultiTagsLocationing:(int)readerID aReportConfig:(srfidReportConfig*)reportConfig aAccessConfig:(srfidAccessConfig*)accessConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidStopTagLocationing:(int)readerID aStatusMessage:(NSString**)statusMessage;

//Stop multiTags locationing
- (SRFID_RESULT) srfidStopMultiTagsLocationing:(int)readerID aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidSaveReaderConfiguration:(int)readerID aSaveCustomDefaults:(BOOL)saveCustomDefaults aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidRestoreReaderConfiguration:(int)readerID aRestoreFactoryDefaults:(BOOL)restoreFactoryDefaults aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidReadTag:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aLength:(short)length aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidWriteTag:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aData:(NSString*)data aPassword:(long)password aDoBlockWrite:(BOOL)blockWrite aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidKillTag:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidLockTag:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aAccessPermissions:(SRFID_ACCESSPERMISSION)accessPermissions aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidBlockErase:(int)readerID aTagID:(NSString *)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aLength:(short)length aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidBlockPermaLock:(int)readerID aTagID:(NSString *)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aDoLock:(BOOL)doLock aBlockPtr:(short)blockPtr aBlockRange:(short)blockRange aBlockMask:(NSString *)blockMask aPassword:(long)password aStatusMessage:(NSString **)statusMessage;

- (SRFID_RESULT) srfidReadTag:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aLength:(short)length aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidWriteTag:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aData:(NSString*)data aPassword:(long)password aDoBlockWrite:(BOOL)blockWrite aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidKillTag:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessTagData:(srfidTagData**)accessTagData aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidLockTag:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aAccessPermissions:(SRFID_ACCESSPERMISSION)accessPermissions aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidBlockErase:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aLength:(short)length aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidBlockPermaLock:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aDoLock:(BOOL)doLock aBlockPtr:(short)blockPtr aBlockRange:(short)blockRange aBlockMask:(NSString *)blockMask aPassword:(long)password aStatusMessage:(NSString **)statusMessage;

- (SRFID_RESULT) srfidRequestBatteryStatus:(int)readerID;
- (SRFID_RESULT) srfidRequestDeviceStatus:(int)readerID aBattery:(BOOL)getBattery aTemperature:(BOOL)getTemperature aPower:(BOOL)getPower;

- (SRFID_RESULT) srfidGetBatchModeConfig:(int)readerID aBatchModeConfig:(SRFID_BATCHMODECONFIG*)batchModeConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetBatchModeConfig:(int)readerID aBatchModeConfig:(SRFID_BATCHMODECONFIG)batchModeConfig aStatusMessage:(NSString**)statusMessage;

// USB BatchMode
- (SRFID_RESULT) srfidGetUSBBatchModeConfig:(int)readerID aBatchModeConfig:(SRFID_BATCHMODECONFIG*)batchModeConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetUSBBatchModeConfig:(int)readerID aBatchModeConfig:(SRFID_BATCHMODECONFIG)batchModeConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidgetTags:(int)readerID aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidGetConfigurations;

- (SRFID_RESULT) srfidPurgeTags:(int)readerID aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetAttribute:(int)readerId attributeNumber:(int)attrNum attributeValue:(int)attrVal attributeType:(NSString*)attrType aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetAttribute:(int)readerID aAttrInfo:(srfidAttribute*)attrInfo aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidGetAttribute:(int)readerID aAttrNum:(int)attrNum aAttrInfo:(srfidAttribute**)attrInfo aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidLocateReader:(int)readerID doEnabled:(BOOL)doEnabled aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidSetAccessCommandOperationWaitTimeout :(int)readerID aTimeoutMs:(int)timeoutMs;

- (SRFID_RESULT) srfidEnableDebugLog;
- (SRFID_RESULT) srfidDisableDebugLog;
- (SRFID_RESULT) srfidResetDebugLog;
- (SRFID_RESULT) srfidRetrieveDebugLog:(NSString **)debugLog;


- (SRFID_RESULT) srfidReadTagAsync:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aLength:(short)length aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidReadTagAsync:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aLength:(short)length aPassword:(long)password aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidWriteTagAsync:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aData:(NSString*)data aPassword:(long)password aDoBlockWrite:(BOOL)blockWrite aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidWriteTagAsync:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aData:(NSString*)data aPassword:(long)password aDoBlockWrite:(BOOL)blockWrite aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidLockTagAsync:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aAccessPermissions:(SRFID_ACCESSPERMISSION)accessPermissions aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidLockTagAsync:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aAccessPermissions:(SRFID_ACCESSPERMISSION)accessPermissions aPassword:(long)password aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidKillTagAsync:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidKillTagAsync:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aPassword:(long)password aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidBlockPermaLockAsync:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aDoLock:(BOOL)doLock aBlockPtr:(short)blockPtr aBlockRange:(short)blockRange aBlockMask:(NSString *)blockMask aPassword:(long)password aStatusMessage:(NSString **)statusMessage;

- (SRFID_RESULT) srfidBlockEraseAsync:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aLength:(short)length aPassword:(long)password aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidPerformAccessInSequence:(int)readerID aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessParameters: (NSArray *)accessParameters aStatusMessage:(NSString**)statusMessage;
#pragma mark UniqueTagsReport
- (SRFID_RESULT) srfidSetUniqueTagReportConfiguration:(int)readerID aUtrConfiguration:(srfidUniqueTagsReport*)UtrConfiguration aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidGetUniqueTagReportConfiguration:(int)readerID aUtrConfiguration:(srfidUniqueTagsReport**)UtrConfiguration aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetCommandResponseTimeout:(int)readerID  atimeout:(int)timeoutMs;

/* g2v2 */
- (SRFID_RESULT) srfidAuthenticate:(int)readerId aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessConfig:(srfidAccessConfig*)accessConfig aPassword:(long)password aMsgLength:(int)msgLength aMsgData:(NSString *)msgData aRespLength:(int)respLength aCsi:(int)csi aDoSendRes:(BOOL)doSendRes aDoIncresplen:(BOOL)doIncresplen aStatusMessage:(NSString **)statusMessage;
- (SRFID_RESULT) srfidUntraceable:(int)readerId aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessConfig:(srfidAccessConfig*)accessConfig aPassword:(long)password aUntraceableConfig:(srfidUntraceableConfig*)untraceableConfig aStatusMessage:(NSString **)statusMessage;
- (SRFID_RESULT) srfidReadBuffer:(int)readerId aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessConfig:(srfidAccessConfig*)accessConfig aPassword:(long)password aWordPtr:(int)wordPtr aBitCount:(int)bitCount aStatusMessage:(NSString **)statusMessage;
- (SRFID_RESULT) srfidSetCryptoSuite:(int)readerId aAccessCriteria:(srfidAccessCriteria*)accessCriteria aAccessConfig:(srfidAccessConfig*)accessConfig aPassword:(long)password aKeyId:(int)keyId aIChallenge:(NSString *)iChallenge aIncCustom:(BOOL)incCustom aProfile:(int)profile aOffset:(int)offset aBlockCount:(int)blockCount aProtMode:(int)protMode aStatusMessage:(NSString **)statusMessage;

- (SRFID_RESULT) srfidStopOperation:(int)readerId aStatusMessage:(NSString **)statusMesssage;

- (SRFID_RESULT) srfidSetDefaultConfiguration:(int)readerId aAntennaRconfig:(srfidAntennaConfiguration*)antennaRfConfig aSingulationControl:(srfidSingulationConfig*)singulationControl aTagStorageSettings:(srfidTagReportConfig *)tagReportConfig aDeleteAllPrefilters:(BOOL) deleteAllPrefilters aDpoEnable:(BOOL) dpoEnable aSetAttributes:(NSMutableArray *)attributesArray aStatusMessage:(NSString**)statusMessage;

// Legacy trigger config
//- (SRFID_RESULT) srfidGetTriggerConfig:(int)readerID aTriggerConfig:(SRFID_ENUM_KEYLAYOUT_TYPE*)triggerConfig __attribute((deprecated("Use the srfidGetKeylayoutType instead.")));
//- (SRFID_RESULT) srfidSetTriggerConfig:(int)readerID aTriggerConfig:(SRFID_ENUM_KEYLAYOUT_TYPE)triggerConfig __attribute((deprecated("Use the srfidSetKeylayoutType instead.")));

// New trigger config as keylayout type
- (SRFID_RESULT)srfidGetKeylayoutType:(int)readerID upperTrigger:(SRFID_NEW_ENUM_KEYLAYOUT_TYPE*)upper lowerTrigger:(SRFID_NEW_ENUM_KEYLAYOUT_TYPE*)lower;
- (SRFID_RESULT)srfidSetKeylayoutType:(int)readerID upperTrigger:(SRFID_NEW_ENUM_KEYLAYOUT_TYPE)upper lowerTrigger:(SRFID_NEW_ENUM_KEYLAYOUT_TYPE)lower;

- (SRFID_RESULT) srfidReboot:(int)readerID  aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidFactoryReset:(int)readerID  aStatusMessage:(NSString**)statusMessage;

//Battery PP+ support
- (SRFID_RESULT) srfidGetBatteryStatus:(int)readerID  batteryStatusArray:(NSMutableArray**)batteryStatusArray aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT)srfidGetWifiStatus:(int)readerID wifiStatusInfo:(srfidGetWifiStatusInfo **)wifiStatusInfo aStatusMessage:(NSString**)astatusMessage;

- (SRFID_RESULT) srfidWifiEnableDisable:(int)readerID enable:(BOOL)enableWifiStatus aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetWlanProfileList:(int)readerID wlanProfileList:(NSMutableArray **)wlanProfileList aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidAddWlanProfile:(int)readerID ssidWlan:(NSString*)ssidWlan  wlanPassword:(NSString*)wlanPassword aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidRemoveWlanProfile:(int)readerID ssidWlan:(NSString*)ssidWlan aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetWlanScanList:(int)readerID  aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidWlanSaveProfile:(int)readerID  aStatusMessage:(NSString**)statusMessage;

@end


#endif /* __RFID_SDK_API__ */
