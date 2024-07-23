//
//  RFIDUniqueTagsReport.h
//  RFIDDemoApp
//
//  Created by Neeraj Seshadri on 05/04/16.
//  Copyright © 2016 Motorola Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface srfidUniqueTagsReport : NSObject
{
    BOOL m_UniqueTagsReportEnabled;
}

- (BOOL)getUniqueTagsReportEnabled;
- (void)setUniqueTagsReportEnabled:(BOOL)val;

@end
