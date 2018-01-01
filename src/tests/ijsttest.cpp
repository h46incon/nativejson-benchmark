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
#include <iostream>

using namespace ijst;
using namespace std;
using namespace rapidjson;

//=== canada
namespace canada {
	IJST_DEFINE_STRUCT(
			StGeometry
			, (IJST_TPRI(Str), type, "type", 0)
			, (IJST_TVEC(IJST_TVEC(IJST_TVEC(IJST_TPRI(Double)))), coordinates, "coordinates", 0)
	);

	IJST_DEFINE_STRUCT(
			StFeature
			, (IJST_TPRI(Str), type, "type", 0)
			, (IJST_TMAP(IJST_TPRI(Str)), properties, "properties", 0)
			, (IJST_TOBJ(StGeometry), geometry, "geometry", 0)
	)

	IJST_DEFINE_STRUCT(
			StCanada
			, (IJST_TPRI(Str), type, "type", 0)
//			, (IJST_TVEC(IJST_TOBJ(StFeature)), features, "features", 0)
	)
}
typedef canada::StCanada StCanada;

//=== twitter
namespace twitter{
	IJST_DEFINE_STRUCT(
			StUser
			, (IJST_TPRI(UInt64), id, "id", 0)
			, (IJST_TPRI(Str), id_str, "id_str", 0)
			, (IJST_TPRI(Str), screen_name, "screen_name", FDesc::Nullable)
			, (IJST_TPRI(Str), location, "location", FDesc::Nullable)
			, (IJST_TPRI(Str), description, "description", FDesc::Nullable)
			, (IJST_TPRI(Str), url, "url", FDesc::Nullable)
			, (IJST_TPRI(Raw), entities, "entities", 0)
			, (IJST_TPRI(RBool), v_protected, "protected", 0)
			, (IJST_TPRI(Int), followers_count, "followers_count", 0)
			, (IJST_TPRI(Int), friends_count, "friends_count", 0)
			, (IJST_TPRI(Int), listed_count, "listed_count", 0)
			, (IJST_TPRI(Str), created_at, "created_at", 0)
			, (IJST_TPRI(Int), favourites_count, "favourites_count", 0)
			, (IJST_TPRI(Int), utc_offset, "utc_offset", FDesc::Nullable)
			, (IJST_TPRI(Str), time_zone, "time_zone", FDesc::Nullable)
			, (IJST_TPRI(RBool), geo_enabled, "geo_enabled", 0)
			, (IJST_TPRI(RBool), verified, "verified", 0)
			, (IJST_TPRI(Int), statuses_count, "statuses_count", 0)
			, (IJST_TPRI(Str), lang, "lang", 0)
			, (IJST_TPRI(RBool), contributors_enabled, "contributors_enabled", 0)
			, (IJST_TPRI(RBool), is_translator, "is_translator", 0)
			, (IJST_TPRI(RBool), is_translation_enabled, "is_translation_enabled", 0)
			, (IJST_TPRI(Str), profile_background_color, "profile_background_color", 0)
			, (IJST_TPRI(Str), profile_background_image_url, "profile_background_image_url", 0)
			, (IJST_TPRI(Str), profile_background_image_url_https, "profile_background_image_url_https", 0)
			, (IJST_TPRI(RBool), profile_background_tile, "profile_background_tile", 0)
			, (IJST_TPRI(Str), profile_image_url, "profile_image_url", 0)
			, (IJST_TPRI(Str), profile_image_url_https, "profile_image_url_https", 0)
			, (IJST_TPRI(Str), profile_banner_url, "profile_banner_url", FDesc::Optional)
			, (IJST_TPRI(Str), profile_link_color, "profile_link_color", 0)
			, (IJST_TPRI(Str), profile_sidebar_border_color, "profile_sidebar_border_color", 0)
			, (IJST_TPRI(Str), profile_sidebar_fill_color, "profile_sidebar_fill_color", 0)
			, (IJST_TPRI(Str), profile_text_color, "profile_text_color", 0)
			, (IJST_TPRI(RBool), profile_use_background_image, "profile_use_background_image", 0)
			, (IJST_TPRI(RBool), default_profile, "default_profile", 0)
			, (IJST_TPRI(RBool), default_profile_image, "default_profile_image", 0)
			, (IJST_TPRI(RBool), following, "following", 0)
			, (IJST_TPRI(RBool), follow_request_sent, "follow_request_sent", 0)
			, (IJST_TPRI(RBool), notifications, "notifications", 0)
	)

