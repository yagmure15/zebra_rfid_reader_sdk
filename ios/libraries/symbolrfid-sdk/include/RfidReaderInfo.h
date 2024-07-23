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
 *  Description:  RfidReaderInfo.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>

@interface srfidReaderInfo : NSObject
{
    int m_ReaderID; /* SDK assigned unique id */
    int m_ConnectionType; /* mfi, btle */
    BOOL m_Active; /* communication session is established */
    NSString *m_ReaderName;
    int m_ReaderModel;
}

- (id)init;
- (void)dealloc;

- (void)setReaderID:(int)readerID;
- (void)setConnectionType:(int)connectionType;
- (void)setActive:(BOOL)active;
- (void)setReaderName:(NSString*)readerName;
- (void)setReaderModel:(int)readerModel;

- (int)getReaderID;
- (int)getConnectionType;
- (BOOL)isActive;
- (NSString*)getReaderName;
- (int)getReaderModel;

@end
