//
//  ABCarView.h
//  ABCarSDK
//
//  Created by 秦阳培 on 2020/6/3.
//  Copyright © 2020 爱保科技. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ABCarView : UIView

@property (nonatomic, assign)NSInteger carId; //车辆id

- (instancetype)initWithFrame:(CGRect)frame;

//根据车辆信息刷新页面
- (void)updateCarVieWithCarInfo:(NSString *)carInfo callback:(void (^)(NSString *result))callback;

@end