	IJST_DEFINE_STRUCT(
			StStatus
			, (IJST_TMAP(IJST_TPRI(Str)), metadata, "metadata", 0)
			, (IJST_TPRI(Str), created_at, "created_at", 0)
			, (IJST_TPRI(UInt64), id, "id", 0)
			, (IJST_TPRI(Str), id_str, "id_str", 0)
			, (IJST_TPRI(Str), text, "text", 0)
			, (IJST_TPRI(Str), source, "source", 0)
			, (IJST_TPRI(RBool), truncated, "truncated", 0)
			, (IJST_TPRI(UInt64), in_reply_to_status_id, "in_reply_to_status_id", FDesc::Nullable)
			, (IJST_TPRI(Str), in_reply_to_status_id_str, "in_reply_to_status_id_str", FDesc::Nullable)
			, (IJST_TPRI(UInt64), in_reply_to_user_id, "in_reply_to_user_id", FDesc::Nullable)
			, (IJST_TPRI(Str), in_reply_to_user_id_str, "in_reply_to_user_id_str", FDesc::Nullable)
			, (IJST_TPRI(Str), in_reply_to_screen_name, "in_reply_to_screen_name", FDesc::Nullable)
			, (IJST_TOBJ(StUser), user, "user", 0)
			, (IJST_TPRI(Str), geo, "geo", FDesc::Nullable)
			, (IJST_TPRI(Str), coordinates, "coordinates", FDesc::Nullable)
			, (IJST_TPRI(Str), place, "place", FDesc::Nullable)
			, (IJST_TPRI(Str), contributors, "contributors", FDesc::Nullable)
			, (IJST_TPRI(Int), retweet_count, "retweet_count", 0)
			, (IJST_TPRI(Int), favorite_count, "favorite_count", 0)
			, (IJST_TPRI(Raw), entities, "entities", 0)
			, (IJST_TPRI(RBool), favorited, "favorited", 0)
			, (IJST_TPRI(RBool), retweeted, "retweeted", 0)
			, (IJST_TPRI(Str), lang, "lang", 0)
	)

	IJST_DEFINE_STRUCT(
			StSearchMetaData
			, (IJST_TPRI(Double), completed_in, "completed_in", 0)
			, (IJST_TPRI(UInt64), max_id, "max_id", 0)
			, (IJST_TPRI(Str), max_id_str, "max_id_str", 0)
			, (IJST_TPRI(Str), next_results, "next_results", 0)
			, (IJST_TPRI(Str), query, "query", 0)
			, (IJST_TPRI(Str), refresh_url, "refresh_url", 0)
			, (IJST_TPRI(Int), count, "count", 0)
			, (IJST_TPRI(UInt64), since_id, "since_id", 0)
			, (IJST_TPRI(Str), since_id_str, "since_id_str", 0)
	)

	IJST_DEFINE_STRUCT(
			StTwitter
			, (IJST_TVEC(IJST_TOBJ(StStatus)), statuses, "statuses", 0)
			, (IJST_TOBJ(StSearchMetaData), search_metadata, "search_metadata", 0)
	)
}
typedef twitter::StTwitter StTwitter;

namespace citm_catalog {
	IJST_DEFINE_STRUCT(
			StEvent
			, (IJST_TPRI(Str), description, "description", FDesc::Nullable)
			, (IJST_TPRI(UInt64), id, "id", 0)
			, (IJST_TPRI(Str), logo, "logo", FDesc::Nullable)
			, (IJST_TPRI(Str), name, "name", 0)
			, (IJST_TVEC(IJST_TPRI(UInt64)), subTopicIds, "subTopicIds", 0)
			, (IJST_TPRI(Int), subjectCode, "subjectCode", FDesc::Nullable)
			, (IJST_TPRI(Str), subtitle, "subtitle", FDesc::Nullable)
			, (IJST_TVEC(IJST_TPRI(UInt64)), topicIds, "topicIds", 0)
	)

	IJST_DEFINE_STRUCT(
			StPrice
			, (IJST_TPRI(Int), amount, "amount", 0)
			, (IJST_TPRI(Int64), audienceSubCategoryId, "audienceSubCategoryId", 0)
			, (IJST_TPRI(Int64), seatCategoryId, "seatCategoryId", 0)
	)

	IJST_DEFINE_STRUCT(
			StArea
			, (IJST_TPRI(UInt64), areaId, "areaId", 0)
			, (IJST_TVEC(IJST_TPRI(UInt64)), blockIds, "blockIds", 0)
	)

	IJST_DEFINE_STRUCT(
			StSeatCategory
			, (IJST_TVEC(IJST_TOBJ(StArea)), areas, "areas", 0)
			, (IJST_TPRI(UInt64), seatCategoryId, "seatCategoryId", 0)
	)

	IJST_DEFINE_STRUCT(
			StPerformance
			, (IJST_TPRI(UInt64), eventId, "eventId", 0)
			, (IJST_TPRI(UInt64), id, "id", 0)
			, (IJST_TPRI(Str), logo, "logo", FDesc::Nullable)
			, (IJST_TPRI(Str), name, "name", FDesc::Nullable)
			, (IJST_TVEC(IJST_TOBJ(StPrice)), prices, "prices", 0)
			, (IJST_TVEC(IJST_TOBJ(StSeatCategory)), seatCategories, "seatCategories", 0)
			, (IJST_TPRI(Str), seatMapImage, "seatMapImage", FDesc::Nullable)
			, (IJST_TPRI(UInt64), start, "start", 0)
			, (IJST_TPRI(Str), venueCode, "venueCode", 0)
	)

