#import <CoreFoundation/CoreFoundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore2.h>
//#import <Preferences/PSViewController.h>
//#import <Preferences/PSTableCell.h>
//#import <Preferences/PSControlTableCell.h>

#define isiOS4 (kCFCoreFoundationVersionNumber >= 550.32 && kCFCoreFoundationVersionNumber < 675.00)
#define isiOS50 (kCFCoreFoundationVersionNumber >= 675.00 && kCFCoreFoundationVersionNumber < 690.10)
#define isiOS51 (kCFCoreFoundationVersionNumber >= 690.10 && kCFCoreFoundationVersionNumber < 793.00)
#define isiOS5 (kCFCoreFoundationVersionNumber >= 675.00 && kCFCoreFoundationVersionNumber < 793.00)
#define isiOS6 (kCFCoreFoundationVersionNumber == 793.00)
#define isiOS70 (kCFCoreFoundationVersionNumber > 793.00 && kCFCoreFoundationVersionNumber < 847.23)
#define isiOS71 (kCFCoreFoundationVersionNumber >= 847.23 && kCFCoreFoundationVersionNumber < 1129.15)
#define isiOS7 (kCFCoreFoundationVersionNumber > 793.00 && kCFCoreFoundationVersionNumber < 1129.15)
#define isiOS8 (kCFCoreFoundationVersionNumber >= 1129.15)

#define isiOS6Up (kCFCoreFoundationVersionNumber >= 793.00)
#define isiOS7Up (kCFCoreFoundationVersionNumber > 793.00)
#define isiOS71Up (kCFCoreFoundationVersionNumber >= 847.23)
#define isiOS8Up (kCFCoreFoundationVersionNumber >= 1129.15)

#define isiOS45 (kCFCoreFoundationVersionNumber >= 550.32 && kCFCoreFoundationVersionNumber < 793.00)
#define isiOS56 (kCFCoreFoundationVersionNumber >= 675.00 && kCFCoreFoundationVersionNumber <= 793.00)
#define isiOS67 (kCFCoreFoundationVersionNumber >= 793.00 && kCFCoreFoundationVersionNumber < 1129.15)
#define isiOS78 (isiOS7 || isiOS8)

#define IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define PS_DONATE_URL @"https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=GBQGZL8EFMM86"
#define PS_TWITTER_URL @"twitter://user?screen_name=PoomSmart"

@interface UIScreen (Addition)
- (CGFloat)_interfaceOrientation;
- (CGRect)_interfaceOrientedBounds;
- (CGRect)_referenceBounds;
- (CGRect)applicationFrame;
@end

@interface UIImage (Addition)
+ (UIImage *)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle;
+ (UIImage *)pu_PhotosUIImageNamed:(NSString *)name;
- (UIImage *)_flatImageWithColor:(UIColor *)color;
@end

@interface UIApplication (Addition)
- (void)setBacklightLevel:(float)level;
- (BOOL)isSuspended;
@end

@interface UIDevice (Addition)
- (NSInteger)_graphicsQuality;
@end

@interface UIColor (Addition)
+ (UIColor *)systemBlueColor;
+ (UIColor *)systemYellowColor;
+ (UIColor *)systemRedColor;
+ (UIColor *)systemGreenColor;
+ (UIColor *)systemGrayColor;
+ (UIColor *)systemOrangeColor;
@end

@interface UIView (PhotoLibraryAdditions)
+ (NSTimeInterval)pl_setHiddenAnimationDuration;
- (void)pl_setHidden:(BOOL)hidden animated:(BOOL)animated;
@end

@interface UIView (CameraKit)
- (void)cam_setHidden:(BOOL)hidden animated:(BOOL)animated;
@end

@interface UIView (Contraints)
- (BOOL)cam_hasConstraintForKey:(NSString *)key;
- (void)cam_addConstraints:(NSArray *)constraints forKey:(NSString *)key;
- (void)cam_removeAllConstraintsForKey:(NSString *)key;
- (NSArray *)cam_constraintsForKey:(NSString *)key;
@end

/*extern "C" float __UIBackdropViewSettingsBlurRadiusNone;
extern "C" float __UIBackdropViewSettingsBlurRadiusSmall;
extern "C" float __UIBackdropViewSettingsBlurRadiusMedium;
extern "C" float __UIBackdropViewSettingsBlurRadiusLarge;*/

@interface CABackdropLayer : CALayer
+ (BOOL)CA_automaticallyNotifiesObservers:(Class)arg1;
+ (BOOL)_hasRenderLayerSubclass;
+ (id)defaultValueForKey:(id)arg1;
@property double statisticsInterval;
@property(copy) NSString *statisticsType;
@property(copy) NSArray *groupFilters;
@property float marginWidth;
@property struct CGRect backdropRect;
@property float scale;
@property(copy) NSString *groupName;
@property(getter=isEnabled) BOOL enabled;
- (NSUInteger)_renderLayerPropertyAnimationFlags:(NSUInteger)arg1;
- (BOOL)_renderLayerDefinesProperty:(NSUInteger)arg1;
- (CALayer *)_copyRenderLayer:(CATransaction *)arg1 layerFlags:(NSUInteger)arg2 commitFlags:(NSUInteger *)arg3;
- (void)didChangeValueForKey:(id)arg1;
- (id)statisticsValues;
- (void)layerDidBecomeVisible:(BOOL)arg1;
@end

@interface _UIBackdropEffectView : UIView
+ (Class)layerClass;
@property(nonatomic) float zoom;
@property(retain, nonatomic) CABackdropLayer *backdropLayer;
- (void)backdropLayerStatisticsDidChange:(id)arg1;
- (id)valueForUndefinedKey:(id)arg1;
- (BOOL)_shouldAnimatePropertyWithKey:(id)arg1;
- (void)dealloc;
- (id)init;
@end

@interface _UIBackdropContentView : UIView
- (void)didMoveToWindow;
- (void)_descendent:(id)arg1 willMoveFromSuperview:(id)arg2 toSuperview:(id)arg3;
- (void)_descendent:(id)arg1 didMoveFromSuperview:(id)arg2 toSuperview:(id)arg3;
- (void)recursivelyRemoveBackdropMaskViewsForView:(id)arg1;
- (void)backdropView:(id)arg1 recursivelyUpdateMaskViewsForView:(id)arg2;
- (id)initWithFrame:(CGRect)arg1;
@end

@class _UIBackdropViewSettings;
@interface _UIBackdropColorSettings : NSObject
@property float averageBrightness;
@property float averageHue;
@property float averageSaturation;
@property(readonly) UIColor *color;
@property float contrast;
@property BOOL hasObservedValues;
@property(assign) _UIBackdropViewSettings *parentSettings;
@property float previousAverageBrightness;
@property float previousAverageHue;
@property float previousAverageSaturation;
@property float previousContrast;
- (BOOL)applyCABackdropLayerStatistics:(id)arg1;
- (BOOL)hasObservedValues;
- (void)setDefaultValues;
- (void)setValuesFromModel:(id)arg1;
@end

