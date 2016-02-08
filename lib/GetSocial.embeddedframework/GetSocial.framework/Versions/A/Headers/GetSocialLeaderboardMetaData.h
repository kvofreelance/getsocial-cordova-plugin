//
//  GetSocialBasicLeaderboard.h
//  GetSocialSDK
//
//  Created by Tsvetomir Stanchev on 1/6/14.
//  Copyright (c) 2014 GetSocial. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GetSocialConstants.h"

/** Describes a Leaderboard meta data.*/
@interface GetSocialLeaderboardMetaData : NSObject {
    
}

/** The unique deveoper Id of the Leaderboard.*/
@property(nonatomic,strong) NSString *leaderboardID;

/** The name of the Leaderboard.*/
@property(nonatomic,strong) NSString *name;

/** The units of the score (example: points, coins, etc).*/
@property(nonatomic,strong) NSString *unit;

/** The direction of the Leaderboard (ASC,DESC).*/
@property(nonatomic,assign) GetSocialLeaderboardDirectionType direction;

/** The format of the score (example: number).*/
@property(nonatomic,strong) NSString *format;

/** Shows if the Leaderboard is published.*/
@property(nonatomic) BOOL published;

+ (GetSocialLeaderboardMetaData*) initLeaderboardMetaDataFromJSON:(id) JSON;


@end
