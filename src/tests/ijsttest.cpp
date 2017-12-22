#include "../test.h"

#ifndef TEST_NAME
#define TEST_NAME "IJST (C++)"
#endif

#ifndef TEST_CLASS
#define TEST_CLASS ijstTest
#endif

#include "IJST/include/ijst/ijst.h"
#include <iostream>

using namespace ijst;
using namespace std;

IJST_DEFINE_STRUCT(
		StCommon
);
/*
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
*/

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
};

template <typename T>
class ijstParseResult : public ijstParseResultBase {
public:
	ijstParseResult(T* _val = IJST_NULL) : st(_val)
	{
	}

	StringResultBase* Stringify() const override {
		string* out = new string();
		int ret = st->_.Serialize(true, *out);
		if (ret != 0) {
			return 0;
		}

		return new ijstStringResult(out);
	}

	~ijstParseResult() { delete st; }
	T* st;
};



class TEST_CLASS : public TestBase {
public:
#if TEST_INFO
	virtual const char* GetName() const { return TEST_NAME; }
	virtual const char* GetFilename() const { return __FILE__; }
#endif

#if TEST_PARSE
	virtual ParseResultBase* Parse(const char* json, size_t length, const char* case_name) const {
		(void)length;
		StCommon* val = new StCommon();
		int ret = val->_.Deserialize(json, length);
		if (ret != 0) {
			delete val;
			return 0;
		}

		return new ijstParseResult<StCommon>(val);
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

#if TEST_STATISTICS
	virtual bool Statistics(const ParseResultBase* parseResult, Stat* stat) const {
		const RapidjsonParseResult* pr = static_cast<const RapidjsonParseResult*>(parseResult);
		memset(stat, 0, sizeof(Stat));
#if SLOWER_STAT
		StatHandler<> h(*stat);
        doc->Accept(h);
#else
		GenStat(*stat, pr->document);
#endif
		return true;
	}
#endif

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

#if TEST_CONFORMANCE
	virtual bool ParseDouble(const char* json, double* d) const {
		Document doc;
#ifdef TEST_INSITU
		RapidjsonParseResult pr(json, strlen(json));
        doc.ParseInsitu<TEST_PARSE_FLAG>(pr.buffer);
#else
		doc.Parse<TEST_PARSE_FLAG>(json);
#endif
		if (!doc.HasParseError() && doc.IsArray() && doc.Size() == 1 && doc[0].IsNumber()) {
			*d = doc[0].GetDouble();
			return true;
		}
		return false;
	}

	virtual bool ParseString(const char* json, std::string& s) const {
		Document doc;
#ifdef TEST_INSITU
		RapidjsonParseResult pr(json, strlen(json));
        doc.ParseInsitu<TEST_PARSE_FLAG>(pr.buffer);
#else
		doc.Parse<TEST_PARSE_FLAG>(json);
#endif
		if (!doc.HasParseError() && doc.IsArray() && doc.Size() == 1 && doc[0].IsString()) {
			s = std::string(doc[0].GetString(), doc[0].GetStringLength());
			return true;
		}
		return false;
	}
#endif
 */
};
REGISTER_TEST(TEST_CLASS);

