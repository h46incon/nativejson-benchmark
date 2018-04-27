#include "../test.h"
#include <cstring>

#ifndef TEST_NAME
#define TEST_NAME "IJST (C++)"
#endif

#ifndef TEST_CLASS
#define TEST_CLASS ijstTest
#endif

#define IJST_ENABLE_TO_JSON_OBJECT			1
#define IJST_ENABLE_FROM_JSON_OBJECT		1

#include "IJST/include/ijst/ijst.h"
#include "IJST/include/ijst/types_std.h"
#include "IJST/include/ijst/types_container.h"
#include <rapidjson/prettywriter.h>
#include <iostream>

using namespace ijst;
using namespace std;
using namespace rapidjson;

#ifndef MAP_TYPE
#define MAP_TYPE	IJST_TOBJ
#endif // !MAP_TYPE

//=== canada
namespace canada {
	IJST_DEFINE_STRUCT(
			StGeometry
			, (T_string, type, "type", 0)
			, (IJST_TVEC(IJST_TVEC(IJST_TVEC(T_double))), coordinates, "coordinates", 0)
	);

	IJST_DEFINE_STRUCT(
			StFeature
			, (T_string, type, "type", 0)
			, (MAP_TYPE(T_string), properties, "properties", 0)
			, (IJST_TST(StGeometry), geometry, "geometry", 0)
	)

	IJST_DEFINE_STRUCT(
			StCanada
			, (T_string, type, "type", 0)
			, (IJST_TVEC(IJST_TST(StFeature)), features, "features", 0)
	)
}
typedef canada::StCanada StCanada;

//=== canada_flat
namespace canada_flat {
IJST_DEFINE_STRUCT(
		StCanadaFlat
		, (IJST_TVEC(T_double), coordinates, "coordinates", 0)
);
}
typedef canada_flat::StCanadaFlat StCanadaFlat;
//=== twitter
namespace twitter{
	IJST_DEFINE_STRUCT(
			StUser
			, (T_uint64, id, "id", 0)
			, (T_string, id_str, "id_str", 0)
			, (T_string, screen_name, "screen_name", FDesc::Nullable)
			, (T_string, location, "location", FDesc::Nullable)
			, (T_string, description, "description", FDesc::Nullable)
			, (T_string, url, "url", FDesc::Nullable)
			, (T_raw, entities, "entities", 0)
			, (T_bool, v_protected, "protected", 0)
			, (T_int, followers_count, "followers_count", 0)
			, (T_int, friends_count, "friends_count", 0)
			, (T_int, listed_count, "listed_count", 0)
			, (T_string, created_at, "created_at", 0)
			, (T_int, favourites_count, "favourites_count", 0)
			, (T_int, utc_offset, "utc_offset", FDesc::Nullable)
			, (T_string, time_zone, "time_zone", FDesc::Nullable)
			, (T_bool, geo_enabled, "geo_enabled", 0)
			, (T_bool, verified, "verified", 0)
			, (T_int, statuses_count, "statuses_count", 0)
			, (T_string, lang, "lang", 0)
			, (T_bool, contributors_enabled, "contributors_enabled", 0)
			, (T_bool, is_translator, "is_translator", 0)
			, (T_bool, is_translation_enabled, "is_translation_enabled", 0)
			, (T_string, profile_background_color, "profile_background_color", 0)
			, (T_string, profile_background_image_url, "profile_background_image_url", 0)
			, (T_string, profile_background_image_url_https, "profile_background_image_url_https", 0)
			, (T_bool, profile_background_tile, "profile_background_tile", 0)
			, (T_string, profile_image_url, "profile_image_url", 0)
			, (T_string, profile_image_url_https, "profile_image_url_https", 0)
			, (T_string, profile_banner_url, "profile_banner_url", FDesc::Optional)
			, (T_string, profile_link_color, "profile_link_color", 0)
			, (T_string, profile_sidebar_border_color, "profile_sidebar_border_color", 0)
			, (T_string, profile_sidebar_fill_color, "profile_sidebar_fill_color", 0)
			, (T_string, profile_text_color, "profile_text_color", 0)
			, (T_bool, profile_use_background_image, "profile_use_background_image", 0)
			, (T_bool, default_profile, "default_profile", 0)
			, (T_bool, default_profile_image, "default_profile_image", 0)
			, (T_bool, following, "following", 0)
			, (T_bool, follow_request_sent, "follow_request_sent", 0)
			, (T_bool, notifications, "notifications", 0)
	)

