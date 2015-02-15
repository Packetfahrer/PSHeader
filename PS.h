#import <CoreFoundation/CoreFoundation.h>
#import <AVFoundation/AVFoundation.h>
#import <Preferences/PSViewController.h>
#import <Preferences/PSTableCell.h>
#import <Preferences/PSControlTableCell.h>

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

#define isiOS45 (isiOS4 || isiOS5)

#define isiOS56 (isiOS5 || isiOS6)
#define isiOS78 (isiOS7 || isiOS8)

#define IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define PS_DONATE_URL @"https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=GBQGZL8EFMM86"
#define PS_TWITTER_URL @"twitter://user?screen_name=PoomSmart"

#define PH_BAR_HEIGHT 80

@interface UIScreen (Addition)
- (CGRect)_referenceBounds;
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

@interface PLCropOverlayBottomBar
- (void)_setVisibility:(BOOL)visible;
@end

@interface PLCameraButtonBar : UIToolbar
@property(retain, nonatomic) PLCameraButton *cameraButton;
- (UIView *)_backgroundView;
- (void)_setVisibility:(BOOL)visible;
@end

@interface CAMZoomSlider : UISlider
- (void)makeVisible;
- (BOOL)isMinimumAutozooming;
- (BOOL)isMaximumAutozooming;
- (void)_setMaximumAutozooming:(BOOL)autozooming;
- (void)_setMinimumAutozooming:(BOOL)autozooming;
@end

@protocol flashButtonDelegate
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
@property(readonly, assign, nonatomic) UIImageView *_flashIconView;
@property(readonly, assign, nonatomic) UIImageView *_iconView;
@property(readonly, assign, nonatomic) CAMButtonLabel *_offLabel;
@property(readonly, assign, nonatomic) CAMButtonLabel *_onLabel;
@property(readonly, assign, nonatomic) CAMButtonLabel *_autoLabel;
@property(assign, nonatomic) NSUInteger selectedIndex;
- (UIView *)delegate;
- (BOOL)isExpanded;
- (void)setAllowsAutomaticFlash:(BOOL)allow;
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
//@property(readonly, assign, nonatomic) BOOL on;
- (void)setOn:(BOOL)on;
@end

@interface CAMHDRButton : UIButton
@end

@interface CAMTimerButton : UIButton
@property NSInteger duration;
- (NSString *)titleForMenuItemAtIndex:(NSUInteger)index;
- (NSInteger)numberOfMenuItems;
@end

@interface CAMShutterButton : UIButton
+ (CAMShutterButton *)tinyShutterButton;
+ (CAMShutterButton *)smallShutterButton;
@end

@interface CAMFlipButton : UIButton
- (UIImage *)_flipImage;
@end

@interface PLCameraFlashButton : PLReorientingButton <flashButtonDelegate>
@property(assign, nonatomic, getter=isAutoHidden) BOOL autoHidden; // iOS 5+
- (id /*PLCameraView **/)delegate;
@end

@interface CAMModeDialItem : UIView
@end

@interface CAMModeDial : UIView
@property(retain, nonatomic) NSMutableArray *_items;
@property NSUInteger selectedIndex;
@end

@interface CAMElapsedTimeView : UIView
- (void)_beginRecordingAnimation;
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
- (NSObject /*<cameraViewDelegate>*/ *)delegate;
- (NSMutableArray *)_allowedControlsForVideoMode;
- (void)setBackgroundStyle:(NSInteger)style animated:(BOOL)animated;
- (void)setStyle:(NSInteger)style animated:(BOOL)animated;
- (void)expandMenuButton:(UIButton *)button animated:(BOOL)animated;
- (void)collapseMenuButton:(UIButton *)button animated:(BOOL)animated;
@end

@interface CAMBottomBar : UIView
@property(readonly, assign, nonatomic) UIView *backgroundView;
@property(retain, nonatomic) CAMFilterButton *filterButton;
@property(retain, nonatomic) CAMFlipButton *flipButton;
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