@class _UIBackdropView;
@interface _UIBackdropViewSettings : NSObject
@property BOOL appliesTintAndBlurSettings;
@property(assign) _UIBackdropView *backdrop;
@property(getter=isBackdropVisible) BOOL backdropVisible;
@property NSInteger blurHardEdges;
@property(copy) NSString *blurQuality;
@property float blurRadius;
@property BOOL blursWithHardEdges;
@property float colorBurnTintAlpha;
@property float colorBurnTintLevel;
@property(retain) UIImage *colorBurnTintMaskImage;
@property(retain) _UIBackdropColorSettings *colorSettings;
@property(retain) UIColor *colorTint;
@property float colorTintAlpha;
@property float colorTintMaskAlpha;
@property(retain) UIImage *colorTintMaskImage;
@property(retain) UIColor *combinedTintColor;
@property BOOL darkenWithSourceOver;
@property float darkeningTintAlpha;
@property float darkeningTintBrightness;
@property float darkeningTintHue;
@property(retain) UIImage *darkeningTintMaskImage;
@property float darkeningTintSaturation;
@property(setter=setDesignMode:) BOOL designMode;
@property(getter=isEnabled) BOOL enabled;
@property BOOL explicitlySetGraphicsQuality;
@property float filterMaskAlpha;
@property(retain) UIImage *filterMaskImage;
@property NSInteger graphicsQuality;
@property float grayscaleTintAlpha;
@property float grayscaleTintLevel;
@property float grayscaleTintMaskAlpha;
@property(retain) UIImage * grayscaleTintMaskImage;
@property(getter=isHighlighted) BOOL highlighted;
@property(retain) UIColor *legibleColor;
@property BOOL lightenGrayscaleWithSourceOver;
@property NSInteger renderingHint;
@property BOOL requiresColorStatistics;
@property float saturationDeltaFactor;
@property float scale;
@property(getter=isSelected) BOOL selected;
@property NSInteger stackingLevel;
@property double statisticsInterval;
@property NSInteger style;
@property NSInteger suppressSettingsDidChange;
@property BOOL usesBackdropEffectView;
@property BOOL usesColorBurnTintView;
@property BOOL usesColorTintView;
@property BOOL usesContentView;
@property BOOL usesDarkeningTintView;
@property BOOL usesGrayscaleTintView;
@property NSUInteger version;
@property BOOL zoomsBack;
+ (UIColor *)darkeningTintColor;
+ (_UIBackdropViewSettings *)settingsForPrivateStyle:(NSInteger)arg1 graphicsQuality:(NSInteger)arg2;
+ (_UIBackdropViewSettings *)settingsForPrivateStyle:(NSInteger)arg1;
+ (_UIBackdropViewSettings *)settingsForStyle:(NSInteger)arg1 graphicsQuality:(NSInteger)arg2;
+ (_UIBackdropViewSettings *)settingsForStyle:(NSInteger)arg1;
- (void)addKeyPathObserver:(CFRunLoopObserverRef)arg1;
- (void)computeOutputSettingsUsingModel:(id)arg1;
- (void)decrementSuppressSettingsDidChange;
- (void)incrementSuppressSettingsDidChange;
- (id)initWithDefaultValues;
- (id)initWithDefaultValuesForGraphicsQuality:(NSInteger)arg1;
- (void)removeKeyPathObserver:(CFRunLoopObserverRef)arg1;
- (void)restoreDefaultValues;
- (void)scheduleSettingsDidChangeIfNeeded;
- (void)setDefaultValues;
@end

@protocol _UIBackdropViewObserver
@required
- (void)backdropViewDidChange:(id)arg1;
@end

@protocol _UIBackdropViewGraphicsQualityChangeDelegate
@required
- (id)backdropView:(id)arg1 willChangeToGraphicsQuality:(NSInteger)arg2;
- (void)backdropView:(id)arg1 didChangeToGraphicsQuality:(NSInteger)arg2;
@end
 
@interface _UIBackdropView : UIView
{
    BOOL _autosizesToFitSuperview;
    BOOL _computesColorSettings;
    BOOL _appliesOutputSettingsAutomatically;
    BOOL _appliesOutputSettingsAutomaticallyEnabledComputesColorSettings;
    BOOL _applyingBackdropChanges;
    BOOL _applyingTransition;
    BOOL _requiresTintViews;
    BOOL _wantsColorSettings;
    BOOL _blursBackground;
    BOOL _allowsColorSettingsSuppression;
    BOOL _contentViewAccessed;
    BOOL _contentViewAccessorGuard;
    BOOL _applySettingsAfterLayout;
    BOOL _updateMaskViewsForViewReentrancyGuard;
    BOOL _simulatesMasks;
    BOOL _backdropVisibilitySetOnce;
    BOOL _blurRadiusSetOnce;
    BOOL __backdropVisible;
    BOOL __zoomsBack;
    NSInteger _style;
    NSHashTable *_observers;
    id <_UIBackdropViewObserver> _observer;
    _UIBackdropViewSettings *_inputSettings;
    _UIBackdropViewSettings *_outputSettings;
    _UIBackdropViewSettings *_savedInputSettingsDuringRenderInContext;
    NSInteger _configuration;
    _UIBackdropEffectView *_backdropEffectView;
    NSString *_groupName;
    UIImage *_filterMaskImage;
    UIView *_grayscaleTintView;
    UIImage *_grayscaleTintMaskImage;
    UIView *_colorTintView;
    UIImage *_colorTintMaskImage;
    CAFilter *_gaussianBlurFilter;
    CAFilter *_colorSaturateFilter;
    CAFilter *_tintFilter;
    UIView *_contentView;
    NSInteger _maskMode;
    NSMutableSet *_partialMaskViews;
    UIView *_grayscaleTintMaskViewContainer;
    NSMutableDictionary *_grayscaleTintMaskViewMap;
    UIView *_colorTintMaskViewContainer;
    NSMutableDictionary *_colorTintMaskViewMap;
    UIView *_filterMaskViewContainer;
    NSMutableDictionary *_filterMaskViewMap;
    id _computeAndApplySettingsNotificationObserver;
    float _colorMatrixGrayscaleTintLevel;
    float _colorMatrixGrayscaleTintAlpha;
    UIColor *_colorMatrixColorTint;
    float _colorMatrixColorTintAlpha;
    NSInteger _blurHardEdges;
    CFRunLoopObserverRef _updateInputBoundsRunLoopObserver;
    float _previousBackdropStatisticsRed;
    float _previousBackdropStatisticsGreen;
    float _previousBackdropStatisticsBlue;
    float _previousBackdropStatisticsContrast;
    id <_UIBackdropViewGraphicsQualityChangeDelegate> _graphicsQualityChangeDelegate;
    NSString *__blurQuality;
    float __blurRadius;
    float __saturationDeltaFactor;
    double _appliesOutputSettingsAnimationDuration;
}
 
