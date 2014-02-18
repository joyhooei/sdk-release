//
//  MATUtils.h
//  MobileAppTrackeriOS
//
//  Created by Pavel Yurchenko on 7/24/12.
//  Copyright (c) 2012 Scopic Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../MobileAppTracker.h"
#import <sys/xattr.h>
#import <dlfcn.h>
#import <objc/runtime.h>

@protocol MATConnectionManagerDelegate;

@interface MATUtils : NSObject

extern const float MAT_IOS_VERSION_501; // float equivalent of 5.0.1

+ (NSString*)generateUserAgentString;
+ (NSString*)generateFBCookieIdString;

+ (NSString *)getUUID;

+ (NSString *)bundleId;

+ (BOOL)isNetworkReachable;

+ (void)setShouldDebug:(BOOL)yesorno;

+ (void)startTrackingSessionForTargetBundleId:(NSString*)targetBundleId
                            publisherBundleId:(NSString*)publisherBundleId
                                 advertiserId:(NSString*)advertiserId
                                   campaignId:(NSString*)campaignId
                                  publisherId:(NSString*)publisherId
                                     redirect:(BOOL)shouldRedirect
                           connectionDelegate:(id<MATConnectionManagerDelegate>)matDelegate;

+ (void)sendRequestGetInstallLogIdWithLink:(NSString *)link
                                    params:(NSMutableDictionary*)params
                        connectionDelegate:(id<MATConnectionManagerDelegate>)connectionDelegate;

+ (void)stopTrackingSession;
+ (BOOL)isTrackingSessionStartedForTargetApplication:(NSString*)targetPackageName;

+ (NSString*)getPublisherBundleId;
+ (NSString*)getSessionDateTime;
+ (NSString*)getAdvertiserId;
+ (NSString*)getCampaignId;

+ (NSString*)getStringForKey:(NSString*)key fromPasteBoard:(NSString *)pasteBoardName;
+ (NSString*)getTrackingId;

+ (id)userDefaultValueforKey:(NSString *)key;
+ (void)setUserDefaultValue:(id)value forKey:(NSString* )key;

+ (NSString *)formattedCurrentDateTime;
+ (BOOL)checkJailBreak;

+ (void)storeToPasteBoardTrackingId:(NSMutableDictionary *)params;
+ (void)failedToRequestTrackingId:(NSMutableDictionary *)params withError:(NSError *)error;

+ (NSDateFormatter *)sharedDateFormatter;
+ (NSInteger)daysBetweenDate:(NSDate*)fromDateTime andDate:(NSDate*)toDateTime;

+ (void)handleInstallLogId:(NSMutableDictionary *)params;
+ (void)failedToRequestInstallLogId:(NSMutableDictionary *)params withError:(NSError *)error;

+ (float)getNumericiOSVersion:(NSString *)iOSVersion;
+ (BOOL)addSkipBackupAttributeToItemAtURL:(NSURL *)URL;

+ (NSString *)serverDomainName;

#pragma mark -

void *MATNewBase64Decode(
                         const char *inputBuffer,
                         size_t length,
                         size_t *outputLength);

char *MATNewBase64Encode(
                         const void *buffer,
                         size_t length,
                         bool separateLines,
                         size_t *outputLength);

+ (NSData *)MATdataFromBase64String:(NSString *)aString;
+ (NSString *)MATbase64EncodedStringFromData:(NSData *)data;

@end