//
//  OMCOfflineState.h
//  OMCSynchronization
//
//  Copyright (c) 2015 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * An enumeration of the different Offline states for the resource.
 *
 * Default is "NoOfflineUpdates".
 */
typedef NS_ENUM(int, SyncOfflineState) {

    /** Denotes No offline updates */
    NoOfflineUpdates = 0,
    
    /** Denotes offline create pending */
    CreatePending = 1,
    
    /** Denotes offline update pending */
    UpdatePending = 2,
    
    /** Denotes offline patch pending */
    PatchPending = 3,
    
    /** Denotes offline delete pending */
    DeletePending = 4,
};


/**
 * An enumeration of the different Conflict states for the resource.
 *
 * Default is "NoConflicts".
 */
typedef NS_ENUM(int, SyncConflictState) {
    
    /** Denotes no conflicts */
    NoConflicts = 0,
    
    /** Denotes has conflicts */
    HasConflict = 1,
    
    /** Denotes has error */
    HasError = 2,
    
    /** Denotes has conflicts, with latest from server copy downloaded */
    HasConflictWithLatestCopy = 3,

};


/**
 * An enumeration of the different Pin states for the resource.
 *
 * Default is "UnPinned".
 */
typedef NS_ENUM(int, SyncResourcePinState) {
    
    /** Denotes Not pinned */
    UnPinned = 0,
    
    /** Denotes pinned */
    Pinned = 1,
    
    /** Denotes Pinned while downloading the object graph of resources */
    PinnedAnciliary = 2,
};


/**
 * An enumeration of the different Pin Priority for the resource.
 * The priority of pinned resources. High priority resources are synchronized first and network status may affect which resources are synchronized in the background.
 * Default is "Normal".
 */
typedef NS_ENUM(int, SyncPinPriority) {
    
    /** A normal priority. Objects pinned with normal priority may not be synchronized on certain network conditions */
    Normal = 0,   //
    
    /** A high priority. Objects pinned with high priority are synchronized before objects with Normal priority. */
    High = 1,
};

/**
 * An enumerration of different comparision operation for local database query
 */
typedef NS_ENUM(int, SyncCompareOperator) {
    
    /** Denotes Equals */
    Equals = 0,
    
    /** Denotes Not Equals */
    NotEquals = 1,
    
    /** Denotes Less than */
    LessThan = 2,
    
    /** Denotes Greater than */
    GreaterThan = 3,
    
    /** Denotes Less than or equal */
    LessThanOrEqual = 4,
    
    /** Denotes Greater than or equal */
    GreaterThanOrEqual = 5,
};