+ (Class)layerClass;
+ (Class)defaultSettingsClass;
+ (void)setAllBackdropViewsToGraphicsQuality:(NSInteger)arg1;
+ (void)adjustGraphicsQualityForAccessibilityIfNeeded:(id)arg1;
+ (void)restoreColorSettingsForRequester:(id)arg1;
+ (void)suppressColorSettingsForRequester:(id)arg1;
+ (void)restoreColorSettingsForDidBecomeActive:(id)arg1;
+ (void)suppressColorSettingsForWillResignActive:(id)arg1;
+ (void)restoreColorSettingsForRunLoopModePop:(id)arg1;
+ (void)suppressColorSettingsForRunLoopModePush:(id)arg1;
+ (NSArray *)allBackdropViews;
@property(nonatomic, setter=setZoomsBack:) BOOL _zoomsBack; // @synthesize _zoomsBack=__zoomsBack;
@property(nonatomic) BOOL _backdropVisible; // @synthesize _backdropVisible=__backdropVisible;
@property(nonatomic) float _saturationDeltaFactor; // @synthesize _saturationDeltaFactor=__saturationDeltaFactor;
@property(nonatomic) float _blurRadius; // @synthesize _blurRadius=__blurRadius;
@property(copy, nonatomic) NSString *_blurQuality; // @synthesize _blurQuality=__blurQuality;
//@property id <_UIBackdropViewGraphicsQualityChangeDelegate> *graphicsQualityChangeDelegate;
@property(nonatomic) float previousBackdropStatisticsContrast; // @synthesize previousBackdropStatisticsContrast=_previousBackdropStatisticsContrast;
@property(nonatomic) float previousBackdropStatisticsBlue; // @synthesize previousBackdropStatisticsBlue=_previousBackdropStatisticsBlue;
@property(nonatomic) float previousBackdropStatisticsGreen; // @synthesize previousBackdropStatisticsGreen=_previousBackdropStatisticsGreen;
@property(nonatomic) float previousBackdropStatisticsRed; // @synthesize previousBackdropStatisticsRed=_previousBackdropStatisticsRed;
@property(nonatomic) BOOL blurRadiusSetOnce; // @synthesize blurRadiusSetOnce=_blurRadiusSetOnce;
@property(nonatomic) BOOL backdropVisibilitySetOnce; // @synthesize backdropVisibilitySetOnce=_backdropVisibilitySetOnce;
@property(nonatomic) NSInteger blurHardEdges; // @synthesize blurHardEdges=_blurHardEdges;
@property(nonatomic) BOOL simulatesMasks; // @synthesize simulatesMasks=_simulatesMasks;
@property(nonatomic) float colorMatrixColorTintAlpha; // @synthesize colorMatrixColorTintAlpha=_colorMatrixColorTintAlpha;
@property(retain, nonatomic) UIColor *colorMatrixColorTint; // @synthesize colorMatrixColorTint=_colorMatrixColorTint;
@property(nonatomic) float colorMatrixGrayscaleTintAlpha; // @synthesize colorMatrixGrayscaleTintAlpha=_colorMatrixGrayscaleTintAlpha;
@property(nonatomic) float colorMatrixGrayscaleTintLevel; // @synthesize colorMatrixGrayscaleTintLevel=_colorMatrixGrayscaleTintLevel;
@property(nonatomic) BOOL updateMaskViewsForViewReentrancyGuard; // @synthesize updateMaskViewsForViewReentrancyGuard=_updateMaskViewsForViewReentrancyGuard;
@property(retain, nonatomic) id computeAndApplySettingsNotificationObserver; // @synthesize computeAndApplySettingsNotificationObserver=_computeAndApplySettingsNotificationObserver;
@property(nonatomic) BOOL applySettingsAfterLayout; // @synthesize applySettingsAfterLayout=_applySettingsAfterLayout;
@property(retain, nonatomic) NSMutableDictionary *filterMaskViewMap; // @synthesize filterMaskViewMap=_filterMaskViewMap;
@property(retain, nonatomic) UIView *filterMaskViewContainer; // @synthesize filterMaskViewContainer=_filterMaskViewContainer;
@property(retain, nonatomic) NSMutableDictionary *colorTintMaskViewMap; // @synthesize colorTintMaskViewMap=_colorTintMaskViewMap;
@property(retain, nonatomic) UIView *colorTintMaskViewContainer; // @synthesize colorTintMaskViewContainer=_colorTintMaskViewContainer;
@property(retain, nonatomic) NSMutableDictionary *grayscaleTintMaskViewMap; // @synthesize grayscaleTintMaskViewMap=_grayscaleTintMaskViewMap;
@property(retain, nonatomic) UIView *grayscaleTintMaskViewContainer; // @synthesize grayscaleTintMaskViewContainer=_grayscaleTintMaskViewContainer;
@property(retain, nonatomic) NSMutableSet *partialMaskViews; // @synthesize partialMaskViews=_partialMaskViews;
@property(nonatomic) NSInteger maskMode; // @synthesize maskMode=_maskMode;
@property(nonatomic) BOOL contentViewAccessorGuard; // @synthesize contentViewAccessorGuard=_contentViewAccessorGuard;
@property(nonatomic) BOOL contentViewAccessed; // @synthesize contentViewAccessed=_contentViewAccessed;
@property(retain, nonatomic) UIView *contentView; // @synthesize contentView=_contentView;
@property(retain, nonatomic) CAFilter *tintFilter; // @synthesize tintFilter=_tintFilter;
@property(retain, nonatomic) CAFilter *colorSaturateFilter; // @synthesize colorSaturateFilter=_colorSaturateFilter;
@property(retain, nonatomic) CAFilter *gaussianBlurFilter; // @synthesize gaussianBlurFilter=_gaussianBlurFilter;
@property(retain, nonatomic) UIImage *colorTintMaskImage; // @synthesize colorTintMaskImage=_colorTintMaskImage;
@property(retain, nonatomic) UIView *colorTintView; // @synthesize colorTintView=_colorTintView;
@property(retain, nonatomic) UIImage *grayscaleTintMaskImage; // @synthesize grayscaleTintMaskImage=_grayscaleTintMaskImage;
@property(retain, nonatomic) UIView *grayscaleTintView; // @synthesize grayscaleTintView=_grayscaleTintView;
@property(retain, nonatomic) UIImage *filterMaskImage; // @synthesize filterMaskImage=_filterMaskImage;
@property(copy, nonatomic) NSString *groupName; // @synthesize groupName=_groupName;
@property(retain, nonatomic) _UIBackdropEffectView *backdropEffectView; // @synthesize backdropEffectView=_backdropEffectView;
@property(nonatomic) BOOL allowsColorSettingsSuppression; // @synthesize allowsColorSettingsSuppression=_allowsColorSettingsSuppression;
@property(nonatomic) BOOL blursBackground; // @synthesize blursBackground=_blursBackground;
@property(nonatomic) BOOL wantsColorSettings; // @synthesize wantsColorSettings=_wantsColorSettings;
@property(nonatomic) BOOL requiresTintViews; // @synthesize requiresTintViews=_requiresTintViews;
@property(nonatomic) BOOL applyingTransition; // @synthesize applyingTransition=_applyingTransition;
@property(nonatomic) BOOL applyingBackdropChanges; // @synthesize applyingBackdropChanges=_applyingBackdropChanges;
@property(nonatomic) BOOL appliesOutputSettingsAutomaticallyEnabledComputesColorSettings; // @synthesize appliesOutputSettingsAutomaticallyEnabledComputesColorSettings=_appliesOutputSettingsAutomaticallyEnabledComputesColorSettings;
@property(nonatomic) NSInteger configuration; // @synthesize configuration=_configuration;
@property(retain, nonatomic) _UIBackdropViewSettings *savedInputSettingsDuringRenderInContext; // @synthesize savedInputSettingsDuringRenderInContext=_savedInputSettingsDuringRenderInContext;
@property(retain, nonatomic) _UIBackdropViewSettings *outputSettings; // @synthesize outputSettings=_outputSettings;
@property(retain, nonatomic) _UIBackdropViewSettings *inputSettings; // @synthesize inputSettings=_inputSettings;
@property(nonatomic) double appliesOutputSettingsAnimationDuration; // @synthesize appliesOutputSettingsAnimationDuration=_appliesOutputSettingsAnimationDuration;
@property(nonatomic) BOOL appliesOutputSettingsAutomatically; // @synthesize appliesOutputSettingsAutomatically=_appliesOutputSettingsAutomatically;
@property(nonatomic) BOOL computesColorSettings; // @synthesize computesColorSettings=_computesColorSettings;
//@property id <_UIBackdropViewObserver> *observer;
@property(retain, nonatomic) NSHashTable *observers; // @synthesize observers=_observers;
@property(nonatomic) BOOL autosizesToFitSuperview; // @synthesize autosizesToFitSuperview=_autosizesToFitSuperview;
@property(nonatomic) NSInteger style; // @synthesize style=_style;
@property(readonly, nonatomic) UIView *effectView; // @dynamic effectView;
- (void)applySettings:(_UIBackdropViewSettings *)arg1;
- (void)applySettingsWithBuiltInAnimation:(id)arg1;
- (void)computeAndApplySettingsForTransition;
- (void)computeAndApplySettings:(_UIBackdropViewSettings *)arg1;
- (void)delayedComputeAndApplySettings;
- (void)adjustTintImplementationIfNeeded:(id)arg1;
- (void)ensureProperSubviewOrdering;
- (void)addContentViewIfNeededForSettings:(_UIBackdropViewSettings *)arg1;
- (void)addColorTintViewIfNeededForSettings:(_UIBackdropViewSettings *)arg1;
- (void)addGrayscaleTintViewIfNeededForSettings:(_UIBackdropViewSettings *)arg1;
- (void)addBackdropEffectViewIfNeededForSettings:(_UIBackdropViewSettings *)arg1;
- (void)updateSubviewHierarchyIfNeededForSettings:(_UIBackdropViewSettings *)arg1;
- (void)transitionComplete;
- (void)transitionIncrementallyToPrivateStyle:(NSInteger)arg1 weighting:(float)arg2;
- (void)transitionIncrementallyToStyle:(NSInteger)arg1 weighting:(float)arg2;
- (void)transitionToSettings:(_UIBackdropViewSettings *)arg1;
- (void)transitionToColor:(UIColor *)arg1;
- (void)transitionToPrivateStyle:(NSInteger)arg1;
- (void)transitionToStyle:(NSInteger)arg1;
- (void)prepareForTransitionToSettings:(_UIBackdropViewSettings *)arg1;
- (void)_setBlursBackground:(BOOL)arg1;
- (void)setUsesZoom;
- (void)_updateInputBounds;
- (void)scheduleUpdateInputBoundsIfNeeded;
- (void)setBlurFilterWithRadius:(float)arg1 blurQuality:(NSString *)arg2 blurHardEdges:(NSInteger)arg3;
- (void)setBlurFilterWithRadius:(float)arg1 blurQuality:(NSString *)arg2;
- (void)setBlursWithHardEdges:(BOOL)arg1;
- (NSArray *)filters;
- (void)_updateFilters;
- (void)removeOverlayBlendModeFromView:(UIView *)arg1;
- (void)applyOverlayBlendModeToView:(UIView *)arg1;
- (void)applyOverlayBlendMode:(NSInteger)arg1 toView:(UIView *)arg2;
- (void)removeMaskViews;
- (void)updateMaskViewsForView:(UIView *)arg1;
- (void)updateMaskViewForView:(UIView *)arg1 flag:(NSInteger)arg2;
- (void)setMaskImage:(UIImage *)arg1 onLayer:(CALayer *)arg2;
- (void)didMoveToSuperview;
- (void)removeObserver:(id)arg1;
- (void)addObserver:(id)arg1;
- (void)didCallRenderInContextOnBackdropViewLayer;
- (void)willCallRenderInContextOnBackdropViewLayer;
- (CALayer *)backdropViewLayer;
- (void)backdropLayerStatisticsDidChange:(id)arg1;
- (void)settingsDidChange:(_UIBackdropViewSettings *)arg1;
- (void)clearUpdateInputBoundsRunLoopObserver;
- (id)initWithFrame:(CGRect)arg1 privateStyle:(NSInteger)arg2;
- (id)initWithFrame:(CGRect)arg1 style:(NSInteger)arg2;
- (id)initWithPrivateStyle:(NSInteger)arg1;
- (id)initWithStyle:(NSInteger)arg1;
- (id)initWithSettings:(_UIBackdropViewSettings *)arg1;
- (id)initWithFrame:(CGRect)arg1 settings:(_UIBackdropViewSettings *)arg2;
- (id)initWithFrame:(CGRect)arg1 autosizesToFitSuperview:(BOOL)arg2 settings:(_UIBackdropViewSettings *)arg3;
@end

