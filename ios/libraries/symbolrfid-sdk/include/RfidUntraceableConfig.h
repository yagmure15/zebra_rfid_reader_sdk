#import <Foundation/Foundation.h>
#import "RfidSdkDefs.h"

@interface srfidUntraceableConfig : NSObject
{
    /* assertu when set to true */
    BOOL m_AssertU;
    
    /* showepc when set to true, hideepc when set to false */
    BOOL m_ShowEpc;
    
    /* epc memory bank length - when using show epc set length to 6 to get full epc */
    int m_EpcLen;
    
    SRFID_CONFIG_TID m_Tid;
    
    /* showuser when set to true, hideuser when set to false */
    BOOL m_ShowUser;
  
    SRFID_CONFIG_RANGE m_Range;
}

- (BOOL) getAssertU;
- (void) setAssertU:(BOOL)val;
- (BOOL) getShowEpc;
- (void) setShowEpc:(BOOL)val;
- (SRFID_CONFIG_TID) getTid;
- (void) setTid:(SRFID_CONFIG_TID)val;
- (BOOL) getShowUser;
- (void) setShowUser:(BOOL)val;
- (int)  getEpcLen;
- (void) setEpcLen:(int)val;
- (SRFID_CONFIG_RANGE) getRange;
- (void) setRange:(SRFID_CONFIG_RANGE)val;

@end
