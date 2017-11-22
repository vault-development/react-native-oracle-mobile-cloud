//
//  OMCStorageConstants.h
//  OMCStorage
//
//  Copyright (c) 2015, Oracle Corp. All rights reserved. 
//

#import <Foundation/Foundation.h>

#pragma mark - HTTP HEADERS
extern NSString* const DEVICE_ID_HEADER;
extern NSString* const DEVICE_ID_VALUE;
extern NSString* const CONTENT_TYPE_HEADER;
extern NSString* const CONTENT_LENGTH_HEADER;
extern NSString* const SYNC_AGENT_HEADER;
extern NSString* const SYNC_NO_STORE_HEADER;
extern NSString* const ACCPET_HEADER;
extern NSString* const DEFAULT_CONTENT_TYPE_VALUE;
extern NSString* const DEFAULT_ACCEPT_VALUE;
extern NSString* const IF_NONE_MATCH_HEADER;


#pragma mark - TAGS for Object properties
extern NSString* const OBJECT_PROPERTY_TAG_CREATEDON;
extern NSString* const OBJECT_PROPERTY_TAG_CREATEDBY;
extern NSString* const OBJECT_PROPERTY_TAG_MODIFIEDON;
extern NSString* const OBJECT_PROPERTY_TAG_MODIFIEDBY;
extern NSString* const OBJECT_PROPERTY_TAG_ID;
extern NSString* const OBJECT_PROPERTY_TAG_DISPLAYNAME;
extern NSString* const OBJECT_PROPERTY_TAG_LINKS;
extern NSString* const OBJECT_PROPERTY_LINK_TAG_REL;
extern NSString* const OBJECT_PROPERTY_LINK_TAG_CANONICAL;
extern NSString* const OBJECT_PROPERTY_LINK_TAG_HREF;
extern NSString* const COLLECTION_PROPERTY_TAG_ID;
extern NSString* const COLLECTION_PROPERTY_TAG_DESCRIPTION;
extern NSString* const COLLECTION_PROPERTY_TAG_USERISOLATED;

#pragma mark - TAGS for Header properties
extern NSString* const HEADER_PROPERTY_TAG_CREATEDON;
extern NSString* const HEADER_PROPRTTY_TAG_CREATEDBY;
extern NSString* const HEADER_PROPERTY_TAG_MODIFIEDON;
extern NSString* const HEADER_PROPERTY_TAG_MODIFIEDBY;
extern NSString* const HEADER_PROPERTY_TAG_CANONICAL_LINK;
extern NSString* const HEADER_PROPERTY_TAG_DISPLAYNAME;

#pragma mark - Property names to be used for reflection
extern NSString* const OBJECT_PROPERTY_NAME_DISPLAYNAME;
extern NSString* const OBJECT_PROPERTY_NAME_CREATEDON;
extern NSString* const OBJECT_PROPERTY_NAME_CREATEDBY;
extern NSString* const OBJECT_PROPERTY_NAME_MODIFIEDON;
extern NSString* const OBJECT_PROPERTY_NAME_MODIFIEDBY;
extern NSString* const OBJECT_PROPERTY_NAME_CANONICAL_LINK;
extern NSString* const COLLECTION_PROPERTY_NAME_ID;
extern NSString* const COLLECTION_PROPERTY_NAME_DESCRIPTION;
extern NSString* const COLLECTION_PROPERTY_NAME_OWNERID;
extern NSString* const COLLECTION_PROPERTY_NAME_USERISOLATED;

#pragma mark - Date Format
extern NSString* const DATE_FORMAT;
extern NSString* const USER_ID_KEY;

#pragma mark - relative Urls
extern NSString* const USER_INFO_RELATIVE_URL;


