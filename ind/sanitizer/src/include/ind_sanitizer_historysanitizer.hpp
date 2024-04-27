/*################################################################################################
## Unit test for IDBClient																		##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Unit test for IDBClient							    ##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef IND_SANITIZER_HISTORYSANITIZER_HPP
#define	IND_SANITIZER_HISTORYSANITIZER_HPP

#include "ind_sanitizer_isanitizer.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>

using namespace testing;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using namespace std;


namespace IND {

	namespace SANITIZER {

		class HistorySanitizer;
		using HistorySanitizerPtr = shared_ptr<HistorySanitizer>;
		class HistorySanitizer : public ISanitizer {

			char* m_filePath;
		public:
			HistorySanitizer(char* filePath);

			bool Sanitize(vector<string>& invalidFiles) const override;
		};

	}
}


#endif // !IND_SANITIZER_HISTORYSANITIZER_HPP