@interface _UIBackdropViewLayer : CALayer
{
    _UIBackdropView *_backdropView;
}
@property(assign) _UIBackdropView *backdropView;
@end

@interface _UIBackdropViewSettingsNone : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsLight : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsBlur : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsColored : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsColorSample : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsCombiner : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsDark : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsDarkLow : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsDarkWithZoom : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsPasscodePaddle : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsUltraLight : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsUltraColored : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsUltraDark : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsAdaptiveLight : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsSemiLight : _UIBackdropViewSettings
@end

@interface _UIBackdropViewSettingsNoneAdaptive : _UIBackdropViewSettings
@end

@interface UIDeviceRGBColor : UIColor
@end

@interface _UILegibilitySettings : NSObject
@property(retain) UIColor *contentColor;
@property(retain) UIColor *primaryColor;
@end

@interface _UILegibilitySettingsProvider : NSObject
- (_UILegibilitySettings *)settings;
@end

@interface _UILegibilitySettingsProvider (PhotoLibraryAdditions)
- (void)pl_primeForUseWithCameraOverlays;
@end

@interface _UILegibilityView : UIView
@property(retain) UIImage *image;
@property(retain) _UILegibilitySettings *settings;
@property(retain) UIImage *shadowImage;
- (id)initWithSettings:(_UILegibilitySettings *)settings strength:(CGFloat)strength image:(UIImage *)image shadowImage:(UIImage *)showImage options:(NSInteger)options;
- (void)setSettings:(_UILegibilitySettings *)settings image:(UIImage *)image shadowImage:(UIImage *)shadowImage;
- (void)updateForChangedSettings:(_UILegibilitySettings *)settings;
@end

@interface _UILegibilityLabel : _UILegibilityView
@end

extern NSInteger _UILegibilityViewOptionUsesColorFilters;

@interface CAMCameraSpec : NSObject
+ (instancetype)specForCurrentPlatform;
+ (instancetype)specForPhone;
+ (instancetype)specForPad;
@end

@interface CAMApplicationSpec : CAMCameraSpec
+ (instancetype)specForPhone;
+ (instancetype)specForPad;
@property(readonly) NSInteger modeDialOrientation;
@property(readonly) NSInteger bottomBarOrientation;
@end

@interface CAMPhoneApplicationSpec : CAMApplicationSpec
@end

@interface CAMPadApplicationSpec : CAMApplicationSpec
@end

@interface AVCaptureDevice (Addition)
- (BOOL)isFaceDetectionSupported;
@end

@interface AVCaptureFigVideoDevice : AVCaptureDevice
@end

@interface PLCameraButton : UIButton
@end

@interface PLCameraZoomSlider : UISlider
- (void)makeVisible;
- (void)makeInvisible;
@end

@interface PLCropOverlayBottomBar : UIToolbar
- (void)_setVisibility:(BOOL)visible;
@end

@interface PLCameraButtonBar : UIToolbar
@property(retain, nonatomic) PLCameraButton *cameraButton;
- (UIView *)_backgroundView;
- (void)_setVisibility:(BOOL)visible;
@end

@interface CAMZoomSlider : UISlider
@property(getter=isMinimumAutozooming) BOOL minimumAutozooming;
@property(getter=isMaximumAutozooming) BOOL maximumAutozooming;
@property(readonly) NSTimer *_visibilityTimer;
@property(getter=_isAutozooming,setter=_setAutozooming:) BOOL _autozooming;
@property(readonly) UIImageView *_thumbImageView;
@property(readonly) UIView *_minTrackMaskView;
@property(readonly) UIView *_maxTrackMaskView;
@property(assign, nonatomic) UIView *delegate;
- (void)_commonCAMZoomSliderInitialization;
- (void)makeInvisible;
- (void)makeVisible;
- (void)stopVisibilityTimer;
- (void)startVisibilityTimer;
- (void)_endAutozooming;
- (void)_beginAutozooming;
- (void)_updateAutozooming;
- (void)_hideZoomSlider:(id)arg1;
- (void)_postHideZoomSliderAnimation;
- (BOOL)visibilityTimerIsValid;
@end

@protocol flashButtonDelegate
@property(assign, nonatomic, getter=isAutoHidden) BOOL autoHidden;
@property NSInteger flashMode;
- (void)_expandAnimated:(BOOL)animated;
- (void)_collapseAndSetMode:(NSInteger)mode animated:(BOOL)animated;
@end

@interface CAMExpandableMenuButton : UIView
@property NSUInteger selectedIndex;
+ (double)expansionDuration;
- (NSArray *)_menuItems;
- (void)setHighlighted:(BOOL)highlighted forIndex:(NSUInteger)index;
@end

