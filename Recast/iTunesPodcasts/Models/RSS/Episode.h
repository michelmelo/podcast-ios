//
//  Episode.h
//  Recast
//
//  Created by Mindy Lou on 10/21/18.
//  Copyright © 2018 Cornell AppDev. All rights reserved.
//

#import <CoreData/CoreData.h>
#import "iTunesNamespace.h"

@class DownloadInfo;
@class Enclosure;
@class ItemSource;

/// A channel may contain any number of <item>s. An item may represent a
/// "story" -- much like a story in a newspaper or magazine; if so its
/// description is a synopsis of the story, and the link points to the full
/// story. An item may also be complete in itself, if so, the description
/// contains the text (entity-encoded HTML is allowed; see examples:
/// http://cyber.law.harvard.edu/rss/encodingDescriptions.html), and
/// the link and title may be omitted. All elements of an item are optional,
/// however at least one of title or description must be present.
@interface Episode : NSManagedObject

/// The title of the item.
///
/// Example: Venice Film Festival Tries to Quit Sinking
@property (nullable, nonatomic, copy) NSString *title;

/// The URL of the item.
///
/// Example: http://nytimes.com/2004/12/07FEST.html
@property (nullable, nonatomic, copy) NSString *link;

/// The item synopsis.
///
/// Example: Some of the most heated chatter at the Venice Film Festival this
/// week was about the way that the arrival of the stars at the Palazzo del
/// Cinema was being staged.
@property (nullable, nonatomic, copy) NSString *descriptionText;

/// Email address of the author of the item.
///
/// Example: oprah\@oxygen.net
///
/// <author> is an optional sub-element of <item>.
///
/// It's the email address of the author of the item. For newspapers and
/// magazines syndicating via RSS, the author is the person who wrote the
/// article that the <item> describes. For collaborative weblogs, the author
/// of the item might be different from the managing editor or webmaster.
/// For a weblog authored by a single individual it would make sense to omit
/// the <author> element.
///
/// <author>lawyer@boyer.net (Lawyer Boyer)</author>
@property (nullable, nonatomic, copy) NSString *author;

/// Includes the item in one or more categories.
///
/// <category> is an optional sub-element of <item>.
///
/// It has one optional attribute, domain, a string that identifies a
/// categorization taxonomy.
///
/// The value of the element is a forward-slash-separated string that
/// identifies a hierarchic location in the indicated taxonomy. Processors
/// may establish conventions for the interpretation of categories.
///
/// Two examples are provided below:
///
/// <category>Grateful Dead</category>
/// <category domain="http://www.fool.com/cusips">MSFT</category>
///
/// You may include as many category elements as you need to, for different
/// domains, and to have an item cross-referenced in different parts of the
/// same domain.
@property (nullable, nonatomic, copy) NSArray<NSString *> *categories;

/// URL of a page for comments relating to the item.
///
/// Example: http://www.myblog.org/cgi-local/mt/mt-comments.cgi?entry_id=290
///
/// <comments> is an optional sub-element of <item>.
///
/// If present, it is the url of the comments page for the item.
///
/// <comments>http://ekzemplo.com/entry/4403/comments</comments>
///
/// More about comments here:
/// http://cyber.law.harvard.edu/rss/weblogComments.html
@property (nullable, nonatomic, copy) NSString *comments;

/// Describes a media object that is attached to the item.
///
/// <enclosure> is an optional sub-element of <item>.
///
/// It has three required attributes. url says where the enclosure is located,
/// length says how big it is in bytes, and type says what its type is, a
/// standard MIME type.
///
/// The url must be an http url.
///
/// <enclosure url="http://www.scripting.com/mp3s/weatherReportSuite.mp3"
/// length="12216320" type="audio/mpeg" />
@property (nullable, nonatomic, copy) Enclosure *enclosure;

/// A string that uniquely identifies the item.
///
/// Example: http://inessential.com/2002/09/01.php#a2
///
/// <guid> is an optional sub-element of <item>.
///
/// guid stands for globally unique identifier. It's a string that uniquely
/// identifies the item. When present, an aggregator may choose to use this
/// string to determine if an item is new.
///
/// <guid>http://some.server.com/weblogItem3207</guid>
///
/// There are no rules for the syntax of a guid. Aggregators must view them
/// as a string. It's up to the source of the feed to establish the
/// uniqueness of the string.
///
/// If the guid element has an attribute named "isPermaLink" with a value of
/// true, the reader may assume that it is a permalink to the item, that is,
/// a url that can be opened in a Web browser, that points to the full item
/// described by the <item> element. An example:
///
/// <guid isPermaLink="true">http://inessential.com/2002/09/01.php#a2</guid>
///
/// isPermaLink is optional, its default value is true. If its value is false,
/// the guid may not be assumed to be a url, or a url to anything in
/// particular.
@property (nullable, nonatomic, copy) NSString *guid;

/// Indicates when the item was published.
///
/// Example: Sun, 19 May 2002 15:21:36 GMT
///
/// <pubDate> is an optional sub-element of <item>.
///
/// Its value is a date, indicating when the item was published. If it's a
/// date in the future, aggregators may choose to not display the item until
/// that date.
@property (nullable, nonatomic, copy) NSDate *pubDate;

/// The RSS channel that the item came from.
///
/// <source> is an optional sub-element of <item>.
///
/// Its value is the name of the RSS channel that the item came from, derived
/// from its <title>. It has one required attribute, url, which links to the
/// XMLization of the source.
///
/// <source url="http://www.tomalak.org/links2.xml">Tomalak's Realm</source>
///
/// The purpose of this element is to propagate credit for links, to
/// publicize the sources of news items. It can be used in the Post command
/// of an aggregator. It should be generated automatically when forwarding
/// an item from an aggregator to a weblog authoring tool.
@property (nullable, nonatomic, copy) ItemSource *source;

// MARK: - Namespaces

/// A module for the actual content of websites, in multiple formats.
///
/// See http://web.resource.org/rss/1.0/modules/content/
@property (nullable, nonatomic, copy) NSString *content;

/// iTunes Podcasting Tags are de facto standard for podcast syndication.
/// see https://help.apple.com/itc/podcasts_connect/#/itcb54353390
@property (nullable, nonatomic, copy) ITunesNamespace *iTunes;

@property (nullable, nonatomic, copy) DownloadInfo *downloadInfo;

@end
