//
//  ZFModalTransitionAnimator.h
//
//  Created by Amornchai Kanokpullwad on 5/10/14.
//  Copyright (c) 2014 zoonref. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UIKit/UIGestureRecognizerSubclass.h>

typedef NS_ENUM(NSUInteger, ZFModalTransitonDirection) {
    ZFModalTransitonDirectionBottom,
    ZFModalTransitonDirectionLeft,
    ZFModalTransitonDirectionRight,
};

@interface ZFDetectScrollViewEndGestureRecognizer : UIPanGestureRecognizer
@property (nonatomic, weak) UIScrollView *scrollview;
@property (nonatomic, weak) UIViewController *modalController;
@end

@interface ZFModalTransitionAnimator : UIPercentDrivenInteractiveTransition <UIViewControllerAnimatedTransitioning, UIViewControllerTransitioningDelegate, UIGestureRecognizerDelegate>

@property (nonatomic, assign, getter=isDragable) BOOL dragable;
@property (nonatomic, readonly) ZFDetectScrollViewEndGestureRecognizer *gesture;
@property (nonatomic, assign) UIGestureRecognizer *gestureRecognizerToFailPan;
@property BOOL bounces;
@property (nonatomic) ZFModalTransitonDirection direction;
@property CGFloat behindViewScale;
@property CGFloat behindViewAlpha;
@property CGFloat transitionDuration;

- (id)initWithModalViewController:(UIViewController *)modalViewController;
- (void)setContentScrollView:(UIScrollView *)scrollView;

@end