	IJST_DEFINE_STRUCT(
			StStatus
			, (MAP_TYPE(T_string), metadata, "metadata", 0)
			, (T_string, created_at, "created_at", 0)
			, (T_uint64, id, "id", 0)
			, (T_string, id_str, "id_str", 0)
			, (T_string, text, "text", 0)
			, (T_string, source, "source", 0)
			, (T_bool, truncated, "truncated", 0)
			, (T_uint64, in_reply_to_status_id, "in_reply_to_status_id", FDesc::Nullable)
			, (T_string, in_reply_to_status_id_str, "in_reply_to_status_id_str", FDesc::Nullable)
			, (T_uint64, in_reply_to_user_id, "in_reply_to_user_id", FDesc::Nullable)
			, (T_string, in_reply_to_user_id_str, "in_reply_to_user_id_str", FDesc::Nullable)
			, (T_string, in_reply_to_screen_name, "in_reply_to_screen_name", FDesc::Nullable)
			, (IJST_TST(StUser), user, "user", 0)
			, (T_string, geo, "geo", FDesc::Nullable)
			, (T_string, coordinates, "coordinates", FDesc::Nullable)
			, (T_string, place, "place", FDesc::Nullable)
			, (T_string, contributors, "contributors", FDesc::Nullable)
			, (T_int, retweet_count, "retweet_count", 0)
			, (T_int, favorite_count, "favorite_count", 0)
			, (T_raw, entities, "entities", 0)
			, (T_bool, favorited, "favorited", 0)
			, (T_bool, retweeted, "retweeted", 0)
			, (T_string, lang, "lang", 0)
	)

	IJST_DEFINE_STRUCT(
			StSearchMetaData
			, (T_double, completed_in, "completed_in", 0)
			, (T_uint64, max_id, "max_id", 0)
			, (T_string, max_id_str, "max_id_str", 0)
			, (T_string, next_results, "next_results", 0)
			, (T_string, query, "query", 0)
			, (T_string, refresh_url, "refresh_url", 0)
			, (T_int, count, "count", 0)
			, (T_uint64, since_id, "since_id", 0)
			, (T_string, since_id_str, "since_id_str", 0)
	)

	IJST_DEFINE_STRUCT(
			StTwitter
			, (IJST_TVEC(IJST_TST(StStatus)), statuses, "statuses", 0)
			, (IJST_TST(StSearchMetaData), search_metadata, "search_metadata", 0)
	)
}
typedef twitter::StTwitter StTwitter;

namespace citm_catalog {
	IJST_DEFINE_STRUCT(
			StEvent
			, (T_string, description, "description", FDesc::Nullable)
			, (T_uint64, id, "id", 0)
			, (T_string, logo, "logo", FDesc::Nullable)
			, (T_string, name, "name", 0)
			, (IJST_TVEC(T_uint64), subTopicIds, "subTopicIds", 0)
			, (T_int, subjectCode, "subjectCode", FDesc::Nullable)
			, (T_string, subtitle, "subtitle", FDesc::Nullable)
			, (IJST_TVEC(T_uint64), topicIds, "topicIds", 0)
	)

	IJST_DEFINE_STRUCT(
			StPrice
			, (T_int, amount, "amount", 0)
			, (T_int64, audienceSubCategoryId, "audienceSubCategoryId", 0)
			, (T_int64, seatCategoryId, "seatCategoryId", 0)
	)

	IJST_DEFINE_STRUCT(
			StArea
			, (T_uint64, areaId, "areaId", 0)
			, (IJST_TVEC(T_uint64), blockIds, "blockIds", 0)
	)

	IJST_DEFINE_STRUCT(
			StSeatCategory
			, (IJST_TVEC(IJST_TST(StArea)), areas, "areas", 0)
			, (T_uint64, seatCategoryId, "seatCategoryId", 0)
	)

