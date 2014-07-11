#include "tokenizor.h"
#include<boost/tokenizer.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace std;

typedef boost::escaped_list_separator<char>  Separator;
typedef boost::tokenizer<Separator> Tokeniser;
Tokens::Tokens(const string& input, char sep)
    : empty("")
{
    string buf(input);
    string working(input);
    boost::algorithm::trim(buf);

    Tokeniser tokeniser(buf,Separator('\\', sep));
    for ( auto it = tokeniser.begin(); it!=tokeniser.end(); ++it) {
        // Skip blank values...
        working = *it;
        boost::algorithm::trim(working);
        if ( working != "" ) {
            push_back(*it);
        }
    }
}

const std::string& Tokens::operator[](size_t idx) {
    if ( idx >= size() ) {
        return empty;
    } else {
        return vector<string>::operator[](idx);
    }
}