@interface CAMButtonLabel : UILabel
- (void)setUseLegibilityView:(BOOL)use;
@end

@interface PLCameraLevelView : UIView
@end

@interface CAMPanoramaLevelView : UIView
@end

@interface PLCameraPanoramaBrokenArrowView : UIView
@end

@interface CAMPanoramaArrowView : UIView
@end

@interface PLCameraPanoramaTextLabel : UILabel
@end

@interface CAMPanoramaLabel : UILabel
@end

@interface PLIOSurfaceData : NSData
@end

@interface PLReorientingButton : UIButton
@property(assign, nonatomic) CGFloat endCapRadius;
- (id)initWithFrame:(CGRect)frame;
- (void)setButtonOrientation:(NSInteger)orientation animated:(BOOL)animated;
@end

@protocol panoramaViewDelegate
- (void)setCaptureDirection:(NSInteger)direction;
- (void)_arrowWasTapped:(id)arg1;
@end

@interface CAMPanoramaView : UIView <panoramaViewDelegate>
@end

@interface PLCameraPanoramaView : UIView <panoramaViewDelegate>
@end

@interface CAMTriStateButton : UIControl
@property(assign, nonatomic) NSInteger flashMode;
@end

@interface CAMFlashButton : UIControl <flashButtonDelegate>
@property(assign, nonatomic) NSInteger orientation;
@property(readonly) UIImageView *_glyphView;
@property(readonly, assign, nonatomic) UIImageView *_flashIconView;
@property(readonly, assign, nonatomic) UIImageView *_iconView;
@property(readonly, assign, nonatomic) CAMButtonLabel *_offLabel;
@property(readonly, assign, nonatomic) CAMButtonLabel *_onLabel;
@property(readonly, assign, nonatomic) CAMButtonLabel *_autoLabel;
@property(assign, nonatomic) NSUInteger selectedIndex;
@property(getter=isUnavailable) BOOL unavailable;
@property BOOL allowsAutomaticFlash;
- (UIView *)delegate;
- (BOOL)isExpanded;
- (void)collapseMenuAnimated:(BOOL)animated;
- (void)expandMenuAnimated:(BOOL)animated;
- (void)collapseMenuAnimated:(BOOL)animated;
- (NSUInteger)indexForMode:(NSInteger)mode;
@end

@interface CAMTorchPattern : NSObject
- (id)initWithType:(NSInteger)type;
@end

@interface CAMTorchPatternController : NSObject
- (void)blink;
- (void)doubleBlink; // type 3
@end

@interface CAMFilterButton : UIButton
@property(readonly) UIImageView *_circlesImageView;
@property(getter=isOn) BOOL on;
@property UIEdgeInsets tappableEdgeInsets;
+ (CAMFilterButton *)filterButton;
- (void)_commonCAMFilterButtonInitialization;
- (UIImage *)_filterImage;
- (UIImage *)_filterOnImage;
- (float)_selectedIndicatorAlpha;
- (UIEdgeInsets )alignmentRectInsets;
- (id)initWithCoder:(id)coder;
- (id)initWithFrame:(CGRect)frame;
- (CGSize)intrinsicContentSize;
@end

@interface CAMHDRButton : UIButton
@property(readonly, nonatomic) CAMButtonLabel *_onLabel; // @synthesize _onLabel=__onLabel;
@property(readonly, nonatomic) CAMButtonLabel *_offLabel; // @synthesize _offLabel=__offLabel;
@property(readonly, nonatomic) CAMButtonLabel *_hdrLabel; // @synthesize _hdrLabel=__hdrLabel;
@property(nonatomic) NSInteger orientation; // @synthesize orientation=_orientation;
@property(nonatomic, getter=isOn) BOOL on; // @synthesize on=_on;
- (void)_updateFromOrientationChangeAnimated:(BOOL)arg1;
- (void)_updateFrameFromOrientation;
- (CGAffineTransform)_transformForOrientation:(NSInteger)arg1;
- (void)_updateLabelsFromOrientation;
- (void)_updateFromOnState;
- (void)setOrientation:(NSInteger)arg1 animated:(BOOL)arg2;
- (void)layoutSubviews;
- (void)_layoutForLandscapeOrientation;
- (void)_layoutForPortraitOrientation;
- (CGSize)sizeThatFits:(CGSize)arg1;
- (void)dealloc;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(CGRect)arg1;
- (void)_commonCAMHDRButtonInitialization;
@end

@interface CAMTimerButton : UIButton
@property NSInteger duration;
- (NSString *)titleForMenuItemAtIndex:(NSUInteger)index;
- (NSInteger)numberOfMenuItems;
@end

@interface CAMShutterButton : UIButton
+ (CAMShutterButton *)tinyShutterButton;
+ (CAMShutterButton *)smallShutterButton;
@property(getter=isPulsing, setter=setPulsing:) BOOL pulsing;
@property BOOL spinning;
@property NSInteger mode;
- (UIColor *)_colorForMode:(NSInteger)mode;
- (UIView *)_innerView;
- (UIView *)_outerView;
- (void)_updateOuterAndInnerLayers;
@end

@interface CAMFlipButton : UIButton
- (UIImage *)_flipImage;
@end

@interface PLCameraFlashButton : PLReorientingButton <flashButtonDelegate>
- (UIView *)delegate;
@end

@interface CAMModeDialItem : UIView
@end

@interface CAMModeDial : UIView
@property(retain, nonatomic) NSMutableArray *_items;
@property(retain, nonatomic) UIView *_itemsContainerView;
@property NSUInteger selectedIndex;
@property NSInteger orientation;
@end

@interface CAMElapsedTimeView : UIView
@property(readonly) UILabel *_timeLabel;
@property(readonly) UIImageView *_recordingImageView;
@property(readonly) NSTimer *_updateTimer;
@property(readonly) NSDate *_startTime;
- (void)_beginRecordingAnimation;
- (void)_endRecordingAnimation;
- (void)startTimer;
- (void)endTimer;
- (void)resetTimer;
- (void)_update:(NSTimer *)timer;
@end

@interface CAMSlalomIndicatorView : UIView
- (void)setFramesPerSecond:(NSInteger)sec;
@end

@interface CAMTopBar : UIView
@property(readonly, assign, nonatomic) UIView *_backgroundView;
@property(retain, nonatomic) CAMFilterButton *filterButton;
@property(retain, nonatomic) CAMHDRButton *HDRButton;
@property(retain, nonatomic) CAMFlashButton *flashButton;
@property(retain, nonatomic) CAMTimerButton *timerButton;
@property(retain, nonatomic) CAMFlipButton* flipButton;
@property(retain, nonatomic) CAMElapsedTimeView *elapsedTimeView;
@property(readonly, assign, nonatomic, getter=isFloating) BOOL floating;
@property(assign, nonatomic) NSInteger orientation;
@property(assign, nonatomic) NSInteger style;
@property(assign, nonatomic) NSInteger backgroundStyle;
- (NSObject /*<cameraViewDelegate>*/ *)delegate;
- (NSMutableArray *)_allowedControlsForVideoMode;
- (BOOL)_isFlashButtonExpanded;
- (BOOL)_shouldHideFlashButton;
- (void)setBackgroundStyle:(NSInteger)style animated:(BOOL)animated;
- (void)setStyle:(NSInteger)style animated:(BOOL)animated;
- (void)expandMenuButton:(UIButton *)button animated:(BOOL)animated;
- (void)collapseMenuButton:(UIButton *)button animated:(BOOL)animated;
@end

