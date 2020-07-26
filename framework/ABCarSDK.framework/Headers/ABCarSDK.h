//
//  ABCarSDK.h
//  ABCarSDK
//
//  Created by 秦阳培 on 2020/5/8.
//  Copyright © 2020 爱保科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCarWKWebViewController.h"
#import "ABCarView.h"

//! Project version number for ABCarSDK.
FOUNDATION_EXPORT double ABCarSDKVersionNumber;

//! Project version string for ABCarSDK.
FOUNDATION_EXPORT const unsigned char ABCarSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ABCarSDK/PublicHeader.h>

//ABCarSDK登录、退出消息
#define  Notification_ABCarLoginSuccess      @"Notification_ABCarLoginSuccess"
#define  Notification_ABCarLoginFailed       @"Notification_ABCarLoginFailed"
#define  Notification_ABCarLogoutSuccess     @"Notification_ABCarLogoutSuccess"

#define  Notification_ABCarViewUpdateSuccess @"Notification_ABCarViewUpdateSuccess"
#define  Notification_ABCarOpenService       @"Notification_ABCarOpenService"


@protocol ABCarServiceDelegate <NSObject>

//唤起宿主app登录页面，在此代理方法中弹出app自身的登录页面
- (void)loginApp;

//唤起微信小程序，需要在此方法中根据params唤起小程序，具体字段见接口文档
- (void)launchWeiXinMiniProgram:(NSString *)jsonParam;

//打开宿主app某个服务，具体字段见接口文档
- (void)openAppServices:(NSString *)jsonParam;

//获取当前城市信息，具体字段见接口文档
- (NSString *)getCityInfo;

//获取当前导航控制器
- (UINavigationController *)currentNavigationController;

@end


@interface ABCarSDK : NSObject

@property (nonatomic, weak) id<ABCarServiceDelegate> delegate;

//强制横屏
@property (nonatomic, assign) BOOL forceLandscape;

//获取单例
+ (ABCarSDK *)sharedServices;

/*! @brief 初始化
 *
 * 请在application:didFinishLaunchingWithOptions:方法里调用
 * @param appId       接入方渠道ID，必传
 * @param secret      接入方secret，非必传
 * @param jsonParam   其他特殊参数，通过json字符串传递，非告知无须传递
 * @param delegate  ABCarServiceDelegate对象，接收ABCarServiceDelegate事件
 * @param testMode  YES连接测试环境，NO连接正式环境，切换环境后需要重新登录获取数据
 * @return 成功返回YES，失败返回NO。
*/
- (BOOL)initWithAppId:(NSString *)appId secret:(NSString *)secret params:(NSString *)jsonParam delegate:(id<ABCarServiceDelegate>)delegate testMode:(BOOL)testMode;


/*! @brief 登录
 *
 * @param uniqueId    唯一用户id，必传
 * @param jsonParam   其他特殊参数，通过json字符串传递，非告知无须传递
 * @param callback    返回登录结果json字符串，具体字段及code码详见接口文档
*/
+ (void)loginWithUniqueId:(NSString *)uniqueId params:(NSString *)jsonParam callback:(void (^)(NSString *result))callback;


//退出
+ (void)logout;


/*! @brief 是否登录
 *
 *  @return 登录状态返回YES，未登录返回NO。
*/
+ (BOOL)isLogin;


/*! @brief 获取SDK当前版本
 *
 *  @return 返回SDK当前版本。
*/
+ (NSString *)getSDKVersion;



/*! @brief 智能估损
 *
 * @param  carInfo   车辆信息，通过json字符串传递，具体字段详见对接文档
*/
+ (void)startAiEstimateWithCarInfo:(NSString *)carInfo;



/*! @brief 查询车辆是否已经投保
 *
 * @param carId       车辆ID，必传
 * @param callback    返回车辆投保状态，具体字段及code码详见接口文档
*/
+ (void)queryInsurance:(NSString *)carId callback:(void(^)(NSString *result))callback;


@end
