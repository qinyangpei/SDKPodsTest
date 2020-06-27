/*******************************************************************************
 ©2019 ArcSoft Corporation Limited. All rights reserved.
 
 This file is ArcSoft's property. It contains ArcSoft's trade secret, proprietary
 and confidential information.
 
 The information and code contained in this file is only for authorized ArcSoft
 employees to design, create, modify, or review.
 
 DO NOT DISTRIBUTE, DO NOT DUPLICATE OR TRANSMIT IN ANY FORM WITHOUT PROPER
 AUTHORIZATION.
 
 If you are not an intended recipient of this file, you must not copy,
 distribute, modify, or take any action in reliance on it.
 
 If you have received this file in error, please immediately notify ArcSoft and
 permanently delete the original and any copy of any file and any printout
 thereof.
 *******************************************************************************/

#import <Foundation/Foundation.h>
#import "asvloffscreen.h"
#import "amcomdef.h"

typedef struct {
    MInt32 lCodebase;       // Codebase version number
    MInt32 lMajor;          // Major version number
    MInt32 lMinor;          // Minor version number
    MInt32 lBuild;          // Build version number, increasable only
    MPChar Version;         // Version in string form
    MPChar BuildDate;       // Latest build Date
    MPChar CopyRight;       // Copyright
} ARCSOFT_VEHICLEENGINE_VERSION;

typedef NS_ENUM(NSInteger, ARCSOFT_VEHICLEENGINE_DISTANCE) {
    DISTANCE_FAR              =   0,                                                   // far distance
    DISTANCE_MIDDLE           =   1,                                                   // middle distance
    DISTANCE_NEAR             =   2,                                                   // near distance
    DISTANCE_FAIL             =   3,                                                   // image quality is not ok
    DISTANCE_SUPER_NEAR       =   4                                                    // super near
};

@interface ArcSoftVehicleDistance : NSObject
@property (nonatomic, readonly) ARCSOFT_VEHICLEENGINE_DISTANCE distance;               // distance
@property (nonatomic, readonly) MFloat confidence;                                     // confidence， 0-1
@end

@interface ArcSoftVehicleEngine : NSObject

- (NSString*)recognitionVin:(const LPASVLOFFSCREEN)pOffscreenIn;

- (NSString*)recognitionPlate:(const LPASVLOFFSCREEN)pOffscreenIn;

- (ArcSoftVehicleDistance*)evaluateDistance:(const LPASVLOFFSCREEN)pOffscreenIn;

- (const ARCSOFT_VEHICLEENGINE_VERSION*)getVersion;

@end