@interface CAMPreviewView : UIView
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
@property(readonly, assign, nonatomic) CAMModeDial *_modeDial;
@property(readonly, assign, nonatomic) CAMTopBar *_topBar;
@property(readonly, assign, nonatomic) CAMBottomBar *_bottomBar;
@property(readonly, assign, nonatomic) CAMFlashButton *_flashButton;
@property(readonly, assign, nonatomic) CAMShutterButton *_stillDuringVideoButton;
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
- (BOOL)_didEverMoveToWindow;
- (void)_handleVolumeUpEvents:(NSUInteger)events;
- (void)showZoomSlider;
- (void)_beginZooming;
- (void)_addZoomAnimationDisplayLinkWithSelector:(SEL)selector;
- (void)_setZoomFactor:(CGFloat)factor;
- (void)_endZooming;
- (void)_createZoomSliderIfNecessary;
- (BOOL)_shouldHideFlashButtonForMode:(NSInteger)mode;
- (BOOL)_isStillImageMode:(NSInteger)mode;
- (BOOL)_isVideoMode:(NSInteger)mode;
- (BOOL)_isHidingBadgesForFilterUI;
- (void)_layoutTopBarForOrientation:(NSInteger)orientation;
- (void)flashButtonModeDidChange:(NSInteger)mode;
- (void)_captureStillDuringVideo;
- (void)_setSwipeToModeSwitchEnabled:(BOOL)enabled;
@end

@interface PLCameraView : UIView <cameraViewDelegate>
@property(retain, nonatomic) UIToolbar *bottomButtonBar;
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
- (BOOL)_shouldUseAvalancheForDelayedCapture;
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
@property(readonly, assign, nonatomic) AVCaptureSession *currentSession;
@property(assign, nonatomic) NSInteger cameraDevice;
@property(assign, nonatomic) NSInteger cameraMode;
@property(assign, nonatomic) NSInteger flashMode;
@property(readonly, assign, nonatomic) NSInteger cameraOrientation;
@property(assign, nonatomic, getter=isHDREnabled) BOOL HDREnabled;
@property(nonatomic) BOOL performingTimedCapture;
@property(retain) NSObject <cameraEffectsRendererDelegate> *effectsRenderer;
@property(assign, nonatomic) CGFloat videoZoomFactor;
+ (BOOL)isStillImageMode:(NSInteger)mode;
- (BOOL)isCameraApp;
- (BOOL)isChangingModes;
- (BOOL)isReady;
- (NSMutableArray *)supportedCameraModes;
- (NSObject <cameraViewDelegate> *)delegate;
- (BOOL)isCapturingVideo;
- (void)_setFlashMode:(NSInteger)mode force:(BOOL)force;
- (void)_suggestedHDRChanged;
- (BOOL)isFocusLockSupported;
- (BOOL)flashWillFire;
- (void)setFaceDetectionEnabled:(BOOL)enabled;
- (void)setFocusDisabled:(BOOL)disabled;
- (void)_lockFocus:(BOOL)focus lockExposure:(BOOL)exposure lockWhiteBalance:(BOOL)whiteBalance;
- (NSUInteger)_activeFilterIndex;
- (double)mogulFrameRate;
- (CGFloat)maximumZoomFactorForDevice:(AVCaptureDevice *)device;

- (void)ToggleMode:(UISwitch *)sender;
- (void)FlashMode:(UISwitch *)sender;
- (void)SliderDidChange:(UISlider *)torchSlider;
@end

@interface PLCameraController : NSObject <cameraControllerDelegate>
- (PLCameraView *)delegate;
- (void)setFaceDetectionEnabled:(BOOL)enabled;
@end

@interface CAMCaptureController : NSObject <cameraControllerDelegate>
+ (BOOL)isStillImageMode:(NSInteger)mode;
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

@interface CAMCameraSpec : NSObject
+ (instancetype)specForCurrentPlatform;
+ (instancetype)specForPhone;
+ (instancetype)specForPad;
@end

@interface CAMApplicationSpec : CAMCameraSpec
+ (instancetype)specForPhone;
+ (instancetype)specForPad;
@end

@interface CAMPhoneApplicationSpec : CAMApplicationSpec
@end

@interface CAMPadApplicationSpec : CAMApplicationSpec
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

@interface PSViewController (Addition)
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
@end
