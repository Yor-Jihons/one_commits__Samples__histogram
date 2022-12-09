#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

namespace Util{
    /** @brief The array of the strings. */
    using StrVec = std::vector<std::string>;

    /**
     * @brief Separate the strings.
     * @param text The string you want to separate.
     * @param delim The delim string. ( def: " " )
     * @return The object of the std::Vector for std::string, which was separated.
    */
    StrVec split( const std::string& text, const std::string& delim = std::string(" ") ){
        StrVec res;
        int end = 0, begin = 0, n = 0;
        while( true ){
            end   = text.find( delim, begin );
            if( end == std::string::npos ){
                res.push_back( text.substr( begin, (text.size() - begin) ) );
                break;
            }
            n = (end - begin);
            res.push_back( text.substr( begin, n ) );
            begin = end + 1;
        }
    return res;
    }

    /**
     * @brief Convert the data to the string.
     * @param val The data you want to convert.
     * @return The string which was converted from the data.
     */
    template<typename T> std::string ToString( T val ){
        std::stringstream ss;
        ss << val << flush;
    return ss.str();
    }
}

namespace Original{
    class Hist{
        public:
            Hist( int begin, int end ) : begin_(begin),end_(end),counter_(0){}
            ~Hist() = default;

            bool IsTarget( int n ){
                // 1, 10
                //if( n >= 1 && n <= 10 ) return true;
                // 1 2 9 6 10 12 32 12 42 23 27 14
                if( n >= this->begin_ && n <= this->end_ ) return true;
            return false;
            }

            void Count(){
                counter_++;
            }

            std::string ToString() const{
                std::string text = "";
                for( int i = 0; i < counter_; i++ ){
                    text += "*";
                }
            return text;
            }
        private:
            int begin_;
            int end_;
            int counter_;
    };

    class HistEx{
        public:
            HistEx(){
                int prev = 1;
                for( int i = 0; i < 10; i++ ){
                    int max = (i + 1) * 10;
                    this->hists_.push_back( Original::Hist( prev, max ) );
                    prev = ((i + 1) * 10) + 1;
                }
            }

            void Count( int n ){
                for( int i = 0; i < static_cast<int>(hists_.size()); i++ ){
                    if( hists_[i].IsTarget( n ) ){
                        hists_[i].Count();
                        return;
                    }
                }
            return;
            }

            void Print( void ){
                for( size_t i = 0; i < static_cast<int>(hists_.size()); i++ ){
                    cout << hists_[i].ToString() << endl;
                }
            }
        private:
            std::vector<Original::Hist> hists_;
    };
}

namespace Original{
    class FormatException : public std::exception{
        public:
            FormatException(){}
            ~FormatException() = default;

            const char* what( void ) const noexcept{
                return "This data is wrong.";
            }
    };

    class OutOfBoundException : public std::exception{
        public:
            OutOfBoundException(){}
            ~OutOfBoundException() = default;

            const char* what( void ) const noexcept{
                return "This data is out of bound.";
            }
    };
}


namespace Original{
    bool IsDigitString( const std::string& str ){
        for( int i = 0; i < static_cast<int>(str.size()); i++ ){
            if( std::isdigit( str[i] ) == 0 ) return false;
        }
    return true;
    }
    int ConvertStringToInt( const std::string& str ){
        if( !IsDigitString( str ) ) throw FormatException();
        int n = std::atoi( str.c_str() );
    return n;
    }

    bool IsValidNumber4N( int n ){
        if( n >= 1 && n <= 30 ) return true;
    return false;
    }

    bool IsValidNumber4An( int n ){
        if( n >= 1 && n <= 100 ) return true;
    return false;
    }
}

int main( int argc, char** argv ){
    try{
        int n;
        {
            std::string str1;
            std::getline( cin, str1 );
            n = std::atoi( str1.c_str() );

            if( !Original::IsValidNumber4N( n ) ) throw Original::OutOfBoundException();
        }

        std::vector<int> nums( n );
        {
            std::string str2;
            std::getline( cin, str2 );
            auto strs = Util::split( str2 );
            int i = 0;
            for( auto s : strs ){
                nums[i] = Original::ConvertStringToInt( s );
                if( !Original::IsValidNumber4An( nums[i] ) ) throw Original::OutOfBoundException();
                i++;
            }
        }

        Original::HistEx histEx;
        for( int i = 0; i < n; i++ ){
            histEx.Count( nums[i] );
        }

        histEx.Print();
    }catch( std::exception& e ){
        cout << e.what() << endl;
    }
return 0;
}
