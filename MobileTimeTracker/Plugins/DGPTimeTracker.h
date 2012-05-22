//
//  DGPTimeTracker.h
//  TikalTimeTracker
//
//  Created by Dov Goldberg on 5/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "Geofencing.h"

#define KEY_PROJECT_NAME                    @"projectname"
#define KEY_PROJECT_ADDRESS                 @"projectaddress"
#define KEY_PROJECT_SHOULD_AUTO_UPDATE      @"shouldautoupdate"
#define KEY_PROJECT_CURRENTLY_HERE          @"currentlyhere"

enum DGPTimeTrackerStatusCode {
    PROJECTNOTFOUND = 20
};
typedef NSUInteger DGPTimeTrackerStatusCode;

@interface DGPTimeTracker : Geofencing

- (void)addProject:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void)removeProject:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void)setShouldAutoUpdateProjectEvents:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void)getShouldAutoUpdateProjectEvents:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void)checkinToProject:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void)checkoutOfProject:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;

- (void)returnTimeTrackerError: (NSUInteger) errorCode withMessage: (NSString*) message;
- (void) doCheckIn:(NSString *)fid;
- (void) doCheckOut:(NSString *)fid;
- (void) postLocalNotificationWithMessage:(NSString *)message;
- (void) forceCheckoutFromAllProjects;
// CoreData Functions
- (NSManagedObjectContext *) managedObjectContext;

@end
