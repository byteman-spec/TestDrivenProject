/*################################################################################################
## Unit test for IDBClient																		##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Unit test for IDBClient							    ##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef IND_HISTORYSANITIZER_MOCKHISTORYSANITIZER_HPP
#define	IND_HISTORYSANITIZER_MOCKHISTORYSANITIZER_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <vector>

using namespace testing;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using namespace std;


namespace IND {

	namespace SANITIZER {

		class ISanitizer {
		
		public:
			virtual bool Sanitize(vector<string>& invalidFiles) const ;
		};

	}
}


#endif // !IND_HISTORYSANITIZER_MOCKHISTORYSANITIZER_HPP