	IJST_DEFINE_STRUCT(
			StPerformance
			, (T_uint64, eventId, "eventId", 0)
			, (T_uint64, id, "id", 0)
			, (T_string, logo, "logo", FDesc::Nullable)
			, (T_string, name, "name", FDesc::Nullable)
			, (IJST_TVEC(IJST_TST(StPrice)), prices, "prices", 0)
			, (IJST_TVEC(IJST_TST(StSeatCategory)), seatCategories, "seatCategories", 0)
			, (T_string, seatMapImage, "seatMapImage", FDesc::Nullable)
			, (T_uint64, start, "start", 0)
			, (T_string, venueCode, "venueCode", 0)
	)

	IJST_DEFINE_STRUCT(
			StCitmCatalog
			, (MAP_TYPE(T_string), areaNames, "areaNames", 0)
			, (MAP_TYPE(T_string), audienceSubCategoryNames, "audienceSubCategoryNames", 0)
			, (MAP_TYPE(T_string), blockNames, "blockNames", 0)
			, (MAP_TYPE(IJST_TST(StEvent)), events, "events", 0)
			, (IJST_TVEC(IJST_TST(StPerformance)), performamces, "performances", 0)
			, (MAP_TYPE(T_string), seatCategoryNames, "seatCategoryNames", 0)
			, (MAP_TYPE(T_string), subTopicNames, "subTopicNames", 0)
			, (MAP_TYPE(T_string), subjectNames, "subjectNames", 0)
			, (MAP_TYPE(T_string), topicNames, "topicNames", 0)
			, (MAP_TYPE(IJST_TVEC(T_uint64)), topicSubTopics, "topicSubTopics", 0)
			, (MAP_TYPE(T_string), venueNames, "venueNames", 0)
	)
}
typedef citm_catalog::StCitmCatalog StCitmCatalog;

