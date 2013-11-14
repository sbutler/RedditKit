//
//  RKOAuthClient.h
//  Pods
//
//  Created by Joseph Pintozzi on 11/14/13.
//
//

#import "RKClient.h"

@interface RKOAuthClient : RKClient

/**
 The current clientId and clientSecret for this app.
 Only required if authenticating via OAuth
 */
@property (nonatomic, strong) NSString *clientId;
@property (nonatomic, strong) NSString *clientSecret;
@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) NSString *refreshToken;

/**
 Returns a RKClient ready for OAuth
 Get a client ID and secret here: https://ssl.reddit.com/prefs/apps
 */
- (id)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;

/**
 Signs into reddit via OAuth
 */
- (NSURL *)oauthURLWithRedirectURI:(NSString *)redirectURI state:(NSString *)state scope:(NSArray*)scope;
- (NSURLSessionDataTask *)signInWithAccessCode:(NSString *)accessCode redirectURI:(NSString *)redirectURI state:(NSString *)state completion:(RKCompletionBlock)completion;

@end