@interface CAMBottomBar : UIView
@property(readonly, assign, nonatomic) UIView *backgroundView;
@property(retain, nonatomic) CAMFilterButton *filterButton;
@property(retain, nonatomic) CAMFlipButton *flipButton;
@property(retain, nonatomic) CAMHDRButton *HDRButton;
@property(retain, nonatomic) CAMTimerButton *timerButton;
@property(retain, nonatomic) CAMShutterButton *shutterButton;
@property(retain, nonatomic) CAMShutterButton *stillDuringVideoButton;
@property(retain, nonatomic) CAMModeDial *modeDial;
@property(retain, nonatomic) CAMSlalomIndicatorView *slalomIndicatorView;
- (NSObject /*<cameraViewDelegate>*/ *)delegate;
- (UIView *)backgroundView;
- (CGSize)sizeThatFits:(CGSize)fits;
- (CGSize)intrinsicContentSize;
- (CGRect)alignmentRectForFrame:(CGRect)frame;
- (UIView *)_shutterButtomBottomLayoutSpacer;
- (BOOL)_isTimerButtonExpanded;
- (UIView *)_filterButtonBottomLayoutSpacer;
- (void)_setupHorizontalFilterButtonConstraints;
- (void)_setupVerticalFilterButtonConstraints;
@end

@interface CAMAvalancheSession : NSObject
@property(readonly, assign, nonatomic) NSUInteger numberOfPhotos;
@end

@interface CAMAvalancheCaptureService : NSObject
- (CAMAvalancheSession *)_activeAvalancheSession;
@end

@protocol cameraPreviewViewDelegate
@property float dimmingStrength;
- (void)setDimmingStrength:(float)strength duration:(double)duration;
@end

@interface CAMPreviewView : UIView <cameraPreviewViewDelegate>
@end

@interface PLCameraPreviewView : UIView <cameraPreviewViewDelegate>
@end

@interface PLPreviewOverlayView : UIView
@end

@interface PLCameraVideoStillCaptureButton : PLReorientingButton
@end

@interface PLCameraOptionsButton : PLReorientingButton
@end

@interface PLCameraSettingsView
@end

@interface PLCameraSettingsGroupView : UIView
@property(retain, nonatomic) UIView *accessorySwitch;
- (void)setType:(NSInteger)type;
- (void)setTitle:(NSString *)title;
@end

@interface PUAvalancheReviewControllerPhoneSpec : NSObject
@end

@interface PUPhotoEditViewController : NSObject
- (UIViewController *)delegate;
- (void)_handleDoneButton:(id)arg1;
@end

@interface PUPhotoBrowserController : UIViewController
- (id)_toolbarButtonForIdentifier:(NSString *)ident;
- (void)photoEditController:(PUPhotoEditViewController *)controller didFinishWithSavedChanges:(BOOL)change;
@end

@protocol effectFilterManagerDelegate
+ (NSObject <effectFilterManagerDelegate> *)sharedInstance;
- (NSUInteger)blackAndWhiteFilterStartIndex;
- (NSUInteger)filterCount;
- (CIFilter *)filterForIndex:(NSUInteger)index;
- (void)_addEffectNamed:(NSString *)name aggdName:(NSString *)aggdName filter:(CIFilter *)filter;
@end

@interface PLEffectFilterManager : NSObject <effectFilterManagerDelegate>
@end

@interface CAMEffectFilterManager : NSObject <effectFilterManagerDelegate>
@end

@protocol cameraGLViewDelegate
- (CGFloat)drawableHeight;
- (CGFloat)drawableWidth;
@end

@interface PLGLView : UIView <cameraGLViewDelegate>
@end

@interface CAMGLView : UIView <cameraGLViewDelegate>
@end

@protocol effectsGridViewDelegate
- (NSUInteger)_cellCount;
- (NSUInteger)_filterIndexForGridIndex:(NSUInteger)index;
- (BOOL)isBlackAndWhite;
- (BOOL)isSquare;
- (CGRect)rectForFilterIndex:(NSUInteger)index;
- (CGRect)_squareCropFromRect:(CGRect)rect;
@end

@interface PLEffectsGridView : UIView <effectsGridViewDelegate, cameraGLViewDelegate>
@end

@interface CAMEffectsGridView : UIView <effectsGridViewDelegate, cameraGLViewDelegate>
@end

@interface PLEffectSelectionViewController : UIViewController
- (void)_setSelectedIndexPath:(NSIndexPath *)indexPath;
@end

@interface CAMEffectSelectionViewController : UIViewController
- (void)_setSelectedIndexPath:(NSIndexPath *)indexPath;
@end

@interface PLImageAdjustmentView : UIView
@property(retain) UIImage *editedImage;
- (void)setEditedImage:(UIImage *)image;
@end

@interface _PLManagedAsset : NSObject
- (NSInteger)orientationValue;
@end

@interface PLManagedAsset : _PLManagedAsset
@property(readonly, nonatomic) NSString *pathForImageFile;
@property(readonly, nonatomic) NSString *pathForOriginalFile;
@property(readonly, nonatomic) NSString *pathForAdjustmentFile;
@property short kindSubtype;
@property short savedAssetType;
@property BOOL hasAdjustments;
- (BOOL)isMogul;
- (BOOL)isVideo;
@end

@interface PLVideoView : UIView
@property(readonly) PLManagedAsset *videoCameraImage;
- (BOOL)isPlaying;
- (BOOL)canEdit;
- (BOOL)_canAccessVideo;
- (BOOL)_mediaIsPlayable;
- (BOOL)_mediaIsVideo;
- (BOOL)_shouldShowSlalomEditor;
@end

@interface PLPublishingAgent : NSObject
@property BOOL enableHDUpload;
@property BOOL mediaIsHDVideo;
@property NSInteger remakerMode;
@property NSInteger selectedOption;
+ (PLPublishingAgent *)publishingAgentForBundleNamed:(NSString *)name toPublishMedia:(PLManagedAsset *)media;
- (NSInteger)_remakerModeForSelectedOption;
- (void)_transcodeVideo:(PLManagedAsset *)asset;
@end

@interface PLPhotoBrowserController : UIViewController <UIActionSheetDelegate>
@property(assign, nonatomic) BOOL isCameraApp;
@property(readonly, assign, nonatomic) PLVideoView *currentVideoView;
- (PLManagedAsset *)currentAsset;
- (BOOL)isEditingVideo;
- (UINavigationBar *)navigationBar;
@end

@interface FigCaptureSourceFormat : NSObject
- (id)initWithFigCaptureStreamFormatDictionary:(id)dictionary;
- (id)AVCaptureSessionPresets;
- (BOOL)isPhotoFormat;
- (BOOL)isHighResPhotoFormat;
@end

@interface PFVideoAdjustments : NSObject
+ (CMTimeRange)defaultSlowMotionTimeRangeForDuration:(CMTime)duration;
+ (float)defaultSlowMotionRateForNominalFrameRate:(float)framerate;
@property CMTimeRange slowMotionTimeRange;
- (id)initWithURL:(NSURL *)url;
- (id)initWithSlowMotionTimeRange:(CMTimeRange)range rate:(float)rate;
- (BOOL)isRecognizedFormat;
@end

@interface AVCaptureDeviceFormat_FigRecorder : NSObject
- (id)initWithDictionary:(NSDictionary *)dictionary;
@end

@interface AVAssetExportSession (Addition)
- (void)setMinVideoFrameDuration:(CMTime)duration;
@end

@interface PLCIFilterUtilties : NSObject
+ (CIImage *)outputImageFromFilters:(NSArray *)filters inputImage:(CIImage *)inputImage orientation:(UIImageOrientation)orientation copyFiltersFirst:(BOOL)copyFirst;
@end

@interface PLEditPhotoController : UIViewController <UIActionSheetDelegate>
@property(readonly) CGRect normalizedCropRect;
- (UINavigationItem *)navigationItem;
- (CIImage *)_newCIImageFromUIImage:(UIImage *)image;
- (NSArray *)_currentNonGeometryFiltersWithEffectFilters:(NSArray *)filters;
- (NSArray *)_cropAndStraightenFiltersForImageSize:(CGSize)size forceSquareCrop:(BOOL)crop forceUseGeometry:(BOOL)geometry;
- (void)_setControlsEnabled:(BOOL)enabled animated:(BOOL)animated;
- (void)_presentSavingHUD;
- (void)_dismissSavingHUD;
- (void)save:(UIBarButtonItem *)item;
- (void)cancel:(UIBarButtonItem *)item;
- (void)saveAdjustments;
@end