namespace pure_obj {
IJST_DEFINE_STRUCT(
		StL1
		, (T_int, i1, "i1", 0)   , (T_int, i2, "i2", 0)   , (T_int, i3, "i3", 0)   , (T_int, i4, "i4", 0)   , (T_int, i5, "i5", 0)
		, (T_int, i6, "i6", 0)   , (T_int, i7, "i7", 0)   , (T_int, i8, "i8", 0)   , (T_int, i9, "i9", 0)   , (T_int, i10, "i10", 0)
		, (T_int, i11, "i11", 0) , (T_int, i12, "i12", 0) , (T_int, i13, "i13", 0) , (T_int, i14, "i14", 0) , (T_int, i15, "i15", 0)
		, (T_int, i16, "i16", 0) , (T_int, i17, "i17", 0) , (T_int, i18, "i18", 0) , (T_int, i19, "i19", 0) , (T_int, i20, "i20", 0)
		, (T_int, i21, "i21", 0) , (T_int, i22, "i22", 0) , (T_int, i23, "i23", 0) , (T_int, i24, "i24", 0) , (T_int, i25, "i25", 0)
		, (T_int, i26, "i26", 0) , (T_int, i27, "i27", 0) , (T_int, i28, "i28", 0) , (T_int, i29, "i29", 0) , (T_int, i30, "i30", 0)
		, (T_int, i31, "i31", 0) , (T_int, i32, "i32", 0) , (T_int, i33, "i33", 0) , (T_int, i34, "i34", 0) , (T_int, i35, "i35", 0)
		, (T_int, i36, "i36", 0) , (T_int, i37, "i37", 0) , (T_int, i38, "i38", 0) , (T_int, i39, "i39", 0) , (T_int, i40, "i40", 0)
		, (T_int, i41, "i41", 0) , (T_int, i42, "i42", 0) , (T_int, i43, "i43", 0) , (T_int, i44, "i44", 0) , (T_int, i45, "i45", 0)
		, (T_int, i46, "i46", 0) , (T_int, i47, "i47", 0) , (T_int, i48, "i48", 0) , (T_int, i49, "i49", 0) , (T_int, i50, "i50", 0)
		, (T_int, i51, "i51", 0) , (T_int, i52, "i52", 0) , (T_int, i53, "i53", 0) , (T_int, i54, "i54", 0) , (T_int, i55, "i55", 0)
		, (T_int, i56, "i56", 0) , (T_int, i57, "i57", 0) , (T_int, i58, "i58", 0) , (T_int, i59, "i59", 0) , (T_int, i60, "i60", 0)
		, (T_int, i61, "i61", 0) , (T_int, i62, "i62", 0) , (T_int, i63, "i63", 0) , (T_int, i64, "i64", 0)
)
IJST_DEFINE_STRUCT(
		StL2
		, (IJST_TST(StL1), i1, "i1", 0)   , (IJST_TST(StL1), i2, "i2", 0)   , (IJST_TST(StL1), i3, "i3", 0)   , (IJST_TST(StL1), i4, "i4", 0)   , (IJST_TST(StL1), i5, "i5", 0)
		, (IJST_TST(StL1), i6, "i6", 0)   , (IJST_TST(StL1), i7, "i7", 0)   , (IJST_TST(StL1), i8, "i8", 0)   , (IJST_TST(StL1), i9, "i9", 0)   , (IJST_TST(StL1), i10, "i10", 0)
		, (IJST_TST(StL1), i11, "i11", 0) , (IJST_TST(StL1), i12, "i12", 0) , (IJST_TST(StL1), i13, "i13", 0) , (IJST_TST(StL1), i14, "i14", 0) , (IJST_TST(StL1), i15, "i15", 0)
		, (IJST_TST(StL1), i16, "i16", 0) , (IJST_TST(StL1), i17, "i17", 0) , (IJST_TST(StL1), i18, "i18", 0) , (IJST_TST(StL1), i19, "i19", 0) , (IJST_TST(StL1), i20, "i20", 0)
		, (IJST_TST(StL1), i21, "i21", 0) , (IJST_TST(StL1), i22, "i22", 0) , (IJST_TST(StL1), i23, "i23", 0) , (IJST_TST(StL1), i24, "i24", 0) , (IJST_TST(StL1), i25, "i25", 0)
		, (IJST_TST(StL1), i26, "i26", 0) , (IJST_TST(StL1), i27, "i27", 0) , (IJST_TST(StL1), i28, "i28", 0) , (IJST_TST(StL1), i29, "i29", 0) , (IJST_TST(StL1), i30, "i30", 0)
		, (IJST_TST(StL1), i31, "i31", 0) , (IJST_TST(StL1), i32, "i32", 0) , (IJST_TST(StL1), i33, "i33", 0) , (IJST_TST(StL1), i34, "i34", 0) , (IJST_TST(StL1), i35, "i35", 0)
		, (IJST_TST(StL1), i36, "i36", 0) , (IJST_TST(StL1), i37, "i37", 0) , (IJST_TST(StL1), i38, "i38", 0) , (IJST_TST(StL1), i39, "i39", 0) , (IJST_TST(StL1), i40, "i40", 0)
		, (IJST_TST(StL1), i41, "i41", 0) , (IJST_TST(StL1), i42, "i42", 0) , (IJST_TST(StL1), i43, "i43", 0) , (IJST_TST(StL1), i44, "i44", 0) , (IJST_TST(StL1), i45, "i45", 0)
		, (IJST_TST(StL1), i46, "i46", 0) , (IJST_TST(StL1), i47, "i47", 0) , (IJST_TST(StL1), i48, "i48", 0) , (IJST_TST(StL1), i49, "i49", 0) , (IJST_TST(StL1), i50, "i50", 0)
		, (IJST_TST(StL1), i51, "i51", 0) , (IJST_TST(StL1), i52, "i52", 0) , (IJST_TST(StL1), i53, "i53", 0) , (IJST_TST(StL1), i54, "i54", 0) , (IJST_TST(StL1), i55, "i55", 0)
		, (IJST_TST(StL1), i56, "i56", 0) , (IJST_TST(StL1), i57, "i57", 0) , (IJST_TST(StL1), i58, "i58", 0) , (IJST_TST(StL1), i59, "i59", 0) , (IJST_TST(StL1), i60, "i60", 0)
		, (IJST_TST(StL1), i61, "i61", 0) , (IJST_TST(StL1), i62, "i62", 0) , (IJST_TST(StL1), i63, "i63", 0) , (IJST_TST(StL1), i64, "i64", 0)
)
IJST_DEFINE_STRUCT(
		StL3
		, (IJST_TST(StL2), i1, "i1", 0)   , (IJST_TST(StL2), i2, "i2", 0)   , (IJST_TST(StL2), i3, "i3", 0)   , (IJST_TST(StL2), i4, "i4", 0)   , (IJST_TST(StL2), i5, "i5", 0)
		, (IJST_TST(StL2), i6, "i6", 0)   , (IJST_TST(StL2), i7, "i7", 0)   , (IJST_TST(StL2), i8, "i8", 0)   , (IJST_TST(StL2), i9, "i9", 0)   , (IJST_TST(StL2), i10, "i10", 0)
		, (IJST_TST(StL2), i11, "i11", 0) , (IJST_TST(StL2), i12, "i12", 0) , (IJST_TST(StL2), i13, "i13", 0) , (IJST_TST(StL2), i14, "i14", 0) , (IJST_TST(StL2), i15, "i15", 0)
		, (IJST_TST(StL2), i16, "i16", 0) , (IJST_TST(StL2), i17, "i17", 0) , (IJST_TST(StL2), i18, "i18", 0) , (IJST_TST(StL2), i19, "i19", 0) , (IJST_TST(StL2), i20, "i20", 0)
		, (IJST_TST(StL2), i21, "i21", 0) , (IJST_TST(StL2), i22, "i22", 0) , (IJST_TST(StL2), i23, "i23", 0) , (IJST_TST(StL2), i24, "i24", 0) , (IJST_TST(StL2), i25, "i25", 0)
		, (IJST_TST(StL2), i26, "i26", 0) , (IJST_TST(StL2), i27, "i27", 0) , (IJST_TST(StL2), i28, "i28", 0) , (IJST_TST(StL2), i29, "i29", 0) , (IJST_TST(StL2), i30, "i30", 0)
		, (IJST_TST(StL2), i31, "i31", 0) , (IJST_TST(StL2), i32, "i32", 0) , (IJST_TST(StL2), i33, "i33", 0) , (IJST_TST(StL2), i34, "i34", 0) , (IJST_TST(StL2), i35, "i35", 0)
		, (IJST_TST(StL2), i36, "i36", 0) , (IJST_TST(StL2), i37, "i37", 0) , (IJST_TST(StL2), i38, "i38", 0) , (IJST_TST(StL2), i39, "i39", 0) , (IJST_TST(StL2), i40, "i40", 0)
		, (IJST_TST(StL2), i41, "i41", 0) , (IJST_TST(StL2), i42, "i42", 0) , (IJST_TST(StL2), i43, "i43", 0) , (IJST_TST(StL2), i44, "i44", 0) , (IJST_TST(StL2), i45, "i45", 0)
		, (IJST_TST(StL2), i46, "i46", 0) , (IJST_TST(StL2), i47, "i47", 0) , (IJST_TST(StL2), i48, "i48", 0) , (IJST_TST(StL2), i49, "i49", 0) , (IJST_TST(StL2), i50, "i50", 0)
		, (IJST_TST(StL2), i51, "i51", 0) , (IJST_TST(StL2), i52, "i52", 0) , (IJST_TST(StL2), i53, "i53", 0) , (IJST_TST(StL2), i54, "i54", 0) , (IJST_TST(StL2), i55, "i55", 0)
		, (IJST_TST(StL2), i56, "i56", 0) , (IJST_TST(StL2), i57, "i57", 0) , (IJST_TST(StL2), i58, "i58", 0) , (IJST_TST(StL2), i59, "i59", 0) , (IJST_TST(StL2), i60, "i60", 0)
		, (IJST_TST(StL2), i61, "i61", 0) , (IJST_TST(StL2), i62, "i62", 0) , (IJST_TST(StL2), i63, "i63", 0) , (IJST_TST(StL2), i64, "i64", 0)
)
}
typedef pure_obj::StL3 StPureObj;

