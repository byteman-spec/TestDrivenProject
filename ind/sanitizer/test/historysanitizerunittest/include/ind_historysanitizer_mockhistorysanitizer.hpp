/*################################################################################################
## Unit test for IDBClient																		##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Unit test for IDBClient							    ##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef IND_SANITIZER_ISANITIZER_HPP
#define	IND_SANITIZER_ISANITIZER_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

using namespace testing;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using namespace std;


namespace IND {

	namespace SANITIZER {

		class ISanitizer {
		
		public:
			bool Sanitize() const = 0;
		};

	}
}


#endif // !IND_SANITIZER_ISANITIZER_HPP