@interface CAMHDRBadge : UIButton
@end

@protocol cameraViewDelegate
@property(assign, nonatomic) NSInteger videoFlashMode;
@property(assign, nonatomic) NSInteger flashMode;
@property(assign, nonatomic) NSInteger lastSelectedPhotoFlashMode;
@property(readonly, assign, nonatomic) CAMModeDial *_modeDial;
@property(readonly, assign, nonatomic) CAMTopBar *_topBar;
@property(readonly, assign, nonatomic) CAMBottomBar *_bottomBar;
@property(readonly, assign, nonatomic) CAMFlashButton *_flashButton;
@property(readonly, assign, nonatomic) CAMShutterButton *_stillDuringVideoButton;
@property(readonly, assign, nonatomic) CAMElapsedTimeView *_elapsedTimeView;
@property(assign, nonatomic, getter=isTallScreen) BOOL tallScreen;
@property(readonly, assign, nonatomic) BOOL isCameraReady;
@property(assign, nonatomic) NSInteger cameraDevice;
@property(assign, nonatomic) NSInteger cameraMode;
@property(readonly, assign, nonatomic) CAMAvalancheSession *_avalancheSession;
@property(assign, nonatomic) BOOL HDRIsOn;
@property(readonly, assign, nonatomic) CGRect unzoomedPreviewFrame;
- (CAMHDRBadge *)_HDRBadge;
- (BOOL)HDRIsOn;
- (BOOL)_shouldHideHDRBadgeForMode:(NSInteger)mode;
- (void)_createHDRBadgeIfNecessary;
- (void)_updateHDRBadge;
- (NSInteger)_photoFlashMode;
- (NSInteger)_currentFlashMode;
- (BOOL)_isCapturing;
- (void)_updateTopBarStyleForDeviceOrientation:(NSInteger)orientation;
- (void)flashButtonDidChangeFlashMode:(id)arg1;
- (BOOL)_performingTimedCapture;
- (BOOL)hasInFlightCaptures;
- (void)_shutterButtonClicked;
- (void)pausePreview;
- (void)resumePreview;
- (void)_setShouldShowFocus:(BOOL)focus;
- (void)hideStaticClosedIris;
- (void)_updatePreviewWellImage:(UIImage *)image;
- (void)_setOverlayControlsEnabled:(BOOL)enabled;
- (void)_setFlashMode:(NSInteger)mode;
- (void)_clearFocusViews;
- (void)_setBottomBarEnabled:(BOOL)enabled;
- (void)setCameraButtonsEnabled:(BOOL)enabled;
- (void)takePictureOpenIrisAnimationFinished;
- (NSString *)modeDial:(CAMModeDial *)modeDial titleForItemAtIndex:(NSUInteger)index;
- (void)_switchFromCameraModeAtIndex:(NSUInteger)fromIndex toCameraModeAtIndex:(NSUInteger)toIndex;
- (void)_rotateCameraControlsAndInterface;
- (CGRect)_bottomBarFrame;
- (BOOL)bottomBarShouldHideFilterButton:(id)arg1;
- (BOOL)_shouldHideFilterButtonForMode:(NSInteger)mode;
- (BOOL)_shouldHideModeDialForMode:(NSInteger)mode;
- (BOOL)_shouldEnableFlashButton;
- (BOOL)_didEverMoveToWindow;
- (BOOL)_shouldEnableModeDial;
- (void)_handleVolumeUpEvents:(NSUInteger)events;
- (void)showZoomSlider;
- (void)_beginZooming;
- (void)_addZoomAnimationDisplayLinkWithSelector:(SEL)selector;
- (void)_setZoomFactor:(CGFloat)factor;
- (void)_endZooming;
- (void)_createZoomSliderIfNecessary;
- (BOOL)_shouldHideFlashButtonForMode:(NSInteger)mode;
- (BOOL)_shouldHideTopBarForMode:(NSInteger)mode;
- (BOOL)_isStillImageMode:(NSInteger)mode;
- (BOOL)_isVideoMode:(NSInteger)mode;
- (BOOL)_isHidingBadgesForFilterUI;
- (void)_layoutTopBarForOrientation:(NSInteger)orientation;
- (void)flashButtonModeDidChange:(NSInteger)mode;
- (void)_captureStillDuringVideo;
- (void)_setSwipeToModeSwitchEnabled:(BOOL)enabled;
- (NSInteger)_glyphOrientationForCameraOrientation:(NSInteger)cameraOrientation;
- (CAMApplicationSpec *)spec;
@end

@interface PLCameraView : UIView <cameraViewDelegate>
@property(retain, nonatomic) UIToolbar *bottomButtonBar;
@property NSInteger photoFlashMode;
//- (PLVideoPreviewView *)videoPreviewView;
- (BOOL)_isStillImageMode:(NSInteger)mode;
- (void)_setSettingsButtonAlpha:(CGFloat)alpha duration:(double)duration;
- (void)_disableBottomBarForContinuousCapture;
- (void)_setBottomBarEnabled:(BOOL)enabled;
- (void)_setShouldShowFocus:(BOOL)show;
- (void)_checkDiskSpaceAfterCapture;
- (void)openIrisWithDidFinishSelector:(SEL)openIrisWith withDuration:(float)duration;
- (void)closeIrisWithDidFinishSelector:(SEL)closeIrisWith withDuration:(float)duration;
@end

@interface PLUICameraViewController : UIViewController
- (PLCameraView *)_cameraView;
@end

@interface CAMCameraView : UIView <cameraViewDelegate>
- (CAMTorchPatternController *)_torchPatternController;
- (NSInteger)_HDRMode;
- (NSInteger)_currentTimerDuration;
- (NSInteger)_remainingDelayedCaptureTicks;
- (CAMPreviewView *)previewView;
- (CAMShutterButton *)_shutterButton;
- (BOOL)_shouldUseAvalancheForDelayedCapture;
- (BOOL)_avalancheCaptureInProgress;
- (void)_startDelayedCapture;
- (void)_updateForFocusCapabilities;
@end

@protocol cameraEffectsRendererDelegate
@property(assign, nonatomic, getter=isShowingGrid) BOOL showGrid;
@end

@interface PLCameraEffectsRenderer : NSObject <cameraEffectsRendererDelegate>
@end

@interface CAMEffectsRenderer : NSObject <cameraEffectsRendererDelegate>
@end

@protocol cameraControllerDelegate
@property(assign, nonatomic) AVCaptureDevice *currentDevice;
@property(assign, nonatomic) AVCaptureOutput *currentOutput;
@property(retain, nonatomic) AVCaptureVideoPreviewLayer *previewLayer;
@property(readonly, assign, nonatomic) AVCaptureSession *currentSession;
@property(assign, nonatomic) NSInteger cameraDevice;
@property(assign, nonatomic) NSInteger cameraMode;
@property(assign, nonatomic) NSInteger flashMode;
@property(readonly, assign, nonatomic) NSInteger cameraOrientation;
@property(assign, nonatomic, getter=isHDREnabled) BOOL HDREnabled;
@property(retain) NSObject <cameraEffectsRendererDelegate> *effectsRenderer;
@property(assign, nonatomic) CGFloat videoZoomFactor;
@property(getter=_isPreviewPaused, setter=_setPreviewPaused:) BOOL _previewPaused;
+ (BOOL)isStillImageMode:(NSInteger)mode;
- (BOOL)isCameraApp;
- (BOOL)canCaptureVideo;
- (BOOL)isChangingModes;
- (BOOL)isReady;
- (NSMutableArray *)supportedCameraModes;
- (UIView <cameraViewDelegate> *)delegate;
- (BOOL)isCapturingVideo;
- (void)_setFlashMode:(NSInteger)mode force:(BOOL)force;
- (void)_suggestedHDRChanged;
- (BOOL)isFocusLockSupported;
- (BOOL)flashWillFire;
- (void)pausePreview;
- (void)resumePreview;
- (void)setFaceDetectionEnabled:(BOOL)enabled;
- (void)setFocusDisabled:(BOOL)disabled;
- (void)_lockFocus:(BOOL)focus lockExposure:(BOOL)exposure lockWhiteBalance:(BOOL)whiteBalance;
- (NSUInteger)_activeFilterIndex;
- (double)mogulFrameRate;
- (CGFloat)maximumZoomFactorForDevice:(AVCaptureDevice *)device;
- (BOOL)_lockCurrentDeviceForConfiguration;
- (void)_unlockCurrentDeviceForConfiguration;
- (void)setFocusDisabled:(BOOL)disabled;
@end