IJST_DEFINE_STRUCT(
		StCommon
);

IJST_DEFINE_VALUE(
		StVal, T_raw, v, 0
)

IJST_DEFINE_VALUE(
		VecDouble, IJST_TVEC(T_double), v, 0
)

IJST_DEFINE_VALUE(
		VecStr, IJST_TVEC(T_string), v, 0
)

template <typename Encoding = UTF8<> >
class StatHandler : public BaseReaderHandler<Encoding, StatHandler<Encoding> > {
public:
	typedef typename Encoding::Ch Ch;

	StatHandler(Stat& stat) : stat_(stat) {}

	bool Null() { stat_.nullCount++; return true; }
	bool Bool(bool b) { if (b) stat_.trueCount++; else stat_.falseCount++; return true; }
	bool Int(int) { stat_.numberCount++; return true; }
	bool Uint(unsigned) { stat_.numberCount++; return true; }
	bool Int64(int64_t) { stat_.numberCount++; return true; }
	bool Uint64(uint64_t) { stat_.numberCount++; return true; }
	bool Double(double) { stat_.numberCount++; return true; }
	bool String(const Ch*, SizeType length, bool) { stat_.stringCount++; stat_.stringLength += length; return true; }
	bool StartObject() { return true; }
	bool EndObject(SizeType memberCount) { stat_.objectCount++; stat_.memberCount += memberCount; return true; }
	bool StartArray() { return true; }
	bool EndArray(SizeType elementCount) { stat_.arrayCount++; stat_.elementCount += elementCount; return true; }

private:
	StatHandler& operator=(const StatHandler&);

