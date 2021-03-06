/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2011 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#include "TestInc.h"
#include "BaseTokenStreamFixture.h"
#include "PersianAnalyzer.h"

using namespace Lucene;

BOOST_FIXTURE_TEST_SUITE(PersianAnalyzerTest, BaseTokenStreamFixture)

/// These tests show how the combination of tokenization (breaking on zero-width
/// non-joiner), normalization (such as treating arabic YEH and farsi YEH the
/// same), and stopwords creates a light-stemming effect for verbs.
///
/// These verb forms are from http://en.wikipedia.org/wiki/Persian_grammar

/// active present indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs1)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 0x8c, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active preterite indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs2)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective preterite indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs3)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 0x8c, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active future indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs4)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0x20, 0xd8, 0xae, 0xd9, 0x88, 
                             0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active present progressive indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs5)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xaf, 0xd8, 0xa7, 0xd8, 0xb1, 0xd8, 0xaf, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 
                             0x8c, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active preterite progressive indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs6)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xaf, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaa, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 
                             0x8c, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active perfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs7)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0xe2, 0x80, 0x8c, 0xd8, 0xa7, 
                             0xd8, 0xb3, 0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective perfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs8)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 0x8c, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 
                             0xd9, 0x87, 0xe2, 0x80, 0x8c, 0xd8, 0xa7, 0xd8, 0xb3, 0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active pluperfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs9)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 
                             0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective pluperfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs10)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 0x8c, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active preterite subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs11)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 
                             0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective preterite subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs12)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 0x8c, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active pluperfect subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs13)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 
                             0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective pluperfect subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs14)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 0x8c, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 
                             0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive present indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs15)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 
                             0xe2, 0x80, 0x8c, 0xd8, 0xb4, 0xd9, 0x88, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive preterite indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs16)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective preterite indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs17)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 
                             0xe2, 0x80, 0x8c, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive perfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs18)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf, 
                             0xd9, 0x87, 0xe2, 0x80, 0x8c, 0xd8, 0xa7, 0xd8, 0xb3, 0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective perfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs19)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 
                             0xe2, 0x80, 0x8c, 0xd8, 0xb4, 0xd8, 0xaf, 0xd9, 0x87, 0xe2, 0x80, 0x8c, 0xd8, 0xa7, 0xd8, 
                             0xb3, 0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive pluperfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs20)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective pluperfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs21)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 
                             0xe2, 0x80, 0x8c, 0xd8, 0xb4, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 
                             0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive future indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs22)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xae, 0xd9, 0x88, 
                             0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0x20, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive present progressive indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs23)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xaf, 0xd8, 0xa7, 0xd8, 0xb1, 0xd8, 0xaf, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 
                             0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 0x8c, 0xd8, 0xb4, 0xd9, 
                             0x88, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive preterite progressive indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbs24)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xaf, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaa, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 
                             0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 0xe2, 0x80, 0x8c, 0xd8, 0xb4, 0xd8, 
                             0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive present subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs25)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd9, 0x88, 
                             0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive preterite subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs26)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective preterite subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs27)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 
                             0xe2, 0x80, 0x8c, 0xd8, 0xb4, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 
                             0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive pluperfect subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs28)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 
                             0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective pluperfect subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs29)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xdb, 0x8c, 
                             0xe2, 0x80, 0x8c, 0xd8, 0xb4, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 
                             0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active present subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbs30)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xa8, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xa8, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// This test shows how the combination of tokenization and stopwords creates a
/// light-stemming effect for verbs.
///
/// In this case, these forms are presented with alternative orthography, using
/// arabic yeh and whitespace. This yeh phenomenon is common for legacy text
/// due to some previous bugs in Microsoft Windows.
///
/// These verb forms are from http://en.wikipedia.org/wiki/Persian_grammar