@interface PLCameraController : NSObject <cameraControllerDelegate>
@property BOOL performingTimedCapture;
- (PLCameraView *)delegate;
- (BOOL)_isVideoMode:(NSInteger)mode;
- (void)setFaceDetectionEnabled:(BOOL)enabled;
@end

@interface CAMCaptureController : NSObject <cameraControllerDelegate>
@property BOOL performingAvalancheCapture;
+ (BOOL)isStillImageMode:(NSInteger)mode;
+ (BOOL)isVideoMode:(NSInteger)mode;
- (CAMCameraView *)delegate;
- (BOOL)isCapturingPanorama;
- (BOOL)isCapturingTimelapse;
- (CAMAvalancheCaptureService *)_avalancheCaptureService;
- (void)setFaceDetectionEnabled:(BOOL)enabled forceDisableImageProcessing:(BOOL)disableIP;
@end

@interface PLCameraController (CamRotate)
- (BOOL)isSyncOrientation;
@end

@interface CAMCaptureController (CamRotate)
- (BOOL)isSyncOrientation;
@end

@interface CAMLegibilityViewHelper : NSObject
+ (UIImage *)_imageFromLabel:(UILabel *)label sizeToFit:(BOOL)fit;
@end

@interface CAMCameraViewController : UIViewController
@end

@interface CAMApplicationViewController : CAMCameraViewController
@end

@interface DeferredPUCameraApplicationViewController : CAMApplicationViewController <UIActionSheetDelegate>
@end

@interface PUAbstractAlbumListViewController : UIViewController
- (UIBarButtonItem *)_internalButtonItem;
@end

@interface PUAlbumListViewController : UIViewController
- (UIBarButtonItem *)_internalButtonItem;
@end

@interface PURootSettings : NSObject
+ (void)presentSettingsController;
@end

@interface PUPhotoEditProtoSettings : NSObject
@property BOOL useOldPhotosEditor2;
@end

@interface PLPhotoEffect : NSObject
+ (NSArray *)allEffects;
+ (PLPhotoEffect *)_effectWithIdentifier:(NSString *)identifier CIFilterName:(NSString *)filterName displayName:(NSString *)displayName;
+ (PLPhotoEffect *)_effectWithIdentifier:(NSString *)identifier;
+ (PLPhotoEffect *)_effectWithCIFilterName:(NSString *)identifier;
+ (NSUInteger)indexOfEffectWithIdentifier:(NSString *)identifier;
- (NSString *)displayName;
- (NSString *)filterIdentifier;
- (NSString *)CIFilterName;
@end

@interface PLProgressHUD : UIView
- (void)done;
- (void)showInView:(UIView *)view;
- (void)hide;
- (void)setText:(NSString *)text;
@end

@interface PBFilter : CIFilter
@end

@interface CIColorPosterize : CIFilter
@property(retain, nonatomic) NSNumber *inputLevels;
@end

@interface CIColorMonochrome : CIFilter
@property(retain, nonatomic) NSNumber *inputIntensity;
@property(retain, nonatomic) CIColor *inputColor;
@end

@interface CIFalseColor : CIFilter
@property(retain, nonatomic) CIColor *inputColor0;
@property(retain, nonatomic) CIColor *inputColor1;
@end

@interface CISepiaTone : CIFilter
@property(retain, nonatomic) NSNumber *inputIntensity;
@end

@interface CIVibrance : CIFilter
@property(retain, nonatomic) NSNumber *inputAmount;
@end

@interface CIBloom : CIFilter
@property(retain, nonatomic) NSNumber *inputIntensity;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIGloom : CIFilter
@property(retain, nonatomic) NSNumber *inputIntensity;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIGaussianBlur : CIFilter
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIThermal : CIFilter
@end

@interface CIXRay : CIFilter
@end

@interface CIPixellate : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputScale;
@end

@interface CIStretch : CIFilter
@property(retain, nonatomic) CIVector *inputPoint;
@property(retain, nonatomic) CIVector *inputSize;
@end

@interface CITwirlDistortion : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRadius;
@property(retain, nonatomic) NSNumber *inputAngle;
@end

@interface CIHoleDistortion : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIPinchDistortion : CIFilter
@property(retain, nonatomic) NSNumber *inputScale;
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CIMirror : CIFilter
@property(retain, nonatomic) NSNumber *inputAngle;
@property(retain, nonatomic) CIVector *inputPoint;
@end

@interface CIWrapMirror : CIFilter
@end

@interface CISharpenLuminance : CIFilter
@property(retain, nonatomic) NSNumber *inputSharpness;
@end

@interface CITriangleKaleidoscope : CIFilter
@property(retain, nonatomic) NSNumber *inputDecay;
@property(retain, nonatomic) NSNumber *inputSize;
@property(retain, nonatomic) NSNumber *inputAngle;
@property(retain, nonatomic) CIVector *inputPoint;
@end

@interface CILightTunnel : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRotation;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CICircleSplashDistortion : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputRadius;
@end

@interface CICircularScreen : CIFilter
@property(retain, nonatomic) CIVector *inputCenter;
@property(retain, nonatomic) NSNumber *inputWidth;
@property(retain, nonatomic) NSNumber *inputSharpness;
@end

@interface CILineScreen : CIFilter
@property(retain, nonatomic) NSNumber *inputAngle;
@property(retain, nonatomic) NSNumber *inputWidth;
@property(retain, nonatomic) NSNumber *inputSharpness;
@end

/*@interface PSViewController (Addition)
- (void)setView:(id)view;
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
- (void)viewDidLoad;
@end

@interface UITableViewCell (Addition)
- (id)initWithFrame:(CGRect)frame reuseIdentifier:(NSString *)identifier;
@end

@interface PSTableCell (Addition)
@property(retain, nonatomic) UIView *accessoryView;
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier specifier:(PSSpecifier *)specifier;
@end

@interface PSSwitchTableCell : PSControlTableCell
- (id)initWithStyle:(NSInteger)arg1 reuseIdentifier:(id)identifier specifier:(id)spec;
@end*/

@interface SBSRestartRenderServerAction : NSObject
+ (SBSRestartRenderServerAction *)restartActionWithTargetRelaunchURL:(NSURL *)url;
@end

@interface FBSSystemService : NSObject
+ (FBSSystemService *)sharedService;
- (void)sendActions:(NSSet *)actions withResult:(id)result;
@end

@interface FigCaptureStillImageSettings : NSObject
@property NSUInteger outputWidth;
@property NSUInteger outputHeight;
@property NSUInteger thumbnailWidth;
@property NSUInteger thumbnailHeight;
@property BOOL outputMirroring;
@property NSInteger outputOrientation;
@property BOOL thumbnailEnabled;
@property BOOL thumbnailMirroring;
@property NSInteger thumbnailOrientation;
@property NSInteger flashMode;
@property NSInteger HDRMode;
@property CGFloat scaleFactor;
@end