	Stat& stat_;
};

class ijstStringResult : public StringResultBase {
public:
	ijstStringResult(string* _str) : str(_str) {}
	~ijstStringResult() {delete str;}
	virtual const char* c_str() const { return str->c_str(); }

	string* str;
};

class ijstStringBufResult : public StringResultBase {
public:
	ijstStringBufResult(rapidjson::StringBuffer* _buf) : buf(_buf) {}
	~ijstStringBufResult() {delete buf;}
	virtual const char* c_str() const { return buf->GetString(); }

	rapidjson::StringBuffer* buf;
};

class ijstParseResultBase : public ParseResultBase {
public:
	virtual StringResultBase* Stringify() const = 0;
	virtual bool GenStat(Stat* stat) const = 0;
	virtual StringResultBase* Prettify() const = 0;
};

template <typename T>
class ijstParseResult : public ijstParseResultBase {
public:
	ijstParseResult(T* _val = IJST_NULL) : st(_val)
	{
	}

	StringResultBase* Stringify() const override {
		string* out = new string();
		int ret = st->_.Serialize(*out, SerFlag::kIgnoreMissing);
		if (ret != 0) {
			delete out;
			return NULL;
		}

		return new ijstStringResult(out);
	}

	StringResultBase* Prettify() const override {
		rapidjson::StringBuffer* buf = new rapidjson::StringBuffer();
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(*buf);
		ijst::HandlerWrapper<rapidjson::PrettyWriter<rapidjson::StringBuffer> > writerWrapper(writer);
		int ret = st->_.Serialize(writerWrapper, SerFlag::kIgnoreMissing);
		if (ret != 0) {
			delete buf;
			return NULL;
		}

		return new ijstStringBufResult(buf);
	}

	bool GenStat(Stat* stat) const override {
		memset(stat, 0, sizeof(Stat));
		StatHandler<> h(*stat);
		HandlerWrapper<StatHandler<> > writerWrapper(h);
		if(st->_.Serialize(writerWrapper, SerFlag::kIgnoreMissing) != 0) {
			return false;
		}
		return true;
	}

	~ijstParseResult() { delete st; }
	T* st;
};


template<typename T>
ijstParseResultBase* GetParseResult(const char* json, size_t length, bool print_err = true)
{
	T* val = new T();
	Document errDoc;
	int ret = val->_.Deserialize(json, length, DeserFlag::kNoneFlag, &errDoc);
	if (ret != 0) {
		if (print_err) {
			StringBuffer sb;
			Writer<StringBuffer> writer;
			errDoc.Accept(writer);
			cout << "Deserialize error:  "  << sb.GetString() << endl;
		}
		delete val;
		return 0;
	}
	return new ijstParseResult<T>(val);
}


