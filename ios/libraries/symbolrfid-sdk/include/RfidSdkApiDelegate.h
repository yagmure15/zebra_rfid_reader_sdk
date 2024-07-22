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
 *  Description:  RfidSdkApiDelegate.h
 *
 *  Notes:
 *
 ******************************************************************************/

#ifndef __RFID_SDK_API_DELEGATE__
#define __RFID_SDK_API_DELEGATE__

#import "RfidReaderInfo.h"
#import "RfidTagData.h"
#import "RfidBatteryEvent.h"
#import "RfidWlanScanList.h"

@protocol srfidISdkApiDelegate <NSObject>

- (void)srfidEventReaderAppeared:(srfidReaderInfo*)availableReader;
- (void)srfidEventReaderDisappeared:(int)readerID;
- (void)srfidEventCommunicationSessionEstablished:(srfidReaderInfo*)activeReader;
- (void)srfidEventCommunicationSessionTerminated:(int)readerID;
- (void)srfidEventReadNotify:(int)readerID aTagData:(srfidTagData*)tagData;
- (void)srfidEventStatusNotify:(int)readerID aEvent:(SRFID_EVENT_STATUS)event aNotification:(id)notificationData;
- (void)srfidEventProximityNotify:(int)readerID aProximityPercent:(int)proximityPercent;

- (void)srfidEventMultiProximityNotify:(int)readerID aTagData:(srfidTagData*)tagData;

- (void)srfidEventTriggerNotify:(int)readerID aTriggerEvent:(SRFID_TRIGGEREVENT)triggerEvent;
- (void)srfidEventBatteryNotity:(int)readerID aBatteryEvent:(srfidBatteryEvent*)batteryEvent;
- (void)srfidEventWifiScan:(int)readerID wlanSCanObject:(srfidWlanScanList*)wlanScanObject;

@end

#endif /* __RFID_SDK_API_DELEGATE__ */
