//
//  GetSocialLeaderboard.h
//  GetSocialSDK
//
//  Created by Tsvetomir Stanchev on 1/6/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GetSocialLeaderboardMetaData.h"
#import "GetSocialLeaderboardScore.h"

/** Describes a Leaderboard.*/
@interface GetSocialLeaderboard : NSObject {
    
}

/** The metadata of the Leaderboard.*/
@property(nonatomic,strong) GetSocialLeaderboardMetaData *leaderboardMetaData;

/** Score of the current user.*/
@property(nonatomic,strong) GetSocialLeaderboardScore *currentScore;


+ (GetSocialLeaderboard*) initLeaderboardFromJSON:(id) JSON;

@end