class TEST_CLASS : public TestBase {
public:
#if TEST_INFO
	virtual const char* GetName() const { return TEST_NAME; }
	virtual const char* GetFilename() const { return __FILE__; }
#endif

#if TEST_PARSE
	virtual ParseResultBase* Parse(const char* json, size_t length, const char* case_name) const {
//		cout << case_name << endl;
		if (strcmp(case_name, "canada.json") == 0) {
			return GetParseResult<StCanada>(json, length);
		}
		else if (strcmp(case_name, "canada_flat.json") == 0) {
			return GetParseResult<StCanadaFlat>(json, length);
		}
		else if (strcmp(case_name, "twitter.json") == 0) {
			return GetParseResult<StTwitter>(json, length);
		}
		else if(strcmp(case_name, "citm_catalog.json") == 0) {
			return GetParseResult<StCitmCatalog>(json, length);
		}
		else if(strcmp(case_name, "pure_obj.json") == 0) {
			return GetParseResult<StPureObj>(json, length);
		}
		else if (strstr(case_name, "jsonchecker") != NULL) {
			return GetParseResult<StVal>(json, length, false);
		}
		else if (strstr(case_name, "roundtrip") != NULL) {
			return GetParseResult<StVal>(json, length);
		}
		else {
			return GetParseResult<StCommon>(json, length);
		}
	}
#endif

#if TEST_STRINGIFY
	virtual StringResultBase* Stringify(const ParseResultBase* parseResult) const {
		const ijstParseResultBase *result = dynamic_cast<const ijstParseResultBase*>(parseResult);
		return result->Stringify();
	}
#endif

#if TEST_PRETTIFY
	virtual StringResultBase* Prettify(const ParseResultBase* parseResult) const {
		const ijstParseResultBase *result = dynamic_cast<const ijstParseResultBase*>(parseResult);
		return result->Prettify();
	}
#endif

#if TEST_STATISTICS
	virtual bool Statistics(const ParseResultBase* parseResult, Stat* stat) const {
		const ijstParseResultBase *result = dynamic_cast<const ijstParseResultBase*>(parseResult);
		return result->GenStat(stat);
	}
#endif

/*
#if TEST_SAXROUNDTRIP
	virtual StringResultBase* SaxRoundtrip(const char* json, size_t length) const {
		(void)length;
		Reader reader;
		RapidjsonStringResult* sr = new RapidjsonStringResult;
		Writer<StringBuffer> writer(sr->sb);

#ifdef TEST_INSITU
		RapidjsonParseResult pr(json, length);
        InsituStringStream is(pr.buffer);
#else
		StringStream is(json);
#endif

		if (!reader.Parse<TEST_PARSE_FLAG>(is, writer)) {
			delete sr;
			return 0;
		}
		return sr;
	}
#endif

#if TEST_SAXSTATISTICS
	virtual bool SaxStatistics(const char* json, size_t length, Stat* stat) const {
		(void)length;
		memset(stat, 0, sizeof(Stat));
		Reader reader;

#ifdef TEST_INSITU
		RapidjsonParseResult pr(json, length);
        InsituStringStream is(pr.buffer);
#else
		StringStream is(json);
#endif

		StatHandler<> handler(*stat);
		return reader.Parse<TEST_PARSE_FLAG>(is, handler);
	}
#endif

#if TEST_SAXSTATISTICSUTF16
	virtual bool SaxStatisticsUTF16(const char* json, size_t length, Stat* stat) const {
		(void)length;
		memset(stat, 0, sizeof(Stat));
		GenericReader<UTF8<>, UTF16<> > reader;

#ifdef TEST_INSITU
		RapidjsonParseResult pr(json, length);
        InsituStringStream is(pr.buffer);
#else
		StringStream is(json);
#endif
		StatHandler<UTF16<> > handler(*stat);
		return reader.Parse<TEST_PARSE_FLAG>(is, handler);
	}
#endif
 */

#if TEST_CONFORMANCE
	virtual bool ParseDouble(const char* json, double* d) const {
		VecDouble v;
		int ret;
#ifdef TEST_INSITU
		ret = v._.DeserializeInsitu(json);
#else
		ret = v._.Deserialize(json, strlen(json));
#endif
		if (ret != 0) {
			return false;
		}
		*d = v.v[0];
		return true;
	}

	virtual bool ParseString(const char* json, std::string& s) const {
		VecStr v;
		int ret;
#ifdef TEST_INSITU
		ret = v._.DeserializeInsitu(json);
#else
		ret = v._.Deserialize(json, strlen(json));
#endif
		if (ret != 0) {
			return false;
		}
		s = v.v[0];
		return true;
	}
#endif
};
REGISTER_TEST(TEST_CLASS);