/// active present subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective1)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active preterite indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective2)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective preterite indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective3)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active future indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective4)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0x20, 0xd8, 0xae, 0xd9, 0x88, 
                             0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active present progressive indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective5)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xaf, 0xd8, 0xa7, 0xd8, 0xb1, 0xd8, 0xaf, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 
                             0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active preterite progressive indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective6)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xaf, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaa, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 
                             0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active perfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective7)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa7, 0xd8, 0xb3, 
                             0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective perfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective8)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 
                             0x20, 0xd8, 0xa7, 0xd8, 0xb3, 0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active pluperfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective9)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 
                             0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective pluperfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective10)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 
                             0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active preterite subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective11)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 
                             0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective preterite subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective12)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 
                             0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active pluperfect subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective13)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 
                             0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active imperfective pluperfect subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective14)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 
                             0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 
                             0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive present indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective15)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 
                             0x20, 0xd8, 0xb4, 0xd9, 0x88, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive preterite indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective16)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective preterite indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective17)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 
                             0x20, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive perfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective18)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa7, 0xd8, 0xb3, 0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective perfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective19)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 
                             0x20, 0xd8, 0xb4, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa7, 0xd8, 0xb3, 0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive pluperfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective20)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective pluperfect indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective21)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 
                             0x20, 0xd8, 0xb4, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive future indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective22)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xae, 0xd9, 0x88, 
                             0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0x20, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive present progressive indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective23)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xaf, 0xd8, 0xa7, 0xd8, 0xb1, 0xd8, 0xaf, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 
                             0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 0xb4, 0xd9, 0x88, 0xd8, 
                             0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive preterite progressive indicative
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective24)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xaf, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaa, 0x20, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 
                             0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 0x20, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive present subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective25)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd9, 0x88, 
                             0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive preterite subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective26)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective preterite subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective27)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 
                             0x20, 0xd8, 0xb4, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 
                             0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive pluperfect subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective28)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xb4, 0xd8, 0xaf, 
                             0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd8, 
                             0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// passive imperfective pluperfect subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective29)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 
                             0x20, 0xd8, 0xb4, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf, 0xd9, 
                             0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// active present subjunctive
BOOST_AUTO_TEST_CASE(testBehaviorVerbsDefective30)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xa8, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xa8, 0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// These tests show how the combination of tokenization (breaking on zero-width
/// non-joiner or space) and stopwords creates a light-stemming effect for
/// nouns, removing the plural -ha.

BOOST_AUTO_TEST_CASE(testBehaviorNouns1)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xa8, 0xd8, 0xb1, 0xda, 0xaf, 0x20, 0xd9, 0x87, 0xd8, 0xa7};
    const uint8_t second[] = {0xd8, 0xa8, 0xd8, 0xb1, 0xda, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

BOOST_AUTO_TEST_CASE(testBehaviorNouns2)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xa8, 0xd8, 0xb1, 0xda, 0xaf, 0xe2, 0x80, 0x8c, 0xd9, 0x87, 0xd8, 0xa7};
    const uint8_t second[] = {0xd8, 0xa8, 0xd8, 0xb1, 0xda, 0xaf};
    checkAnalyzesTo(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// Test showing that non-Persian text is treated very much like SimpleAnalyzer (lowercased, etc)
BOOST_AUTO_TEST_CASE(testBehaviorNonPersian)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    checkAnalyzesTo(a, L"English test.", newCollection<String>(L"english", L"test"));
}

BOOST_AUTO_TEST_CASE(testReusableTokenStream1)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd9, 0x85, 0xd9, 0x8a, 
                             0x20, 0xd8, 0xb4, 0xd8, 0xaf, 0xd9, 0x87, 0x20, 0xd8, 0xa8, 0xd9, 0x88, 0xd8, 0xaf, 0xd9, 
                             0x87, 0x20, 0xd8, 0xa8, 0xd8, 0xa7, 0xd8, 0xb4, 0xd8, 0xaf};
    const uint8_t second[] = {0xd8, 0xae, 0xd9, 0x88, 0xd8, 0xb1, 0xd8, 0xaf, 0xd9, 0x87};
    checkAnalyzesToReuse(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

BOOST_AUTO_TEST_CASE(testReusableTokenStream2)
{
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT);
    const uint8_t first[] = {0xd8, 0xa8, 0xd8, 0xb1, 0xda, 0xaf, 0xe2, 0x80, 0x8c, 0xd9, 0x87, 0xd8, 0xa7};
    const uint8_t second[] = {0xd8, 0xa8, 0xd8, 0xb1, 0xda, 0xaf};
    checkAnalyzesToReuse(a, UTF8_TO_STRING(first), newCollection<String>(UTF8_TO_STRING(second)));
}

/// Test that custom stopwords work, and are not case-sensitive.
BOOST_AUTO_TEST_CASE(testCustomStopwords)
{
    Collection<String> stopWords = newCollection<String>(L"the", L"and", L"a");
    PersianAnalyzerPtr a = newLucene<PersianAnalyzer>(LuceneVersion::LUCENE_CURRENT, HashSet<String>::newInstance(stopWords.begin(), stopWords.end()));
    checkAnalyzesTo(a, L"The quick brown fox.", newCollection<String>(L"quick", L"brown", L"fox"));
}

BOOST_AUTO_TEST_SUITE_END()
