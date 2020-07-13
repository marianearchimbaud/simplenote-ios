#import <UIKit/UIKit.h>
#import "SPActionSheet.h"
#import "SPActivityView.h"
#import "SPTagView.h"
#import "SPAddCollaboratorsViewController.h"
#import <Simperium/Simperium.h>
@class Note;
@class SPTextView;
@class SPEditorTextView;
@class SPOutsideTouchView;
@class SPHistoryLoader;

@interface SPNoteEditorViewController : UIViewController  <SPActionSheetDelegate, SPActivityViewDelegate, UIActionSheetDelegate, SPTagViewDelegate, SPCollaboratorDelegate> {
    
    // Other Objects
    NSTimer *saveTimer;
    NSTimer *guarenteedSaveTimer;
    
    // BOOLS
    BOOL bBlankNote;
    BOOL bDisableShrinkingNavigationBar;
    BOOL bShouldDelete;
    BOOL beditingTags;
    BOOL bActionSheetVisible;
    BOOL bVoiceoverEnabled;
    
    CGAffineTransform navigationBarTransform;
    CGFloat scrollPosition;
    
    SPOutsideTouchView *navigationButtonContainer;
    
    UIBarButtonItem *nextSearchButton;
    UIBarButtonItem *prevSearchButton;
    UIBarButtonItem *doneSearchButton;
    
    // sheets
    SPActivityView *noteActivityView;
    SPActionSheet *noteActionSheet;
    
    BOOL bSearching;
    NSInteger highlightedSearchResultIndex;
    
    UILabel *searchDetailLabel;
}

// Navigation Back Button
@property (nonatomic, strong) UIButton *backButton;

// Navigation Buttons
@property (nonatomic, strong) UIButton *actionButton;
@property (nonatomic, strong) UIButton *checklistButton;
@property (nonatomic, strong) UIButton *keyboardButton;
@property (nonatomic, strong) UIButton *createNoteButton;

@property (nonatomic, strong) Note *currentNote;
@property (nonatomic, strong) SPEditorTextView *noteEditorTextView;
@property (nonatomic, strong) SPTagView *tagView;
@property (nonatomic, strong) NSString *searchString;

@property (nonatomic, weak) UIViewController *historyCardViewController;
@property (nonatomic, weak) SPHistoryLoader *historyLoader;

@property (nonatomic, getter=isEditingNote) BOOL editingNote;
@property (nonatomic, getter=isPreviewing) BOOL previewing;
@property (nonatomic, getter=isKeyboardVisible) BOOL keyboardVisible;
@property (nonatomic, getter=isModified) BOOL modified;

- (void)prepareToPopView;
- (void)updateNote:(Note *)note;
- (void)setSearchString:(NSString *)string;
- (void)clearNote;

- (void)willReceiveNewContent;
- (void)didReceiveNewContent;
- (void)didDeleteCurrentNote;

- (void)save;

@end
