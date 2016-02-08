//
//  GetSocialLeaderborder.h
//  GetSocialSDK
//
//  Created by Tsvetomir Stanchev on 1/6/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GetSocialUserIdentity.h"

/** Describes a Leaderboard score.*/
@interface GetSocialLeaderboardScore : NSObject {
    
}

/** User that has the score.*/
@property(nonatomic,strong) GetSocialUserIdentity *user;

/** The value of the score.*/
@property(nonatomic) NSInteger value;

/** The rank of the user.*/
@property(nonatomic) NSInteger rank;

+ (GetSocialLeaderboardScore*) initLeaderboardScoreFromJSON:(id) JSON;
- (NSString*) valueWithFormat:(NSString*) format;

@end