	IJST_DEFINE_STRUCT(
			StCitmCatalog
			, (IJST_TMAP(IJST_TPRI(Str)), areaNames, "areaNames", 0)
			, (IJST_TMAP(IJST_TPRI(Str)), audienceSubCategoryNames, "audienceSubCategoryNames", 0)
			, (IJST_TMAP(IJST_TPRI(Str)), blockNames, "blockNames", 0)
			, (IJST_TMAP(IJST_TOBJ(StEvent)), events, "events", 0)
			, (IJST_TVEC(IJST_TOBJ(StPerformance)), performamces, "performances", 0)
			, (IJST_TMAP(IJST_TPRI(Str)), seatCategoryNames, "seatCategoryNames", 0)
			, (IJST_TMAP(IJST_TPRI(Str)), subTopicNames, "subTopicNames", 0)
			, (IJST_TMAP(IJST_TPRI(Str)), subjectNames, "subjectNames", 0)
			, (IJST_TMAP(IJST_TPRI(Str)), topicNames, "topicNames", 0)
			, (IJST_TMAP(IJST_TVEC(IJST_TPRI(UInt64))), topicSubTopics, "topicSubTopics", 0)
			, (IJST_TMAP(IJST_TPRI(Str)), venueNames, "venueNames", 0)
	)
}
typedef citm_catalog::StCitmCatalog StCitmCatalog;

IJST_DEFINE_STRUCT(
		StCommon
);

IJST_DEFINE_VALUE(
		StVal, IJST_TPRI(Raw), v, 0
)

IJST_DEFINE_VALUE(
		VecDouble, IJST_TVEC(IJST_TPRI(Double)), v, 0
)

IJST_DEFINE_VALUE(
		VecStr, IJST_TVEC(IJST_TPRI(Str)), v, 0
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

static void GenStat(Stat& stat, const Value& v) {
	switch (v.GetType()) {
		case kNullType:  stat.nullCount++; break;
		case kFalseType: stat.falseCount++; break;
		case kTrueType:  stat.trueCount++; break;

		case kObjectType:
			for (Value::ConstMemberIterator m = v.MemberBegin(); m != v.MemberEnd(); ++m) {
				stat.stringLength += m->name.GetStringLength();
				GenStat(stat, m->value);
			}
			stat.objectCount++;
			stat.memberCount += (v.MemberEnd() - v.MemberBegin());
			stat.stringCount += (v.MemberEnd() - v.MemberBegin()); // Key
			break;

		case kArrayType:
			for (Value::ConstValueIterator i = v.Begin(); i != v.End(); ++i)
				GenStat(stat, *i);
			stat.arrayCount++;
			stat.elementCount += v.Size();
			break;

		case kStringType:
			stat.stringCount++;
			stat.stringLength += v.GetStringLength();
			break;

		case kNumberType:
			stat.numberCount++;
			break;
	}
}

class ijstStringResult : public StringResultBase {
public:
	ijstStringResult(string* _str) : str(_str) {}
	~ijstStringResult() {delete str;}
	virtual const char* c_str() const { return str->c_str(); }

	string* str;
};

class ijstParseResultBase : public ParseResultBase {
public:
	virtual StringResultBase* Stringify() const = 0;
	virtual bool GenStat(Stat* stat) const = 0;
};

template <typename T>
class ijstParseResult : public ijstParseResultBase {
public:
	ijstParseResult(T* _val = IJST_NULL) : st(_val)
	{
	}

	StringResultBase* Stringify() const override {
		string* out = new string();
		int ret = st->_.Serialize(*out, FPush::kPushUnknown);
		if (ret != 0) {
			delete out;
			return NULL;
		}

		return new ijstStringResult(out);
	}

	bool GenStat(Stat* stat) const override {
		memset(stat, 0, sizeof(Stat));
		Document doc;
		if(st->_.ToJson(doc, doc.GetAllocator(), FPush::kPushUnknown) != 0) {
			return false;
		}
#if SLOWER_STAT
		StatHandler<> h(*stat);
        doc->Accept(h);
#else
		::GenStat(*stat, doc);
#endif
		return true;
	}

	~ijstParseResult() { delete st; }
	T* st;
};


template<typename T>
ijstParseResultBase* GetParseResult(const char* json, size_t length, bool print_err = true)
{
	T* val = new T();
	string strErrMsg;
	int ret = val->_.Deserialize(json, length, UnknownMode::kKeep, &strErrMsg);
	if (ret != 0) {
		if (print_err) {
			cout << "Deserialize error:  "  << strErrMsg << endl;
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
		else if (strcmp(case_name, "twitter.json") == 0) {
			return GetParseResult<StTwitter>(json, length);
		}
		else if(strcmp(case_name, "citm_catalog.json") == 0) {
			return GetParseResult<StCitmCatalog>(json, length);
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

/*
#if TEST_PRETTIFY
	virtual StringResultBase* Prettify(const ParseResultBase* parseResult) const {
		const RapidjsonParseResult* pr = static_cast<const RapidjsonParseResult*>(parseResult);
		RapidjsonStringResult* sr = new RapidjsonStringResult;
		PrettyWriter<StringBuffer> writer(sr->sb);
		pr->document.Accept(writer);
		return sr;
	}
#endif
*/

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

