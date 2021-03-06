/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2011 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#include "ContribInc.h"
#include "NullFragmenter.h"

namespace Lucene
{
    NullFragmenter::~NullFragmenter()
    {
    }
    
    void NullFragmenter::start(const String& originalText, TokenStreamPtr tokenStream)
    {
    }
    
    bool NullFragmenter::isNewFragment()
    {
        return false;
    }
}
