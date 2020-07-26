//
//  ABCarWKWebViewController.h
//  ABCarSDK
//
//  Created by 秦阳培 on 2020/5/19.
//  Copyright © 2020 爱保科技. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

typedef enum ABCarWebViewStatusBarStyle{
    ABCarStatusBarStyle_DarkContent = 0,    //默认使用黑色字体
    ABCarStatusBarStyle_LightContent = 1    //白色字体
}ABCarWebViewStatusBarStyle;


@interface ABCarWKWebViewController : UIViewController

/** 加载的url */
@property (nonatomic, copy) NSString *visitUrl;
/** 拼接到url之后的参数 */
@property (nonatomic, strong) NSMutableDictionary *urlParameters;
/** 是否是原生头，1-不是 2-是 默认为0不带原生头 */
@property (nonatomic, assign) NSInteger isNativeHeader;
/** 是否是沉浸式状态栏 1-不是 2-是，默认为0是沉浸式 */
@property (nonatomic, assign) NSInteger isImmersionStatusBar;

/** 原生导航栏标题（目前原生头背景为白色，状态栏为黑色字体） */
@property (nonatomic, copy) NSString *navigationTitle;
/** 状态栏样式，默认为白色字体 */
@property (nonatomic, assign) ABCarWebViewStatusBarStyle stautsBarStyle;

/** 是否隐藏关闭按钮，默认为NO,显示关闭按钮 */
@property (nonatomic, assign) BOOL hideCloseButton;
/** 是否隐藏菜单按钮，默认为NO,显示菜单按钮 */
@property (nonatomic, assign) BOOL hideMenuButton;



@end


