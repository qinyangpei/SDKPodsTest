//
//  ABCarSDK.h
//  ABCarSDK
//
//  Created by 秦阳培 on 2020/5/8.
//  Copyright © 2020 爱保科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCarWKWebViewController.h"
#import "ABCarAIClaimGuideViewController.h"
#import "ABCarAIClaimScanViewController.h"

//! Project version number for ABCarSDK.
FOUNDATION_EXPORT double ABCarSDKVersionNumber;

//! Project version string for ABCarSDK.
FOUNDATION_EXPORT const unsigned char ABCarSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ABCarSDK/PublicHeader.h>

//ABCarSDK登录、退出消息
#define  Notification_ABCarLoginSuccess      @"Notification_ABCarLoginSuccess"
#define  Notification_ABCarLoginFailed       @"Notification_ABCarLoginFailed"
#define  Notification_ABCarLogoutSuccess     @"Notification_ABCarLogoutSuccess"

@protocol ABCarServiceDelegate <NSObject>

- (void)presentLoginController;

@end

@interface ABCarSDK : NSObject

@property (nonatomic, weak) id<ABCarServiceDelegate> delegate;

//获取单例
+ (ABCarSDK *)sharedServices;

//初始化
- (BOOL)initWithAppId:(NSString *)appId secret:(NSString *)secret delegate:(id<ABCarServiceDelegate>)delegate testMode:(BOOL)testMode;

//登录
+ (void)loginWithUniqueId:(NSString *)uniqueId phone:(NSString *)phone token:(NSString *)token userName:(NSString *)userName sex:(NSString *)sex callback:(void (^)(NSError *error))callback;

//退出
+ (void)logout;


//打开webview
+ (void)openWebview;


//智能测损
+ (void)aiclaimWithGuideView:(BOOL)needGuideView PlateNum:(NSString *)plateNum vinNum:(NSString *)vinNum;


@end
